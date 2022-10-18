#pragma once
#include <string>
#include <map>

namespace items {
	enum rarity { HEIRLOOM, LEGENDARY, EPIC, RARE, COMMON };

	struct c_prop {
		std::string item_name;
		rarity m_rarity;
	};

	std::map<uint32_t, c_prop> item_list = {
		{ 1, { ("Kraber"), rarity::HEIRLOOM }},
		{ 2, { ("Mastiff"), rarity::COMMON }},
		{ 6, { ("Mastiff Gold"), rarity::LEGENDARY }},
		{ 7, { ("LStar"), rarity::COMMON }},
		{ 11, { ("LStar Gold"), rarity::LEGENDARY }},
		{ 12, { ("Havoc"), rarity::COMMON }},
		{ 16, { ("Havoc Gold"), rarity::LEGENDARY }},
		{ 17, { ("Devotion"), rarity::COMMON }},
		{ 21, { ("Devotion Gold"), rarity::LEGENDARY }},
		{ 22, { ("Triple Take"), rarity::HEIRLOOM }},
		{ 23, { ("Flatline"), rarity::COMMON }},
		{ 27, { ("Flatline Gold"), rarity::LEGENDARY }},
		{ 28, { ("Hemlock"), rarity::COMMON }},
		{ 32, { ("Hemlock Gold"), rarity::LEGENDARY }},
		{ 33, { ("G7 Scout"), rarity::COMMON }},
		{ 37, { ("G7 Scout Gold"), rarity::LEGENDARY }},
		{ 38, { ("Alternator"), rarity::HEIRLOOM }},
		{ 39, { ("R99"), rarity::COMMON }},
		{ 43, { ("R99 Gold"), rarity::LEGENDARY }},
		{ 44, { ("Prowler"), rarity::COMMON }},
		{ 48, { ("Prowler Gold"), rarity::LEGENDARY }},
		{ 49, { ("Volt"), rarity::COMMON }},
		{ 53, { ("Volt Gold"), rarity::LEGENDARY }},
		{ 54, { ("Longbow"), rarity::COMMON }},
		{ 58, { ("Longbow Gold"), rarity::LEGENDARY }},
		{ 59, { ("Charge Rifle"), rarity::COMMON }},
		{ 63, { ("Charge Rifle Gold"), rarity::LEGENDARY }},
		{ 64, { ("Spitfire"), rarity::HEIRLOOM }},
		{ 65, { ("R301"), rarity::COMMON }},
		{ 69, { ("R301 Gold"), rarity::LEGENDARY }},
		{ 70, { ("Eva-8 Auto"), rarity::COMMON }},
		{ 74, { ("Eva-8 Auto Gold"), rarity::LEGENDARY }},
		{ 75, { ("Peacekeeper"), rarity::COMMON }},
		{ 79, { ("Peacekeeper Gold"), rarity::LEGENDARY }},
		{ 80, { ("Mozambique"), rarity::COMMON }},
		{ 84, { ("Mozambique Gold"), rarity::LEGENDARY }},
		{ 85, { ("Wingman"), rarity::COMMON }},
		{ 89, { ("Wingman Gold"), rarity::LEGENDARY }},
		{ 90, { ("P2020"), rarity::COMMON }},
		{ 94, { ("P2020 Gold"), rarity::LEGENDARY }},
		{ 95, { ("RE45"), rarity::COMMON }},
		{ 99,  {("RE45 Gold"), rarity::LEGENDARY }},
		{ 100, { ("Sentinel"), rarity::COMMON }},
		{ 104, { ("Sentinel Gold"), rarity::LEGENDARY }},
		{ 105, { ("Bocek Bow"), rarity::COMMON }},
		{ 109, { ("Bocek Bow Gold"), rarity::LEGENDARY }},
		{ 110, { ("30 30 Repeater"), rarity::COMMON }},
		{ 114, { ("30 30 Repeater Gold"), rarity::LEGENDARY }},

		{ 115, { ("Light Ammo"), rarity::COMMON }},
		{ 116, { ("Energy Ammo"), rarity::COMMON }},
		{ 117, { ("Shotgun Ammo"), rarity::COMMON }},
		{ 118, { ("Heavy Ammo"), rarity::COMMON }},
		{ 119, { ("Sniper Ammo"), rarity::COMMON }},
		{ 120, { ("Arrow"), rarity::COMMON }},

		{ 121, { ("Rampage"), rarity::COMMON }},
		{ 125, { ("Rampage Gold"), rarity::LEGENDARY }},

		{ 151, { ("Ultimate Accelerant"), rarity::RARE }},
		{ 152, { ("Pheonix Kit"), rarity::EPIC }},
		{ 153, { ("Med Kit"), rarity::RARE }},
		{ 154, { ("Syringe"), rarity::COMMON }},
		{ 155, { ("Shield Battery"), rarity::RARE }},
		{ 156, { ("Shield Cell"), rarity::COMMON }},

		{ 157, { ("Helmet"), rarity::COMMON }},
		{ 158, { ("Helmet"), rarity::RARE }},
		{ 159, { ("Helmet"), rarity::EPIC }},
		{ 160, { ("Helmet"), rarity::LEGENDARY }},

		{ 161, { ("Body Armor"), rarity::COMMON }},
		{ 162, { ("Body Armor"), rarity::RARE }},
		{ 163, { ("Body Armor"), rarity::EPIC }},
		{ 164, { ("Body Armor"), rarity::LEGENDARY }},
		{ 165, { ("Body Armor"), rarity::HEIRLOOM }},

		{ 166, { ("Evo Body Armor"), rarity::COMMON }},
		{ 167, { ("Evo Body Armor"), rarity::RARE }},
		{ 168, { ("Evo Body Armor"), rarity::EPIC }},
		{ 169, { ("Evo Body Armor"), rarity::HEIRLOOM }},

		{ 170, { ("Heat Shield"), rarity::HEIRLOOM }},

		{ 171, { ("Knockdown Shield"), rarity::COMMON }},
		{ 172, { ("Knockdown Shield"), rarity::RARE }},
		{ 173, { ("Knockdown Shield"), rarity::EPIC }},
		{ 174, { ("Knockdown Shield"), rarity::LEGENDARY }},

		{ 175, { ("Backpack"), rarity::COMMON }},
		{ 176, { ("Backpack"), rarity::RARE }},
		{ 177, { ("Backpack"), rarity::EPIC }},
		{ 178, { ("Backpack"), rarity::LEGENDARY }},

		{ 179, { ("Thermite Grenade"), rarity::COMMON }},
		{ 180, { ("Frag Grenade"), rarity::COMMON }},
		{ 181, { ("Arc Star"), rarity::COMMON }},

		{ 182, { ("1x HCOG 'Classic'"), rarity::COMMON }},
		{ 183, { ("2x HCOG 'Bruiser'"), rarity::RARE }},
		{ 184, { ("1x Holo"), rarity::COMMON }},
		{ 185, { ("1x-2x Variable Holo"), rarity::RARE }},
		{ 186, { ("1x Digital Threat"), rarity::LEGENDARY }},
		{ 187, { ("3x HCOG 'Ranger'"), rarity::EPIC }},
		{ 188, { ("2x-4x Variable AOG"), rarity::EPIC }},
		{ 189, { ("6x Sniper"), rarity::RARE }},
		{ 190, { ("4x-8x Variable Sniper"), rarity::EPIC }},
		{ 191, { ("4x-10x Digital Sniper Threat"), rarity::LEGENDARY }},

		{ 192, { ("Barrel Stabilizer"), rarity::COMMON }},
		{ 193, { ("Barrel Stabilizer"), rarity::RARE }},
		{ 194, { ("Barrel Stabilizer"), rarity::EPIC }},
		{ 195, { ("Barrel Stabilizer"), rarity::LEGENDARY }}, // Unobtainable?

		{ 196, { ("Light Magazine"), rarity::COMMON }},
		{ 197, { ("Light Magazine"), rarity::RARE }},
		{ 198, { ("Light Magazine"), rarity::EPIC }},
		{ 199, { ("Light Magazine"), rarity::LEGENDARY }},

		{ 200, { ("Heavy Magazine"), rarity::COMMON }},
		{ 201, { ("Heavy Magazine"), rarity::RARE }},
		{ 202, { ("Heavy Magazine"), rarity::EPIC }},
		{ 203, { ("Heavy Magazine"), rarity::LEGENDARY }},

		{ 204, { ("Energy Magazine"), rarity::COMMON }},
		{ 205, { ("Energy Magazine"), rarity::RARE }},
		{ 206, { ("Energy Magazine"), rarity::EPIC }},
		{ 207, { ("Energy Magazine"), rarity::LEGENDARY }},

		{ 208, { ("Sniper Magazine"), rarity::COMMON }},
		{ 209, { ("Sniper Magazine"), rarity::RARE }},
		{ 210, { ("Sniper Magazine"), rarity::EPIC }},
		{ 211, { ("Sniper Magazine"), rarity::LEGENDARY }},

		{ 212, { ("Shotgun Bolt"), rarity::COMMON }},
		{ 213, { ("Shotgun Bolt"), rarity::RARE }},
		{ 214, { ("Shotgun Bolt"), rarity::EPIC }},

		{ 215, { ("Standard Stock"), rarity::COMMON }},
		{ 216, { ("Standard Stock"), rarity::RARE }},
		{ 217, { ("Standard Stock"), rarity::EPIC }},

		{ 218, { ("Sniper Stock"), rarity::COMMON }},
		{ 219, { ("Sniper Stock"), rarity::RARE }},
		{ 220, { ("Sniper Stock"), rarity::EPIC }},

		{ 221, { ("Turbocharger"), rarity::LEGENDARY }},
		{ 222, { ("Skull Piercer"), rarity::LEGENDARY }},
		{ 223, { ("Hammer Point"), rarity::EPIC }},
		{ 224, { ("Anvil Receiver"), rarity::LEGENDARY }},
		{ 225, { ("Graffiti Mod"), rarity::COMMON }},
		{ 226, { ("Paintball 1"), rarity::HEIRLOOM }}, // TODO: Find this rarity
		{ 227, { ("Paintball 2"), rarity::HEIRLOOM }}, // TODO: Find this rarity
		{ 228, { ("Deadeye's Tempo"), rarity::EPIC }},
		{ 229, { ("Quickdraw Holster"), rarity::EPIC }}, // Might be 229
		{ 230, { ("Shatter Caps"), rarity::EPIC }},
		{ 231, { ("Boosted Loader"), rarity::LEGENDARY }},
		{ 232, { ("Mobile Respawn Beacon"), rarity::RARE }},
		{ 233, { ("Vault Key"), rarity::HEIRLOOM }},
		{ 234, { ("Steel Cut"), rarity::HEIRLOOM }}, // Might be overwritten every season/every time there's a new charm.
		{ 235, { ("Treasure Pack"), rarity::HEIRLOOM }},
		{ 236, { ("Survival Doubler"), rarity::HEIRLOOM }}, // TODO: Find this rarity
		{ 237, { ("Survival Quadrupler"), rarity::HEIRLOOM }}, // TODO: Find this rarity
		{ 238, { ("Heat Shield"), rarity::RARE }},
		{ 239, { ("Mobile Respawn Beacon 2"), rarity::RARE }},
		{ 240, { ("MRVN Arm"), rarity::EPIC }},
		{ 241, { ("Vault Key"), rarity::HEIRLOOM }}
	};
}