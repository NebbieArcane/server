#include "specialproc_room.hpp"
#include "spec_procs.hpp"
#include "spec_procs2.hpp"
#include "spec_procs3.hpp"
#include "lucertole.hpp"
struct RoomSpecialProcEntry roomproc[] = {
	{ "BlockWay", BlockWay },
	{ "CapannaVillaggio", CapannaVillaggio },
	{ "ChurchBell", ChurchBell },
	{ "ColloSerpente", ColloSerpente },
	{ "Donation", Donation },
	{ "Fountain", Fountain },
	{ "House", House },
	{ "Magic_Fountain", Magic_Fountain },
	{ "Rampicante", Rampicante },
	{ "bank", bank },
	{ "druid_challenge_prep_room", druid_challenge_prep_room },
	{ "druid_challenge_room", druid_challenge_room },
	{ "dump", dump },
	{ "monk_challenge_prep_room", monk_challenge_prep_room },
	{ "monk_challenge_room", monk_challenge_room },
	{ "pet_shops", pet_shops },
	{ "pray_for_items", pray_for_items },
	{ "BlockAlign", BlockAlign },
	{ "MOBKilled", MOBKilled },   // SALVO 2006 Quest fisse
	{ "zFineprocedure", NULL },
};
