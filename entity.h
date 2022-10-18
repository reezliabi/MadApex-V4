#pragma once
#include "driver.h"
#include "offsets.h"
#include "skCrypt.h"
#include "ImGui/imgui.h"

uintptr_t glocalplayer;
int realkey;
int keystatus;

struct GlowMode
{
	int8_t GeneralGlowMode, BorderGlowMode, BorderSize, TransparentLevel;
};
struct CGlobalVars {
	/*0x00*/double realtime;
	/*0x08*/int32_t framecount;
	/*0x0c*/float absoluteframetime;
	/*0x10*/float curtime;
	/*0x14*/float curtime2;
	/*0x18*/float curtime3;
	/*0x1c*/float curtime4;
	/*0x20*/float frametime;
	/*0x24*/float curtime5;
	/*0x28*/float curtime6;
	/*0x2c*/float zero;
	/*0x30*/float frametime2;
	/*0x34*/int32_t maxClients;
	/*0x38*/int32_t unk38;
	/*0x3c*/int32_t unk3C;
	/*0x40*/int32_t tickcount;
	/*0x44*/float interval_per_tick;
	/*0x48*/float interpolation_amount;
	// There's more stuff after this but I don't know and I don't care
};
DWORD64 GetEntityById(int Ent, DWORD64 Base)
{
	DWORD64 EntityList = Base + CL_ENTITYLIST;
	DWORD64 BaseEntity = driver::read<DWORD64>(EntityList);
	if (!BaseEntity)
		return NULL;
	return driver::read<DWORD64>(EntityList + (Ent << 5));
}
bool IsTeam(uintptr_t localplayer, DWORD64 entity)
{
	int a = driver::read<int>(localplayer + M_ITEAMNUM);
	int b = driver::read<int>(entity + M_ITEAMNUM);
	if (a == b)
		return true;

	return false;
}
DWORD64 GetWeapon(DWORD64 entity)
{
	DWORD64 WeaponHandle = driver::read<DWORD64>(entity + M_LASTESTPRIMARYWINDOWS);
	WeaponHandle &= 0xffff;
	return driver::read<DWORD64>(driver::g_base + CL_ENTITYLIST + (WeaponHandle << 5));
}
float LastVisTime(uintptr_t entity)
{
	return driver::read<float>(entity + LASTVISIBLETIME);
}
float oVisTime[100];
bool IsVisible(uintptr_t entity, int i) {
	const auto VisCheck = LastVisTime(entity);
	const auto IsVis = VisCheck > oVisTime[i] || VisCheck < 0.f && oVisTime[i] > 0.f;
	oVisTime[i] = VisCheck;
	return IsVis;
}
bool IsAlive(uintptr_t player) {
	return driver::read<int>(player + LIFESTATE) == 0 && driver::read<int>(player + BLEEDOUTSTATE) == 0;
}
inline bool IsDummy(uintptr_t ent)
{
	uint64_t team = driver::read<uint64_t>(ent + M_ITEAMNUM);
	return (team == 97);
}
int isKnocked(uintptr_t entity) {
	return driver::read<int>(entity + BLEEDOUTSTATE);
}
int iTeam(uintptr_t entity) {
	return driver::read<int>(entity + M_ITEAMNUM);
}
int get_item_id(uintptr_t entity) {
	return driver::read<int>(entity + ITEM_ID);
}
bool GetKey(int key)
{
	realkey = key;
	return true;
}
void ChangeKey(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				aimkey = i;
				keystatus = 0;
				return;
			}
		}
	}
}
//static const char* keyNames[] =
//{
//	"",
//	"Left Mouse",
//	"Right Mouse",
//	"Cancel",
//	"Middle Mouse",
//	"Mouse 5",
//	"Mouse 4",
//	"",
//	"Backspace",
//	"Tab",
//	"",
//	"",
//	"Clear",
//	"Enter",
//	"",
//	"",
//	"Shift",
//	"Control",
//	"Alt",
//	"Pause",
//	"Caps",
//	"",
//	"",
//	"",
//	"",
//	"",
//	"",
//	"Escape",
//	"",
//	"",
//	"",
//	"",
//	"Space",
//	"Page Up",
//	"Page Down",
//	"End",
//	"Home",
//	"Left",
//	"Up",
//	"Right",
//	"Down",
//	"",
//	"",
//	"",
//	"Print",
//	"Insert",
//	"Delete",
//	"",
//	"0",
//	"1",
//	"2",
//	"3",
//	"4",
//	"5",
//	"6",
//	"7",
//	"8",
//	"9",
//	"",
//	"",
//	"",
//	"",
//	"",
//	"",
//	"",
//	"A",
//	"B",
//	"C",
//	"D",
//	"E",
//	"F",
//	"G",
//	"H",
//	"I",
//	"J",
//	"K",
//	"L",
//	"M",
//	"N",
//	"O",
//	"P",
//	"Q",
//	"R",
//	"S",
//	"T",
//	"U",
//	"V",
//	"W",
//	"X",
//	"Y",
//	"Z",
//	"",
//	"",
//	"",
//	"",
//	"",
//	"Numpad 0",
//	"Numpad 1",
//	"Numpad 2",
//	"Numpad 3",
//	"Numpad 4",
//	"Numpad 5",
//	"Numpad 6",
//	"Numpad 7",
//	"Numpad 8",
//	"Numpad 9",
//	"Multiply",
//	"Add",
//	"",
//	"Subtract",
//	"Decimal",
//	"Divide",
//	"F1",
//	"F2",
//	"F3",
//	"F4",
//	"F5",
//	"F6",
//	"F7",
//	"F8",
//	"F9",
//	"F10",
//	"F11",
//	"F12",
//};
