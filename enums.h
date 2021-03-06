#pragma once
#pragma once
#include <cstdint>

enum class ClassEffect : bool {
	Negative = 0,
	Positive
};

enum class EffectsName : uint8_t {
	CureDisease = 0,
	CurePoison,
	DamageHealth,
	DamageMagicka,
	DamageMagickaRegen,
	DamageStamina,
	DamageStaminaRegen,
	Fear,
	Fortify,
	FortifyAlteration,
	FortifyBarter,
	FortifyBlock,
	FortifyCarryWeight,
	FortifyConjuration,
	FortifyDestruction,
	FortifyEnchanting,
	FortifyHealth,
	FortifyHeavyArmor,
	FortifyIllusion,
	FortifyLightArmor,
	FortifyLockpicking,
	FortifyMagicka,
	FortifyMarksman,
	FortifyOneHanded,
	FortifyPickpocket,
	FortifyRestoration,
	FortifySmithing,
	FortifySneak,
	FortifyStamina,
	FortifyTwoHanded,
	FortifyFrenzy,
	Frenzy,
	Invisibility,
	LingeringDamageHealth,
	LingeringDamageMagicka,
	LingeringDamageStamina,
	Paralysis,
	RavageHealth,
	RavageMagicka,
	RavageStamina,
	RegenerateHealth,
	RegenerateMagicka,
	RegenerateStamina,
	ResistFire,
	ResistFrost,
	ResistMagic,
	ResistPoison,
	ResistShock,
	RestoreHealth,
	RestoreMagicka,
	RestoreStamina,
	Slow,
	Waterbreathing,
	WeaknesstoFire,
	WeaknesstoFrost,
	WeaknesstoMagic,
	WeaknesstoPoison,
	WeaknesstoShock
};

enum class IngridientsName : uint8_t {
	AbeceanLongfin = 0,
	AncestorMothWing,
	AshCreepCluster,
	AshHopperJelly,
	AshenGrassPod,
	BearClaws,
	Bee,
	BeehiveHusk,
	BeritsAshes,
	BleedingCrown,
	Blisterwort,
	BlueButterflyWing,
	BlueDartwing,
	BlueMountainFlower,
	BoarTusk,
	BoneMeal,
	BriarHeart,
	BurntSprigganWood,
	ButterflyWing,
	CanisRoot,
	CharredSkeeverHide,
	ChaurusEggs,
	ChaurusHunterAntennae,
	ChickensEgg,
	CreepCluster,
	CrimsonNirnroot,
	CyrodilicSpadetail,
	DaedraHeart,
	Deathbell,
	DragonsTongue,
	DwarvenOil,
	Ectoplasm,
	ElvesEar,
	EmperorParasolMoss,
	EyeOfSabreCat,
	FalmerEar,
	FelsaadTernFeathers,
	FineCutVoidSalts,
	FireSalts,
	FlyAmanita,
	FrostMirriam,
	FrostSalts,
	Garlic,
	GiantLichen,
	GiantsToe,
	Gleamblossom,
	GlowDust,
	GlowingMushroom,
	GrassPod,
	HagravenClaw,
	HagravenFeathers,
	HangingMoss,
	HawkBeak,
	HawkFeathers,
	HawksEgg,
	Histcarp,
	Honeycomb,
	HumanFlesh,
	HumanHeart,
	IceWraithTeeth,
	ImpStool,
	JarrinRoot,
	JazbayGrapes,
	JuniperBerries,
	LargeAntlers,
	Lavender,
	LunaMothWing,
	MoonSugar,
	MoraTapinella,
	MudcrabChitin,
	NamirasRot,
	NetchJelly,
	Nightshade,
	Nirnroot,
	NordicBarnacle,
	OrangeDartwing,
	Pearl,
	PineThrushEgg,
	PoisonBloom,
	PowderedMammothTusk,
	PurpleMountainFlower,
	RedMountainFlower,
	RiverBetty,
	RockWarblerEgg,
	SabreCatTooth,
	SalmonRoe,
	SaltPile,
	ScalyPholiota,
	Scathecraw,
	SilversidePerch,
	SkeeverTail,
	SlaughterfishEgg,
	SlaughterfishScales,
	SmallAntlers,
	SmallPearl,
	Snowberries,
	SpawnAsh,
	SpiderEgg,
	SprigganSap,
	SwampFungalPod,
	Taproot,
	ThistleBranch,
	TorchbugThorax,
	TramaRoot,
	TrollFat,
	TundraCotton,
	VampireDust,
	VoidSalts,
	Wheat,
	WhiteCap,
	WispWrappings,
	YellowMountainFlower
};