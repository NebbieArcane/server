/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
//  Original intial comments
/***************************  System  include ************************************/
/***************************  General include ************************************/
#include "config.hpp"
#include "typedefs.hpp"
#include "flags.hpp"
#include "autoenums.hpp"
#include "structs.hpp"
#include "logging.hpp"
#include "constants.hpp"
#include "utils.hpp"
/***************************  Local    include ************************************/
#include "pedit.hpp"
#include "specialproc_other.hpp"
#include "spec_procs.hpp"
#include "spec_procs2.hpp"
#include "spec_procs3.hpp"
#include "speciali.hpp"
#include "lucertole.hpp"
#include "nilmys.hpp"
#include "rhyodin.hpp"
#include "breath.hpp"
#include "board.hpp"
#include "reception.hpp"
namespace Alarmud {
struct OtherSpecialProcEntry otherproc[] = {
	{ "AGGRESSIVE",(genericspecial_func) AGGRESSIVE },
	{ "AbbarachDragon",(genericspecial_func)AbbarachDragon },
	{ "AbyssGateKeeper",(genericspecial_func) AbyssGateKeeper },
	{ "Ankheg",(genericspecial_func) Ankheg },
	{ "banshee_lorelai",(genericspecial_func) banshee_lorelai },
	{ "Beholder",(genericspecial_func) Beholder },
	{ "BerserkerItem",(genericspecial_func) BerserkerItem },
	{ "BiosKaiThanatos",(genericspecial_func) BiosKaiThanatos },
	{ "BreathWeapon",(genericspecial_func) BreathWeapon },
	{ "Capo_Fucina",(genericspecial_func) Capo_Fucina },
	{ "camino",(genericspecial_func) camino },
	{ "CaravanGuildGuard",(genericspecial_func) CaravanGuildGuard },
	{ "CarrionCrawler",(genericspecial_func) CarrionCrawler },
	{ "ClericGuildMaster",(genericspecial_func) ClericGuildMaster },
	{ "Cockatrice",(genericspecial_func) Cockatrice },
	{ "Demon",(genericspecial_func) Demon },
	{ "DemonTeacher",(genericspecial_func) DemonTeacher },
	{ "Devil",(genericspecial_func) Devil },
	{ "DogCatcher",(genericspecial_func) DogCatcher },
	{ "DragonHunterLeader",(genericspecial_func) DragonHunterLeader },
	{ "Drow",(genericspecial_func) Drow },
	{ "DruidChallenger",(genericspecial_func) DruidChallenger },
	{ "DruidGuildMaster",(genericspecial_func) DruidGuildMaster },
	{ "DwarvenMiners",(genericspecial_func) DwarvenMiners },
#if EGO
	{ "EvilBlade",(genericspecial_func) EvilBlade },
	{ "GoodBlade",(genericspecial_func) GoodBlade },
	{ "NeutralBlade",(genericspecial_func) NeutralBlade },
#endif
	{ "EditMaster",(genericspecial_func)EditMaster},
	{ "Esattore",(genericspecial_func)Esattore},
	{ "ForceMobToAction",(genericspecial_func) ForceMobToAction },
	{ "FireBreather",(genericspecial_func) FireBreather },
	{ "HuntingMercenary",(genericspecial_func) HuntingMercenary },
	{ "Interact",(genericspecial_func) Interact },
	{ "Keftab",(genericspecial_func) Keftab },
	{ "LegionariV",(genericspecial_func) LegionariV },
	{ "LightningBreather",(genericspecial_func) LightningBreather },
	{ "Lizardman",(genericspecial_func) Lizardman },
	{ "MageGuildMaster",(genericspecial_func) MageGuildMaster },
	{ "MidgaardCityguard",(genericspecial_func) MidgaardCityguard },
	{ "MobBlockWay",(genericspecial_func) MobBlockWay },
	{ "ModHit",(genericspecial_func) ModHit },
	{ "MonkChallenger",(genericspecial_func) MonkChallenger },
	{ "MordGuard",(genericspecial_func) MordGuard },
	{ "MordGuildGuard",(genericspecial_func) MordGuildGuard },
	{ "NewThalosGuildGuard",(genericspecial_func) NewThalosGuildGuard },
	{ "NewThalosMayor",(genericspecial_func) NewThalosMayor },
	{ "NudgeNudge",(genericspecial_func) NudgeNudge },
	{ "Orso_Bianco",(genericspecial_func) Orso_Bianco },
	{ "PaladinGuildGuard",(genericspecial_func) PaladinGuildGuard },
	{ "PaladinGuildmaster",(genericspecial_func) PaladinGuildmaster },
	{ "PostMaster",(genericspecial_func) PostMaster },
	{ "PrimoAlbero",(genericspecial_func) PrimoAlbero },
	{ "PrisonGuard",(genericspecial_func) PrisonGuard },
	{ "PrydainGuard",(genericspecial_func) PrydainGuard },
	{ "PsiGuildmaster",(genericspecial_func) PsiGuildmaster },
	{ "Pungiglione",(genericspecial_func) Pungiglione },
	{ "Pungiglione_maggiore",(genericspecial_func) Pungiglione_maggiore },
	{ "RangerGuildmaster",(genericspecial_func) RangerGuildmaster },
	{ "RepairGuy",(genericspecial_func) RepairGuy },
	{ "Ringwraith",(genericspecial_func) Ringwraith },
	{ "RustMonster",(genericspecial_func) RustMonster },
	{ "Samah",(genericspecial_func) Samah },
	{ "Slavalis",(genericspecial_func) Slavalis },
	{ "SlotMachine",(genericspecial_func) SlotMachine },
	{ "spGeneric",(genericspecial_func) spGeneric },
	{ "SporeCloud",(genericspecial_func) SporeCloud },
	{ "ChangeDam",(genericspecial_func) ChangeDam },
	{ "LibroEroi",(genericspecial_func) LibroEroi },
	{ "MobBlockAlign",(genericspecial_func) MobBlockAlign },
	{ "LadroOfferte",(genericspecial_func) LadroOfferte },
	{ "Vampire_Summoner",(genericspecial_func) Vampire_Summoner },
    { "bambola",(genericspecial_func) bambola },
	{ "Nightmare",(genericspecial_func) Nightmare },
	{ "SputoVelenoso",(genericspecial_func) SputoVelenoso },
	{ "StatTeller",(genericspecial_func) StatTeller },
	{ "StatMaster",(genericspecial_func)StatMaster  },
	{ "StormGiant",(genericspecial_func) StormGiant },
	{ "SultanGuard",(genericspecial_func) SultanGuard },
	{ "ThiefGuildMaster",(genericspecial_func) ThiefGuildMaster },
	{ "thion_loader",(genericspecial_func) thion_loader },
    { "MobIdent",(genericspecial_func) MobIdent },
    { "AssignQuest",(genericspecial_func) AssignQuest },
    { "MobCaccia",(genericspecial_func) MobCaccia },
    { "MobSalvataggio",(genericspecial_func) MobSalvataggio },
    { "BossKill",(genericspecial_func) BossKill },
	{ "ThrowerMob",(genericspecial_func) ThrowerMob },
	{ "trap_obj",(genericspecial_func) trap_obj },
	{ "TreeThrowerMob",(genericspecial_func) TreeThrowerMob },
	{ "TrueDam",(genericspecial_func) TrueDam },
	{ "Tsuchigumo",(genericspecial_func) Tsuchigumo },
	{ "Tyrannosaurus_swallower",(genericspecial_func) Tyrannosaurus_swallower },
	{ "Tytan",(genericspecial_func) Tytan },
	{ "Valik",(genericspecial_func) Valik },
	{ "WarriorGuildMaster",(genericspecial_func) WarriorGuildMaster },
	{ "XpMaster",(genericspecial_func) XpMaster },
	{ "acid_monster",(genericspecial_func) acid_monster },
	{ "acid_monster/*",(genericspecial_func) acid_monster },
	{ "andy_wilcox",(genericspecial_func) andy_wilcox },
	{ "archer_instructor",(genericspecial_func) archer_instructor },
	{ "astral_portal",(genericspecial_func) astral_portal },
	{ "attack_rats",(genericspecial_func) attack_rats },
	{ "avatar_celestian",(genericspecial_func) avatar_celestian },
	{ "baby_bear",(genericspecial_func) baby_bear },
	{ "banana",(genericspecial_func) banana },
	{ "banshee",(genericspecial_func) banshee },
	{ "barbarian_guildmaster",(genericspecial_func) barbarian_guildmaster },
	{ "behir",(genericspecial_func) behir },
	{ "blink",(genericspecial_func) blink },
	{ "board",(genericspecial_func) board },
	{ "chess_game",(genericspecial_func) chess_game },
	{ "coldcaster",(genericspecial_func) coldcaster },
	{ "creceptionist",(genericspecial_func) creceptionist },
	{ "creeping_death",(genericspecial_func) creeping_death },
	{ "death_knight",(genericspecial_func) death_knight },
	{ "delivery_beast",(genericspecial_func) delivery_beast },
	{ "delivery_elf",(genericspecial_func) delivery_elf },
	{ "druid_protector",(genericspecial_func) druid_protector },
	{ "enter_obj",(genericspecial_func) enter_obj },
	{ "eric_johnson",(genericspecial_func) eric_johnson },
	{ "fido",(genericspecial_func) fido },
	{ "fighter_mage",(genericspecial_func) fighter_mage },
	{ "flame",(genericspecial_func) flame },
	{ "geyser",(genericspecial_func) geyser },
	{ "ghost",(genericspecial_func) ghost },
	{ "ghostsoldier",(genericspecial_func) ghostsoldier },
	{ "ghoul",(genericspecial_func) ghoul },
	{ "goblin_sentry",(genericspecial_func) goblin_sentry },
	{ "golgar",(genericspecial_func) golgar },
	{ "green_slime",(genericspecial_func) green_slime },
	{ "guardian",(genericspecial_func) guardian },
	{ "guild_guard",(genericspecial_func) guild_guard },
	{ "hit_sucker",(genericspecial_func) hit_sucker },
	{ "hunter",(genericspecial_func) hunter },
	{ "miner_teacher",(genericspecial_func) miner_teacher },
	{ "forge_teacher",(genericspecial_func) forge_teacher },
	{ "determine_teacher",(genericspecial_func) determine_teacher },
	{ "equilibrium_teacher",(genericspecial_func) equilibrium_teacher },
	{ "jabberwocky",(genericspecial_func) jabberwocky },
	{ "janitor",(genericspecial_func) janitor },
	{ "jive_box",(genericspecial_func) jive_box },
    { "key_one_use",(genericspecial_func) key_one_use },
	{ "jugglernaut",(genericspecial_func) jugglernaut },
	{ "keystone",(genericspecial_func) keystone },
	{ "lattimore",(genericspecial_func) lattimore },
	{ "lich_church",(genericspecial_func) lich_church },
	{ "lizardman_shaman",(genericspecial_func) lizardman_shaman },
	{ "loremaster",(genericspecial_func) loremaster },
	{ "mad_cyrus",(genericspecial_func) mad_cyrus },
	{ "mad_gertruda",(genericspecial_func) mad_gertruda },
	{ "mage_specialist_guildmaster",(genericspecial_func) mage_specialist_guildmaster },
	{ "mayor",(genericspecial_func) mayor },
	{ "medusa",(genericspecial_func) medusa },
	{ "monk_master",(genericspecial_func) monk_master },
	{ "Moribondo",(genericspecial_func) Moribondo },
	{ "msg_obj",(genericspecial_func) msg_obj },
	{ "ninja_master",(genericspecial_func) ninja_master },
	{ "nodrop",(genericspecial_func) nodrop },
	{ "paramedics",(genericspecial_func) paramedics },
	{ "portal",(genericspecial_func) portal },
	{ "puff",(genericspecial_func) puff },
	{ "ragno_intermittente",(genericspecial_func) ragno_intermittente },
	{ "Rakda",(genericspecial_func) Rakda },
	{ "raven_iron_golem",(genericspecial_func) raven_iron_golem },
	{ "real_fox",(genericspecial_func) real_fox },
	{ "real_rabbit",(genericspecial_func) real_rabbit },
	{ "receptionist",(genericspecial_func) receptionist },
	{ "regenerator",(genericspecial_func) regenerator },
	{ "replicant",(genericspecial_func) replicant },
	{ "sailor",(genericspecial_func) sailor },
	{ "scraps",(genericspecial_func) scraps },
	{ "shadow",(genericspecial_func) shadow },
	{ "shaman",(genericspecial_func) shaman },
	{ "sisyphus",(genericspecial_func) sisyphus },
	{ "snake",(genericspecial_func) snake },
	{ "snake_plus",(genericspecial_func) snake_plus },
	{ "snake_avt",(genericspecial_func) snake_avt },
	{ "snake_avt2",(genericspecial_func) snake_avt2 },
	{ "snake_guardian",(genericspecial_func) snake_guardian },
	{ "soap",(genericspecial_func) soap },
	{ "strahd_vampire",(genericspecial_func) strahd_vampire },
	{ "strahd_zombie",(genericspecial_func) strahd_zombie },
	{ "temple_labrynth_liar",(genericspecial_func) temple_labrynth_liar },
	{ "temple_labrynth_sentry",(genericspecial_func) temple_labrynth_sentry },
	{ "timnus",(genericspecial_func) timnus },
	{ "tormentor",(genericspecial_func) tormentor },
	{ "trapper",(genericspecial_func) trapper },
	{ "trogcook",(genericspecial_func) trogcook },
	{ "troguard",(genericspecial_func) troguard },
	{ "vampire",(genericspecial_func) vampire },
	{ "village_woman",(genericspecial_func) village_woman },
	{ "virgin_sac",(genericspecial_func) virgin_sac },
	{ "web_slinger",(genericspecial_func) web_slinger },
	{ "winger",(genericspecial_func) winger },
	{ "wraith",(genericspecial_func) wraith },
	{ "zone_obj",(genericspecial_func) zone_obj },
	{ "zombie_master",(genericspecial_func) zombie_master },
	{ "ItemGiven",(genericspecial_func) ItemGiven },  // SALVO 2006 Quest fisse
	{ "ItemPut",(genericspecial_func)ItemPut },  // SALVO 2006 Quest fisse
//  Quest Nilmys
    //  oggetti
    { "urna_nilmys", (genericspecial_func) urna_nilmys },
    //  mob
    { "Arkhat", (genericspecial_func) Arkhat },
    { "Atropal", (genericspecial_func) Atropal},
    { "Boris_Ivanhoe", (genericspecial_func) Boris_Ivanhoe },
    { "Garebeth", (genericspecial_func) Garebeth},
    { "Uguik_Aurum", (genericspecial_func) Uguik_Aurum },
    { "Umag_Ulbar", (genericspecial_func) Umag_Ulbar},
    { "stanislav_spirit", (genericspecial_func) stanislav_spirit },
//  fine Quest Nilmys
	{ "zFineprocedure", NULL },
};
} // namespace Alarmud

