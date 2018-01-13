/*$Id: hash.c,v 1.2 2002/02/13 12:30:58 root Exp $
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "protos.h"
#include "snew.h"
#define        HASH_KEY(ht,key) ( (((unsigned int)(key)) * 17) % (ht)->table_size )

void init_hash_table(struct hash_header        *ht, int rec_size, int table_size)
{
  ht->rec_size = rec_size;
  ht->table_size = table_size;
  ht->buckets = (struct hash_link **)calloc(sizeof(struct hash_link**), 
                                           table_size);
  ht->keylist = (int *)malloc(sizeof(ht->keylist)*(ht->klistsize=128));
  ht->klistlen = 0;
}

void init_world(struct room_data *room_db[])
{
#ifdef CYGWIN
   bzero((char *)room_db, sizeof(struct room_data *) * WORLD_SIZE);  /* zero out the world */
#else
   bzero(room_db, sizeof(struct room_data *) * WORLD_SIZE);  /* zero out the world */
#endif
}
void destroy_hash_table(struct hash_header *ht, void (*gman)(void *))
{
  int        i;
  struct hash_link *scan, *temp;

  for (i=0; i<ht->table_size; i++)
  {
    for (scan = ht->buckets[i]; scan; )
    {
      temp = scan->next;
      (*gman)(scan->data);
      free(scan);
      scan = temp;
    }
  }
  
  free(ht->buckets);
  ht->buckets = NULL;
  free(ht->keylist);
  ht->keylist = NULL;
}


void _hash_enter(struct hash_header *ht, long key, void *data)

{ /* precondition: there is no entry for <key> yet */
  struct hash_link *temp;
  int        i;

  temp = (struct hash_link *)malloc(sizeof(struct hash_link));
  temp->key = key;
  temp->next = ht->buckets[HASH_KEY(ht,key)];
  temp->data = data;
  ht->buckets[HASH_KEY(ht,key)] = temp;
  if (ht->klistlen >= ht->klistsize)
  {
    ht->keylist = (int *)realloc(ht->keylist,sizeof(*ht->keylist)*
                                 (ht->klistsize*=2));
  }
  for (i=ht->klistlen; i>=0; i--) {
    if (ht->keylist[i-1]<key) {
      ht->keylist[i] = key;
      break;
    }
    ht->keylist[i] = ht->keylist[i-1];
  }
  ht->klistlen++;
}

struct room_data *room_find( struct room_data *room_db[], long key)
{
   return((key<WORLD_SIZE&&key>-1)?room_db[key]:0);
}

void *hash_find(struct hash_header *ht, long key)
{
  struct hash_link        *scan;

  scan = ht->buckets[HASH_KEY(ht,key)];

  while (scan && scan->key != key)
    scan = scan->next;

  return scan ? scan->data : NULL;
}

int room_enter(struct room_data *rb[], long key, struct room_data *rm)
{
   struct room_data *temp;
   
   temp = room_find(rb, key);
   if (temp) return(0);

   rb[key] = rm;
   return(1);

}

int hash_enter(struct hash_header *ht, long key, void *data)
{
  void        *temp;
  temp = hash_find(ht, key);
  if (temp)
    return 0;

  _hash_enter(ht, key, data);
  return 1;
}

struct room_data *room_find_or_create(struct room_data *rb[], long key)
{
  struct room_data *rv;

  rv = room_find(rb, key);
  if (rv)
    return rv;

  rv = (struct room_data *)malloc(sizeof(struct room_data));

  rb[key] = rv;
    
  return rv;
}

void *hash_find_or_create(struct hash_header *ht, long key)
{
  void        *rval;

  rval = hash_find(ht, key);
  if (rval)
    return rval;

  rval = (void*)malloc(ht->rec_size);
  _hash_enter(ht,key,rval);
  return rval;
}

int room_remove(struct room_data *rb[], long key)
{

   struct room_data *tmp;

   tmp = room_find(rb, key);

   if (tmp) {
     rb[key] = 0;
     free(tmp);
   } 
   return(0);
}

void *hash_remove(struct hash_header *ht, long key)
{
  struct hash_link        **scan;

  scan = ht->buckets +HASH_KEY(ht,key);

  while (*scan && (*scan)->key != key)
    scan = &(*scan)->next;

  if (*scan) {
    int        i;

    struct hash_link *temp, *aux;
    temp = (struct hash_link *)(*scan)->data;
    aux = *scan;
    *scan = aux->next;
    free(aux);

    for (i=0; i<ht->klistlen; i++)
      if (ht->keylist[i]==key)
        break;

    if (i<ht->klistlen) {
#ifdef CYGWIN
      bcopy((const char *)ht->keylist+i+1, (char *)ht->keylist+i, 
#else
      bcopy(ht->keylist+i+1, ht->keylist+i, 
#endif
            (ht->klistlen-i)*sizeof(*ht->keylist));
      ht->klistlen--;
    }

    return temp;
  }

  return NULL;
}

void room_iterate( struct room_data *rb[], 
                   void (*func)( int, struct room_data *, void * ), 
                   void *cdata )
{
  register int        i;
  for (i=0; i<WORLD_SIZE; i++)
  {
    struct room_data  *temp;
  
    temp = room_find(rb, i);
    if (temp)
    {
       (*func)(i, temp, cdata);
    }
  }
}


void hash_iterate( struct hash_header *ht,
                   void (*func)( int, void *, void * ),
                   void *cdata )
{
  int        i;
  for (i=0; i<ht->klistlen; i++)
  {
    void        *temp;
    register long key;

    key = ht->keylist[i];
    temp = hash_find(ht, key);
    (*func)(key, temp, cdata);
    if (ht->keylist[i]!=key) /* They must have deleted this room */
      i--;        /* Hit this slot again. */
  }
}
