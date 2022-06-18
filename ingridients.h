#pragma once
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

#include "enums.h"

using namespace std;

using Effect = pair<ClassEffect, EffectsName>;

struct Ingridient;
struct IngridientBag;
struct Mix;
class IngridientVector;
class IngridientBags;
class Mixer;
class Combinator;

struct Ingridient {
	Effect effect[4];
	Ingridient(Effect first, Effect second, Effect third, Effect fourth) {
		effect[0] = first;
		effect[1] = second;
		effect[2] = third;
		effect[3] = fourth;
	}
	bool operator== (const Ingridient& rv) {
	        for (uint8_t i = 0; i < 4; i++) {
		      if (this->effect[0].second != rv.effect[0].second) {
			    return false;
		      }
	        }
	        return true;
	}
};
struct IngridientBag {
        Ingridient ingridient;
        string name;
        uint64_t count = 0;
        IngridientsName ingId;
        bool operator== (const IngridientBag& rv) {
	      return this->ingId == rv.ingId;
        }
};
struct Mix {
        vector<IngridientBag> parts;
        uint8_t points;
public:
        Mix() {
	      parts.reserve(3);
	      points = 0;
        }
        uint64_t min();
        
        bool operator== (const Mix& rv) {
	      if (this->points == rv.points && this->parts.size() == rv.parts.size()) {
		    for (uint8_t i = 0; i < this->parts.size(); i++) {
			  if (this->parts[i].ingId != rv.parts[i].ingId) {
				return false;
			  }
		    }
		    return true;
	      }
	      else {
		    return false;
	      }
        }
};

class IngridientVector : public vector<Ingridient> {
public:
	 IngridientVector() {
	      reserve(120);
	      push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFrost),
			make_pair(ClassEffect::Positive, EffectsName::FortifySneak),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoPoison),
			make_pair(ClassEffect::Positive, EffectsName::FortifyRestoration)
			)
		); //AbeceanLongfi
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyConjuration),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen),
			make_pair(ClassEffect::Positive, EffectsName::FortifyEnchanting)
			)
		);//AncestorMothWing
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::Invisibility),
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Positive, EffectsName::FortifyDestruction)
			)
		);//AshCreepCluster
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLightArmor),
			make_pair(ClassEffect::Positive, EffectsName::ResistShock),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFrost)
			)
		);//AshHopperJelly
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoShock),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLockpicking),
			make_pair(ClassEffect::Positive, EffectsName::FortifySneak)
			)
		);//AshenGrassPod
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyOneHanded),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen)
			)
		);//BearClaws
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Negative, EffectsName::RavageStamina),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateStamina),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoShock)
			)
		);//Bee
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistPoison),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLightArmor),
			make_pair(ClassEffect::Positive, EffectsName::FortifySneak),
			make_pair(ClassEffect::Positive, EffectsName::FortifyDestruction)
			)
		);//BeehiveHusk
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Positive, EffectsName::FortifyConjuration),
			make_pair(ClassEffect::Negative, EffectsName::RavageStamina)
			)
		);//BeritsAshes
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFire),
			make_pair(ClassEffect::Positive, EffectsName::FortifyBlock),
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoPoison)
			)
		);//BleedingCrown  
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifySmithing),
			make_pair(ClassEffect::Negative, EffectsName::Frenzy)
			)
		);//Blisterwort
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyConjuration),
			make_pair(ClassEffect::Positive, EffectsName::FortifyEnchanting),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen)
			)
		);//BlueButterflyWing
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth),
			make_pair(ClassEffect::Positive, EffectsName::ResistShock),
			make_pair(ClassEffect::Positive, EffectsName::FortifyPickpocket),
			make_pair(ClassEffect::Negative, EffectsName::Fear)
			)
		);//BlueDartwing
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyConjuration),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen)
			)
		);//BlueMountainFlower
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyBlock),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHealth),
			make_pair(ClassEffect::Negative, EffectsName::Frenzy)
			)
		);//BoarTusk	 	
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Positive, EffectsName::FortifyConjuration),
			make_pair(ClassEffect::Negative, EffectsName::RavageStamina)
			)
		);//BoneMeal
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyBlock),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMagicka),
			make_pair(ClassEffect::Negative, EffectsName::Paralysis)
			)
		);//BriarHeart	 	
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFire),
			make_pair(ClassEffect::Positive, EffectsName::FortifyAlteration),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen),
			make_pair(ClassEffect::Negative, EffectsName::Slow)
			)
		);//BurntSprigganWood 	 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyBarter),
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageStamina),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka)
			)
		);//ButterflyWing 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyOneHanded),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMarksman),
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Negative, EffectsName::Paralysis)
			)
		);//CanisRoot 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::CureDisease),
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::ResistPoison),
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth)
			)
		);//CharredSkeeverHide 
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoPoison), 
			make_pair(ClassEffect::Positive, EffectsName::FortifyStamina),   
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),    
			make_pair(ClassEffect::Positive, EffectsName::Invisibility)	   
			)
		);//ChaurusEggs  	
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyConjuration),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen),
			make_pair(ClassEffect::Positive, EffectsName::FortifyEnchanting)
			)
		);//ChaurusHunterAntennae 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::Waterbreathing)
			)
		);//ChickensEgg  
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Negative, EffectsName::DamageStaminaRegen),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoMagic),
			make_pair(ClassEffect::Positive, EffectsName::FortifyCarryWeight)
			)
		);//CreepCluster 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::Invisibility),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic)
			)
		);//CrimsonNirnroot  
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyRestoration),
			make_pair(ClassEffect::Negative, EffectsName::Fear),
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Negative, EffectsName::RavageHealth)
			)
		);//CyrodilicSpadetail  
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageStaminaRegen),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),
			make_pair(ClassEffect::Negative, EffectsName::Fear)
			)
		);//DaedraHeart 
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoPoison),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::RavageStamina),
			make_pair(ClassEffect::Negative, EffectsName::Slow)
			)
		);//Deathbell 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Positive, EffectsName::FortifyBarter),
			make_pair(ClassEffect::Positive, EffectsName::FortifyIllusion),
			make_pair(ClassEffect::Positive, EffectsName::FortifyTwoHanded)
			)
		);//DragonsTongue 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyIllusion),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoMagic)
			)
		);//DwarvenOil 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyDestruction),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMagicka),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth)
			)
		);//Ectoplasm 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMarksman),
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFrost)
			)
		);//ElvesEar 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyTwoHanded),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth)
			)
		);//EmperorParasolMoss 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),
			make_pair(ClassEffect::Negative, EffectsName::RavageHealth)
			)
		);//EyeOfSabreCat 	
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyLockpicking),
			make_pair(ClassEffect::Positive, EffectsName::ResistPoison),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::Frenzy)
			)
		);//FalmerEar 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLightArmor),
			make_pair(ClassEffect::Positive, EffectsName::CureDisease),
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic)
			)
		);//FelsaadTernFeathers 
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoShock),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMagicka),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic)
			)
		);//FineCutVoidSalts 
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFrost),
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka)
			)
		);//FireSalts 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyTwoHanded),
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Negative, EffectsName::Frenzy),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateStamina)
			)
		);//FlyAmanita 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistFrost),
			make_pair(ClassEffect::Positive, EffectsName::FortifySneak),
			make_pair(ClassEffect::Negative, EffectsName::RavageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::DamageStaminaRegen)
			)
		);//FrostMirriam 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistFrost),
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFire),
			make_pair(ClassEffect::Positive, EffectsName::FortifyConjuration)
			)
		);//FrostSalts 
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistPoison),
			make_pair(ClassEffect::Positive, EffectsName::FortifyStamina),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateHealth)
			)
		);//Garlic
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoShock),
			make_pair(ClassEffect::Negative, EffectsName::RavageHealth),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoPoison),
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka)
			)
		);//GiantLichen
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageStaminaRegen),
			make_pair(ClassEffect::Positive, EffectsName::FortifyCarryWeight)
			)
		);//GiantsToe
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::Paralysis),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateHealth),
			make_pair(ClassEffect::Negative, EffectsName::Fear),
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic)
			)
		);//Gleamblossom
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyDestruction),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen),
			make_pair(ClassEffect::Positive, EffectsName::ResistShock)
			)
		);//GlowDust
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyDestruction),
			make_pair(ClassEffect::Positive, EffectsName::FortifySmithing),
			make_pair(ClassEffect::Positive, EffectsName::ResistShock)
			)
		);//GlowingMushroom
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::RavageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::ResistPoison),
			make_pair(ClassEffect::Positive, EffectsName::FortifyAlteration),
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka)
			)
		);//GrassPod
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic),
			make_pair(ClassEffect::Positive, EffectsName::FortifyEnchanting),
			make_pair(ClassEffect::Positive, EffectsName::FortifyBarter)
			)
		);//HagravenClaw
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyConjuration),
			make_pair(ClassEffect::Negative, EffectsName::Frenzy),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoShock)
			)
		);//HagravenFeathers
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen),
			make_pair(ClassEffect::Positive, EffectsName::FortifyOneHanded)
			)
		);//HangingMoss
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistShock),
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyCarryWeight),
			make_pair(ClassEffect::Positive, EffectsName::ResistFrost)
			)
		);//HawkBeak
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::CureDisease),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLightArmor),
			make_pair(ClassEffect::Positive, EffectsName::FortifyOneHanded),
			make_pair(ClassEffect::Positive, EffectsName::FortifySneak)
			)
		);//HawkFeathers
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen),
			make_pair(ClassEffect::Positive, EffectsName::Waterbreathing),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageStamina)
			)
		);//HawksEgg
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMagicka),
			make_pair(ClassEffect::Positive, EffectsName::Waterbreathing),
			make_pair(ClassEffect::Negative, EffectsName::DamageStaminaRegen)
			)
		);//Histcarp
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyBlock),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLightArmor),
			make_pair(ClassEffect::Negative, EffectsName::RavageStamina)
			)
		);//Honeycomb
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifySneak),
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Negative, EffectsName::Paralysis),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth)
			)
		);//HumanFlesh
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::Frenzy),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka)
			)
		);//HumanHeart
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFrost),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHeavyArmor),
			make_pair(ClassEffect::Positive, EffectsName::Invisibility),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFire)
			)
		);//IceWraithTeeth
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::Paralysis),
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageHealth)
			)
		);//ImpStool
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen)
			)
		);//JarrinRoot
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoMagic),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateMagicka),
			make_pair(ClassEffect::Negative, EffectsName::RavageHealth)
			)
		);//JazbayGrapes
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFire),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMarksman),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageStaminaRegen)
			)
		);//JuniperBerries
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyStamina),
			make_pair(ClassEffect::Negative, EffectsName::DamageStaminaRegen),
			make_pair(ClassEffect::Negative, EffectsName::Slow)
			)
		);//LargeAntlers
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyStamina),
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic),
			make_pair(ClassEffect::Negative, EffectsName::RavageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyConjuration)
			)
		);//Lavender
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::Invisibility),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLightArmor)
			)
		);//LunaMothWing
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RegenerateMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFire),
			make_pair(ClassEffect::Positive, EffectsName::ResistFrost)
			)
		);//MoonSugar
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateStamina),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyIllusion)
			)
		);//MoraTapinella
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::CureDisease),
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Positive, EffectsName::ResistPoison)
			)
		);//MudcrabChitin
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLockpicking),
			make_pair(ClassEffect::Negative, EffectsName::Fear),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateHealth)
			)
		);//NamirasRot
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::Paralysis),
			make_pair(ClassEffect::Positive, EffectsName::FortifyCarryWeight),
			make_pair(ClassEffect::Negative, EffectsName::Fear),
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina)
			)
		);//NetchJelly
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageStamina),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen),
			make_pair(ClassEffect::Positive, EffectsName::FortifyDestruction)
			)
		);//Nightshade
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic),
			make_pair(ClassEffect::Positive, EffectsName::Invisibility)
			)
		);//Nirnroot
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyPickpocket),
			make_pair(ClassEffect::Positive, EffectsName::Waterbreathing),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateHealth)
			)
		);//NordicBarnacle
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Negative, EffectsName::RavageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyPickpocket),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageHealth)
			)
		);//OrangeDartwing
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyBlock),
			make_pair(ClassEffect::Positive, EffectsName::ResistShock)
			)
		);//Pearl
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLockpicking),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoPoison),
			make_pair(ClassEffect::Positive, EffectsName::ResistShock)
			)
		);//PineThrushEgg
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyCarryWeight),
			make_pair(ClassEffect::Negative, EffectsName::Fear),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::Slow)
			)
		);//PoisonBloom
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifySneak),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFire),
			make_pair(ClassEffect::Negative, EffectsName::Fear)
			)
		);//PowderedMammothTusk
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifySneak),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageMagicka),
			make_pair(ClassEffect::Negative, EffectsName::ResistFrost)
			)
		);//PurpleMountainFlower
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMagicka),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::RavageMagicka)
			)
		);//RedMountainFlower
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyCarryWeight),
			make_pair(ClassEffect::Positive, EffectsName::FortifyAlteration),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::Slow)
			)
		);//RiverBetty
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyOneHanded),
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoMagic)
			)
		);//RockWarblerEgg
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHeavyArmor),
			make_pair(ClassEffect::Positive, EffectsName::FortifySmithing),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoPoison)
			)
		);//SabreCatTooth
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::Waterbreathing),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateMagicka)
			)
		);//SalmonRoe
		push_back(Ingridient(
		          make_pair(ClassEffect::Negative, EffectsName::WeaknesstoMagic),
		          make_pair(ClassEffect::Positive, EffectsName::FortifyRestoration),
		          make_pair(ClassEffect::Negative, EffectsName::Slow),
		          make_pair(ClassEffect::Positive, EffectsName::RegenerateMagicka)
			)
		);//SaltPile
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoMagic),
			make_pair(ClassEffect::Positive, EffectsName::FortifyIllusion),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyCarryWeight)
			)
		);//ScalyPholiota
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::RavageHealth),
			make_pair(ClassEffect::Negative, EffectsName::RavageStamina),
			make_pair(ClassEffect::Negative, EffectsName::RavageMagicka),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageHealth)
			)
		);//Scathecraw
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Negative, EffectsName::DamageStaminaRegen),
			make_pair(ClassEffect::Negative, EffectsName::RavageHealth),
			make_pair(ClassEffect::Positive, EffectsName::ResistFrost)
			)
		);//SilversidePerch
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageStaminaRegen),
			make_pair(ClassEffect::Negative, EffectsName::RavageHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLightArmor)
			)
		);//SkeeverTail
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistPoison),
			make_pair(ClassEffect::Positive, EffectsName::FortifyPickpocket),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyStamina)
			)
		);//SlaughterfishEgg
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistFrost),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHeavyArmor),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyBlock)
			)
		);//SlaughterfishScales
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyRestoration),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageStamina),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoPoison),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth)
			)
		);//SmallAntlers
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyOneHanded),
			make_pair(ClassEffect::Positive, EffectsName::FortifyRestoration),
			make_pair(ClassEffect::Positive, EffectsName::ResistFrost)
			)
		);//SmallPearl
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Positive, EffectsName::FortifyEnchanting),
			make_pair(ClassEffect::Positive, EffectsName::ResistFrost),
			make_pair(ClassEffect::Positive, EffectsName::ResistShock)
			)
		);//Snowberries
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::RavageStamina),
			make_pair(ClassEffect::Positive, EffectsName::ResistFire),
			make_pair(ClassEffect::Positive, EffectsName::FortifyEnchanting),
			make_pair(ClassEffect::Negative, EffectsName::RavageMagicka)
			)
		);//SpawnAsh
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyLockpicking),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMarksman),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen)
			)
		);//SpiderEgg
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::DamageMagickaRegen),
			make_pair(ClassEffect::Positive, EffectsName::FortifyEnchanting),
			make_pair(ClassEffect::Positive, EffectsName::FortifySmithing),
			make_pair(ClassEffect::Positive, EffectsName::FortifyAlteration)
			)
		);//SprigganSap
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistShock),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageMagicka),
			make_pair(ClassEffect::Negative, EffectsName::Paralysis),
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth)
			)
		);//SwampFungalPod
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyIllusion),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoMagic),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka)
			)
		);//Taproot
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistFrost),
			make_pair(ClassEffect::Negative, EffectsName::RavageStamina),
			make_pair(ClassEffect::Positive, EffectsName::ResistPoison),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHeavyArmor)
			)
		);//ThistleBranch
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageMagicka),
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoMagic),
			make_pair(ClassEffect::Positive, EffectsName::FortifyStamina)
			)
		);//TorchbugThorax
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoShock),
			make_pair(ClassEffect::Negative, EffectsName::Slow),
			make_pair(ClassEffect::Negative, EffectsName::DamageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyCarryWeight)
			)
		);//TramaRoot
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistPoison),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Negative, EffectsName::Frenzy),
			make_pair(ClassEffect::Positive, EffectsName::FortifyTwoHanded)
			)
		);//TrollFat
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic),
			make_pair(ClassEffect::Positive, EffectsName::FortifyBarter),
			make_pair(ClassEffect::Positive, EffectsName::FortifyBlock),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMagicka)
			)
		);//TundraCotton
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::Invisibility),
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RegenerateHealth),
			make_pair(ClassEffect::Positive, EffectsName::CureDisease)
			)
		);//VampireDust
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoShock),
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic),
			make_pair(ClassEffect::Negative, EffectsName::DamageHealth),
			make_pair(ClassEffect::Positive, EffectsName::FortifyMagicka)
			)
		);//VoidSalts
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::LingeringDamageMagicka),
			make_pair(ClassEffect::Negative, EffectsName::DamageStaminaRegen),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHealth),
			make_pair(ClassEffect::Positive, EffectsName::RestoreHealth)
			)
		);//Wheat
		push_back(Ingridient(
			make_pair(ClassEffect::Negative, EffectsName::WeaknesstoFrost),
			make_pair(ClassEffect::Negative, EffectsName::RavageMagicka),
			make_pair(ClassEffect::Positive, EffectsName::RestoreMagicka),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHeavyArmor)
			)
		);//WhiteCap
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::FortifyCarryWeight),
			make_pair(ClassEffect::Positive, EffectsName::ResistMagic),
			make_pair(ClassEffect::Positive, EffectsName::RestoreStamina),
			make_pair(ClassEffect::Positive, EffectsName::FortifyDestruction)
			)
		);//WispWrappings
		push_back(Ingridient(
			make_pair(ClassEffect::Positive, EffectsName::ResistPoison),
			make_pair(ClassEffect::Positive, EffectsName::FortifyRestoration),
			make_pair(ClassEffect::Positive, EffectsName::FortifyHealth),
			make_pair(ClassEffect::Negative, EffectsName::DamageStaminaRegen)
			)
		);//YellowMountainFlower
	}	 	 	
};

class IngridientBags {
        vector<IngridientBag> collection;
public:
        void fill(string filePath);
        
        friend Combinator;
};

class Combinator {
        unordered_map<string, uint64_t> combination;
        array<vector<Mix>, 6> mix_creator(IngridientBags bag);
public:
        Combinator(IngridientBags bag);
        void show();
};