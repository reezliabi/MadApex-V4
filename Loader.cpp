#include "Loader.h"
#include "entity.h"
#include "offsets.h"
#include "vector.h"
#include "aimbot.h"
#include "items.h"
#include <dwmapi.h>
#include "skcrypt.h"
#include "bytesuwu.h"
#include "auth.h"


ImVec2 pos;
ImDrawList* draww;
ImFont* tolstiy = nullptr;

int WallHackKeyStatus;
int SkinKeyStatus;
int AimBotKeyStatus;
int RecoilKeyStatus;

int RecoilRealKey;
int WallHackRealKey;
int SkinRealKey;
int AimBotRealKey;

int SkinKey;
int RecoilKey;

int WallHackKey;


static const char* keyNames[] =
{
	"",
	"    Left Mouse",
	"   Right Mouse",
	"       Cancel",
	"   Middle Mouse",
	"      Mouse 5",
	"      Mouse 4",
	"",
	"     Backspace",
	"          Tab",
	"",
	"",
	"         Clear",
	"        Enter",
	"",
	"",
	"         Shift",
	"       Control",
	"           Alt",
	"        Pause",
	"         Caps",
	"",
	"",
	"",
	"",
	"",
	"",
	"        Escape",
	"",
	"",
	"",
	"",
	"         Space",
	"      Page Up",
	"    Page Down",
	"           End",
	"         Home",
	"          Left",
	"           Up",
	"         Right",
	"         Down",
	"             ",
	"             ",
	"             ",
	"         Print",
	"        Insert",
	"        Delete",
	"             ",
	"             0",
	"             1",
	"             2",
	"             3",
	"             4",
	"             5",
	"             6",
	"             7",
	"             8",
	"             9",
	"             ",
	"             ",
	"             ",
	"             ",
	"             ",
	"             ",
	"             ",
	"             A",
	"             B",
	"             C",
	"             D",
	"             E",
	"             F",
	"             G",
	"             H",
	"             I",
	"             J",
	"             K",
	"             L",
	"             M",
	"             N",
	"             O",
	"             P",
	"             Q",
	"             R",
	"             S",
	"             T",
	"             U",
	"             V",
	"             W",
	"             X",
	"             Y",
	"             Z",
	"",
	"",
	"",
	"",
	"",
	"       Numpad 0",
	"       Numpad 1",
	"       Numpad 2",
	"       Numpad 3",
	"       Numpad 4",
	"       Numpad 5",
	"       Numpad 6",
	"       Numpad 7",
	"       Numpad 8",
	"       Numpad 9",
	"       Multiply",
	"            Add",
	"",
	"         Subtract",
	"          Decimal",
	"           Divide",
	"            F1",
	"            F2",
	"            F3",
	"            F4",
	"            F5",
	"            F6",
	"            F7",
	"            F8",
	"            F9",
	"            F10",
	"            F11",
	"            F12",
};
static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}
void HotkeyButton(int aimkey, void* changekey, int status, ImVec2 a)
{
	const char* preview_value = NULL;
	if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(keyNames))
		Items_ArrayGetter(keyNames, aimkey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = anbaCrypt("Select Key");
	else
		aimkeys = preview_value;

	if (status == 1)
	{
		aimkeys = anbaCrypt("Press key to bind");
	}
	if (ImGui::Button(aimkeys.c_str(), a))
	{
		if (status == 0)
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}
static bool yarrrrraaaaa(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}

void WallHackChangeKey(void* blank)
{
	WallHackKeyStatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				WallHackKey = i;
				WallHackKeyStatus = 0;
				return;
			}
		}
	}
}
void AimBotChangeKey(void* blank)
{
	AimBotKeyStatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				AimBotKey = i;
				AimBotKeyStatus = 0;
				return;
			}
		}
	}
}
void SkinChangeKey(void* blank)
{
	SkinKeyStatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				SkinKey = i;
				SkinKeyStatus = 0;
				return;
			}
		}
	}
}
void RecoilChangeKey(void* blank)
{
	RecoilKeyStatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				RecoilKey = i;
				RecoilKeyStatus = 0;
				return;
			}
		}
	}
}

void WallHackKeyButton(int AimBotKey, void* changekey, int status, ImVec2 a)
{

	const char* preview_value = NULL;
	if (WallHackKey >= 0 && WallHackKey < IM_ARRAYSIZE(keyNames))
		yarrrrraaaaa(keyNames, WallHackKey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = anbaCrypt("     Select Key");
	else
		aimkeys = preview_value;
	if (status == 1)
	{
		aimkeys = anbaCrypt("     Press key");
	}
	if (ImGui::Button(aimkeys.c_str(), a))
	{
		if (status == 0)
		{

			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}
void AimBotKeyButton(int AimBotKey, void* changekey, int status, ImVec2 a)
{

	const char* preview_value = NULL;
	if (AimBotKey >= 0 && AimBotKey < IM_ARRAYSIZE(keyNames))
		yarrrrraaaaa(keyNames, AimBotKey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = anbaCrypt("     Select Key");
	else
		aimkeys = preview_value;
	if (status == 1)
	{
		aimkeys = anbaCrypt("     Press key");
	}
	if (ImGui::Button(aimkeys.c_str(), a))
	{
		if (status == 0)
		{

			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}
void SkinKeyButton(int AimBotKey, void* changekey, int status, ImVec2 a)
{

	const char* preview_value = NULL;
	if (SkinKey >= 0 && SkinKey < IM_ARRAYSIZE(keyNames))
		yarrrrraaaaa(keyNames, SkinKey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = anbaCrypt("     Select Key");
	else
		aimkeys = preview_value;
	if (status == 1)
	{
		aimkeys = anbaCrypt("     Press key");
	}
	if (ImGui::Button(aimkeys.c_str(), a))
	{
		if (status == 0)
		{

			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}
void RecoilKeyButton(int RecoilKey, void* changekey, int status, ImVec2 a)
{

	const char* preview_value = NULL;
	if (RecoilKey >= 0 && RecoilKey < IM_ARRAYSIZE(keyNames))
		yarrrrraaaaa(keyNames, RecoilKey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = anbaCrypt("     Select Key");
	else
		aimkeys = preview_value;
	if (status == 1)
	{
		aimkeys = anbaCrypt("     Press key");
	}
	if (ImGui::Button(aimkeys.c_str(), a))
	{
		if (status == 0)
		{

			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}

void cheaternet(int c, int u) {
	draww->AddLine(ImVec2(c + 0, u + 0), ImVec2(c + 0, u + 1), ImColor(15, 16, 22, 255));
	draww->AddLine(ImVec2(c + 1, u + 0), ImVec2(c + 1, u + 1), ImColor(25, 28, 33, 255));
	draww->AddLine(ImVec2(c + 2, u + 0), ImVec2(c + 2, u + 1), ImColor(9, 9, 14, 255));
	draww->AddLine(ImVec2(c + 3, u + 0), ImVec2(c + 25, u + 0), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 25, u + 0), ImVec2(c + 25, u + 1), ImColor(10, 11, 16, 255));
	draww->AddLine(ImVec2(c + 26, u + 0), ImVec2(c + 26, u + 1), ImColor(35, 40, 46, 255));
	draww->AddLine(ImVec2(c + 0, u + 1), ImVec2(c + 0, u + 2), ImColor(9, 9, 14, 255));
	draww->AddLine(ImVec2(c + 1, u + 1), ImVec2(c + 1, u + 2), ImColor(66, 75, 83, 255));
	draww->AddLine(ImVec2(c + 2, u + 1), ImVec2(c + 2, u + 2), ImColor(54, 61, 68, 255));
	draww->AddLine(ImVec2(c + 3, u + 1), ImVec2(c + 3, u + 2), ImColor(15, 17, 22, 255));
	draww->AddLine(ImVec2(c + 4, u + 1), ImVec2(c + 4, u + 2), ImColor(10, 10, 15, 255));
	draww->AddLine(ImVec2(c + 5, u + 1), ImVec2(c + 23, u + 1), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 23, u + 1), ImVec2(c + 23, u + 2), ImColor(14, 15, 20, 255));
	draww->AddLine(ImVec2(c + 24, u + 1), ImVec2(c + 24, u + 2), ImColor(23, 25, 31, 255));
	draww->AddLine(ImVec2(c + 25, u + 1), ImVec2(c + 25, u + 2), ImColor(70, 80, 88, 255));
	draww->AddLine(ImVec2(c + 26, u + 1), ImVec2(c + 26, u + 2), ImColor(51, 58, 65, 255));
	draww->AddLine(ImVec2(c + 0, u + 2), ImVec2(c + 0, u + 3), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 1, u + 2), ImVec2(c + 1, u + 3), ImColor(36, 40, 46, 255));
	draww->AddLine(ImVec2(c + 2, u + 2), ImVec2(c + 2, u + 3), ImColor(111, 128, 137, 255));
	draww->AddLine(ImVec2(c + 3, u + 2), ImVec2(c + 3, u + 3), ImColor(77, 92, 101, 255));
	draww->AddLine(ImVec2(c + 4, u + 2), ImVec2(c + 4, u + 3), ImColor(55, 67, 76, 255));
	draww->AddLine(ImVec2(c + 5, u + 2), ImVec2(c + 5, u + 3), ImColor(17, 19, 24, 255));
	draww->AddLine(ImVec2(c + 6, u + 2), ImVec2(c + 21, u + 2), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 21, u + 2), ImVec2(c + 21, u + 3), ImColor(10, 10, 15, 255));
	draww->AddLine(ImVec2(c + 22, u + 2), ImVec2(c + 22, u + 3), ImColor(29, 33, 39, 255));
	draww->AddLine(ImVec2(c + 23, u + 2), ImVec2(c + 23, u + 3), ImColor(62, 80, 93, 255));
	draww->AddLine(ImVec2(c + 24, u + 2), ImVec2(c + 24, u + 3), ImColor(103, 120, 132, 255));
	draww->AddLine(ImVec2(c + 25, u + 2), ImVec2(c + 25, u + 3), ImColor(115, 132, 142, 255));
	draww->AddLine(ImVec2(c + 26, u + 2), ImVec2(c + 26, u + 3), ImColor(36, 41, 47, 255));
	draww->AddLine(ImVec2(c + 0, u + 3), ImVec2(c + 0, u + 4), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 1, u + 3), ImVec2(c + 1, u + 4), ImColor(14, 15, 20, 255));
	draww->AddLine(ImVec2(c + 2, u + 3), ImVec2(c + 2, u + 4), ImColor(95, 109, 118, 255));
	draww->AddLine(ImVec2(c + 3, u + 3), ImVec2(c + 3, u + 4), ImColor(123, 146, 159, 255));
	draww->AddLine(ImVec2(c + 4, u + 3), ImVec2(c + 4, u + 4), ImColor(81, 130, 153, 255));
	draww->AddLine(ImVec2(c + 5, u + 3), ImVec2(c + 5, u + 4), ImColor(71, 106, 123, 255));
	draww->AddLine(ImVec2(c + 6, u + 3), ImVec2(c + 6, u + 4), ImColor(39, 44, 50, 255));
	draww->AddLine(ImVec2(c + 7, u + 3), ImVec2(c + 7, u + 4), ImColor(9, 9, 14, 255));
	draww->AddLine(ImVec2(c + 8, u + 3), ImVec2(c + 20, u + 3), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 20, u + 3), ImVec2(c + 20, u + 4), ImColor(11, 12, 17, 255));
	draww->AddLine(ImVec2(c + 21, u + 3), ImVec2(c + 21, u + 4), ImColor(63, 74, 83, 255));
	draww->AddLine(ImVec2(c + 22, u + 3), ImVec2(c + 22, u + 4), ImColor(83, 126, 148, 255));
	draww->AddLine(ImVec2(c + 23, u + 3), ImVec2(c + 23, u + 4), ImColor(102, 156, 184, 255));
	draww->AddLine(ImVec2(c + 24, u + 3), ImVec2(c + 24, u + 4), ImColor(147, 171, 184, 255));
	draww->AddLine(ImVec2(c + 25, u + 3), ImVec2(c + 25, u + 4), ImColor(98, 113, 123, 255));
	draww->AddLine(ImVec2(c + 26, u + 3), ImVec2(c + 26, u + 4), ImColor(16, 17, 22, 255));
	draww->AddLine(ImVec2(c + 0, u + 4), ImVec2(c + 2, u + 4), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 2, u + 4), ImVec2(c + 2, u + 5), ImColor(54, 62, 69, 255));
	draww->AddLine(ImVec2(c + 3, u + 4), ImVec2(c + 3, u + 5), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 4, u + 4), ImVec2(c + 4, u + 5), ImColor(118, 148, 164, 255));
	draww->AddLine(ImVec2(c + 5, u + 4), ImVec2(c + 5, u + 5), ImColor(50, 150, 197, 255));
	draww->AddLine(ImVec2(c + 6, u + 4), ImVec2(c + 6, u + 5), ImColor(59, 134, 169, 255));
	draww->AddLine(ImVec2(c + 7, u + 4), ImVec2(c + 7, u + 5), ImColor(65, 88, 101, 255));
	draww->AddLine(ImVec2(c + 8, u + 4), ImVec2(c + 8, u + 5), ImColor(26, 29, 35, 255));
	draww->AddLine(ImVec2(c + 9, u + 4), ImVec2(c + 9, u + 5), ImColor(13, 14, 19, 255));
	draww->AddLine(ImVec2(c + 10, u + 4), ImVec2(c + 10, u + 5), ImColor(20, 22, 28, 255));
	draww->AddLine(ImVec2(c + 11, u + 4), ImVec2(c + 11, u + 5), ImColor(40, 48, 56, 255));
	draww->AddLine(ImVec2(c + 12, u + 4), ImVec2(c + 12, u + 5), ImColor(67, 77, 85, 255));
	draww->AddLine(ImVec2(c + 13, u + 4), ImVec2(c + 13, u + 5), ImColor(88, 101, 110, 255));
	draww->AddLine(ImVec2(c + 14, u + 4), ImVec2(c + 14, u + 5), ImColor(97, 112, 121, 255));
	draww->AddLine(ImVec2(c + 15, u + 4), ImVec2(c + 15, u + 5), ImColor(75, 89, 99, 255));
	draww->AddLine(ImVec2(c + 16, u + 4), ImVec2(c + 16, u + 5), ImColor(46, 55, 63, 255));
	draww->AddLine(ImVec2(c + 17, u + 4), ImVec2(c + 17, u + 5), ImColor(21, 24, 29, 255));
	draww->AddLine(ImVec2(c + 18, u + 4), ImVec2(c + 18, u + 5), ImColor(16, 17, 23, 255));
	draww->AddLine(ImVec2(c + 19, u + 4), ImVec2(c + 19, u + 5), ImColor(32, 38, 45, 255));
	draww->AddLine(ImVec2(c + 20, u + 4), ImVec2(c + 20, u + 5), ImColor(75, 107, 124, 255));
	draww->AddLine(ImVec2(c + 21, u + 4), ImVec2(c + 21, u + 5), ImColor(61, 144, 184, 255));
	draww->AddLine(ImVec2(c + 22, u + 4), ImVec2(c + 22, u + 5), ImColor(74, 165, 209, 255));
	draww->AddLine(ImVec2(c + 23, u + 4), ImVec2(c + 23, u + 5), ImColor(136, 173, 192, 255));
	draww->AddLine(ImVec2(c + 24, u + 4), ImVec2(c + 24, u + 5), ImColor(138, 159, 170, 255));
	draww->AddLine(ImVec2(c + 25, u + 4), ImVec2(c + 25, u + 5), ImColor(57, 65, 73, 255));
	draww->AddLine(ImVec2(c + 26, u + 4), ImVec2(c + 26, u + 5), ImColor(9, 9, 14, 255));
	draww->AddLine(ImVec2(c + 0, u + 5), ImVec2(c + 2, u + 5), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 2, u + 5), ImVec2(c + 2, u + 6), ImColor(11, 11, 16, 255));
	draww->AddLine(ImVec2(c + 3, u + 5), ImVec2(c + 3, u + 6), ImColor(122, 140, 151, 255));
	draww->AddLine(ImVec2(c + 4, u + 5), ImVec2(c + 4, u + 6), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 5, u + 5), ImVec2(c + 5, u + 6), ImColor(124, 149, 163, 255));
	draww->AddLine(ImVec2(c + 6, u + 5), ImVec2(c + 6, u + 6), ImColor(33, 155, 212, 255));
	draww->AddLine(ImVec2(c + 7, u + 5), ImVec2(c + 7, u + 6), ImColor(27, 154, 213, 255));
	draww->AddLine(ImVec2(c + 8, u + 5), ImVec2(c + 8, u + 6), ImColor(65, 133, 165, 255));
	draww->AddLine(ImVec2(c + 9, u + 5), ImVec2(c + 9, u + 6), ImColor(63, 83, 94, 255));
	draww->AddLine(ImVec2(c + 10, u + 5), ImVec2(c + 10, u + 6), ImColor(69, 119, 143, 255));
	draww->AddLine(ImVec2(c + 11, u + 5), ImVec2(c + 11, u + 6), ImColor(63, 143, 182, 255));
	draww->AddLine(ImVec2(c + 12, u + 5), ImVec2(c + 12, u + 6), ImColor(108, 144, 161, 255));
	draww->AddLine(ImVec2(c + 13, u + 5), ImVec2(c + 13, u + 6), ImColor(136, 157, 168, 255));
	draww->AddLine(ImVec2(c + 14, u + 5), ImVec2(c + 14, u + 6), ImColor(150, 172, 185, 255));
	draww->AddLine(ImVec2(c + 15, u + 5), ImVec2(c + 15, u + 6), ImColor(114, 167, 193, 255));
	draww->AddLine(ImVec2(c + 16, u + 5), ImVec2(c + 16, u + 6), ImColor(77, 159, 198, 255));
	draww->AddLine(ImVec2(c + 17, u + 5), ImVec2(c + 17, u + 6), ImColor(88, 138, 164, 255));
	draww->AddLine(ImVec2(c + 18, u + 5), ImVec2(c + 18, u + 6), ImColor(78, 100, 114, 255));
	draww->AddLine(ImVec2(c + 19, u + 5), ImVec2(c + 19, u + 6), ImColor(74, 146, 180, 255));
	draww->AddLine(ImVec2(c + 20, u + 5), ImVec2(c + 20, u + 6), ImColor(35, 163, 223, 255));
	draww->AddLine(ImVec2(c + 21, u + 5), ImVec2(c + 21, u + 6), ImColor(64, 169, 219, 255));
	draww->AddLine(ImVec2(c + 22, u + 5), ImVec2(c + 22, u + 6), ImColor(138, 173, 192, 255));
	draww->AddLine(ImVec2(c + 23, u + 5), ImVec2(c + 23, u + 6), ImColor(153, 176, 189, 255));
	draww->AddLine(ImVec2(c + 24, u + 5), ImVec2(c + 24, u + 6), ImColor(118, 135, 147, 255));
	draww->AddLine(ImVec2(c + 25, u + 5), ImVec2(c + 25, u + 6), ImColor(22, 25, 30, 255));
	draww->AddLine(ImVec2(c + 0, u + 6), ImVec2(c + 3, u + 6), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 6), ImVec2(c + 3, u + 7), ImColor(85, 97, 106, 255));
	draww->AddLine(ImVec2(c + 4, u + 6), ImVec2(c + 6, u + 6), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 6, u + 6), ImVec2(c + 6, u + 7), ImColor(112, 149, 168, 255));
	draww->AddLine(ImVec2(c + 7, u + 6), ImVec2(c + 7, u + 7), ImColor(39, 156, 211, 255));
	draww->AddLine(ImVec2(c + 8, u + 6), ImVec2(c + 8, u + 7), ImColor(17, 155, 220, 255));
	draww->AddLine(ImVec2(c + 9, u + 6), ImVec2(c + 9, u + 7), ImColor(54, 146, 189, 255));
	draww->AddLine(ImVec2(c + 10, u + 6), ImVec2(c + 10, u + 7), ImColor(16, 160, 228, 255));
	draww->AddLine(ImVec2(c + 11, u + 6), ImVec2(c + 11, u + 7), ImColor(7, 166, 240, 255));
	draww->AddLine(ImVec2(c + 12, u + 6), ImVec2(c + 12, u + 7), ImColor(116, 150, 167, 255));
	draww->AddLine(ImVec2(c + 13, u + 6), ImVec2(c + 13, u + 7), ImColor(136, 157, 168, 255));
	draww->AddLine(ImVec2(c + 14, u + 6), ImVec2(c + 14, u + 7), ImColor(150, 172, 185, 255));
	draww->AddLine(ImVec2(c + 15, u + 6), ImVec2(c + 15, u + 7), ImColor(116, 172, 200, 255));
	draww->AddLine(ImVec2(c + 16, u + 6), ImVec2(c + 16, u + 7), ImColor(9, 164, 237, 255));
	draww->AddLine(ImVec2(c + 17, u + 6), ImVec2(c + 17, u + 7), ImColor(21, 165, 232, 255));
	draww->AddLine(ImVec2(c + 18, u + 6), ImVec2(c + 18, u + 7), ImColor(67, 160, 204, 255));
	draww->AddLine(ImVec2(c + 19, u + 6), ImVec2(c + 19, u + 7), ImColor(29, 162, 224, 255));
	draww->AddLine(ImVec2(c + 20, u + 6), ImVec2(c + 20, u + 7), ImColor(51, 168, 223, 255));
	draww->AddLine(ImVec2(c + 21, u + 6), ImVec2(c + 21, u + 7), ImColor(137, 173, 192, 255));
	draww->AddLine(ImVec2(c + 22, u + 6), ImVec2(c + 24, u + 6), ImColor(153, 176, 189, 255));
	draww->AddLine(ImVec2(c + 24, u + 6), ImVec2(c + 24, u + 7), ImColor(79, 91, 100, 255));
	draww->AddLine(ImVec2(c + 25, u + 6), ImVec2(c + 25, u + 7), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 0, u + 7), ImVec2(c + 3, u + 7), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 7), ImVec2(c + 3, u + 8), ImColor(47, 53, 60, 255));
	draww->AddLine(ImVec2(c + 4, u + 7), ImVec2(c + 4, u + 8), ImColor(129, 148, 159, 255));
	draww->AddLine(ImVec2(c + 5, u + 7), ImVec2(c + 7, u + 7), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 7, u + 7), ImVec2(c + 7, u + 8), ImColor(112, 151, 170, 255));
	draww->AddLine(ImVec2(c + 8, u + 7), ImVec2(c + 8, u + 8), ImColor(34, 156, 213, 255));
	draww->AddLine(ImVec2(c + 9, u + 7), ImVec2(c + 9, u + 8), ImColor(10, 165, 237, 255));
	draww->AddLine(ImVec2(c + 10, u + 7), ImVec2(c + 10, u + 8), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 11, u + 7), ImVec2(c + 11, u + 8), ImColor(25, 161, 225, 255));
	draww->AddLine(ImVec2(c + 12, u + 7), ImVec2(c + 12, u + 8), ImColor(130, 151, 163, 255));
	draww->AddLine(ImVec2(c + 13, u + 7), ImVec2(c + 13, u + 8), ImColor(136, 157, 168, 255));
	draww->AddLine(ImVec2(c + 14, u + 7), ImVec2(c + 14, u + 8), ImColor(150, 172, 185, 255));
	draww->AddLine(ImVec2(c + 15, u + 7), ImVec2(c + 15, u + 8), ImColor(134, 174, 195, 255));
	draww->AddLine(ImVec2(c + 16, u + 7), ImVec2(c + 16, u + 8), ImColor(30, 168, 233, 255));
	draww->AddLine(ImVec2(c + 17, u + 7), ImVec2(c + 17, u + 8), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 18, u + 7), ImVec2(c + 18, u + 8), ImColor(15, 167, 238, 255));
	draww->AddLine(ImVec2(c + 19, u + 7), ImVec2(c + 19, u + 8), ImColor(59, 168, 219, 255));
	draww->AddLine(ImVec2(c + 20, u + 7), ImVec2(c + 20, u + 8), ImColor(128, 173, 196, 255));
	draww->AddLine(ImVec2(c + 21, u + 7), ImVec2(c + 23, u + 7), ImColor(153, 176, 189, 255));
	draww->AddLine(ImVec2(c + 23, u + 7), ImVec2(c + 23, u + 8), ImColor(151, 174, 186, 255));
	draww->AddLine(ImVec2(c + 24, u + 7), ImVec2(c + 24, u + 8), ImColor(39, 44, 50, 255));
	draww->AddLine(ImVec2(c + 25, u + 7), ImVec2(c + 28, u + 7), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 28, u + 7), ImVec2(c + 28, u + 8), ImColor(7, 45, 66, 255));
	draww->AddLine(ImVec2(c + 29, u + 7), ImVec2(c + 32, u + 7), ImColor(6, 73, 107, 255));
	draww->AddLine(ImVec2(c + 32, u + 7), ImVec2(c + 32, u + 8), ImColor(7, 46, 68, 255));
	draww->AddLine(ImVec2(c + 33, u + 7), ImVec2(c + 33, u + 8), ImColor(7, 56, 83, 255));
	draww->AddLine(ImVec2(c + 34, u + 7), ImVec2(c + 34, u + 8), ImColor(7, 65, 96, 255));
	draww->AddLine(ImVec2(c + 35, u + 7), ImVec2(c + 35, u + 8), ImColor(8, 18, 28, 255));
	draww->AddLine(ImVec2(c + 36, u + 7), ImVec2(c + 36, u + 8), ImColor(8, 34, 51, 255));
	draww->AddLine(ImVec2(c + 37, u + 7), ImVec2(c + 37, u + 8), ImColor(6, 73, 107, 255));
	draww->AddLine(ImVec2(c + 38, u + 7), ImVec2(c + 38, u + 8), ImColor(8, 35, 53, 255));
	draww->AddLine(ImVec2(c + 39, u + 7), ImVec2(c + 39, u + 8), ImColor(7, 54, 80, 255));
	draww->AddLine(ImVec2(c + 40, u + 7), ImVec2(c + 43, u + 7), ImColor(6, 73, 107, 255));
	draww->AddLine(ImVec2(c + 43, u + 7), ImVec2(c + 43, u + 8), ImColor(7, 60, 88, 255));
	draww->AddLine(ImVec2(c + 44, u + 7), ImVec2(c + 44, u + 8), ImColor(8, 16, 25, 255));
	draww->AddLine(ImVec2(c + 45, u + 7), ImVec2(c + 45, u + 8), ImColor(8, 28, 43, 255));
	draww->AddLine(ImVec2(c + 46, u + 7), ImVec2(c + 46, u + 8), ImColor(7, 61, 91, 255));
	draww->AddLine(ImVec2(c + 47, u + 7), ImVec2(c + 49, u + 7), ImColor(6, 73, 107, 255));
	draww->AddLine(ImVec2(c + 49, u + 7), ImVec2(c + 49, u + 8), ImColor(7, 55, 82, 255));
	draww->AddLine(ImVec2(c + 50, u + 7), ImVec2(c + 50, u + 8), ImColor(7, 59, 87, 255));
	draww->AddLine(ImVec2(c + 51, u + 7), ImVec2(c + 54, u + 7), ImColor(6, 73, 107, 255));
	draww->AddLine(ImVec2(c + 54, u + 7), ImVec2(c + 54, u + 8), ImColor(7, 61, 90, 255));
	draww->AddLine(ImVec2(c + 55, u + 7), ImVec2(c + 55, u + 8), ImColor(7, 51, 75, 255));
	draww->AddLine(ImVec2(c + 56, u + 7), ImVec2(c + 56, u + 8), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 57, u + 7), ImVec2(c + 60, u + 7), ImColor(6, 73, 107, 255));
	draww->AddLine(ImVec2(c + 60, u + 7), ImVec2(c + 60, u + 8), ImColor(8, 32, 48, 255));
	draww->AddLine(ImVec2(c + 61, u + 7), ImVec2(c + 61, u + 8), ImColor(7, 61, 91, 255));
	draww->AddLine(ImVec2(c + 62, u + 7), ImVec2(c + 64, u + 7), ImColor(6, 73, 107, 255));
	draww->AddLine(ImVec2(c + 64, u + 7), ImVec2(c + 64, u + 8), ImColor(7, 53, 78, 255));
	draww->AddLine(ImVec2(c + 65, u + 7), ImVec2(c + 65, u + 8), ImColor(8, 14, 22, 255));
	draww->AddLine(ImVec2(c + 66, u + 7), ImVec2(c + 69, u + 7), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 69, u + 7), ImVec2(c + 69, u + 8), ImColor(8, 30, 45, 255));
	draww->AddLine(ImVec2(c + 70, u + 7), ImVec2(c + 70, u + 8), ImColor(6, 74, 109, 255));
	draww->AddLine(ImVec2(c + 71, u + 7), ImVec2(c + 71, u + 8), ImColor(7, 55, 81, 255));
	draww->AddLine(ImVec2(c + 72, u + 7), ImVec2(c + 72, u + 8), ImColor(8, 27, 41, 255));
	draww->AddLine(ImVec2(c + 73, u + 7), ImVec2(c + 73, u + 8), ImColor(7, 66, 98, 255));
	draww->AddLine(ImVec2(c + 74, u + 7), ImVec2(c + 74, u + 8), ImColor(7, 43, 63, 255));
	draww->AddLine(ImVec2(c + 75, u + 7), ImVec2(c + 75, u + 8), ImColor(7, 42, 63, 255));
	draww->AddLine(ImVec2(c + 76, u + 7), ImVec2(c + 79, u + 7), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 79, u + 7), ImVec2(c + 79, u + 8), ImColor(7, 65, 96, 255));
	draww->AddLine(ImVec2(c + 80, u + 7), ImVec2(c + 80, u + 8), ImColor(7, 53, 79, 255));
	draww->AddLine(ImVec2(c + 81, u + 7), ImVec2(c + 84, u + 7), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 84, u + 7), ImVec2(c + 84, u + 8), ImColor(7, 63, 93, 255));
	draww->AddLine(ImVec2(c + 0, u + 8), ImVec2(c + 3, u + 8), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 8), ImVec2(c + 3, u + 9), ImColor(20, 22, 28, 255));
	draww->AddLine(ImVec2(c + 4, u + 8), ImVec2(c + 4, u + 9), ImColor(100, 116, 125, 255));
	draww->AddLine(ImVec2(c + 5, u + 8), ImVec2(c + 8, u + 8), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 8, u + 8), ImVec2(c + 8, u + 9), ImColor(119, 148, 163, 255));
	draww->AddLine(ImVec2(c + 9, u + 8), ImVec2(c + 9, u + 9), ImColor(23, 157, 220, 255));
	draww->AddLine(ImVec2(c + 10, u + 8), ImVec2(c + 10, u + 9), ImColor(3, 167, 243, 255));
	draww->AddLine(ImVec2(c + 11, u + 8), ImVec2(c + 11, u + 9), ImColor(38, 158, 213, 255));
	draww->AddLine(ImVec2(c + 12, u + 8), ImVec2(c + 12, u + 9), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 13, u + 8), ImVec2(c + 13, u + 9), ImColor(136, 157, 168, 255));
	draww->AddLine(ImVec2(c + 14, u + 8), ImVec2(c + 14, u + 9), ImColor(150, 172, 185, 255));
	draww->AddLine(ImVec2(c + 15, u + 8), ImVec2(c + 15, u + 9), ImColor(136, 173, 193, 255));
	draww->AddLine(ImVec2(c + 16, u + 8), ImVec2(c + 16, u + 9), ImColor(49, 167, 224, 255));
	draww->AddLine(ImVec2(c + 17, u + 8), ImVec2(c + 17, u + 9), ImColor(4, 167, 243, 255));
	draww->AddLine(ImVec2(c + 18, u + 8), ImVec2(c + 18, u + 9), ImColor(57, 169, 222, 255));
	draww->AddLine(ImVec2(c + 19, u + 8), ImVec2(c + 19, u + 9), ImColor(132, 173, 193, 255));
	draww->AddLine(ImVec2(c + 20, u + 8), ImVec2(c + 23, u + 8), ImColor(153, 176, 189, 255));
	draww->AddLine(ImVec2(c + 23, u + 8), ImVec2(c + 23, u + 9), ImColor(116, 134, 145, 255));
	draww->AddLine(ImVec2(c + 24, u + 8), ImVec2(c + 27, u + 8), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 27, u + 8), ImVec2(c + 27, u + 9), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 28, u + 8), ImVec2(c + 28, u + 9), ImColor(6, 90, 132, 255));
	draww->AddLine(ImVec2(c + 29, u + 8), ImVec2(c + 29, u + 9), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 30, u + 8), ImVec2(c + 30, u + 9), ImColor(4, 144, 210, 255));
	draww->AddLine(ImVec2(c + 31, u + 8), ImVec2(c + 31, u + 9), ImColor(4, 139, 204, 255));
	draww->AddLine(ImVec2(c + 32, u + 8), ImVec2(c + 32, u + 9), ImColor(6, 96, 141, 255));
	draww->AddLine(ImVec2(c + 33, u + 8), ImVec2(c + 33, u + 9), ImColor(5, 118, 173, 255));
	draww->AddLine(ImVec2(c + 34, u + 8), ImVec2(c + 34, u + 9), ImColor(4, 154, 225, 255));
	draww->AddLine(ImVec2(c + 35, u + 8), ImVec2(c + 35, u + 9), ImColor(7, 41, 61, 255));
	draww->AddLine(ImVec2(c + 36, u + 8), ImVec2(c + 36, u + 9), ImColor(7, 58, 86, 255));
	draww->AddLine(ImVec2(c + 37, u + 8), ImVec2(c + 37, u + 9), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 38, u + 8), ImVec2(c + 38, u + 9), ImColor(6, 88, 129, 255));
	draww->AddLine(ImVec2(c + 39, u + 8), ImVec2(c + 39, u + 9), ImColor(6, 103, 151, 255));
	draww->AddLine(ImVec2(c + 40, u + 8), ImVec2(c + 40, u + 9), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 41, u + 8), ImVec2(c + 41, u + 9), ImColor(4, 141, 206, 255));
	draww->AddLine(ImVec2(c + 42, u + 8), ImVec2(c + 42, u + 9), ImColor(4, 139, 203, 255));
	draww->AddLine(ImVec2(c + 43, u + 8), ImVec2(c + 43, u + 9), ImColor(5, 120, 175, 255));
	draww->AddLine(ImVec2(c + 44, u + 8), ImVec2(c + 44, u + 9), ImColor(8, 39, 58, 255));
	draww->AddLine(ImVec2(c + 45, u + 8), ImVec2(c + 45, u + 9), ImColor(4, 136, 199, 255));
	draww->AddLine(ImVec2(c + 46, u + 8), ImVec2(c + 46, u + 9), ImColor(4, 160, 234, 255));
	draww->AddLine(ImVec2(c + 47, u + 8), ImVec2(c + 47, u + 9), ImColor(4, 144, 210, 255));
	draww->AddLine(ImVec2(c + 48, u + 8), ImVec2(c + 48, u + 9), ImColor(4, 164, 239, 255));
	draww->AddLine(ImVec2(c + 49, u + 8), ImVec2(c + 49, u + 9), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 50, u + 8), ImVec2(c + 50, u + 9), ImColor(5, 114, 167, 255));
	draww->AddLine(ImVec2(c + 51, u + 8), ImVec2(c + 51, u + 9), ImColor(4, 146, 214, 255));
	draww->AddLine(ImVec2(c + 52, u + 8), ImVec2(c + 52, u + 9), ImColor(4, 164, 240, 255));
	draww->AddLine(ImVec2(c + 53, u + 8), ImVec2(c + 53, u + 9), ImColor(4, 159, 232, 255));
	draww->AddLine(ImVec2(c + 54, u + 8), ImVec2(c + 54, u + 9), ImColor(5, 126, 184, 255));
	draww->AddLine(ImVec2(c + 55, u + 8), ImVec2(c + 55, u + 9), ImColor(5, 107, 156, 255));
	draww->AddLine(ImVec2(c + 56, u + 8), ImVec2(c + 56, u + 9), ImColor(4, 159, 232, 255));
	draww->AddLine(ImVec2(c + 57, u + 8), ImVec2(c + 57, u + 9), ImColor(4, 146, 213, 255));
	draww->AddLine(ImVec2(c + 58, u + 8), ImVec2(c + 58, u + 9), ImColor(4, 137, 200, 255));
	draww->AddLine(ImVec2(c + 59, u + 8), ImVec2(c + 59, u + 9), ImColor(4, 142, 207, 255));
	draww->AddLine(ImVec2(c + 60, u + 8), ImVec2(c + 60, u + 9), ImColor(7, 68, 100, 255));
	draww->AddLine(ImVec2(c + 61, u + 8), ImVec2(c + 61, u + 9), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 62, u + 8), ImVec2(c + 62, u + 9), ImColor(4, 164, 239, 255));
	draww->AddLine(ImVec2(c + 63, u + 8), ImVec2(c + 63, u + 9), ImColor(4, 150, 219, 255));
	draww->AddLine(ImVec2(c + 64, u + 8), ImVec2(c + 64, u + 9), ImColor(4, 164, 240, 255));
	draww->AddLine(ImVec2(c + 65, u + 8), ImVec2(c + 65, u + 9), ImColor(6, 94, 138, 255));
	draww->AddLine(ImVec2(c + 66, u + 8), ImVec2(c + 69, u + 8), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 69, u + 8), ImVec2(c + 69, u + 9), ImColor(7, 45, 67, 255));
	draww->AddLine(ImVec2(c + 70, u + 8), ImVec2(c + 72, u + 8), ImColor(4, 162, 237, 255));
	draww->AddLine(ImVec2(c + 72, u + 8), ImVec2(c + 72, u + 9), ImColor(6, 78, 114, 255));
	draww->AddLine(ImVec2(c + 73, u + 8), ImVec2(c + 73, u + 9), ImColor(4, 152, 223, 255));
	draww->AddLine(ImVec2(c + 74, u + 8), ImVec2(c + 74, u + 9), ImColor(5, 107, 157, 255));
	draww->AddLine(ImVec2(c + 75, u + 8), ImVec2(c + 75, u + 9), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 76, u + 8), ImVec2(c + 76, u + 9), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 77, u + 8), ImVec2(c + 77, u + 9), ImColor(4, 145, 212, 255));
	draww->AddLine(ImVec2(c + 78, u + 8), ImVec2(c + 78, u + 9), ImColor(4, 137, 201, 255));
	draww->AddLine(ImVec2(c + 79, u + 8), ImVec2(c + 79, u + 9), ImColor(5, 133, 194, 255));
	draww->AddLine(ImVec2(c + 80, u + 8), ImVec2(c + 80, u + 9), ImColor(6, 98, 144, 255));
	draww->AddLine(ImVec2(c + 81, u + 8), ImVec2(c + 81, u + 9), ImColor(4, 146, 213, 255));
	draww->AddLine(ImVec2(c + 82, u + 8), ImVec2(c + 84, u + 8), ImColor(4, 162, 237, 255));
	draww->AddLine(ImVec2(c + 84, u + 8), ImVec2(c + 84, u + 9), ImColor(5, 129, 188, 255));
	draww->AddLine(ImVec2(c + 0, u + 9), ImVec2(c + 3, u + 9), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 9), ImVec2(c + 3, u + 10), ImColor(21, 23, 29, 255));
	draww->AddLine(ImVec2(c + 4, u + 9), ImVec2(c + 4, u + 10), ImColor(92, 105, 114, 255));
	draww->AddLine(ImVec2(c + 5, u + 9), ImVec2(c + 9, u + 9), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 9, u + 9), ImVec2(c + 9, u + 10), ImColor(110, 150, 169, 255));
	draww->AddLine(ImVec2(c + 10, u + 9), ImVec2(c + 10, u + 10), ImColor(31, 159, 219, 255));
	draww->AddLine(ImVec2(c + 11, u + 9), ImVec2(c + 11, u + 10), ImColor(12, 164, 236, 255));
	draww->AddLine(ImVec2(c + 12, u + 9), ImVec2(c + 12, u + 10), ImColor(96, 155, 185, 255));
	draww->AddLine(ImVec2(c + 13, u + 9), ImVec2(c + 13, u + 10), ImColor(136, 157, 168, 255));
	draww->AddLine(ImVec2(c + 14, u + 9), ImVec2(c + 14, u + 10), ImColor(150, 172, 185, 255));
	draww->AddLine(ImVec2(c + 15, u + 9), ImVec2(c + 15, u + 10), ImColor(85, 168, 208, 255));
	draww->AddLine(ImVec2(c + 16, u + 9), ImVec2(c + 16, u + 10), ImColor(20, 165, 234, 255));
	draww->AddLine(ImVec2(c + 17, u + 9), ImVec2(c + 17, u + 10), ImColor(49, 167, 224, 255));
	draww->AddLine(ImVec2(c + 18, u + 9), ImVec2(c + 18, u + 10), ImColor(134, 173, 194, 255));
	draww->AddLine(ImVec2(c + 19, u + 9), ImVec2(c + 22, u + 9), ImColor(153, 176, 189, 255));
	draww->AddLine(ImVec2(c + 22, u + 9), ImVec2(c + 22, u + 10), ImColor(151, 174, 187, 255));
	draww->AddLine(ImVec2(c + 23, u + 9), ImVec2(c + 23, u + 10), ImColor(102, 117, 127, 255));
	draww->AddLine(ImVec2(c + 24, u + 9), ImVec2(c + 27, u + 9), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 27, u + 9), ImVec2(c + 27, u + 10), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 28, u + 9), ImVec2(c + 28, u + 10), ImColor(6, 90, 132, 255));
	draww->AddLine(ImVec2(c + 29, u + 9), ImVec2(c + 29, u + 10), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 30, u + 9), ImVec2(c + 30, u + 10), ImColor(6, 72, 106, 255));
	draww->AddLine(ImVec2(c + 31, u + 9), ImVec2(c + 31, u + 10), ImColor(8, 38, 56, 255));
	draww->AddLine(ImVec2(c + 32, u + 9), ImVec2(c + 32, u + 10), ImColor(8, 31, 47, 255));
	draww->AddLine(ImVec2(c + 33, u + 9), ImVec2(c + 33, u + 10), ImColor(5, 118, 173, 255));
	draww->AddLine(ImVec2(c + 34, u + 9), ImVec2(c + 34, u + 10), ImColor(4, 154, 225, 255));
	draww->AddLine(ImVec2(c + 35, u + 9), ImVec2(c + 35, u + 10), ImColor(7, 41, 61, 255));
	draww->AddLine(ImVec2(c + 36, u + 9), ImVec2(c + 36, u + 10), ImColor(7, 58, 86, 255));
	draww->AddLine(ImVec2(c + 37, u + 9), ImVec2(c + 37, u + 10), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 38, u + 9), ImVec2(c + 38, u + 10), ImColor(6, 88, 129, 255));
	draww->AddLine(ImVec2(c + 39, u + 9), ImVec2(c + 39, u + 10), ImColor(6, 103, 151, 255));
	draww->AddLine(ImVec2(c + 40, u + 9), ImVec2(c + 40, u + 10), ImColor(4, 166, 242, 255));
	draww->AddLine(ImVec2(c + 41, u + 9), ImVec2(c + 41, u + 10), ImColor(7, 63, 93, 255));
	draww->AddLine(ImVec2(c + 42, u + 9), ImVec2(c + 44, u + 9), ImColor(8, 36, 54, 255));
	draww->AddLine(ImVec2(c + 44, u + 9), ImVec2(c + 44, u + 10), ImColor(7, 44, 65, 255));
	draww->AddLine(ImVec2(c + 45, u + 9), ImVec2(c + 45, u + 10), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 46, u + 9), ImVec2(c + 46, u + 10), ImColor(5, 116, 170, 255));
	draww->AddLine(ImVec2(c + 47, u + 9), ImVec2(c + 47, u + 10), ImColor(7, 49, 73, 255));
	draww->AddLine(ImVec2(c + 48, u + 9), ImVec2(c + 48, u + 10), ImColor(4, 147, 214, 255));
	draww->AddLine(ImVec2(c + 49, u + 9), ImVec2(c + 49, u + 10), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 50, u + 9), ImVec2(c + 50, u + 10), ImColor(7, 51, 75, 255));
	draww->AddLine(ImVec2(c + 51, u + 9), ImVec2(c + 51, u + 10), ImColor(7, 63, 93, 255));
	draww->AddLine(ImVec2(c + 52, u + 9), ImVec2(c + 52, u + 10), ImColor(4, 152, 222, 255));
	draww->AddLine(ImVec2(c + 53, u + 9), ImVec2(c + 53, u + 10), ImColor(5, 132, 193, 255));
	draww->AddLine(ImVec2(c + 54, u + 9), ImVec2(c + 54, u + 10), ImColor(8, 36, 53, 255));
	draww->AddLine(ImVec2(c + 55, u + 9), ImVec2(c + 55, u + 10), ImColor(6, 80, 118, 255));
	draww->AddLine(ImVec2(c + 56, u + 9), ImVec2(c + 56, u + 10), ImColor(4, 159, 232, 255));
	draww->AddLine(ImVec2(c + 57, u + 9), ImVec2(c + 57, u + 10), ImColor(6, 89, 131, 255));
	draww->AddLine(ImVec2(c + 58, u + 9), ImVec2(c + 58, u + 10), ImColor(8, 34, 51, 255));
	draww->AddLine(ImVec2(c + 59, u + 9), ImVec2(c + 59, u + 10), ImColor(7, 41, 61, 255));
	draww->AddLine(ImVec2(c + 60, u + 9), ImVec2(c + 60, u + 10), ImColor(7, 44, 65, 255));
	draww->AddLine(ImVec2(c + 61, u + 9), ImVec2(c + 61, u + 10), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 62, u + 9), ImVec2(c + 62, u + 10), ImColor(4, 151, 221, 255));
	draww->AddLine(ImVec2(c + 63, u + 9), ImVec2(c + 63, u + 10), ImColor(7, 60, 89, 255));
	draww->AddLine(ImVec2(c + 64, u + 9), ImVec2(c + 64, u + 10), ImColor(4, 138, 202, 255));
	draww->AddLine(ImVec2(c + 65, u + 9), ImVec2(c + 65, u + 10), ImColor(4, 141, 206, 255));
	draww->AddLine(ImVec2(c + 66, u + 9), ImVec2(c + 69, u + 9), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 69, u + 9), ImVec2(c + 69, u + 10), ImColor(7, 45, 67, 255));
	draww->AddLine(ImVec2(c + 70, u + 9), ImVec2(c + 70, u + 10), ImColor(4, 162, 237, 255));
	draww->AddLine(ImVec2(c + 71, u + 9), ImVec2(c + 71, u + 10), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 72, u + 9), ImVec2(c + 72, u + 10), ImColor(4, 158, 231, 255));
	draww->AddLine(ImVec2(c + 73, u + 9), ImVec2(c + 73, u + 10), ImColor(4, 160, 234, 255));
	draww->AddLine(ImVec2(c + 74, u + 9), ImVec2(c + 74, u + 10), ImColor(5, 107, 157, 255));
	draww->AddLine(ImVec2(c + 75, u + 9), ImVec2(c + 75, u + 10), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 76, u + 9), ImVec2(c + 76, u + 10), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 77, u + 9), ImVec2(c + 77, u + 10), ImColor(6, 83, 122, 255));
	draww->AddLine(ImVec2(c + 78, u + 9), ImVec2(c + 78, u + 10), ImColor(8, 34, 52, 255));
	draww->AddLine(ImVec2(c + 79, u + 9), ImVec2(c + 79, u + 10), ImColor(8, 38, 57, 255));
	draww->AddLine(ImVec2(c + 80, u + 9), ImVec2(c + 80, u + 10), ImColor(8, 29, 43, 255));
	draww->AddLine(ImVec2(c + 81, u + 9), ImVec2(c + 81, u + 10), ImColor(7, 60, 89, 255));
	draww->AddLine(ImVec2(c + 82, u + 9), ImVec2(c + 82, u + 10), ImColor(4, 142, 208, 255));
	draww->AddLine(ImVec2(c + 83, u + 9), ImVec2(c + 83, u + 10), ImColor(4, 148, 216, 255));
	draww->AddLine(ImVec2(c + 84, u + 9), ImVec2(c + 84, u + 10), ImColor(8, 33, 50, 255));
	draww->AddLine(ImVec2(c + 0, u + 10), ImVec2(c + 3, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 10), ImVec2(c + 3, u + 11), ImColor(28, 31, 37, 255));
	draww->AddLine(ImVec2(c + 4, u + 10), ImVec2(c + 4, u + 11), ImColor(80, 113, 130, 255));
	draww->AddLine(ImVec2(c + 5, u + 10), ImVec2(c + 5, u + 11), ImColor(120, 147, 162, 255));
	draww->AddLine(ImVec2(c + 6, u + 10), ImVec2(c + 6, u + 11), ImColor(116, 140, 153, 255));
	draww->AddLine(ImVec2(c + 7, u + 10), ImVec2(c + 7, u + 11), ImColor(123, 150, 164, 255));
	draww->AddLine(ImVec2(c + 8, u + 10), ImVec2(c + 10, u + 10), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 10, u + 10), ImVec2(c + 10, u + 11), ImColor(110, 151, 172, 255));
	draww->AddLine(ImVec2(c + 11, u + 10), ImVec2(c + 11, u + 11), ImColor(23, 158, 221, 255));
	draww->AddLine(ImVec2(c + 12, u + 10), ImVec2(c + 12, u + 11), ImColor(17, 165, 234, 255));
	draww->AddLine(ImVec2(c + 13, u + 10), ImVec2(c + 13, u + 11), ImColor(100, 160, 190, 255));
	draww->AddLine(ImVec2(c + 14, u + 10), ImVec2(c + 14, u + 11), ImColor(96, 163, 196, 255));
	draww->AddLine(ImVec2(c + 15, u + 10), ImVec2(c + 15, u + 11), ImColor(16, 166, 236, 255));
	draww->AddLine(ImVec2(c + 16, u + 10), ImVec2(c + 16, u + 11), ImColor(46, 167, 223, 255));
	draww->AddLine(ImVec2(c + 17, u + 10), ImVec2(c + 17, u + 11), ImColor(127, 173, 196, 255));
	draww->AddLine(ImVec2(c + 18, u + 10), ImVec2(c + 20, u + 10), ImColor(153, 176, 189, 255));
	draww->AddLine(ImVec2(c + 20, u + 10), ImVec2(c + 20, u + 11), ImColor(137, 170, 186, 255));
	draww->AddLine(ImVec2(c + 21, u + 10), ImVec2(c + 21, u + 11), ImColor(136, 160, 173, 255));
	draww->AddLine(ImVec2(c + 22, u + 10), ImVec2(c + 22, u + 11), ImColor(128, 169, 189, 255));
	draww->AddLine(ImVec2(c + 23, u + 10), ImVec2(c + 23, u + 11), ImColor(118, 146, 161, 255));
	draww->AddLine(ImVec2(c + 24, u + 10), ImVec2(c + 27, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 27, u + 10), ImVec2(c + 27, u + 11), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 28, u + 10), ImVec2(c + 28, u + 11), ImColor(6, 90, 132, 255));
	draww->AddLine(ImVec2(c + 29, u + 10), ImVec2(c + 29, u + 11), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 30, u + 10), ImVec2(c + 30, u + 11), ImColor(7, 55, 82, 255));
	draww->AddLine(ImVec2(c + 31, u + 10), ImVec2(c + 33, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 33, u + 10), ImVec2(c + 33, u + 11), ImColor(5, 118, 173, 255));
	draww->AddLine(ImVec2(c + 34, u + 10), ImVec2(c + 34, u + 11), ImColor(4, 154, 225, 255));
	draww->AddLine(ImVec2(c + 35, u + 10), ImVec2(c + 35, u + 11), ImColor(7, 41, 61, 255));
	draww->AddLine(ImVec2(c + 36, u + 10), ImVec2(c + 36, u + 11), ImColor(7, 58, 86, 255));
	draww->AddLine(ImVec2(c + 37, u + 10), ImVec2(c + 37, u + 11), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 38, u + 10), ImVec2(c + 38, u + 11), ImColor(6, 88, 129, 255));
	draww->AddLine(ImVec2(c + 39, u + 10), ImVec2(c + 39, u + 11), ImColor(6, 103, 151, 255));
	draww->AddLine(ImVec2(c + 40, u + 10), ImVec2(c + 40, u + 11), ImColor(4, 164, 240, 255));
	draww->AddLine(ImVec2(c + 41, u + 10), ImVec2(c + 41, u + 11), ImColor(7, 46, 68, 255));
	draww->AddLine(ImVec2(c + 42, u + 10), ImVec2(c + 44, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 44, u + 10), ImVec2(c + 44, u + 11), ImColor(7, 40, 60, 255));
	draww->AddLine(ImVec2(c + 45, u + 10), ImVec2(c + 45, u + 11), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 46, u + 10), ImVec2(c + 46, u + 11), ImColor(6, 95, 140, 255));
	draww->AddLine(ImVec2(c + 47, u + 10), ImVec2(c + 47, u + 11), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 48, u + 10), ImVec2(c + 48, u + 11), ImColor(4, 141, 205, 255));
	draww->AddLine(ImVec2(c + 49, u + 10), ImVec2(c + 49, u + 11), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 50, u + 10), ImVec2(c + 50, u + 11), ImColor(8, 31, 46, 255));
	draww->AddLine(ImVec2(c + 51, u + 10), ImVec2(c + 51, u + 11), ImColor(8, 38, 57, 255));
	draww->AddLine(ImVec2(c + 52, u + 10), ImVec2(c + 52, u + 11), ImColor(4, 149, 218, 255));
	draww->AddLine(ImVec2(c + 53, u + 10), ImVec2(c + 53, u + 11), ImColor(5, 125, 184, 255));
	draww->AddLine(ImVec2(c + 54, u + 10), ImVec2(c + 54, u + 11), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 55, u + 10), ImVec2(c + 55, u + 11), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 56, u + 10), ImVec2(c + 56, u + 11), ImColor(4, 159, 232, 255));
	draww->AddLine(ImVec2(c + 57, u + 10), ImVec2(c + 57, u + 11), ImColor(6, 78, 114, 255));
	draww->AddLine(ImVec2(c + 58, u + 10), ImVec2(c + 60, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 60, u + 10), ImVec2(c + 60, u + 11), ImColor(8, 31, 46, 255));
	draww->AddLine(ImVec2(c + 61, u + 10), ImVec2(c + 61, u + 11), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 62, u + 10), ImVec2(c + 62, u + 11), ImColor(4, 148, 216, 255));
	draww->AddLine(ImVec2(c + 63, u + 10), ImVec2(c + 63, u + 11), ImColor(8, 23, 35, 255));
	draww->AddLine(ImVec2(c + 64, u + 10), ImVec2(c + 64, u + 11), ImColor(5, 120, 175, 255));
	draww->AddLine(ImVec2(c + 65, u + 10), ImVec2(c + 65, u + 11), ImColor(4, 148, 216, 255));
	draww->AddLine(ImVec2(c + 66, u + 10), ImVec2(c + 69, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 69, u + 10), ImVec2(c + 69, u + 11), ImColor(7, 45, 67, 255));
	draww->AddLine(ImVec2(c + 70, u + 10), ImVec2(c + 70, u + 11), ImColor(4, 162, 237, 255));
	draww->AddLine(ImVec2(c + 71, u + 10), ImVec2(c + 71, u + 11), ImColor(5, 130, 190, 255));
	draww->AddLine(ImVec2(c + 72, u + 10), ImVec2(c + 74, u + 10), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 74, u + 10), ImVec2(c + 74, u + 11), ImColor(5, 107, 157, 255));
	draww->AddLine(ImVec2(c + 75, u + 10), ImVec2(c + 75, u + 11), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 76, u + 10), ImVec2(c + 76, u + 11), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 77, u + 10), ImVec2(c + 77, u + 11), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 78, u + 10), ImVec2(c + 81, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 81, u + 10), ImVec2(c + 81, u + 11), ImColor(8, 33, 49, 255));
	draww->AddLine(ImVec2(c + 82, u + 10), ImVec2(c + 82, u + 11), ImColor(4, 137, 201, 255));
	draww->AddLine(ImVec2(c + 83, u + 10), ImVec2(c + 83, u + 11), ImColor(4, 145, 212, 255));
	draww->AddLine(ImVec2(c + 0, u + 11), ImVec2(c + 3, u + 11), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 11), ImVec2(c + 3, u + 12), ImColor(31, 35, 41, 255));
	draww->AddLine(ImVec2(c + 4, u + 11), ImVec2(c + 4, u + 12), ImColor(62, 137, 173, 255));
	draww->AddLine(ImVec2(c + 5, u + 11), ImVec2(c + 5, u + 12), ImColor(95, 152, 180, 255));
	draww->AddLine(ImVec2(c + 6, u + 11), ImVec2(c + 6, u + 12), ImColor(109, 151, 173, 255));
	draww->AddLine(ImVec2(c + 7, u + 11), ImVec2(c + 7, u + 12), ImColor(60, 152, 195, 255));
	draww->AddLine(ImVec2(c + 8, u + 11), ImVec2(c + 8, u + 12), ImColor(115, 153, 172, 255));
	draww->AddLine(ImVec2(c + 9, u + 11), ImVec2(c + 11, u + 11), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 11, u + 11), ImVec2(c + 11, u + 12), ImColor(118, 149, 165, 255));
	draww->AddLine(ImVec2(c + 12, u + 11), ImVec2(c + 12, u + 12), ImColor(21, 159, 223, 255));
	draww->AddLine(ImVec2(c + 13, u + 11), ImVec2(c + 13, u + 12), ImColor(9, 165, 237, 255));
	draww->AddLine(ImVec2(c + 14, u + 11), ImVec2(c + 14, u + 12), ImColor(7, 166, 241, 255));
	draww->AddLine(ImVec2(c + 15, u + 11), ImVec2(c + 15, u + 12), ImColor(50, 166, 221, 255));
	draww->AddLine(ImVec2(c + 16, u + 11), ImVec2(c + 16, u + 12), ImColor(132, 173, 193, 255));
	draww->AddLine(ImVec2(c + 17, u + 11), ImVec2(c + 17, u + 12), ImColor(153, 176, 189, 255));
	draww->AddLine(ImVec2(c + 18, u + 11), ImVec2(c + 18, u + 12), ImColor(152, 176, 189, 255));
	draww->AddLine(ImVec2(c + 19, u + 11), ImVec2(c + 19, u + 12), ImColor(127, 169, 191, 255));
	draww->AddLine(ImVec2(c + 20, u + 11), ImVec2(c + 20, u + 12), ImColor(55, 157, 206, 255));
	draww->AddLine(ImVec2(c + 21, u + 11), ImVec2(c + 21, u + 12), ImColor(145, 173, 188, 255));
	draww->AddLine(ImVec2(c + 22, u + 11), ImVec2(c + 22, u + 12), ImColor(89, 169, 207, 255));
	draww->AddLine(ImVec2(c + 23, u + 11), ImVec2(c + 23, u + 12), ImColor(102, 157, 184, 255));
	draww->AddLine(ImVec2(c + 24, u + 11), ImVec2(c + 24, u + 12), ImColor(13, 14, 19, 255));
	draww->AddLine(ImVec2(c + 25, u + 11), ImVec2(c + 27, u + 11), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 27, u + 11), ImVec2(c + 27, u + 12), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 28, u + 11), ImVec2(c + 28, u + 12), ImColor(6, 90, 132, 255));
	draww->AddLine(ImVec2(c + 29, u + 11), ImVec2(c + 29, u + 12), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 30, u + 11), ImVec2(c + 30, u + 12), ImColor(7, 55, 82, 255));
	draww->AddLine(ImVec2(c + 31, u + 11), ImVec2(c + 31, u + 12), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 32, u + 11), ImVec2(c + 32, u + 12), ImColor(8, 10, 16, 255));
	draww->AddLine(ImVec2(c + 33, u + 11), ImVec2(c + 33, u + 12), ImColor(5, 119, 174, 255));
	draww->AddLine(ImVec2(c + 34, u + 11), ImVec2(c + 34, u + 12), ImColor(4, 156, 227, 255));
	draww->AddLine(ImVec2(c + 35, u + 11), ImVec2(c + 35, u + 12), ImColor(7, 46, 69, 255));
	draww->AddLine(ImVec2(c + 36, u + 11), ImVec2(c + 36, u + 12), ImColor(7, 62, 92, 255));
	draww->AddLine(ImVec2(c + 37, u + 11), ImVec2(c + 37, u + 12), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 38, u + 11), ImVec2(c + 38, u + 12), ImColor(6, 90, 132, 255));
	draww->AddLine(ImVec2(c + 39, u + 11), ImVec2(c + 39, u + 12), ImColor(5, 105, 154, 255));
	draww->AddLine(ImVec2(c + 40, u + 11), ImVec2(c + 40, u + 12), ImColor(4, 164, 240, 255));
	draww->AddLine(ImVec2(c + 41, u + 11), ImVec2(c + 41, u + 12), ImColor(7, 51, 75, 255));
	draww->AddLine(ImVec2(c + 42, u + 11), ImVec2(c + 44, u + 11), ImColor(8, 13, 21, 255));
	draww->AddLine(ImVec2(c + 44, u + 11), ImVec2(c + 44, u + 12), ImColor(7, 45, 66, 255));
	draww->AddLine(ImVec2(c + 45, u + 11), ImVec2(c + 45, u + 12), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 46, u + 11), ImVec2(c + 46, u + 12), ImColor(6, 98, 144, 255));
	draww->AddLine(ImVec2(c + 47, u + 11), ImVec2(c + 47, u + 12), ImColor(8, 17, 26, 255));
	draww->AddLine(ImVec2(c + 48, u + 11), ImVec2(c + 48, u + 12), ImColor(4, 141, 205, 255));
	draww->AddLine(ImVec2(c + 49, u + 11), ImVec2(c + 49, u + 12), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 50, u + 11), ImVec2(c + 50, u + 12), ImColor(8, 31, 46, 255));
	draww->AddLine(ImVec2(c + 51, u + 11), ImVec2(c + 51, u + 12), ImColor(8, 38, 57, 255));
	draww->AddLine(ImVec2(c + 52, u + 11), ImVec2(c + 52, u + 12), ImColor(4, 149, 218, 255));
	draww->AddLine(ImVec2(c + 53, u + 11), ImVec2(c + 53, u + 12), ImColor(5, 125, 184, 255));
	draww->AddLine(ImVec2(c + 54, u + 11), ImVec2(c + 54, u + 12), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 55, u + 11), ImVec2(c + 55, u + 12), ImColor(6, 73, 107, 255));
	draww->AddLine(ImVec2(c + 56, u + 11), ImVec2(c + 56, u + 12), ImColor(4, 159, 232, 255));
	draww->AddLine(ImVec2(c + 57, u + 11), ImVec2(c + 57, u + 12), ImColor(6, 82, 121, 255));
	draww->AddLine(ImVec2(c + 58, u + 11), ImVec2(c + 60, u + 11), ImColor(8, 13, 21, 255));
	draww->AddLine(ImVec2(c + 60, u + 11), ImVec2(c + 60, u + 12), ImColor(8, 31, 46, 255));
	draww->AddLine(ImVec2(c + 61, u + 11), ImVec2(c + 61, u + 12), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 62, u + 11), ImVec2(c + 62, u + 12), ImColor(4, 148, 216, 255));
	draww->AddLine(ImVec2(c + 63, u + 11), ImVec2(c + 63, u + 12), ImColor(8, 36, 54, 255));
	draww->AddLine(ImVec2(c + 64, u + 11), ImVec2(c + 64, u + 12), ImColor(5, 129, 189, 255));
	draww->AddLine(ImVec2(c + 65, u + 11), ImVec2(c + 65, u + 12), ImColor(4, 148, 216, 255));
	draww->AddLine(ImVec2(c + 66, u + 11), ImVec2(c + 69, u + 11), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 69, u + 11), ImVec2(c + 69, u + 12), ImColor(7, 45, 67, 255));
	draww->AddLine(ImVec2(c + 70, u + 11), ImVec2(c + 70, u + 12), ImColor(4, 162, 237, 255));
	draww->AddLine(ImVec2(c + 71, u + 11), ImVec2(c + 71, u + 12), ImColor(6, 93, 136, 255));
	draww->AddLine(ImVec2(c + 72, u + 11), ImVec2(c + 72, u + 12), ImColor(6, 91, 134, 255));
	draww->AddLine(ImVec2(c + 73, u + 11), ImVec2(c + 73, u + 12), ImColor(4, 165, 241, 255));
	draww->AddLine(ImVec2(c + 74, u + 11), ImVec2(c + 74, u + 12), ImColor(5, 107, 157, 255));
	draww->AddLine(ImVec2(c + 75, u + 11), ImVec2(c + 75, u + 12), ImColor(6, 72, 106, 255));
	draww->AddLine(ImVec2(c + 76, u + 11), ImVec2(c + 76, u + 12), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 77, u + 11), ImVec2(c + 77, u + 12), ImColor(6, 74, 109, 255));
	draww->AddLine(ImVec2(c + 78, u + 11), ImVec2(c + 78, u + 12), ImColor(8, 13, 20, 255));
	draww->AddLine(ImVec2(c + 79, u + 11), ImVec2(c + 79, u + 12), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 80, u + 11), ImVec2(c + 80, u + 12), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 81, u + 11), ImVec2(c + 81, u + 12), ImColor(8, 33, 49, 255));
	draww->AddLine(ImVec2(c + 82, u + 11), ImVec2(c + 82, u + 12), ImColor(4, 137, 201, 255));
	draww->AddLine(ImVec2(c + 83, u + 11), ImVec2(c + 83, u + 12), ImColor(4, 145, 212, 255));
	draww->AddLine(ImVec2(c + 0, u + 12), ImVec2(c + 3, u + 12), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 12), ImVec2(c + 3, u + 13), ImColor(29, 32, 38, 255));
	draww->AddLine(ImVec2(c + 4, u + 12), ImVec2(c + 4, u + 13), ImColor(57, 128, 162, 255));
	draww->AddLine(ImVec2(c + 5, u + 12), ImVec2(c + 5, u + 13), ImColor(49, 149, 197, 255));
	draww->AddLine(ImVec2(c + 6, u + 12), ImVec2(c + 6, u + 13), ImColor(124, 152, 166, 255));
	draww->AddLine(ImVec2(c + 7, u + 12), ImVec2(c + 7, u + 13), ImColor(52, 157, 207, 255));
	draww->AddLine(ImVec2(c + 8, u + 12), ImVec2(c + 8, u + 13), ImColor(45, 160, 214, 255));
	draww->AddLine(ImVec2(c + 9, u + 12), ImVec2(c + 9, u + 13), ImColor(123, 152, 167, 255));
	draww->AddLine(ImVec2(c + 10, u + 12), ImVec2(c + 12, u + 12), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 12, u + 12), ImVec2(c + 12, u + 13), ImColor(101, 150, 175, 255));
	draww->AddLine(ImVec2(c + 13, u + 12), ImVec2(c + 13, u + 13), ImColor(29, 159, 220, 255));
	draww->AddLine(ImVec2(c + 14, u + 12), ImVec2(c + 14, u + 13), ImColor(39, 164, 224, 255));
	draww->AddLine(ImVec2(c + 15, u + 12), ImVec2(c + 15, u + 13), ImColor(132, 173, 194, 255));
	draww->AddLine(ImVec2(c + 16, u + 12), ImVec2(c + 18, u + 12), ImColor(153, 176, 189, 255));
	draww->AddLine(ImVec2(c + 18, u + 12), ImVec2(c + 18, u + 13), ImColor(128, 170, 192, 255));
	draww->AddLine(ImVec2(c + 19, u + 12), ImVec2(c + 19, u + 13), ImColor(46, 163, 218, 255));
	draww->AddLine(ImVec2(c + 20, u + 12), ImVec2(c + 20, u + 13), ImColor(64, 161, 207, 255));
	draww->AddLine(ImVec2(c + 21, u + 12), ImVec2(c + 21, u + 13), ImColor(140, 174, 193, 255));
	draww->AddLine(ImVec2(c + 22, u + 12), ImVec2(c + 22, u + 13), ImColor(55, 165, 217, 255));
	draww->AddLine(ImVec2(c + 23, u + 12), ImVec2(c + 23, u + 13), ImColor(91, 148, 176, 255));
	draww->AddLine(ImVec2(c + 24, u + 12), ImVec2(c + 24, u + 13), ImColor(10, 11, 16, 255));
	draww->AddLine(ImVec2(c + 25, u + 12), ImVec2(c + 27, u + 12), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 27, u + 12), ImVec2(c + 27, u + 13), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 28, u + 12), ImVec2(c + 28, u + 13), ImColor(6, 90, 132, 255));
	draww->AddLine(ImVec2(c + 29, u + 12), ImVec2(c + 29, u + 13), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 30, u + 12), ImVec2(c + 30, u + 13), ImColor(7, 55, 82, 255));
	draww->AddLine(ImVec2(c + 31, u + 12), ImVec2(c + 31, u + 13), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 32, u + 12), ImVec2(c + 32, u + 13), ImColor(8, 19, 30, 255));
	draww->AddLine(ImVec2(c + 33, u + 12), ImVec2(c + 33, u + 13), ImColor(4, 145, 212, 255));
	draww->AddLine(ImVec2(c + 34, u + 12), ImVec2(c + 34, u + 13), ImColor(4, 164, 239, 255));
	draww->AddLine(ImVec2(c + 35, u + 12), ImVec2(c + 35, u + 13), ImColor(5, 114, 167, 255));
	draww->AddLine(ImVec2(c + 36, u + 12), ImVec2(c + 36, u + 13), ImColor(5, 120, 176, 255));
	draww->AddLine(ImVec2(c + 37, u + 12), ImVec2(c + 37, u + 13), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 38, u + 12), ImVec2(c + 38, u + 13), ImColor(6, 95, 140, 255));
	draww->AddLine(ImVec2(c + 39, u + 12), ImVec2(c + 39, u + 13), ImColor(4, 139, 204, 255));
	draww->AddLine(ImVec2(c + 40, u + 12), ImVec2(c + 40, u + 13), ImColor(4, 166, 243, 255));
	draww->AddLine(ImVec2(c + 41, u + 12), ImVec2(c + 41, u + 13), ImColor(5, 115, 169, 255));
	draww->AddLine(ImVec2(c + 42, u + 12), ImVec2(c + 42, u + 13), ImColor(6, 99, 145, 255));
	draww->AddLine(ImVec2(c + 43, u + 12), ImVec2(c + 43, u + 13), ImColor(6, 85, 125, 255));
	draww->AddLine(ImVec2(c + 44, u + 12), ImVec2(c + 44, u + 13), ImColor(6, 98, 144, 255));
	draww->AddLine(ImVec2(c + 45, u + 12), ImVec2(c + 45, u + 13), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 46, u + 12), ImVec2(c + 46, u + 13), ImColor(4, 137, 200, 255));
	draww->AddLine(ImVec2(c + 47, u + 12), ImVec2(c + 47, u + 13), ImColor(6, 101, 148, 255));
	draww->AddLine(ImVec2(c + 48, u + 12), ImVec2(c + 48, u + 13), ImColor(4, 154, 225, 255));
	draww->AddLine(ImVec2(c + 49, u + 12), ImVec2(c + 49, u + 13), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 50, u + 12), ImVec2(c + 50, u + 13), ImColor(8, 31, 46, 255));
	draww->AddLine(ImVec2(c + 51, u + 12), ImVec2(c + 51, u + 13), ImColor(8, 38, 57, 255));
	draww->AddLine(ImVec2(c + 52, u + 12), ImVec2(c + 52, u + 13), ImColor(4, 149, 218, 255));
	draww->AddLine(ImVec2(c + 53, u + 12), ImVec2(c + 53, u + 13), ImColor(5, 125, 184, 255));
	draww->AddLine(ImVec2(c + 54, u + 12), ImVec2(c + 54, u + 13), ImColor(8, 19, 29, 255));
	draww->AddLine(ImVec2(c + 55, u + 12), ImVec2(c + 55, u + 13), ImColor(6, 100, 147, 255));
	draww->AddLine(ImVec2(c + 56, u + 12), ImVec2(c + 56, u + 13), ImColor(4, 163, 238, 255));
	draww->AddLine(ImVec2(c + 57, u + 12), ImVec2(c + 57, u + 13), ImColor(5, 131, 192, 255));
	draww->AddLine(ImVec2(c + 58, u + 12), ImVec2(c + 60, u + 12), ImColor(6, 99, 145, 255));
	draww->AddLine(ImVec2(c + 60, u + 12), ImVec2(c + 60, u + 13), ImColor(7, 51, 76, 255));
	draww->AddLine(ImVec2(c + 61, u + 12), ImVec2(c + 61, u + 13), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 62, u + 12), ImVec2(c + 62, u + 13), ImColor(4, 158, 231, 255));
	draww->AddLine(ImVec2(c + 63, u + 12), ImVec2(c + 63, u + 13), ImColor(5, 118, 173, 255));
	draww->AddLine(ImVec2(c + 64, u + 12), ImVec2(c + 64, u + 13), ImColor(4, 159, 232, 255));
	draww->AddLine(ImVec2(c + 65, u + 12), ImVec2(c + 65, u + 13), ImColor(5, 104, 152, 255));
	draww->AddLine(ImVec2(c + 66, u + 12), ImVec2(c + 69, u + 12), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 69, u + 12), ImVec2(c + 69, u + 13), ImColor(7, 45, 67, 255));
	draww->AddLine(ImVec2(c + 70, u + 12), ImVec2(c + 70, u + 13), ImColor(4, 162, 237, 255));
	draww->AddLine(ImVec2(c + 71, u + 12), ImVec2(c + 71, u + 13), ImColor(6, 93, 136, 255));
	draww->AddLine(ImVec2(c + 72, u + 12), ImVec2(c + 72, u + 13), ImColor(7, 41, 62, 255));
	draww->AddLine(ImVec2(c + 73, u + 12), ImVec2(c + 73, u + 13), ImColor(4, 155, 226, 255));
	draww->AddLine(ImVec2(c + 74, u + 12), ImVec2(c + 74, u + 13), ImColor(5, 107, 157, 255));
	draww->AddLine(ImVec2(c + 75, u + 12), ImVec2(c + 75, u + 13), ImColor(5, 115, 168, 255));
	draww->AddLine(ImVec2(c + 76, u + 12), ImVec2(c + 76, u + 13), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 77, u + 12), ImVec2(c + 77, u + 13), ImColor(5, 126, 184, 255));
	draww->AddLine(ImVec2(c + 78, u + 12), ImVec2(c + 78, u + 13), ImColor(6, 97, 143, 255));
	draww->AddLine(ImVec2(c + 79, u + 12), ImVec2(c + 79, u + 13), ImColor(6, 90, 132, 255));
	draww->AddLine(ImVec2(c + 80, u + 12), ImVec2(c + 80, u + 13), ImColor(8, 26, 40, 255));
	draww->AddLine(ImVec2(c + 81, u + 12), ImVec2(c + 81, u + 13), ImColor(8, 33, 49, 255));
	draww->AddLine(ImVec2(c + 82, u + 12), ImVec2(c + 82, u + 13), ImColor(4, 137, 201, 255));
	draww->AddLine(ImVec2(c + 83, u + 12), ImVec2(c + 83, u + 13), ImColor(4, 145, 212, 255));
	draww->AddLine(ImVec2(c + 0, u + 13), ImVec2(c + 3, u + 13), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 13), ImVec2(c + 3, u + 14), ImColor(18, 19, 25, 255));
	draww->AddLine(ImVec2(c + 4, u + 13), ImVec2(c + 4, u + 14), ImColor(61, 102, 123, 255));
	draww->AddLine(ImVec2(c + 5, u + 13), ImVec2(c + 5, u + 14), ImColor(24, 156, 217, 255));
	draww->AddLine(ImVec2(c + 6, u + 13), ImVec2(c + 6, u + 14), ImColor(128, 151, 164, 255));
	draww->AddLine(ImVec2(c + 7, u + 13), ImVec2(c + 7, u + 14), ImColor(98, 149, 174, 255));
	draww->AddLine(ImVec2(c + 8, u + 13), ImVec2(c + 8, u + 14), ImColor(46, 150, 199, 255));
	draww->AddLine(ImVec2(c + 9, u + 13), ImVec2(c + 9, u + 14), ImColor(81, 146, 177, 255));
	draww->AddLine(ImVec2(c + 10, u + 13), ImVec2(c + 10, u + 14), ImColor(127, 148, 160, 255));
	draww->AddLine(ImVec2(c + 11, u + 13), ImVec2(c + 13, u + 13), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 13, u + 13), ImVec2(c + 13, u + 14), ImColor(111, 155, 177, 255));
	draww->AddLine(ImVec2(c + 14, u + 13), ImVec2(c + 14, u + 14), ImColor(128, 170, 191, 255));
	draww->AddLine(ImVec2(c + 15, u + 13), ImVec2(c + 17, u + 13), ImColor(153, 176, 189, 255));
	draww->AddLine(ImVec2(c + 17, u + 13), ImVec2(c + 17, u + 14), ImColor(150, 172, 185, 255));
	draww->AddLine(ImVec2(c + 18, u + 13), ImVec2(c + 18, u + 14), ImColor(83, 155, 189, 255));
	draww->AddLine(ImVec2(c + 19, u + 13), ImVec2(c + 19, u + 14), ImColor(47, 153, 202, 255));
	draww->AddLine(ImVec2(c + 20, u + 13), ImVec2(c + 20, u + 14), ImColor(119, 166, 189, 255));
	draww->AddLine(ImVec2(c + 21, u + 13), ImVec2(c + 21, u + 14), ImColor(120, 172, 198, 255));
	draww->AddLine(ImVec2(c + 22, u + 13), ImVec2(c + 22, u + 14), ImColor(45, 162, 216, 255));
	draww->AddLine(ImVec2(c + 23, u + 13), ImVec2(c + 23, u + 14), ImColor(79, 115, 134, 255));
	draww->AddLine(ImVec2(c + 24, u + 13), ImVec2(c + 27, u + 13), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 27, u + 13), ImVec2(c + 27, u + 14), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 28, u + 13), ImVec2(c + 28, u + 14), ImColor(6, 90, 132, 255));
	draww->AddLine(ImVec2(c + 29, u + 13), ImVec2(c + 29, u + 14), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 30, u + 13), ImVec2(c + 30, u + 14), ImColor(7, 55, 82, 255));
	draww->AddLine(ImVec2(c + 31, u + 13), ImVec2(c + 31, u + 14), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 32, u + 13), ImVec2(c + 32, u + 14), ImColor(8, 11, 17, 255));
	draww->AddLine(ImVec2(c + 33, u + 13), ImVec2(c + 33, u + 14), ImColor(4, 152, 223, 255));
	draww->AddLine(ImVec2(c + 34, u + 13), ImVec2(c + 34, u + 14), ImColor(4, 162, 236, 255));
	draww->AddLine(ImVec2(c + 35, u + 13), ImVec2(c + 35, u + 14), ImColor(4, 139, 203, 255));
	draww->AddLine(ImVec2(c + 36, u + 13), ImVec2(c + 36, u + 14), ImColor(4, 149, 218, 255));
	draww->AddLine(ImVec2(c + 37, u + 13), ImVec2(c + 37, u + 14), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 38, u + 13), ImVec2(c + 38, u + 14), ImColor(6, 90, 132, 255));
	draww->AddLine(ImVec2(c + 39, u + 13), ImVec2(c + 39, u + 14), ImColor(4, 137, 201, 255));
	draww->AddLine(ImVec2(c + 40, u + 13), ImVec2(c + 40, u + 14), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 41, u + 13), ImVec2(c + 43, u + 13), ImColor(4, 139, 203, 255));
	draww->AddLine(ImVec2(c + 43, u + 13), ImVec2(c + 43, u + 14), ImColor(5, 124, 182, 255));
	draww->AddLine(ImVec2(c + 44, u + 13), ImVec2(c + 44, u + 14), ImColor(6, 97, 142, 255));
	draww->AddLine(ImVec2(c + 45, u + 13), ImVec2(c + 45, u + 14), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 46, u + 13), ImVec2(c + 46, u + 14), ImColor(4, 148, 216, 255));
	draww->AddLine(ImVec2(c + 47, u + 13), ImVec2(c + 47, u + 14), ImColor(4, 136, 198, 255));
	draww->AddLine(ImVec2(c + 48, u + 13), ImVec2(c + 48, u + 14), ImColor(4, 164, 240, 255));
	draww->AddLine(ImVec2(c + 49, u + 13), ImVec2(c + 49, u + 14), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 50, u + 13), ImVec2(c + 50, u + 14), ImColor(8, 31, 46, 255));
	draww->AddLine(ImVec2(c + 51, u + 13), ImVec2(c + 51, u + 14), ImColor(8, 38, 57, 255));
	draww->AddLine(ImVec2(c + 52, u + 13), ImVec2(c + 52, u + 14), ImColor(4, 149, 218, 255));
	draww->AddLine(ImVec2(c + 53, u + 13), ImVec2(c + 53, u + 14), ImColor(5, 125, 184, 255));
	draww->AddLine(ImVec2(c + 54, u + 13), ImVec2(c + 54, u + 14), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 55, u + 13), ImVec2(c + 55, u + 14), ImColor(6, 92, 134, 255));
	draww->AddLine(ImVec2(c + 56, u + 13), ImVec2(c + 56, u + 14), ImColor(4, 164, 240, 255));
	draww->AddLine(ImVec2(c + 57, u + 13), ImVec2(c + 57, u + 14), ImColor(4, 141, 206, 255));
	draww->AddLine(ImVec2(c + 58, u + 13), ImVec2(c + 58, u + 14), ImColor(4, 136, 199, 255));
	draww->AddLine(ImVec2(c + 59, u + 13), ImVec2(c + 59, u + 14), ImColor(4, 145, 212, 255));
	draww->AddLine(ImVec2(c + 60, u + 13), ImVec2(c + 60, u + 14), ImColor(6, 72, 105, 255));
	draww->AddLine(ImVec2(c + 61, u + 13), ImVec2(c + 61, u + 14), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 62, u + 13), ImVec2(c + 62, u + 14), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 63, u + 13), ImVec2(c + 63, u + 14), ImColor(4, 166, 242, 255));
	draww->AddLine(ImVec2(c + 64, u + 13), ImVec2(c + 64, u + 14), ImColor(4, 161, 235, 255));
	draww->AddLine(ImVec2(c + 65, u + 13), ImVec2(c + 65, u + 14), ImColor(7, 49, 73, 255));
	draww->AddLine(ImVec2(c + 66, u + 13), ImVec2(c + 69, u + 13), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 69, u + 13), ImVec2(c + 69, u + 14), ImColor(7, 46, 68, 255));
	draww->AddLine(ImVec2(c + 70, u + 13), ImVec2(c + 70, u + 14), ImColor(4, 164, 240, 255));
	draww->AddLine(ImVec2(c + 71, u + 13), ImVec2(c + 71, u + 14), ImColor(6, 93, 136, 255));
	draww->AddLine(ImVec2(c + 72, u + 13), ImVec2(c + 72, u + 14), ImColor(7, 40, 60, 255));
	draww->AddLine(ImVec2(c + 73, u + 13), ImVec2(c + 73, u + 14), ImColor(4, 152, 223, 255));
	draww->AddLine(ImVec2(c + 74, u + 13), ImVec2(c + 74, u + 14), ImColor(5, 107, 157, 255));
	draww->AddLine(ImVec2(c + 75, u + 13), ImVec2(c + 75, u + 14), ImColor(5, 112, 164, 255));
	draww->AddLine(ImVec2(c + 76, u + 13), ImVec2(c + 76, u + 14), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 77, u + 13), ImVec2(c + 77, u + 14), ImColor(4, 139, 204, 255));
	draww->AddLine(ImVec2(c + 78, u + 13), ImVec2(c + 78, u + 14), ImColor(4, 137, 201, 255));
	draww->AddLine(ImVec2(c + 79, u + 13), ImVec2(c + 79, u + 14), ImColor(5, 135, 197, 255));
	draww->AddLine(ImVec2(c + 80, u + 13), ImVec2(c + 80, u + 14), ImColor(8, 39, 58, 255));
	draww->AddLine(ImVec2(c + 81, u + 13), ImVec2(c + 81, u + 14), ImColor(8, 33, 49, 255));
	draww->AddLine(ImVec2(c + 82, u + 13), ImVec2(c + 82, u + 14), ImColor(4, 137, 201, 255));
	draww->AddLine(ImVec2(c + 83, u + 13), ImVec2(c + 83, u + 14), ImColor(4, 145, 212, 255));
	draww->AddLine(ImVec2(c + 0, u + 14), ImVec2(c + 4, u + 14), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 4, u + 14), ImVec2(c + 4, u + 15), ImColor(43, 49, 55, 255));
	draww->AddLine(ImVec2(c + 5, u + 14), ImVec2(c + 5, u + 15), ImColor(72, 128, 154, 255));
	draww->AddLine(ImVec2(c + 6, u + 14), ImVec2(c + 6, u + 15), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 7, u + 14), ImVec2(c + 7, u + 15), ImColor(124, 143, 154, 255));
	draww->AddLine(ImVec2(c + 8, u + 14), ImVec2(c + 8, u + 15), ImColor(93, 137, 159, 255));
	draww->AddLine(ImVec2(c + 9, u + 14), ImVec2(c + 9, u + 15), ImColor(85, 141, 168, 255));
	draww->AddLine(ImVec2(c + 10, u + 14), ImVec2(c + 10, u + 15), ImColor(82, 145, 175, 255));
	draww->AddLine(ImVec2(c + 11, u + 14), ImVec2(c + 11, u + 15), ImColor(123, 151, 166, 255));
	draww->AddLine(ImVec2(c + 12, u + 14), ImVec2(c + 12, u + 15), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 13, u + 14), ImVec2(c + 13, u + 15), ImColor(136, 157, 168, 255));
	draww->AddLine(ImVec2(c + 14, u + 14), ImVec2(c + 14, u + 15), ImColor(150, 172, 185, 255));
	draww->AddLine(ImVec2(c + 15, u + 14), ImVec2(c + 15, u + 15), ImColor(152, 176, 189, 255));
	draww->AddLine(ImVec2(c + 16, u + 14), ImVec2(c + 16, u + 15), ImColor(131, 170, 190, 255));
	draww->AddLine(ImVec2(c + 17, u + 14), ImVec2(c + 17, u + 15), ImColor(87, 158, 191, 255));
	draww->AddLine(ImVec2(c + 18, u + 14), ImVec2(c + 18, u + 15), ImColor(101, 154, 181, 255));
	draww->AddLine(ImVec2(c + 19, u + 14), ImVec2(c + 19, u + 15), ImColor(124, 158, 176, 255));
	draww->AddLine(ImVec2(c + 20, u + 14), ImVec2(c + 20, u + 15), ImColor(149, 171, 184, 255));
	draww->AddLine(ImVec2(c + 21, u + 14), ImVec2(c + 21, u + 15), ImColor(134, 168, 185, 255));
	draww->AddLine(ImVec2(c + 22, u + 14), ImVec2(c + 22, u + 15), ImColor(88, 135, 158, 255));
	draww->AddLine(ImVec2(c + 23, u + 14), ImVec2(c + 23, u + 15), ImColor(42, 50, 58, 255));
	draww->AddLine(ImVec2(c + 24, u + 14), ImVec2(c + 27, u + 14), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 27, u + 14), ImVec2(c + 27, u + 15), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 28, u + 14), ImVec2(c + 28, u + 15), ImColor(6, 88, 129, 255));
	draww->AddLine(ImVec2(c + 29, u + 14), ImVec2(c + 29, u + 15), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 30, u + 14), ImVec2(c + 30, u + 15), ImColor(6, 75, 110, 255));
	draww->AddLine(ImVec2(c + 31, u + 14), ImVec2(c + 31, u + 15), ImColor(8, 24, 36, 255));
	draww->AddLine(ImVec2(c + 32, u + 14), ImVec2(c + 32, u + 15), ImColor(8, 15, 23, 255));
	draww->AddLine(ImVec2(c + 33, u + 14), ImVec2(c + 33, u + 15), ImColor(5, 118, 173, 255));
	draww->AddLine(ImVec2(c + 34, u + 14), ImVec2(c + 34, u + 15), ImColor(4, 154, 225, 255));
	draww->AddLine(ImVec2(c + 35, u + 14), ImVec2(c + 35, u + 15), ImColor(7, 41, 61, 255));
	draww->AddLine(ImVec2(c + 36, u + 14), ImVec2(c + 36, u + 15), ImColor(7, 58, 86, 255));
	draww->AddLine(ImVec2(c + 37, u + 14), ImVec2(c + 37, u + 15), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 38, u + 14), ImVec2(c + 38, u + 15), ImColor(6, 88, 129, 255));
	draww->AddLine(ImVec2(c + 39, u + 14), ImVec2(c + 39, u + 15), ImColor(6, 103, 151, 255));
	draww->AddLine(ImVec2(c + 40, u + 14), ImVec2(c + 40, u + 15), ImColor(4, 164, 240, 255));
	draww->AddLine(ImVec2(c + 41, u + 14), ImVec2(c + 41, u + 15), ImColor(7, 58, 86, 255));
	draww->AddLine(ImVec2(c + 42, u + 14), ImVec2(c + 42, u + 15), ImColor(8, 22, 33, 255));
	draww->AddLine(ImVec2(c + 43, u + 14), ImVec2(c + 43, u + 15), ImColor(8, 20, 31, 255));
	draww->AddLine(ImVec2(c + 44, u + 14), ImVec2(c + 44, u + 15), ImColor(7, 40, 60, 255));
	draww->AddLine(ImVec2(c + 45, u + 14), ImVec2(c + 45, u + 15), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 46, u + 14), ImVec2(c + 46, u + 15), ImColor(6, 95, 139, 255));
	draww->AddLine(ImVec2(c + 47, u + 14), ImVec2(c + 47, u + 15), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 48, u + 14), ImVec2(c + 48, u + 15), ImColor(4, 141, 205, 255));
	draww->AddLine(ImVec2(c + 49, u + 14), ImVec2(c + 49, u + 15), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 50, u + 14), ImVec2(c + 50, u + 15), ImColor(8, 31, 46, 255));
	draww->AddLine(ImVec2(c + 51, u + 14), ImVec2(c + 51, u + 15), ImColor(8, 38, 57, 255));
	draww->AddLine(ImVec2(c + 52, u + 14), ImVec2(c + 52, u + 15), ImColor(4, 149, 218, 255));
	draww->AddLine(ImVec2(c + 53, u + 14), ImVec2(c + 53, u + 15), ImColor(5, 125, 184, 255));
	draww->AddLine(ImVec2(c + 54, u + 14), ImVec2(c + 54, u + 15), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 55, u + 14), ImVec2(c + 55, u + 15), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 56, u + 14), ImVec2(c + 56, u + 15), ImColor(4, 159, 232, 255));
	draww->AddLine(ImVec2(c + 57, u + 14), ImVec2(c + 57, u + 15), ImColor(6, 87, 127, 255));
	draww->AddLine(ImVec2(c + 58, u + 14), ImVec2(c + 58, u + 15), ImColor(8, 22, 33, 255));
	draww->AddLine(ImVec2(c + 59, u + 14), ImVec2(c + 59, u + 15), ImColor(8, 24, 37, 255));
	draww->AddLine(ImVec2(c + 60, u + 14), ImVec2(c + 60, u + 15), ImColor(8, 34, 52, 255));
	draww->AddLine(ImVec2(c + 61, u + 14), ImVec2(c + 61, u + 15), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 62, u + 14), ImVec2(c + 62, u + 15), ImColor(4, 157, 229, 255));
	draww->AddLine(ImVec2(c + 63, u + 14), ImVec2(c + 63, u + 15), ImColor(5, 117, 172, 255));
	draww->AddLine(ImVec2(c + 64, u + 14), ImVec2(c + 64, u + 15), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 65, u + 14), ImVec2(c + 65, u + 15), ImColor(6, 76, 112, 255));
	draww->AddLine(ImVec2(c + 66, u + 14), ImVec2(c + 66, u + 15), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 67, u + 14), ImVec2(c + 67, u + 15), ImColor(7, 40, 59, 255));
	draww->AddLine(ImVec2(c + 68, u + 14), ImVec2(c + 68, u + 15), ImColor(8, 26, 39, 255));
	draww->AddLine(ImVec2(c + 69, u + 14), ImVec2(c + 69, u + 15), ImColor(7, 46, 68, 255));
	draww->AddLine(ImVec2(c + 70, u + 14), ImVec2(c + 70, u + 15), ImColor(4, 164, 240, 255));
	draww->AddLine(ImVec2(c + 71, u + 14), ImVec2(c + 71, u + 15), ImColor(6, 93, 136, 255));
	draww->AddLine(ImVec2(c + 72, u + 14), ImVec2(c + 72, u + 15), ImColor(7, 40, 60, 255));
	draww->AddLine(ImVec2(c + 73, u + 14), ImVec2(c + 73, u + 15), ImColor(4, 152, 223, 255));
	draww->AddLine(ImVec2(c + 74, u + 14), ImVec2(c + 74, u + 15), ImColor(5, 107, 157, 255));
	draww->AddLine(ImVec2(c + 75, u + 14), ImVec2(c + 75, u + 15), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 76, u + 14), ImVec2(c + 76, u + 15), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 77, u + 14), ImVec2(c + 77, u + 15), ImColor(6, 80, 117, 255));
	draww->AddLine(ImVec2(c + 78, u + 14), ImVec2(c + 78, u + 15), ImColor(8, 21, 32, 255));
	draww->AddLine(ImVec2(c + 79, u + 14), ImVec2(c + 79, u + 15), ImColor(8, 22, 33, 255));
	draww->AddLine(ImVec2(c + 80, u + 14), ImVec2(c + 80, u + 15), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 81, u + 14), ImVec2(c + 81, u + 15), ImColor(8, 33, 49, 255));
	draww->AddLine(ImVec2(c + 82, u + 14), ImVec2(c + 82, u + 15), ImColor(4, 137, 201, 255));
	draww->AddLine(ImVec2(c + 83, u + 14), ImVec2(c + 83, u + 15), ImColor(4, 145, 212, 255));
	draww->AddLine(ImVec2(c + 0, u + 15), ImVec2(c + 4, u + 15), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 4, u + 15), ImVec2(c + 4, u + 16), ImColor(11, 11, 16, 255));
	draww->AddLine(ImVec2(c + 5, u + 15), ImVec2(c + 5, u + 16), ImColor(70, 80, 88, 255));
	draww->AddLine(ImVec2(c + 6, u + 15), ImVec2(c + 8, u + 15), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 8, u + 15), ImVec2(c + 8, u + 16), ImColor(76, 150, 185, 255));
	draww->AddLine(ImVec2(c + 9, u + 15), ImVec2(c + 9, u + 16), ImColor(41, 154, 208, 255));
	draww->AddLine(ImVec2(c + 10, u + 15), ImVec2(c + 10, u + 16), ImColor(49, 150, 197, 255));
	draww->AddLine(ImVec2(c + 11, u + 15), ImVec2(c + 11, u + 16), ImColor(76, 143, 176, 255));
	draww->AddLine(ImVec2(c + 12, u + 15), ImVec2(c + 12, u + 16), ImColor(124, 150, 164, 255));
	draww->AddLine(ImVec2(c + 13, u + 15), ImVec2(c + 13, u + 16), ImColor(136, 157, 168, 255));
	draww->AddLine(ImVec2(c + 14, u + 15), ImVec2(c + 14, u + 16), ImColor(150, 172, 185, 255));
	draww->AddLine(ImVec2(c + 15, u + 15), ImVec2(c + 15, u + 16), ImColor(139, 172, 189, 255));
	draww->AddLine(ImVec2(c + 16, u + 15), ImVec2(c + 16, u + 16), ImColor(99, 156, 185, 255));
	draww->AddLine(ImVec2(c + 17, u + 15), ImVec2(c + 17, u + 16), ImColor(57, 156, 203, 255));
	draww->AddLine(ImVec2(c + 18, u + 15), ImVec2(c + 18, u + 16), ImColor(45, 162, 216, 255));
	draww->AddLine(ImVec2(c + 19, u + 15), ImVec2(c + 19, u + 16), ImColor(93, 166, 202, 255));
	draww->AddLine(ImVec2(c + 20, u + 15), ImVec2(c + 20, u + 16), ImColor(149, 175, 189, 255));
	draww->AddLine(ImVec2(c + 21, u + 15), ImVec2(c + 21, u + 16), ImColor(143, 164, 177, 255));
	draww->AddLine(ImVec2(c + 22, u + 15), ImVec2(c + 22, u + 16), ImColor(73, 84, 92, 255));
	draww->AddLine(ImVec2(c + 23, u + 15), ImVec2(c + 23, u + 16), ImColor(15, 16, 22, 255));
	draww->AddLine(ImVec2(c + 24, u + 15), ImVec2(c + 28, u + 15), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 28, u + 15), ImVec2(c + 28, u + 16), ImColor(7, 56, 83, 255));
	draww->AddLine(ImVec2(c + 29, u + 15), ImVec2(c + 29, u + 16), ImColor(4, 157, 230, 255));
	draww->AddLine(ImVec2(c + 30, u + 15), ImVec2(c + 30, u + 16), ImColor(4, 150, 219, 255));
	draww->AddLine(ImVec2(c + 31, u + 15), ImVec2(c + 31, u + 16), ImColor(5, 126, 184, 255));
	draww->AddLine(ImVec2(c + 32, u + 15), ImVec2(c + 32, u + 16), ImColor(6, 80, 117, 255));
	draww->AddLine(ImVec2(c + 33, u + 15), ImVec2(c + 33, u + 16), ImColor(5, 118, 173, 255));
	draww->AddLine(ImVec2(c + 34, u + 15), ImVec2(c + 34, u + 16), ImColor(4, 154, 225, 255));
	draww->AddLine(ImVec2(c + 35, u + 15), ImVec2(c + 35, u + 16), ImColor(7, 41, 61, 255));
	draww->AddLine(ImVec2(c + 36, u + 15), ImVec2(c + 36, u + 16), ImColor(7, 58, 86, 255));
	draww->AddLine(ImVec2(c + 37, u + 15), ImVec2(c + 37, u + 16), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 38, u + 15), ImVec2(c + 38, u + 16), ImColor(6, 88, 129, 255));
	draww->AddLine(ImVec2(c + 39, u + 15), ImVec2(c + 39, u + 16), ImColor(6, 103, 151, 255));
	draww->AddLine(ImVec2(c + 40, u + 15), ImVec2(c + 40, u + 16), ImColor(4, 166, 243, 255));
	draww->AddLine(ImVec2(c + 41, u + 15), ImVec2(c + 41, u + 16), ImColor(5, 130, 191, 255));
	draww->AddLine(ImVec2(c + 42, u + 15), ImVec2(c + 42, u + 16), ImColor(5, 120, 176, 255));
	draww->AddLine(ImVec2(c + 43, u + 15), ImVec2(c + 43, u + 16), ImColor(5, 104, 153, 255));
	draww->AddLine(ImVec2(c + 44, u + 15), ImVec2(c + 44, u + 16), ImColor(7, 58, 85, 255));
	draww->AddLine(ImVec2(c + 45, u + 15), ImVec2(c + 45, u + 16), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 46, u + 15), ImVec2(c + 46, u + 16), ImColor(6, 95, 139, 255));
	draww->AddLine(ImVec2(c + 47, u + 15), ImVec2(c + 47, u + 16), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 48, u + 15), ImVec2(c + 48, u + 16), ImColor(4, 141, 205, 255));
	draww->AddLine(ImVec2(c + 49, u + 15), ImVec2(c + 49, u + 16), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 50, u + 15), ImVec2(c + 50, u + 16), ImColor(8, 31, 46, 255));
	draww->AddLine(ImVec2(c + 51, u + 15), ImVec2(c + 51, u + 16), ImColor(8, 38, 57, 255));
	draww->AddLine(ImVec2(c + 52, u + 15), ImVec2(c + 52, u + 16), ImColor(4, 149, 218, 255));
	draww->AddLine(ImVec2(c + 53, u + 15), ImVec2(c + 53, u + 16), ImColor(5, 125, 184, 255));
	draww->AddLine(ImVec2(c + 54, u + 15), ImVec2(c + 54, u + 16), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 55, u + 15), ImVec2(c + 55, u + 16), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 56, u + 15), ImVec2(c + 56, u + 16), ImColor(4, 159, 232, 255));
	draww->AddLine(ImVec2(c + 57, u + 15), ImVec2(c + 57, u + 16), ImColor(4, 141, 206, 255));
	draww->AddLine(ImVec2(c + 58, u + 15), ImVec2(c + 58, u + 16), ImColor(5, 119, 174, 255));
	draww->AddLine(ImVec2(c + 59, u + 15), ImVec2(c + 59, u + 16), ImColor(5, 126, 184, 255));
	draww->AddLine(ImVec2(c + 60, u + 15), ImVec2(c + 60, u + 16), ImColor(7, 60, 88, 255));
	draww->AddLine(ImVec2(c + 61, u + 15), ImVec2(c + 61, u + 16), ImColor(5, 134, 196, 255));
	draww->AddLine(ImVec2(c + 62, u + 15), ImVec2(c + 62, u + 16), ImColor(4, 148, 216, 255));
	draww->AddLine(ImVec2(c + 63, u + 15), ImVec2(c + 63, u + 16), ImColor(7, 48, 72, 255));
	draww->AddLine(ImVec2(c + 64, u + 15), ImVec2(c + 64, u + 16), ImColor(4, 162, 236, 255));
	draww->AddLine(ImVec2(c + 65, u + 15), ImVec2(c + 65, u + 16), ImColor(5, 115, 168, 255));
	draww->AddLine(ImVec2(c + 66, u + 15), ImVec2(c + 66, u + 16), ImColor(8, 27, 41, 255));
	draww->AddLine(ImVec2(c + 67, u + 15), ImVec2(c + 67, u + 16), ImColor(5, 123, 180, 255));
	draww->AddLine(ImVec2(c + 68, u + 15), ImVec2(c + 68, u + 16), ImColor(5, 107, 157, 255));
	draww->AddLine(ImVec2(c + 69, u + 15), ImVec2(c + 69, u + 16), ImColor(7, 46, 68, 255));
	draww->AddLine(ImVec2(c + 70, u + 15), ImVec2(c + 70, u + 16), ImColor(4, 164, 240, 255));
	draww->AddLine(ImVec2(c + 71, u + 15), ImVec2(c + 71, u + 16), ImColor(6, 93, 136, 255));
	draww->AddLine(ImVec2(c + 72, u + 15), ImVec2(c + 72, u + 16), ImColor(7, 40, 60, 255));
	draww->AddLine(ImVec2(c + 73, u + 15), ImVec2(c + 73, u + 16), ImColor(4, 152, 223, 255));
	draww->AddLine(ImVec2(c + 74, u + 15), ImVec2(c + 74, u + 16), ImColor(5, 107, 157, 255));
	draww->AddLine(ImVec2(c + 75, u + 15), ImVec2(c + 75, u + 16), ImColor(7, 70, 103, 255));
	draww->AddLine(ImVec2(c + 76, u + 15), ImVec2(c + 76, u + 16), ImColor(3, 168, 245, 255));
	draww->AddLine(ImVec2(c + 77, u + 15), ImVec2(c + 77, u + 16), ImColor(4, 137, 201, 255));
	draww->AddLine(ImVec2(c + 78, u + 15), ImVec2(c + 78, u + 16), ImColor(5, 117, 172, 255));
	draww->AddLine(ImVec2(c + 79, u + 15), ImVec2(c + 79, u + 16), ImColor(5, 114, 167, 255));
	draww->AddLine(ImVec2(c + 80, u + 15), ImVec2(c + 80, u + 16), ImColor(8, 31, 47, 255));
	draww->AddLine(ImVec2(c + 81, u + 15), ImVec2(c + 81, u + 16), ImColor(8, 33, 49, 255));
	draww->AddLine(ImVec2(c + 82, u + 15), ImVec2(c + 82, u + 16), ImColor(4, 137, 201, 255));
	draww->AddLine(ImVec2(c + 83, u + 15), ImVec2(c + 83, u + 16), ImColor(4, 145, 212, 255));
	draww->AddLine(ImVec2(c + 0, u + 16), ImVec2(c + 5, u + 16), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 5, u + 16), ImVec2(c + 5, u + 17), ImColor(39, 44, 50, 255));
	draww->AddLine(ImVec2(c + 6, u + 16), ImVec2(c + 8, u + 16), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 8, u + 16), ImVec2(c + 8, u + 17), ImColor(117, 140, 153, 255));
	draww->AddLine(ImVec2(c + 9, u + 16), ImVec2(c + 9, u + 17), ImColor(50, 69, 81, 255));
	draww->AddLine(ImVec2(c + 10, u + 16), ImVec2(c + 10, u + 17), ImColor(60, 73, 82, 255));
	draww->AddLine(ImVec2(c + 11, u + 16), ImVec2(c + 11, u + 17), ImColor(92, 119, 134, 255));
	draww->AddLine(ImVec2(c + 12, u + 16), ImVec2(c + 12, u + 17), ImColor(73, 148, 183, 255));
	draww->AddLine(ImVec2(c + 13, u + 16), ImVec2(c + 13, u + 17), ImColor(127, 156, 171, 255));
	draww->AddLine(ImVec2(c + 14, u + 16), ImVec2(c + 14, u + 17), ImColor(145, 172, 187, 255));
	draww->AddLine(ImVec2(c + 15, u + 16), ImVec2(c + 15, u + 17), ImColor(84, 157, 193, 255));
	draww->AddLine(ImVec2(c + 16, u + 16), ImVec2(c + 16, u + 17), ImColor(111, 139, 155, 255));
	draww->AddLine(ImVec2(c + 17, u + 16), ImVec2(c + 17, u + 17), ImColor(63, 76, 86, 255));
	draww->AddLine(ImVec2(c + 18, u + 16), ImVec2(c + 18, u + 17), ImColor(73, 97, 111, 255));
	draww->AddLine(ImVec2(c + 19, u + 16), ImVec2(c + 19, u + 17), ImColor(134, 160, 174, 255));
	draww->AddLine(ImVec2(c + 20, u + 16), ImVec2(c + 20, u + 17), ImColor(153, 176, 189, 255));
	draww->AddLine(ImVec2(c + 21, u + 16), ImVec2(c + 21, u + 17), ImColor(134, 154, 166, 255));
	draww->AddLine(ImVec2(c + 22, u + 16), ImVec2(c + 22, u + 17), ImColor(44, 50, 56, 255));
	draww->AddLine(ImVec2(c + 23, u + 16), ImVec2(c + 28, u + 16), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 28, u + 16), ImVec2(c + 28, u + 17), ImColor(8, 16, 25, 255));
	draww->AddLine(ImVec2(c + 29, u + 16), ImVec2(c + 29, u + 17), ImColor(7, 65, 96, 255));
	draww->AddLine(ImVec2(c + 30, u + 16), ImVec2(c + 30, u + 17), ImColor(5, 104, 153, 255));
	draww->AddLine(ImVec2(c + 31, u + 16), ImVec2(c + 31, u + 17), ImColor(5, 109, 159, 255));
	draww->AddLine(ImVec2(c + 32, u + 16), ImVec2(c + 32, u + 17), ImColor(6, 75, 110, 255));
	draww->AddLine(ImVec2(c + 33, u + 16), ImVec2(c + 33, u + 17), ImColor(6, 77, 113, 255));
	draww->AddLine(ImVec2(c + 34, u + 16), ImVec2(c + 34, u + 17), ImColor(6, 100, 146, 255));
	draww->AddLine(ImVec2(c + 35, u + 16), ImVec2(c + 35, u + 17), ImColor(8, 28, 42, 255));
	draww->AddLine(ImVec2(c + 36, u + 16), ImVec2(c + 36, u + 17), ImColor(7, 40, 60, 255));
	draww->AddLine(ImVec2(c + 37, u + 16), ImVec2(c + 37, u + 17), ImColor(5, 109, 159, 255));
	draww->AddLine(ImVec2(c + 38, u + 16), ImVec2(c + 38, u + 17), ImColor(7, 60, 89, 255));
	draww->AddLine(ImVec2(c + 39, u + 16), ImVec2(c + 39, u + 17), ImColor(7, 63, 93, 255));
	draww->AddLine(ImVec2(c + 40, u + 16), ImVec2(c + 40, u + 17), ImColor(5, 104, 153, 255));
	draww->AddLine(ImVec2(c + 41, u + 16), ImVec2(c + 43, u + 16), ImColor(6, 102, 149, 255));
	draww->AddLine(ImVec2(c + 43, u + 16), ImVec2(c + 43, u + 17), ImColor(6, 85, 124, 255));
	draww->AddLine(ImVec2(c + 44, u + 16), ImVec2(c + 44, u + 17), ImColor(7, 41, 62, 255));
	draww->AddLine(ImVec2(c + 45, u + 16), ImVec2(c + 45, u + 17), ImColor(5, 109, 159, 255));
	draww->AddLine(ImVec2(c + 46, u + 16), ImVec2(c + 46, u + 17), ImColor(7, 60, 88, 255));
	draww->AddLine(ImVec2(c + 47, u + 16), ImVec2(c + 47, u + 17), ImColor(8, 9, 15, 255));
	draww->AddLine(ImVec2(c + 48, u + 16), ImVec2(c + 48, u + 17), ImColor(6, 91, 134, 255));
	draww->AddLine(ImVec2(c + 49, u + 16), ImVec2(c + 49, u + 17), ImColor(6, 88, 130, 255));
	draww->AddLine(ImVec2(c + 50, u + 16), ImVec2(c + 50, u + 17), ImColor(8, 23, 34, 255));
	draww->AddLine(ImVec2(c + 51, u + 16), ImVec2(c + 51, u + 17), ImColor(8, 26, 39, 255));
	draww->AddLine(ImVec2(c + 52, u + 16), ImVec2(c + 52, u + 17), ImColor(6, 98, 144, 255));
	draww->AddLine(ImVec2(c + 53, u + 16), ImVec2(c + 53, u + 17), ImColor(6, 83, 122, 255));
	draww->AddLine(ImVec2(c + 54, u + 16), ImVec2(c + 54, u + 17), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 55, u + 16), ImVec2(c + 55, u + 17), ImColor(7, 49, 73, 255));
	draww->AddLine(ImVec2(c + 56, u + 16), ImVec2(c + 56, u + 17), ImColor(6, 101, 148, 255));
	draww->AddLine(ImVec2(c + 57, u + 16), ImVec2(c + 60, u + 16), ImColor(6, 102, 149, 255));
	draww->AddLine(ImVec2(c + 60, u + 16), ImVec2(c + 60, u + 17), ImColor(7, 46, 69, 255));
	draww->AddLine(ImVec2(c + 61, u + 16), ImVec2(c + 61, u + 17), ImColor(6, 89, 131, 255));
	draww->AddLine(ImVec2(c + 62, u + 16), ImVec2(c + 62, u + 17), ImColor(6, 97, 142, 255));
	draww->AddLine(ImVec2(c + 63, u + 16), ImVec2(c + 63, u + 17), ImColor(8, 23, 34, 255));
	draww->AddLine(ImVec2(c + 64, u + 16), ImVec2(c + 66, u + 16), ImColor(6, 91, 134, 255));
	draww->AddLine(ImVec2(c + 66, u + 16), ImVec2(c + 66, u + 17), ImColor(8, 13, 21, 255));
	draww->AddLine(ImVec2(c + 67, u + 16), ImVec2(c + 67, u + 17), ImColor(7, 67, 99, 255));
	draww->AddLine(ImVec2(c + 68, u + 16), ImVec2(c + 68, u + 17), ImColor(7, 58, 86, 255));
	draww->AddLine(ImVec2(c + 69, u + 16), ImVec2(c + 69, u + 17), ImColor(8, 31, 46, 255));
	draww->AddLine(ImVec2(c + 70, u + 16), ImVec2(c + 70, u + 17), ImColor(5, 108, 158, 255));
	draww->AddLine(ImVec2(c + 71, u + 16), ImVec2(c + 71, u + 17), ImColor(7, 61, 91, 255));
	draww->AddLine(ImVec2(c + 72, u + 16), ImVec2(c + 72, u + 17), ImColor(8, 27, 41, 255));
	draww->AddLine(ImVec2(c + 73, u + 16), ImVec2(c + 73, u + 17), ImColor(6, 98, 144, 255));
	draww->AddLine(ImVec2(c + 74, u + 16), ImVec2(c + 74, u + 17), ImColor(7, 71, 104, 255));
	draww->AddLine(ImVec2(c + 75, u + 16), ImVec2(c + 75, u + 17), ImColor(7, 43, 64, 255));
	draww->AddLine(ImVec2(c + 76, u + 16), ImVec2(c + 76, u + 17), ImColor(6, 103, 151, 255));
	draww->AddLine(ImVec2(c + 77, u + 16), ImVec2(c + 79, u + 16), ImColor(6, 99, 145, 255));
	draww->AddLine(ImVec2(c + 79, u + 16), ImVec2(c + 79, u + 17), ImColor(6, 92, 135, 255));
	draww->AddLine(ImVec2(c + 80, u + 16), ImVec2(c + 80, u + 17), ImColor(8, 26, 39, 255));
	draww->AddLine(ImVec2(c + 81, u + 16), ImVec2(c + 81, u + 17), ImColor(8, 21, 33, 255));
	draww->AddLine(ImVec2(c + 82, u + 16), ImVec2(c + 82, u + 17), ImColor(6, 87, 128, 255));
	draww->AddLine(ImVec2(c + 83, u + 16), ImVec2(c + 83, u + 17), ImColor(6, 93, 137, 255));
	draww->AddLine(ImVec2(c + 0, u + 17), ImVec2(c + 6, u + 17), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 6, u + 17), ImVec2(c + 6, u + 18), ImColor(72, 83, 91, 255));
	draww->AddLine(ImVec2(c + 7, u + 17), ImVec2(c + 7, u + 18), ImColor(129, 148, 159, 255));
	draww->AddLine(ImVec2(c + 8, u + 17), ImVec2(c + 8, u + 18), ImColor(132, 152, 163, 255));
	draww->AddLine(ImVec2(c + 9, u + 17), ImVec2(c + 9, u + 18), ImColor(34, 39, 44, 255));
	draww->AddLine(ImVec2(c + 10, u + 17), ImVec2(c + 10, u + 18), ImColor(11, 12, 17, 255));
	draww->AddLine(ImVec2(c + 11, u + 17), ImVec2(c + 11, u + 18), ImColor(96, 111, 119, 255));
	draww->AddLine(ImVec2(c + 12, u + 17), ImVec2(c + 12, u + 18), ImColor(80, 136, 163, 255));
	draww->AddLine(ImVec2(c + 13, u + 17), ImVec2(c + 13, u + 18), ImColor(57, 155, 201, 255));
	draww->AddLine(ImVec2(c + 14, u + 17), ImVec2(c + 14, u + 18), ImColor(61, 157, 203, 255));
	draww->AddLine(ImVec2(c + 15, u + 17), ImVec2(c + 15, u + 18), ImColor(109, 157, 181, 255));
	draww->AddLine(ImVec2(c + 16, u + 17), ImVec2(c + 16, u + 18), ImColor(90, 104, 113, 255));
	draww->AddLine(ImVec2(c + 17, u + 17), ImVec2(c + 17, u + 18), ImColor(20, 22, 27, 255));
	draww->AddLine(ImVec2(c + 18, u + 17), ImVec2(c + 18, u + 18), ImColor(60, 69, 76, 255));
	draww->AddLine(ImVec2(c + 19, u + 17), ImVec2(c + 19, u + 18), ImColor(148, 170, 182, 255));
	draww->AddLine(ImVec2(c + 20, u + 17), ImVec2(c + 20, u + 18), ImColor(146, 169, 181, 255));
	draww->AddLine(ImVec2(c + 21, u + 17), ImVec2(c + 21, u + 18), ImColor(64, 72, 80, 255));
	draww->AddLine(ImVec2(c + 22, u + 17), ImVec2(c + 22, u + 18), ImColor(12, 12, 17, 255));
	draww->AddLine(ImVec2(c + 23, u + 17), ImVec2(c + 30, u + 17), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 30, u + 17), ImVec2(c + 33, u + 17), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 33, u + 17), ImVec2(c + 33, u + 18), ImColor(8, 10, 16, 255));
	draww->AddLine(ImVec2(c + 34, u + 17), ImVec2(c + 34, u + 18), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 35, u + 17), ImVec2(c + 35, u + 18), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 36, u + 17), ImVec2(c + 36, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 37, u + 17), ImVec2(c + 39, u + 17), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 39, u + 17), ImVec2(c + 39, u + 18), ImColor(8, 9, 15, 255));
	draww->AddLine(ImVec2(c + 40, u + 17), ImVec2(c + 40, u + 18), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 41, u + 17), ImVec2(c + 44, u + 17), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 44, u + 17), ImVec2(c + 44, u + 18), ImColor(8, 10, 16, 255));
	draww->AddLine(ImVec2(c + 45, u + 17), ImVec2(c + 47, u + 17), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 47, u + 17), ImVec2(c + 47, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 48, u + 17), ImVec2(c + 48, u + 18), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 49, u + 17), ImVec2(c + 49, u + 18), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 50, u + 17), ImVec2(c + 50, u + 18), ImColor(8, 11, 17, 255));
	draww->AddLine(ImVec2(c + 51, u + 17), ImVec2(c + 51, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 52, u + 17), ImVec2(c + 52, u + 18), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 53, u + 17), ImVec2(c + 53, u + 18), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 54, u + 17), ImVec2(c + 56, u + 17), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 56, u + 17), ImVec2(c + 60, u + 17), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 60, u + 17), ImVec2(c + 60, u + 18), ImColor(8, 9, 14, 255));
	draww->AddLine(ImVec2(c + 61, u + 17), ImVec2(c + 61, u + 18), ImColor(8, 10, 16, 255));
	draww->AddLine(ImVec2(c + 62, u + 17), ImVec2(c + 62, u + 18), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 63, u + 17), ImVec2(c + 63, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 64, u + 17), ImVec2(c + 64, u + 18), ImColor(8, 10, 16, 255));
	draww->AddLine(ImVec2(c + 65, u + 17), ImVec2(c + 65, u + 18), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 66, u + 17), ImVec2(c + 68, u + 17), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 68, u + 17), ImVec2(c + 68, u + 18), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 69, u + 17), ImVec2(c + 69, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 70, u + 17), ImVec2(c + 72, u + 17), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 72, u + 17), ImVec2(c + 72, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 73, u + 17), ImVec2(c + 73, u + 18), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 74, u + 17), ImVec2(c + 74, u + 18), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 75, u + 17), ImVec2(c + 75, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 76, u + 17), ImVec2(c + 76, u + 18), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 77, u + 17), ImVec2(c + 80, u + 17), ImColor(8, 11, 18, 255));
	draww->AddLine(ImVec2(c + 80, u + 17), ImVec2(c + 80, u + 18), ImColor(8, 11, 17, 255));
	draww->AddLine(ImVec2(c + 81, u + 17), ImVec2(c + 81, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 82, u + 17), ImVec2(c + 82, u + 18), ImColor(8, 10, 16, 255));
	draww->AddLine(ImVec2(c + 83, u + 17), ImVec2(c + 83, u + 18), ImColor(8, 12, 19, 255));
	draww->AddLine(ImVec2(c + 0, u + 18), ImVec2(c + 6, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 6, u + 18), ImVec2(c + 6, u + 19), ImColor(17, 19, 24, 255));
	draww->AddLine(ImVec2(c + 7, u + 18), ImVec2(c + 7, u + 19), ImColor(89, 102, 111, 255));
	draww->AddLine(ImVec2(c + 8, u + 18), ImVec2(c + 8, u + 19), ImColor(130, 150, 161, 255));
	draww->AddLine(ImVec2(c + 9, u + 18), ImVec2(c + 9, u + 19), ImColor(75, 86, 94, 255));
	draww->AddLine(ImVec2(c + 10, u + 18), ImVec2(c + 10, u + 19), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 11, u + 18), ImVec2(c + 11, u + 19), ImColor(50, 57, 64, 255));
	draww->AddLine(ImVec2(c + 12, u + 18), ImVec2(c + 12, u + 19), ImColor(125, 150, 164, 255));
	draww->AddLine(ImVec2(c + 13, u + 18), ImVec2(c + 13, u + 19), ImColor(64, 151, 192, 255));
	draww->AddLine(ImVec2(c + 14, u + 18), ImVec2(c + 14, u + 19), ImColor(76, 163, 204, 255));
	draww->AddLine(ImVec2(c + 15, u + 18), ImVec2(c + 15, u + 19), ImColor(138, 160, 172, 255));
	draww->AddLine(ImVec2(c + 16, u + 18), ImVec2(c + 16, u + 19), ImColor(59, 67, 75, 255));
	draww->AddLine(ImVec2(c + 17, u + 18), ImVec2(c + 17, u + 19), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 18, u + 18), ImVec2(c + 18, u + 19), ImColor(105, 121, 131, 255));
	draww->AddLine(ImVec2(c + 19, u + 18), ImVec2(c + 19, u + 19), ImColor(148, 171, 184, 255));
	draww->AddLine(ImVec2(c + 20, u + 18), ImVec2(c + 20, u + 19), ImColor(95, 109, 119, 255));
	draww->AddLine(ImVec2(c + 21, u + 18), ImVec2(c + 21, u + 19), ImColor(12, 13, 18, 255));
	draww->AddLine(ImVec2(c + 0, u + 19), ImVec2(c + 7, u + 19), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 7, u + 19), ImVec2(c + 7, u + 20), ImColor(28, 32, 38, 255));
	draww->AddLine(ImVec2(c + 8, u + 19), ImVec2(c + 8, u + 20), ImColor(102, 117, 126, 255));
	draww->AddLine(ImVec2(c + 9, u + 19), ImVec2(c + 9, u + 20), ImColor(107, 123, 132, 255));
	draww->AddLine(ImVec2(c + 10, u + 19), ImVec2(c + 10, u + 20), ImColor(22, 24, 30, 255));
	draww->AddLine(ImVec2(c + 11, u + 19), ImVec2(c + 11, u + 20), ImColor(17, 18, 23, 255));
	draww->AddLine(ImVec2(c + 12, u + 19), ImVec2(c + 12, u + 20), ImColor(124, 143, 154, 255));
	draww->AddLine(ImVec2(c + 13, u + 19), ImVec2(c + 13, u + 20), ImColor(124, 153, 168, 255));
	draww->AddLine(ImVec2(c + 14, u + 19), ImVec2(c + 14, u + 20), ImColor(143, 170, 185, 255));
	draww->AddLine(ImVec2(c + 15, u + 19), ImVec2(c + 15, u + 20), ImColor(122, 140, 151, 255));
	draww->AddLine(ImVec2(c + 16, u + 19), ImVec2(c + 16, u + 20), ImColor(26, 30, 36, 255));
	draww->AddLine(ImVec2(c + 17, u + 19), ImVec2(c + 17, u + 20), ImColor(19, 21, 27, 255));
	draww->AddLine(ImVec2(c + 18, u + 19), ImVec2(c + 18, u + 20), ImColor(140, 160, 173, 255));
	draww->AddLine(ImVec2(c + 19, u + 19), ImVec2(c + 19, u + 20), ImColor(109, 125, 136, 255));
	draww->AddLine(ImVec2(c + 20, u + 19), ImVec2(c + 20, u + 20), ImColor(24, 26, 32, 255));
	draww->AddLine(ImVec2(c + 0, u + 20), ImVec2(c + 8, u + 20), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 8, u + 20), ImVec2(c + 8, u + 21), ImColor(26, 29, 35, 255));
	draww->AddLine(ImVec2(c + 9, u + 20), ImVec2(c + 9, u + 21), ImColor(121, 140, 151, 255));
	draww->AddLine(ImVec2(c + 10, u + 20), ImVec2(c + 10, u + 21), ImColor(57, 65, 72, 255));
	draww->AddLine(ImVec2(c + 11, u + 20), ImVec2(c + 11, u + 21), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 12, u + 20), ImVec2(c + 12, u + 21), ImColor(91, 105, 114, 255));
	draww->AddLine(ImVec2(c + 13, u + 20), ImVec2(c + 13, u + 21), ImColor(136, 157, 168, 255));
	draww->AddLine(ImVec2(c + 14, u + 20), ImVec2(c + 14, u + 21), ImColor(150, 172, 185, 255));
	draww->AddLine(ImVec2(c + 15, u + 20), ImVec2(c + 15, u + 21), ImColor(83, 95, 104, 255));
	draww->AddLine(ImVec2(c + 16, u + 20), ImVec2(c + 16, u + 21), ImColor(9, 10, 15, 255));
	draww->AddLine(ImVec2(c + 17, u + 20), ImVec2(c + 17, u + 21), ImColor(73, 84, 92, 255));
	draww->AddLine(ImVec2(c + 18, u + 20), ImVec2(c + 18, u + 21), ImColor(121, 139, 149, 255));
	draww->AddLine(ImVec2(c + 19, u + 20), ImVec2(c + 19, u + 21), ImColor(37, 42, 49, 255));
	draww->AddLine(ImVec2(c + 20, u + 20), ImVec2(c + 20, u + 21), ImColor(9, 9, 15, 255));
	draww->AddLine(ImVec2(c + 0, u + 21), ImVec2(c + 9, u + 21), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 9, u + 21), ImVec2(c + 9, u + 22), ImColor(48, 55, 61, 255));
	draww->AddLine(ImVec2(c + 10, u + 21), ImVec2(c + 10, u + 22), ImColor(78, 90, 98, 255));
	draww->AddLine(ImVec2(c + 11, u + 21), ImVec2(c + 11, u + 22), ImColor(14, 15, 21, 255));
	draww->AddLine(ImVec2(c + 12, u + 21), ImVec2(c + 12, u + 22), ImColor(37, 42, 48, 255));
	draww->AddLine(ImVec2(c + 13, u + 21), ImVec2(c + 13, u + 22), ImColor(130, 149, 161, 255));
	draww->AddLine(ImVec2(c + 14, u + 21), ImVec2(c + 14, u + 22), ImColor(145, 167, 179, 255));
	draww->AddLine(ImVec2(c + 15, u + 21), ImVec2(c + 15, u + 22), ImColor(30, 34, 40, 255));
	draww->AddLine(ImVec2(c + 16, u + 21), ImVec2(c + 16, u + 22), ImColor(18, 20, 26, 255));
	draww->AddLine(ImVec2(c + 17, u + 21), ImVec2(c + 17, u + 22), ImColor(101, 115, 125, 255));
	draww->AddLine(ImVec2(c + 18, u + 21), ImVec2(c + 18, u + 22), ImColor(49, 56, 63, 255));
	draww->AddLine(ImVec2(c + 0, u + 22), ImVec2(c + 9, u + 22), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 9, u + 22), ImVec2(c + 9, u + 23), ImColor(11, 12, 17, 255));
	draww->AddLine(ImVec2(c + 10, u + 22), ImVec2(c + 10, u + 23), ImColor(59, 67, 75, 255));
	draww->AddLine(ImVec2(c + 11, u + 22), ImVec2(c + 11, u + 23), ImColor(25, 28, 34, 255));
	draww->AddLine(ImVec2(c + 12, u + 22), ImVec2(c + 12, u + 23), ImColor(20, 22, 28, 255));
	draww->AddLine(ImVec2(c + 13, u + 22), ImVec2(c + 13, u + 23), ImColor(105, 121, 130, 255));
	draww->AddLine(ImVec2(c + 14, u + 22), ImVec2(c + 14, u + 23), ImColor(114, 130, 141, 255));
	draww->AddLine(ImVec2(c + 15, u + 22), ImVec2(c + 15, u + 23), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 16, u + 22), ImVec2(c + 16, u + 23), ImColor(37, 42, 49, 255));
	draww->AddLine(ImVec2(c + 17, u + 22), ImVec2(c + 17, u + 23), ImColor(54, 61, 69, 255));
	draww->AddLine(ImVec2(c + 0, u + 23), ImVec2(c + 10, u + 23), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 10, u + 23), ImVec2(c + 10, u + 24), ImColor(13, 14, 19, 255));
	draww->AddLine(ImVec2(c + 11, u + 23), ImVec2(c + 11, u + 24), ImColor(16, 18, 23, 255));
	draww->AddLine(ImVec2(c + 12, u + 23), ImVec2(c + 12, u + 24), ImColor(9, 9, 14, 255));
	draww->AddLine(ImVec2(c + 13, u + 23), ImVec2(c + 13, u + 24), ImColor(73, 84, 92, 255));
	draww->AddLine(ImVec2(c + 14, u + 23), ImVec2(c + 14, u + 24), ImColor(64, 73, 80, 255));
	draww->AddLine(ImVec2(c + 15, u + 23), ImVec2(c + 15, u + 24), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 16, u + 23), ImVec2(c + 16, u + 24), ImColor(17, 19, 24, 255));
	draww->AddLine(ImVec2(c + 17, u + 23), ImVec2(c + 17, u + 24), ImColor(16, 17, 22, 255));
	draww->AddLine(ImVec2(c + 0, u + 24), ImVec2(c + 13, u + 24), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 24), ImVec2(c + 13, u + 25), ImColor(20, 22, 28, 255));
	draww->AddLine(ImVec2(c + 14, u + 24), ImVec2(c + 14, u + 25), ImColor(15, 16, 22, 255));
}
void anba(int c, int u) {
	draww->AddLine(ImVec2(c + 0, u + 0), ImVec2(c + 6, u + 0), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 6, u + 0), ImVec2(c + 6, u + 1), ImColor(8, 17, 28, 255));
	draww->AddLine(ImVec2(c + 7, u + 0), ImVec2(c + 7, u + 1), ImColor(28, 48, 61, 255));
	draww->AddLine(ImVec2(c + 8, u + 0), ImVec2(c + 8, u + 1), ImColor(53, 68, 79, 255));
	draww->AddLine(ImVec2(c + 9, u + 0), ImVec2(c + 9, u + 1), ImColor(16, 24, 35, 255));
	draww->AddLine(ImVec2(c + 10, u + 0), ImVec2(c + 14, u + 0), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 14, u + 0), ImVec2(c + 14, u + 1), ImColor(26, 47, 60, 255));
	draww->AddLine(ImVec2(c + 15, u + 0), ImVec2(c + 15, u + 1), ImColor(49, 61, 72, 255));
	draww->AddLine(ImVec2(c + 16, u + 0), ImVec2(c + 16, u + 1), ImColor(11, 19, 30, 255));
	draww->AddLine(ImVec2(c + 17, u + 0), ImVec2(c + 20, u + 0), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 20, u + 0), ImVec2(c + 20, u + 1), ImColor(15, 32, 44, 255));
	draww->AddLine(ImVec2(c + 21, u + 0), ImVec2(c + 21, u + 1), ImColor(50, 67, 78, 255));
	draww->AddLine(ImVec2(c + 22, u + 0), ImVec2(c + 22, u + 1), ImColor(18, 26, 36, 255));
	draww->AddLine(ImVec2(c + 23, u + 0), ImVec2(c + 35, u + 0), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 0), ImVec2(c + 35, u + 1), ImColor(9, 21, 32, 255));
	draww->AddLine(ImVec2(c + 36, u + 0), ImVec2(c + 36, u + 1), ImColor(42, 64, 77, 255));
	draww->AddLine(ImVec2(c + 37, u + 0), ImVec2(c + 40, u + 0), ImColor(59, 78, 90, 255));
	draww->AddLine(ImVec2(c + 40, u + 0), ImVec2(c + 40, u + 1), ImColor(53, 69, 79, 255));
	draww->AddLine(ImVec2(c + 41, u + 0), ImVec2(c + 41, u + 1), ImColor(20, 28, 39, 255));
	draww->AddLine(ImVec2(c + 42, u + 0), ImVec2(c + 48, u + 0), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 48, u + 0), ImVec2(c + 48, u + 1), ImColor(16, 32, 45, 255));
	draww->AddLine(ImVec2(c + 49, u + 0), ImVec2(c + 49, u + 1), ImColor(52, 72, 84, 255));
	draww->AddLine(ImVec2(c + 50, u + 0), ImVec2(c + 50, u + 1), ImColor(31, 40, 50, 255));
	draww->AddLine(ImVec2(c + 0, u + 1), ImVec2(c + 6, u + 1), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 6, u + 1), ImVec2(c + 6, u + 2), ImColor(22, 49, 63, 255));
	draww->AddLine(ImVec2(c + 7, u + 1), ImVec2(c + 7, u + 2), ImColor(156, 197, 210, 255));
	draww->AddLine(ImVec2(c + 8, u + 1), ImVec2(c + 8, u + 2), ImColor(206, 225, 231, 255));
	draww->AddLine(ImVec2(c + 9, u + 1), ImVec2(c + 9, u + 2), ImColor(116, 124, 131, 255));
	draww->AddLine(ImVec2(c + 10, u + 1), ImVec2(c + 10, u + 2), ImColor(9, 17, 28, 255));
	draww->AddLine(ImVec2(c + 11, u + 1), ImVec2(c + 13, u + 1), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 1), ImVec2(c + 13, u + 2), ImColor(9, 20, 32, 255));
	draww->AddLine(ImVec2(c + 14, u + 1), ImVec2(c + 14, u + 2), ImColor(96, 150, 167, 255));
	draww->AddLine(ImVec2(c + 15, u + 1), ImVec2(c + 15, u + 2), ImColor(206, 222, 227, 255));
	draww->AddLine(ImVec2(c + 16, u + 1), ImVec2(c + 16, u + 2), ImColor(87, 97, 105, 255));
	draww->AddLine(ImVec2(c + 17, u + 1), ImVec2(c + 17, u + 2), ImColor(10, 18, 28, 255));
	draww->AddLine(ImVec2(c + 18, u + 1), ImVec2(c + 20, u + 1), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 20, u + 1), ImVec2(c + 20, u + 2), ImColor(52, 100, 117, 255));
	draww->AddLine(ImVec2(c + 21, u + 1), ImVec2(c + 21, u + 2), ImColor(196, 217, 224, 255));
	draww->AddLine(ImVec2(c + 22, u + 1), ImVec2(c + 22, u + 2), ImColor(68, 75, 83, 255));
	draww->AddLine(ImVec2(c + 23, u + 1), ImVec2(c + 35, u + 1), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 1), ImVec2(c + 35, u + 2), ImColor(17, 45, 59, 255));
	draww->AddLine(ImVec2(c + 36, u + 1), ImVec2(c + 36, u + 2), ImColor(161, 203, 214, 255));
	draww->AddLine(ImVec2(c + 37, u + 1), ImVec2(c + 37, u + 2), ImColor(204, 226, 232, 255));
	draww->AddLine(ImVec2(c + 38, u + 1), ImVec2(c + 40, u + 1), ImColor(192, 218, 226, 255));
	draww->AddLine(ImVec2(c + 40, u + 1), ImVec2(c + 40, u + 2), ImColor(191, 217, 225, 255));
	draww->AddLine(ImVec2(c + 41, u + 1), ImVec2(c + 41, u + 2), ImColor(182, 207, 214, 255));
	draww->AddLine(ImVec2(c + 42, u + 1), ImVec2(c + 42, u + 2), ImColor(140, 158, 166, 255));
	draww->AddLine(ImVec2(c + 43, u + 1), ImVec2(c + 43, u + 2), ImColor(29, 37, 47, 255));
	draww->AddLine(ImVec2(c + 44, u + 1), ImVec2(c + 47, u + 1), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 47, u + 1), ImVec2(c + 47, u + 2), ImColor(10, 23, 34, 255));
	draww->AddLine(ImVec2(c + 48, u + 1), ImVec2(c + 48, u + 2), ImColor(98, 149, 166, 255));
	draww->AddLine(ImVec2(c + 49, u + 1), ImVec2(c + 49, u + 2), ImColor(206, 227, 233, 255));
	draww->AddLine(ImVec2(c + 50, u + 1), ImVec2(c + 50, u + 2), ImColor(171, 183, 188, 255));
	draww->AddLine(ImVec2(c + 51, u + 1), ImVec2(c + 51, u + 2), ImColor(23, 30, 41, 255));
	draww->AddLine(ImVec2(c + 0, u + 2), ImVec2(c + 5, u + 2), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 5, u + 2), ImVec2(c + 5, u + 3), ImColor(8, 17, 28, 255));
	draww->AddLine(ImVec2(c + 6, u + 2), ImVec2(c + 6, u + 3), ImColor(59, 110, 128, 255));
	draww->AddLine(ImVec2(c + 7, u + 2), ImVec2(c + 7, u + 3), ImColor(212, 232, 239, 255));
	draww->AddLine(ImVec2(c + 8, u + 2), ImVec2(c + 8, u + 3), ImColor(192, 221, 229, 255));
	draww->AddLine(ImVec2(c + 9, u + 2), ImVec2(c + 9, u + 3), ImColor(191, 201, 205, 255));
	draww->AddLine(ImVec2(c + 10, u + 2), ImVec2(c + 10, u + 3), ImColor(24, 32, 42, 255));
	draww->AddLine(ImVec2(c + 11, u + 2), ImVec2(c + 13, u + 2), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 2), ImVec2(c + 13, u + 3), ImColor(10, 21, 33, 255));
	draww->AddLine(ImVec2(c + 14, u + 2), ImVec2(c + 14, u + 3), ImColor(108, 166, 182, 255));
	draww->AddLine(ImVec2(c + 15, u + 2), ImVec2(c + 15, u + 3), ImColor(233, 245, 248, 255));
	draww->AddLine(ImVec2(c + 16, u + 2), ImVec2(c + 16, u + 3), ImColor(193, 204, 209, 255));
	draww->AddLine(ImVec2(c + 17, u + 2), ImVec2(c + 17, u + 3), ImColor(40, 48, 58, 255));
	draww->AddLine(ImVec2(c + 18, u + 2), ImVec2(c + 20, u + 2), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 20, u + 2), ImVec2(c + 20, u + 3), ImColor(59, 112, 130, 255));
	draww->AddLine(ImVec2(c + 21, u + 2), ImVec2(c + 21, u + 3), ImColor(220, 236, 241, 255));
	draww->AddLine(ImVec2(c + 22, u + 2), ImVec2(c + 22, u + 3), ImColor(77, 84, 92, 255));
	draww->AddLine(ImVec2(c + 23, u + 2), ImVec2(c + 35, u + 2), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 2), ImVec2(c + 35, u + 3), ImColor(19, 49, 64, 255));
	draww->AddLine(ImVec2(c + 36, u + 2), ImVec2(c + 36, u + 3), ImColor(180, 219, 230, 255));
	draww->AddLine(ImVec2(c + 37, u + 2), ImVec2(c + 37, u + 3), ImColor(168, 178, 183, 255));
	draww->AddLine(ImVec2(c + 38, u + 2), ImVec2(c + 38, u + 3), ImColor(34, 49, 61, 255));
	draww->AddLine(ImVec2(c + 39, u + 2), ImVec2(c + 39, u + 3), ImColor(34, 50, 61, 255));
	draww->AddLine(ImVec2(c + 40, u + 2), ImVec2(c + 40, u + 3), ImColor(48, 74, 87, 255));
	draww->AddLine(ImVec2(c + 41, u + 2), ImVec2(c + 41, u + 3), ImColor(111, 156, 170, 255));
	draww->AddLine(ImVec2(c + 42, u + 2), ImVec2(c + 42, u + 3), ImColor(209, 230, 235, 255));
	draww->AddLine(ImVec2(c + 43, u + 2), ImVec2(c + 43, u + 3), ImColor(95, 103, 111, 255));
	draww->AddLine(ImVec2(c + 44, u + 2), ImVec2(c + 47, u + 2), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 47, u + 2), ImVec2(c + 47, u + 3), ImColor(23, 53, 68, 255));
	draww->AddLine(ImVec2(c + 48, u + 2), ImVec2(c + 48, u + 3), ImColor(172, 212, 223, 255));
	draww->AddLine(ImVec2(c + 49, u + 2), ImVec2(c + 49, u + 3), ImColor(197, 222, 229, 255));
	draww->AddLine(ImVec2(c + 50, u + 2), ImVec2(c + 50, u + 3), ImColor(216, 231, 235, 255));
	draww->AddLine(ImVec2(c + 51, u + 2), ImVec2(c + 51, u + 3), ImColor(70, 77, 86, 255));
	draww->AddLine(ImVec2(c + 0, u + 3), ImVec2(c + 5, u + 3), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 5, u + 3), ImVec2(c + 5, u + 4), ImColor(12, 28, 41, 255));
	draww->AddLine(ImVec2(c + 6, u + 3), ImVec2(c + 6, u + 4), ImColor(125, 179, 194, 255));
	draww->AddLine(ImVec2(c + 7, u + 3), ImVec2(c + 7, u + 4), ImColor(202, 211, 215, 255));
	draww->AddLine(ImVec2(c + 8, u + 3), ImVec2(c + 8, u + 4), ImColor(89, 139, 154, 255));
	draww->AddLine(ImVec2(c + 9, u + 3), ImVec2(c + 9, u + 4), ImColor(217, 233, 238, 255));
	draww->AddLine(ImVec2(c + 10, u + 3), ImVec2(c + 10, u + 4), ImColor(76, 83, 92, 255));
	draww->AddLine(ImVec2(c + 11, u + 3), ImVec2(c + 13, u + 3), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 3), ImVec2(c + 13, u + 4), ImColor(10, 21, 33, 255));
	draww->AddLine(ImVec2(c + 14, u + 3), ImVec2(c + 14, u + 4), ImColor(108, 166, 182, 255));
	draww->AddLine(ImVec2(c + 15, u + 3), ImVec2(c + 15, u + 4), ImColor(226, 239, 243, 255));
	draww->AddLine(ImVec2(c + 16, u + 3), ImVec2(c + 16, u + 4), ImColor(212, 232, 238, 255));
	draww->AddLine(ImVec2(c + 17, u + 3), ImVec2(c + 17, u + 4), ImColor(138, 148, 155, 255));
	draww->AddLine(ImVec2(c + 18, u + 3), ImVec2(c + 18, u + 4), ImColor(15, 22, 33, 255));
	draww->AddLine(ImVec2(c + 19, u + 3), ImVec2(c + 19, u + 4), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 20, u + 3), ImVec2(c + 20, u + 4), ImColor(59, 112, 130, 255));
	draww->AddLine(ImVec2(c + 21, u + 3), ImVec2(c + 21, u + 4), ImColor(220, 236, 241, 255));
	draww->AddLine(ImVec2(c + 22, u + 3), ImVec2(c + 22, u + 4), ImColor(77, 84, 92, 255));
	draww->AddLine(ImVec2(c + 23, u + 3), ImVec2(c + 26, u + 3), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 26, u + 3), ImVec2(c + 26, u + 4), ImColor(9, 19, 31, 255));
	draww->AddLine(ImVec2(c + 27, u + 3), ImVec2(c + 27, u + 4), ImColor(18, 46, 61, 255));
	draww->AddLine(ImVec2(c + 28, u + 3), ImVec2(c + 28, u + 4), ImColor(20, 53, 68, 255));
	draww->AddLine(ImVec2(c + 29, u + 3), ImVec2(c + 29, u + 4), ImColor(11, 24, 36, 255));
	draww->AddLine(ImVec2(c + 30, u + 3), ImVec2(c + 35, u + 3), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 3), ImVec2(c + 35, u + 4), ImColor(19, 49, 64, 255));
	draww->AddLine(ImVec2(c + 36, u + 3), ImVec2(c + 36, u + 4), ImColor(180, 219, 230, 255));
	draww->AddLine(ImVec2(c + 37, u + 3), ImVec2(c + 37, u + 4), ImColor(160, 166, 171, 255));
	draww->AddLine(ImVec2(c + 38, u + 3), ImVec2(c + 41, u + 3), ImColor(8, 16, 27, 255));
	draww->AddLine(ImVec2(c + 41, u + 3), ImVec2(c + 41, u + 4), ImColor(25, 60, 75, 255));
	draww->AddLine(ImVec2(c + 42, u + 3), ImVec2(c + 42, u + 4), ImColor(187, 223, 233, 255));
	draww->AddLine(ImVec2(c + 43, u + 3), ImVec2(c + 43, u + 4), ImColor(160, 167, 172, 255));
	draww->AddLine(ImVec2(c + 44, u + 3), ImVec2(c + 44, u + 4), ImColor(10, 18, 29, 255));
	draww->AddLine(ImVec2(c + 45, u + 3), ImVec2(c + 45, u + 4), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 46, u + 3), ImVec2(c + 46, u + 4), ImColor(8, 17, 28, 255));
	draww->AddLine(ImVec2(c + 47, u + 3), ImVec2(c + 47, u + 4), ImColor(62, 114, 132, 255));
	draww->AddLine(ImVec2(c + 48, u + 3), ImVec2(c + 48, u + 4), ImColor(213, 231, 236, 255));
	draww->AddLine(ImVec2(c + 49, u + 3), ImVec2(c + 49, u + 4), ImColor(98, 128, 140, 255));
	draww->AddLine(ImVec2(c + 50, u + 3), ImVec2(c + 50, u + 4), ImColor(182, 219, 229, 255));
	draww->AddLine(ImVec2(c + 51, u + 3), ImVec2(c + 51, u + 4), ImColor(146, 154, 159, 255));
	draww->AddLine(ImVec2(c + 52, u + 3), ImVec2(c + 52, u + 4), ImColor(10, 18, 29, 255));
	draww->AddLine(ImVec2(c + 0, u + 4), ImVec2(c + 5, u + 4), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 5, u + 4), ImVec2(c + 5, u + 5), ImColor(33, 71, 87, 255));
	draww->AddLine(ImVec2(c + 6, u + 4), ImVec2(c + 6, u + 5), ImColor(189, 222, 232, 255));
	draww->AddLine(ImVec2(c + 7, u + 4), ImVec2(c + 7, u + 5), ImColor(137, 145, 151, 255));
	draww->AddLine(ImVec2(c + 8, u + 4), ImVec2(c + 8, u + 5), ImColor(28, 60, 75, 255));
	draww->AddLine(ImVec2(c + 9, u + 4), ImVec2(c + 9, u + 5), ImColor(178, 217, 227, 255));
	draww->AddLine(ImVec2(c + 10, u + 4), ImVec2(c + 10, u + 5), ImColor(152, 160, 166, 255));
	draww->AddLine(ImVec2(c + 11, u + 4), ImVec2(c + 11, u + 5), ImColor(12, 20, 31, 255));
	draww->AddLine(ImVec2(c + 12, u + 4), ImVec2(c + 12, u + 5), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 4), ImVec2(c + 13, u + 5), ImColor(10, 21, 33, 255));
	draww->AddLine(ImVec2(c + 14, u + 4), ImVec2(c + 14, u + 5), ImColor(108, 166, 182, 255));
	draww->AddLine(ImVec2(c + 15, u + 4), ImVec2(c + 15, u + 5), ImColor(213, 224, 227, 255));
	draww->AddLine(ImVec2(c + 16, u + 4), ImVec2(c + 16, u + 5), ImColor(125, 171, 185, 255));
	draww->AddLine(ImVec2(c + 17, u + 4), ImVec2(c + 17, u + 5), ImColor(210, 226, 231, 255));
	draww->AddLine(ImVec2(c + 18, u + 4), ImVec2(c + 18, u + 5), ImColor(80, 88, 96, 255));
	draww->AddLine(ImVec2(c + 19, u + 4), ImVec2(c + 19, u + 5), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 20, u + 4), ImVec2(c + 20, u + 5), ImColor(59, 112, 130, 255));
	draww->AddLine(ImVec2(c + 21, u + 4), ImVec2(c + 21, u + 5), ImColor(220, 236, 241, 255));
	draww->AddLine(ImVec2(c + 22, u + 4), ImVec2(c + 22, u + 5), ImColor(77, 84, 92, 255));
	draww->AddLine(ImVec2(c + 23, u + 4), ImVec2(c + 26, u + 4), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 26, u + 4), ImVec2(c + 26, u + 5), ImColor(32, 88, 107, 255));
	draww->AddLine(ImVec2(c + 27, u + 4), ImVec2(c + 27, u + 5), ImColor(44, 122, 146, 255));
	draww->AddLine(ImVec2(c + 28, u + 4), ImVec2(c + 28, u + 5), ImColor(38, 105, 127, 255));
	draww->AddLine(ImVec2(c + 29, u + 4), ImVec2(c + 29, u + 5), ImColor(43, 121, 144, 255));
	draww->AddLine(ImVec2(c + 30, u + 4), ImVec2(c + 30, u + 5), ImColor(8, 17, 28, 255));
	draww->AddLine(ImVec2(c + 31, u + 4), ImVec2(c + 35, u + 4), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 4), ImVec2(c + 35, u + 5), ImColor(19, 49, 64, 255));
	draww->AddLine(ImVec2(c + 36, u + 4), ImVec2(c + 36, u + 5), ImColor(180, 219, 230, 255));
	draww->AddLine(ImVec2(c + 37, u + 4), ImVec2(c + 37, u + 5), ImColor(166, 175, 180, 255));
	draww->AddLine(ImVec2(c + 38, u + 4), ImVec2(c + 38, u + 5), ImColor(27, 41, 51, 255));
	draww->AddLine(ImVec2(c + 39, u + 4), ImVec2(c + 39, u + 5), ImColor(27, 41, 52, 255));
	draww->AddLine(ImVec2(c + 40, u + 4), ImVec2(c + 40, u + 5), ImColor(38, 60, 73, 255));
	draww->AddLine(ImVec2(c + 41, u + 4), ImVec2(c + 41, u + 5), ImColor(91, 136, 151, 255));
	draww->AddLine(ImVec2(c + 42, u + 4), ImVec2(c + 42, u + 5), ImColor(210, 232, 239, 255));
	draww->AddLine(ImVec2(c + 43, u + 4), ImVec2(c + 43, u + 5), ImColor(124, 132, 139, 255));
	draww->AddLine(ImVec2(c + 44, u + 4), ImVec2(c + 44, u + 5), ImColor(9, 17, 28, 255));
	draww->AddLine(ImVec2(c + 45, u + 4), ImVec2(c + 45, u + 5), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 46, u + 4), ImVec2(c + 46, u + 5), ImColor(13, 30, 43, 255));
	draww->AddLine(ImVec2(c + 47, u + 4), ImVec2(c + 47, u + 5), ImColor(132, 184, 199, 255));
	draww->AddLine(ImVec2(c + 48, u + 4), ImVec2(c + 48, u + 5), ImColor(195, 205, 209, 255));
	draww->AddLine(ImVec2(c + 49, u + 4), ImVec2(c + 49, u + 5), ImColor(30, 44, 55, 255));
	draww->AddLine(ImVec2(c + 50, u + 4), ImVec2(c + 50, u + 5), ImColor(115, 170, 186, 255));
	draww->AddLine(ImVec2(c + 51, u + 4), ImVec2(c + 51, u + 5), ImColor(204, 214, 218, 255));
	draww->AddLine(ImVec2(c + 52, u + 4), ImVec2(c + 52, u + 5), ImColor(35, 42, 52, 255));
	draww->AddLine(ImVec2(c + 0, u + 5), ImVec2(c + 4, u + 5), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 4, u + 5), ImVec2(c + 4, u + 6), ImColor(9, 18, 29, 255));
	draww->AddLine(ImVec2(c + 5, u + 5), ImVec2(c + 5, u + 6), ImColor(82, 137, 155, 255));
	draww->AddLine(ImVec2(c + 6, u + 5), ImVec2(c + 6, u + 6), ImColor(215, 230, 234, 255));
	draww->AddLine(ImVec2(c + 7, u + 5), ImVec2(c + 7, u + 6), ImColor(61, 69, 77, 255));
	draww->AddLine(ImVec2(c + 8, u + 5), ImVec2(c + 8, u + 6), ImColor(11, 24, 35, 255));
	draww->AddLine(ImVec2(c + 9, u + 5), ImVec2(c + 9, u + 6), ImColor(110, 165, 182, 255));
	draww->AddLine(ImVec2(c + 10, u + 5), ImVec2(c + 10, u + 6), ImColor(208, 219, 223, 255));
	draww->AddLine(ImVec2(c + 11, u + 5), ImVec2(c + 11, u + 6), ImColor(39, 46, 55, 255));
	draww->AddLine(ImVec2(c + 12, u + 5), ImVec2(c + 12, u + 6), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 5), ImVec2(c + 13, u + 6), ImColor(10, 21, 33, 255));
	draww->AddLine(ImVec2(c + 14, u + 5), ImVec2(c + 14, u + 6), ImColor(108, 166, 182, 255));
	draww->AddLine(ImVec2(c + 15, u + 5), ImVec2(c + 15, u + 6), ImColor(211, 220, 223, 255));
	draww->AddLine(ImVec2(c + 16, u + 5), ImVec2(c + 16, u + 6), ImColor(49, 75, 89, 255));
	draww->AddLine(ImVec2(c + 17, u + 5), ImVec2(c + 17, u + 6), ImColor(158, 202, 214, 255));
	draww->AddLine(ImVec2(c + 18, u + 5), ImVec2(c + 18, u + 6), ImColor(189, 200, 204, 255));
	draww->AddLine(ImVec2(c + 19, u + 5), ImVec2(c + 19, u + 6), ImColor(31, 39, 49, 255));
	draww->AddLine(ImVec2(c + 20, u + 5), ImVec2(c + 20, u + 6), ImColor(59, 112, 130, 255));
	draww->AddLine(ImVec2(c + 21, u + 5), ImVec2(c + 21, u + 6), ImColor(220, 236, 241, 255));
	draww->AddLine(ImVec2(c + 22, u + 5), ImVec2(c + 22, u + 6), ImColor(77, 84, 92, 255));
	draww->AddLine(ImVec2(c + 23, u + 5), ImVec2(c + 26, u + 5), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 26, u + 5), ImVec2(c + 26, u + 6), ImColor(45, 127, 151, 255));
	draww->AddLine(ImVec2(c + 27, u + 5), ImVec2(c + 27, u + 6), ImColor(20, 52, 67, 255));
	draww->AddLine(ImVec2(c + 28, u + 5), ImVec2(c + 28, u + 6), ImColor(12, 29, 42, 255));
	draww->AddLine(ImVec2(c + 29, u + 5), ImVec2(c + 29, u + 6), ImColor(49, 140, 166, 255));
	draww->AddLine(ImVec2(c + 30, u + 5), ImVec2(c + 30, u + 6), ImColor(9, 20, 32, 255));
	draww->AddLine(ImVec2(c + 31, u + 5), ImVec2(c + 35, u + 5), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 5), ImVec2(c + 35, u + 6), ImColor(19, 49, 64, 255));
	draww->AddLine(ImVec2(c + 36, u + 5), ImVec2(c + 36, u + 6), ImColor(180, 220, 230, 255));
	draww->AddLine(ImVec2(c + 37, u + 5), ImVec2(c + 37, u + 6), ImColor(216, 230, 235, 255));
	draww->AddLine(ImVec2(c + 38, u + 5), ImVec2(c + 38, u + 6), ImColor(181, 203, 210, 255));
	draww->AddLine(ImVec2(c + 39, u + 5), ImVec2(c + 39, u + 6), ImColor(181, 204, 211, 255));
	draww->AddLine(ImVec2(c + 40, u + 5), ImVec2(c + 40, u + 6), ImColor(187, 211, 218, 255));
	draww->AddLine(ImVec2(c + 41, u + 5), ImVec2(c + 41, u + 6), ImColor(209, 231, 237, 255));
	draww->AddLine(ImVec2(c + 42, u + 5), ImVec2(c + 42, u + 6), ImColor(189, 200, 204, 255));
	draww->AddLine(ImVec2(c + 43, u + 5), ImVec2(c + 43, u + 6), ImColor(37, 45, 55, 255));
	draww->AddLine(ImVec2(c + 44, u + 5), ImVec2(c + 46, u + 5), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 46, u + 5), ImVec2(c + 46, u + 6), ImColor(35, 75, 91, 255));
	draww->AddLine(ImVec2(c + 47, u + 5), ImVec2(c + 47, u + 6), ImColor(194, 225, 233, 255));
	draww->AddLine(ImVec2(c + 48, u + 5), ImVec2(c + 48, u + 6), ImColor(129, 137, 143, 255));
	draww->AddLine(ImVec2(c + 49, u + 5), ImVec2(c + 49, u + 6), ImColor(9, 18, 28, 255));
	draww->AddLine(ImVec2(c + 50, u + 5), ImVec2(c + 50, u + 6), ImColor(52, 100, 118, 255));
	draww->AddLine(ImVec2(c + 51, u + 5), ImVec2(c + 51, u + 6), ImColor(208, 231, 237, 255));
	draww->AddLine(ImVec2(c + 52, u + 5), ImVec2(c + 52, u + 6), ImColor(98, 105, 113, 255));
	draww->AddLine(ImVec2(c + 0, u + 6), ImVec2(c + 4, u + 6), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 4, u + 6), ImVec2(c + 4, u + 7), ImColor(17, 40, 54, 255));
	draww->AddLine(ImVec2(c + 5, u + 6), ImVec2(c + 5, u + 7), ImColor(152, 199, 213, 255));
	draww->AddLine(ImVec2(c + 6, u + 6), ImVec2(c + 6, u + 7), ImColor(183, 193, 197, 255));
	draww->AddLine(ImVec2(c + 7, u + 6), ImVec2(c + 7, u + 7), ImColor(25, 36, 47, 255));
	draww->AddLine(ImVec2(c + 8, u + 6), ImVec2(c + 8, u + 7), ImColor(17, 28, 39, 255));
	draww->AddLine(ImVec2(c + 9, u + 6), ImVec2(c + 9, u + 7), ImColor(56, 103, 120, 255));
	draww->AddLine(ImVec2(c + 10, u + 6), ImVec2(c + 10, u + 7), ImColor(208, 231, 237, 255));
	draww->AddLine(ImVec2(c + 11, u + 6), ImVec2(c + 11, u + 7), ImColor(105, 113, 120, 255));
	draww->AddLine(ImVec2(c + 12, u + 6), ImVec2(c + 12, u + 7), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 6), ImVec2(c + 13, u + 7), ImColor(10, 21, 33, 255));
	draww->AddLine(ImVec2(c + 14, u + 6), ImVec2(c + 14, u + 7), ImColor(108, 166, 182, 255));
	draww->AddLine(ImVec2(c + 15, u + 6), ImVec2(c + 15, u + 7), ImColor(211, 220, 223, 255));
	draww->AddLine(ImVec2(c + 16, u + 6), ImVec2(c + 16, u + 7), ImColor(32, 41, 52, 255));
	draww->AddLine(ImVec2(c + 17, u + 6), ImVec2(c + 17, u + 7), ImColor(59, 105, 122, 255));
	draww->AddLine(ImVec2(c + 18, u + 6), ImVec2(c + 18, u + 7), ImColor(199, 225, 233, 255));
	draww->AddLine(ImVec2(c + 19, u + 6), ImVec2(c + 19, u + 7), ImColor(131, 141, 148, 255));
	draww->AddLine(ImVec2(c + 20, u + 6), ImVec2(c + 20, u + 7), ImColor(64, 117, 134, 255));
	draww->AddLine(ImVec2(c + 21, u + 6), ImVec2(c + 21, u + 7), ImColor(220, 236, 241, 255));
	draww->AddLine(ImVec2(c + 22, u + 6), ImVec2(c + 22, u + 7), ImColor(77, 84, 92, 255));
	draww->AddLine(ImVec2(c + 23, u + 6), ImVec2(c + 26, u + 6), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 26, u + 6), ImVec2(c + 26, u + 7), ImColor(28, 76, 94, 255));
	draww->AddLine(ImVec2(c + 27, u + 6), ImVec2(c + 27, u + 7), ImColor(43, 122, 145, 255));
	draww->AddLine(ImVec2(c + 28, u + 6), ImVec2(c + 28, u + 7), ImColor(41, 114, 136, 255));
	draww->AddLine(ImVec2(c + 29, u + 6), ImVec2(c + 29, u + 7), ImColor(32, 87, 106, 255));
	draww->AddLine(ImVec2(c + 30, u + 6), ImVec2(c + 30, u + 7), ImColor(8, 17, 28, 255));
	draww->AddLine(ImVec2(c + 31, u + 6), ImVec2(c + 31, u + 7), ImColor(9, 20, 31, 255));
	draww->AddLine(ImVec2(c + 32, u + 6), ImVec2(c + 35, u + 6), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 6), ImVec2(c + 35, u + 7), ImColor(19, 49, 64, 255));
	draww->AddLine(ImVec2(c + 36, u + 6), ImVec2(c + 36, u + 7), ImColor(180, 219, 230, 255));
	draww->AddLine(ImVec2(c + 37, u + 6), ImVec2(c + 37, u + 7), ImColor(190, 204, 209, 255));
	draww->AddLine(ImVec2(c + 38, u + 6), ImVec2(c + 38, u + 7), ImColor(100, 128, 139, 255));
	draww->AddLine(ImVec2(c + 39, u + 6), ImVec2(c + 39, u + 7), ImColor(100, 128, 140, 255));
	draww->AddLine(ImVec2(c + 40, u + 6), ImVec2(c + 40, u + 7), ImColor(111, 145, 158, 255));
	draww->AddLine(ImVec2(c + 41, u + 6), ImVec2(c + 41, u + 7), ImColor(165, 202, 212, 255));
	draww->AddLine(ImVec2(c + 42, u + 6), ImVec2(c + 42, u + 7), ImColor(211, 227, 232, 255));
	draww->AddLine(ImVec2(c + 43, u + 6), ImVec2(c + 43, u + 7), ImColor(97, 106, 114, 255));
	draww->AddLine(ImVec2(c + 44, u + 6), ImVec2(c + 44, u + 7), ImColor(9, 17, 28, 255));
	draww->AddLine(ImVec2(c + 45, u + 6), ImVec2(c + 45, u + 7), ImColor(9, 20, 32, 255));
	draww->AddLine(ImVec2(c + 46, u + 6), ImVec2(c + 46, u + 7), ImColor(89, 144, 161, 255));
	draww->AddLine(ImVec2(c + 47, u + 6), ImVec2(c + 47, u + 7), ImColor(218, 231, 235, 255));
	draww->AddLine(ImVec2(c + 48, u + 6), ImVec2(c + 48, u + 7), ImColor(65, 75, 85, 255));
	draww->AddLine(ImVec2(c + 49, u + 6), ImVec2(c + 49, u + 7), ImColor(16, 27, 39, 255));
	draww->AddLine(ImVec2(c + 50, u + 6), ImVec2(c + 50, u + 7), ImColor(28, 56, 70, 255));
	draww->AddLine(ImVec2(c + 51, u + 6), ImVec2(c + 51, u + 7), ImColor(164, 207, 220, 255));
	draww->AddLine(ImVec2(c + 52, u + 6), ImVec2(c + 52, u + 7), ImColor(173, 182, 187, 255));
	draww->AddLine(ImVec2(c + 53, u + 6), ImVec2(c + 53, u + 7), ImColor(16, 24, 35, 255));
	draww->AddLine(ImVec2(c + 0, u + 7), ImVec2(c + 4, u + 7), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 4, u + 7), ImVec2(c + 4, u + 8), ImColor(47, 93, 109, 255));
	draww->AddLine(ImVec2(c + 5, u + 7), ImVec2(c + 5, u + 8), ImColor(206, 232, 239, 255));
	draww->AddLine(ImVec2(c + 6, u + 7), ImVec2(c + 6, u + 8), ImColor(181, 198, 204, 255));
	draww->AddLine(ImVec2(c + 7, u + 7), ImVec2(c + 9, u + 7), ImColor(114, 143, 154, 255));
	draww->AddLine(ImVec2(c + 9, u + 7), ImVec2(c + 9, u + 8), ImColor(120, 157, 170, 255));
	draww->AddLine(ImVec2(c + 10, u + 7), ImVec2(c + 10, u + 8), ImColor(202, 230, 237, 255));
	draww->AddLine(ImVec2(c + 11, u + 7), ImVec2(c + 11, u + 8), ImColor(178, 187, 191, 255));
	draww->AddLine(ImVec2(c + 12, u + 7), ImVec2(c + 12, u + 8), ImColor(17, 25, 35, 255));
	draww->AddLine(ImVec2(c + 13, u + 7), ImVec2(c + 13, u + 8), ImColor(10, 21, 33, 255));
	draww->AddLine(ImVec2(c + 14, u + 7), ImVec2(c + 14, u + 8), ImColor(108, 166, 182, 255));
	draww->AddLine(ImVec2(c + 15, u + 7), ImVec2(c + 15, u + 8), ImColor(211, 220, 223, 255));
	draww->AddLine(ImVec2(c + 16, u + 7), ImVec2(c + 16, u + 8), ImColor(31, 38, 48, 255));
	draww->AddLine(ImVec2(c + 17, u + 7), ImVec2(c + 17, u + 8), ImColor(13, 30, 42, 255));
	draww->AddLine(ImVec2(c + 18, u + 7), ImVec2(c + 18, u + 8), ImColor(109, 161, 176, 255));
	draww->AddLine(ImVec2(c + 19, u + 7), ImVec2(c + 19, u + 8), ImColor(206, 222, 227, 255));
	draww->AddLine(ImVec2(c + 20, u + 7), ImVec2(c + 20, u + 8), ImColor(116, 161, 176, 255));
	draww->AddLine(ImVec2(c + 21, u + 7), ImVec2(c + 21, u + 8), ImColor(220, 237, 241, 255));
	draww->AddLine(ImVec2(c + 22, u + 7), ImVec2(c + 22, u + 8), ImColor(77, 84, 92, 255));
	draww->AddLine(ImVec2(c + 23, u + 7), ImVec2(c + 25, u + 7), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 25, u + 7), ImVec2(c + 25, u + 8), ImColor(8, 17, 28, 255));
	draww->AddLine(ImVec2(c + 26, u + 7), ImVec2(c + 26, u + 8), ImColor(29, 77, 96, 255));
	draww->AddLine(ImVec2(c + 27, u + 7), ImVec2(c + 27, u + 8), ImColor(52, 146, 173, 255));
	draww->AddLine(ImVec2(c + 28, u + 7), ImVec2(c + 28, u + 8), ImColor(46, 130, 154, 255));
	draww->AddLine(ImVec2(c + 29, u + 7), ImVec2(c + 29, u + 8), ImColor(10, 21, 33, 255));
	draww->AddLine(ImVec2(c + 30, u + 7), ImVec2(c + 30, u + 8), ImColor(16, 40, 54, 255));
	draww->AddLine(ImVec2(c + 31, u + 7), ImVec2(c + 31, u + 8), ImColor(32, 87, 106, 255));
	draww->AddLine(ImVec2(c + 32, u + 7), ImVec2(c + 35, u + 7), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 7), ImVec2(c + 35, u + 8), ImColor(19, 49, 64, 255));
	draww->AddLine(ImVec2(c + 36, u + 7), ImVec2(c + 36, u + 8), ImColor(180, 219, 230, 255));
	draww->AddLine(ImVec2(c + 37, u + 7), ImVec2(c + 37, u + 8), ImColor(162, 169, 174, 255));
	draww->AddLine(ImVec2(c + 38, u + 7), ImVec2(c + 40, u + 7), ImColor(14, 24, 35, 255));
	draww->AddLine(ImVec2(c + 40, u + 7), ImVec2(c + 40, u + 8), ImColor(16, 28, 39, 255));
	draww->AddLine(ImVec2(c + 41, u + 7), ImVec2(c + 41, u + 8), ImColor(35, 67, 82, 255));
	draww->AddLine(ImVec2(c + 42, u + 7), ImVec2(c + 42, u + 8), ImColor(176, 216, 227, 255));
	draww->AddLine(ImVec2(c + 43, u + 7), ImVec2(c + 43, u + 8), ImColor(179, 187, 191, 255));
	draww->AddLine(ImVec2(c + 44, u + 7), ImVec2(c + 44, u + 8), ImColor(15, 23, 34, 255));
	draww->AddLine(ImVec2(c + 45, u + 7), ImVec2(c + 45, u + 8), ImColor(19, 44, 58, 255));
	draww->AddLine(ImVec2(c + 46, u + 7), ImVec2(c + 46, u + 8), ImColor(158, 204, 216, 255));
	draww->AddLine(ImVec2(c + 47, u + 7), ImVec2(c + 47, u + 8), ImColor(214, 226, 231, 255));
	draww->AddLine(ImVec2(c + 48, u + 7), ImVec2(c + 48, u + 8), ImColor(122, 150, 160, 255));
	draww->AddLine(ImVec2(c + 49, u + 7), ImVec2(c + 49, u + 8), ImColor(114, 143, 154, 255));
	draww->AddLine(ImVec2(c + 50, u + 7), ImVec2(c + 50, u + 8), ImColor(115, 146, 158, 255));
	draww->AddLine(ImVec2(c + 51, u + 7), ImVec2(c + 51, u + 8), ImColor(166, 207, 218, 255));
	draww->AddLine(ImVec2(c + 52, u + 7), ImVec2(c + 52, u + 8), ImColor(222, 232, 235, 255));
	draww->AddLine(ImVec2(c + 53, u + 7), ImVec2(c + 53, u + 8), ImColor(57, 64, 73, 255));
	draww->AddLine(ImVec2(c + 0, u + 8), ImVec2(c + 3, u + 8), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 8), ImVec2(c + 3, u + 9), ImColor(11, 24, 35, 255));
	draww->AddLine(ImVec2(c + 4, u + 8), ImVec2(c + 4, u + 9), ImColor(109, 165, 182, 255));
	draww->AddLine(ImVec2(c + 5, u + 8), ImVec2(c + 5, u + 9), ImColor(221, 235, 239, 255));
	draww->AddLine(ImVec2(c + 6, u + 8), ImVec2(c + 6, u + 9), ImColor(184, 205, 212, 255));
	draww->AddLine(ImVec2(c + 7, u + 8), ImVec2(c + 10, u + 8), ImColor(182, 204, 211, 255));
	draww->AddLine(ImVec2(c + 10, u + 8), ImVec2(c + 10, u + 9), ImColor(190, 217, 225, 255));
	draww->AddLine(ImVec2(c + 11, u + 8), ImVec2(c + 11, u + 9), ImColor(219, 231, 235, 255));
	draww->AddLine(ImVec2(c + 12, u + 8), ImVec2(c + 12, u + 9), ImColor(61, 68, 77, 255));
	draww->AddLine(ImVec2(c + 13, u + 8), ImVec2(c + 13, u + 9), ImColor(10, 21, 33, 255));
	draww->AddLine(ImVec2(c + 14, u + 8), ImVec2(c + 14, u + 9), ImColor(108, 166, 182, 255));
	draww->AddLine(ImVec2(c + 15, u + 8), ImVec2(c + 15, u + 9), ImColor(211, 220, 223, 255));
	draww->AddLine(ImVec2(c + 16, u + 8), ImVec2(c + 16, u + 9), ImColor(31, 38, 48, 255));
	draww->AddLine(ImVec2(c + 17, u + 8), ImVec2(c + 17, u + 9), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 18, u + 8), ImVec2(c + 18, u + 9), ImColor(26, 57, 72, 255));
	draww->AddLine(ImVec2(c + 19, u + 8), ImVec2(c + 19, u + 9), ImColor(166, 206, 218, 255));
	draww->AddLine(ImVec2(c + 20, u + 8), ImVec2(c + 20, u + 9), ImColor(207, 229, 235, 255));
	draww->AddLine(ImVec2(c + 21, u + 8), ImVec2(c + 21, u + 9), ImColor(226, 239, 243, 255));
	draww->AddLine(ImVec2(c + 22, u + 8), ImVec2(c + 22, u + 9), ImColor(77, 84, 92, 255));
	draww->AddLine(ImVec2(c + 23, u + 8), ImVec2(c + 25, u + 8), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 25, u + 8), ImVec2(c + 25, u + 9), ImColor(17, 44, 58, 255));
	draww->AddLine(ImVec2(c + 26, u + 8), ImVec2(c + 26, u + 9), ImColor(46, 129, 154, 255));
	draww->AddLine(ImVec2(c + 27, u + 8), ImVec2(c + 27, u + 9), ImColor(14, 35, 48, 255));
	draww->AddLine(ImVec2(c + 28, u + 8), ImVec2(c + 28, u + 9), ImColor(34, 94, 114, 255));
	draww->AddLine(ImVec2(c + 29, u + 8), ImVec2(c + 29, u + 9), ImColor(38, 106, 127, 255));
	draww->AddLine(ImVec2(c + 30, u + 8), ImVec2(c + 30, u + 9), ImColor(37, 101, 122, 255));
	draww->AddLine(ImVec2(c + 31, u + 8), ImVec2(c + 31, u + 9), ImColor(31, 86, 105, 255));
	draww->AddLine(ImVec2(c + 32, u + 8), ImVec2(c + 35, u + 8), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 8), ImVec2(c + 35, u + 9), ImColor(19, 49, 64, 255));
	draww->AddLine(ImVec2(c + 36, u + 8), ImVec2(c + 36, u + 9), ImColor(180, 219, 230, 255));
	draww->AddLine(ImVec2(c + 37, u + 8), ImVec2(c + 37, u + 9), ImColor(160, 166, 171, 255));
	draww->AddLine(ImVec2(c + 38, u + 8), ImVec2(c + 41, u + 8), ImColor(8, 16, 27, 255));
	draww->AddLine(ImVec2(c + 41, u + 8), ImVec2(c + 41, u + 9), ImColor(17, 40, 53, 255));
	draww->AddLine(ImVec2(c + 42, u + 8), ImVec2(c + 42, u + 9), ImColor(154, 201, 215, 255));
	draww->AddLine(ImVec2(c + 43, u + 8), ImVec2(c + 43, u + 9), ImColor(197, 206, 209, 255));
	draww->AddLine(ImVec2(c + 44, u + 8), ImVec2(c + 44, u + 9), ImColor(21, 29, 40, 255));
	draww->AddLine(ImVec2(c + 45, u + 8), ImVec2(c + 45, u + 9), ImColor(52, 100, 117, 255));
	draww->AddLine(ImVec2(c + 46, u + 8), ImVec2(c + 46, u + 9), ImColor(209, 233, 239, 255));
	draww->AddLine(ImVec2(c + 47, u + 8), ImVec2(c + 47, u + 9), ImColor(193, 212, 218, 255));
	draww->AddLine(ImVec2(c + 48, u + 8), ImVec2(c + 51, u + 8), ImColor(182, 204, 211, 255));
	draww->AddLine(ImVec2(c + 51, u + 8), ImVec2(c + 51, u + 9), ImColor(183, 208, 216, 255));
	draww->AddLine(ImVec2(c + 52, u + 8), ImVec2(c + 52, u + 9), ImColor(218, 237, 242, 255));
	draww->AddLine(ImVec2(c + 53, u + 8), ImVec2(c + 53, u + 9), ImColor(128, 136, 143, 255));
	draww->AddLine(ImVec2(c + 54, u + 8), ImVec2(c + 54, u + 9), ImColor(9, 17, 28, 255));
	draww->AddLine(ImVec2(c + 0, u + 9), ImVec2(c + 3, u + 9), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 9), ImVec2(c + 3, u + 10), ImColor(26, 58, 73, 255));
	draww->AddLine(ImVec2(c + 4, u + 9), ImVec2(c + 4, u + 10), ImColor(179, 217, 228, 255));
	draww->AddLine(ImVec2(c + 5, u + 9), ImVec2(c + 5, u + 10), ImColor(164, 173, 179, 255));
	draww->AddLine(ImVec2(c + 6, u + 9), ImVec2(c + 6, u + 10), ImColor(32, 45, 56, 255));
	draww->AddLine(ImVec2(c + 7, u + 9), ImVec2(c + 10, u + 9), ImColor(28, 41, 52, 255));
	draww->AddLine(ImVec2(c + 10, u + 9), ImVec2(c + 10, u + 10), ImColor(52, 93, 109, 255));
	draww->AddLine(ImVec2(c + 11, u + 9), ImVec2(c + 11, u + 10), ImColor(197, 227, 235, 255));
	draww->AddLine(ImVec2(c + 12, u + 9), ImVec2(c + 12, u + 10), ImColor(136, 144, 150, 255));
	draww->AddLine(ImVec2(c + 13, u + 9), ImVec2(c + 13, u + 10), ImColor(12, 24, 35, 255));
	draww->AddLine(ImVec2(c + 14, u + 9), ImVec2(c + 14, u + 10), ImColor(108, 166, 182, 255));
	draww->AddLine(ImVec2(c + 15, u + 9), ImVec2(c + 15, u + 10), ImColor(211, 220, 223, 255));
	draww->AddLine(ImVec2(c + 16, u + 9), ImVec2(c + 16, u + 10), ImColor(31, 38, 48, 255));
	draww->AddLine(ImVec2(c + 17, u + 9), ImVec2(c + 17, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 18, u + 9), ImVec2(c + 18, u + 10), ImColor(9, 18, 30, 255));
	draww->AddLine(ImVec2(c + 19, u + 9), ImVec2(c + 19, u + 10), ImColor(64, 110, 127, 255));
	draww->AddLine(ImVec2(c + 20, u + 9), ImVec2(c + 20, u + 10), ImColor(206, 232, 240, 255));
	draww->AddLine(ImVec2(c + 21, u + 9), ImVec2(c + 21, u + 10), ImColor(233, 242, 245, 255));
	draww->AddLine(ImVec2(c + 22, u + 9), ImVec2(c + 22, u + 10), ImColor(77, 84, 92, 255));
	draww->AddLine(ImVec2(c + 23, u + 9), ImVec2(c + 25, u + 9), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 25, u + 9), ImVec2(c + 25, u + 10), ImColor(21, 56, 72, 255));
	draww->AddLine(ImVec2(c + 26, u + 9), ImVec2(c + 26, u + 10), ImColor(45, 127, 151, 255));
	draww->AddLine(ImVec2(c + 27, u + 9), ImVec2(c + 27, u + 10), ImColor(10, 24, 36, 255));
	draww->AddLine(ImVec2(c + 28, u + 9), ImVec2(c + 28, u + 10), ImColor(11, 26, 38, 255));
	draww->AddLine(ImVec2(c + 29, u + 9), ImVec2(c + 29, u + 10), ImColor(42, 117, 140, 255));
	draww->AddLine(ImVec2(c + 30, u + 9), ImVec2(c + 30, u + 10), ImColor(54, 154, 181, 255));
	draww->AddLine(ImVec2(c + 31, u + 9), ImVec2(c + 31, u + 10), ImColor(15, 36, 50, 255));
	draww->AddLine(ImVec2(c + 32, u + 9), ImVec2(c + 35, u + 9), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 9), ImVec2(c + 35, u + 10), ImColor(19, 49, 64, 255));
	draww->AddLine(ImVec2(c + 36, u + 9), ImVec2(c + 36, u + 10), ImColor(180, 219, 230, 255));
	draww->AddLine(ImVec2(c + 37, u + 9), ImVec2(c + 37, u + 10), ImColor(177, 188, 193, 255));
	draww->AddLine(ImVec2(c + 38, u + 9), ImVec2(c + 38, u + 10), ImColor(59, 81, 93, 255));
	draww->AddLine(ImVec2(c + 39, u + 9), ImVec2(c + 39, u + 10), ImColor(60, 81, 93, 255));
	draww->AddLine(ImVec2(c + 40, u + 9), ImVec2(c + 40, u + 10), ImColor(68, 95, 107, 255));
	draww->AddLine(ImVec2(c + 41, u + 9), ImVec2(c + 41, u + 10), ImColor(112, 152, 165, 255));
	draww->AddLine(ImVec2(c + 42, u + 9), ImVec2(c + 42, u + 10), ImColor(208, 232, 238, 255));
	draww->AddLine(ImVec2(c + 43, u + 9), ImVec2(c + 43, u + 10), ImColor(139, 148, 154, 255));
	draww->AddLine(ImVec2(c + 44, u + 9), ImVec2(c + 44, u + 10), ImColor(13, 27, 39, 255));
	draww->AddLine(ImVec2(c + 45, u + 9), ImVec2(c + 45, u + 10), ImColor(115, 170, 186, 255));
	draww->AddLine(ImVec2(c + 46, u + 9), ImVec2(c + 46, u + 10), ImColor(209, 220, 224, 255));
	draww->AddLine(ImVec2(c + 47, u + 9), ImVec2(c + 47, u + 10), ImColor(54, 66, 76, 255));
	draww->AddLine(ImVec2(c + 48, u + 9), ImVec2(c + 51, u + 9), ImColor(28, 41, 52, 255));
	draww->AddLine(ImVec2(c + 51, u + 9), ImVec2(c + 51, u + 10), ImColor(33, 56, 69, 255));
	draww->AddLine(ImVec2(c + 52, u + 9), ImVec2(c + 52, u + 10), ImColor(146, 194, 208, 255));
	draww->AddLine(ImVec2(c + 53, u + 9), ImVec2(c + 53, u + 10), ImColor(195, 205, 209, 255));
	draww->AddLine(ImVec2(c + 54, u + 9), ImVec2(c + 54, u + 10), ImColor(27, 35, 45, 255));
	draww->AddLine(ImVec2(c + 0, u + 10), ImVec2(c + 3, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 3, u + 10), ImVec2(c + 3, u + 11), ImColor(61, 113, 130, 255));
	draww->AddLine(ImVec2(c + 4, u + 10), ImVec2(c + 4, u + 11), ImColor(213, 231, 236, 255));
	draww->AddLine(ImVec2(c + 5, u + 10), ImVec2(c + 5, u + 11), ImColor(82, 90, 98, 255));
	draww->AddLine(ImVec2(c + 6, u + 10), ImVec2(c + 10, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 10, u + 10), ImVec2(c + 10, u + 11), ImColor(14, 32, 45, 255));
	draww->AddLine(ImVec2(c + 11, u + 10), ImVec2(c + 11, u + 11), ImColor(132, 184, 199, 255));
	draww->AddLine(ImVec2(c + 12, u + 10), ImVec2(c + 12, u + 11), ImColor(196, 205, 209, 255));
	draww->AddLine(ImVec2(c + 13, u + 10), ImVec2(c + 13, u + 11), ImColor(26, 36, 47, 255));
	draww->AddLine(ImVec2(c + 14, u + 10), ImVec2(c + 14, u + 11), ImColor(103, 161, 178, 255));
	draww->AddLine(ImVec2(c + 15, u + 10), ImVec2(c + 15, u + 11), ImColor(207, 216, 220, 255));
	draww->AddLine(ImVec2(c + 16, u + 10), ImVec2(c + 16, u + 11), ImColor(28, 36, 46, 255));
	draww->AddLine(ImVec2(c + 17, u + 10), ImVec2(c + 19, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 19, u + 10), ImVec2(c + 19, u + 11), ImColor(14, 31, 43, 255));
	draww->AddLine(ImVec2(c + 20, u + 10), ImVec2(c + 20, u + 11), ImColor(111, 163, 178, 255));
	draww->AddLine(ImVec2(c + 21, u + 10), ImVec2(c + 21, u + 11), ImColor(224, 237, 241, 255));
	draww->AddLine(ImVec2(c + 22, u + 10), ImVec2(c + 22, u + 11), ImColor(72, 79, 87, 255));
	draww->AddLine(ImVec2(c + 23, u + 10), ImVec2(c + 25, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 25, u + 10), ImVec2(c + 25, u + 11), ImColor(10, 23, 35, 255));
	draww->AddLine(ImVec2(c + 26, u + 10), ImVec2(c + 26, u + 11), ImColor(42, 117, 139, 255));
	draww->AddLine(ImVec2(c + 27, u + 10), ImVec2(c + 27, u + 11), ImColor(43, 122, 146, 255));
	draww->AddLine(ImVec2(c + 28, u + 10), ImVec2(c + 28, u + 11), ImColor(41, 115, 138, 255));
	draww->AddLine(ImVec2(c + 29, u + 10), ImVec2(c + 29, u + 11), ImColor(45, 127, 151, 255));
	draww->AddLine(ImVec2(c + 30, u + 10), ImVec2(c + 30, u + 11), ImColor(38, 106, 128, 255));
	draww->AddLine(ImVec2(c + 31, u + 10), ImVec2(c + 31, u + 11), ImColor(39, 109, 131, 255));
	draww->AddLine(ImVec2(c + 32, u + 10), ImVec2(c + 32, u + 11), ImColor(8, 17, 28, 255));
	draww->AddLine(ImVec2(c + 33, u + 10), ImVec2(c + 35, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 10), ImVec2(c + 35, u + 11), ImColor(18, 47, 62, 255));
	draww->AddLine(ImVec2(c + 36, u + 10), ImVec2(c + 36, u + 11), ImColor(176, 217, 228, 255));
	draww->AddLine(ImVec2(c + 37, u + 10), ImVec2(c + 37, u + 11), ImColor(222, 236, 240, 255));
	draww->AddLine(ImVec2(c + 38, u + 10), ImVec2(c + 38, u + 11), ImColor(199, 220, 226, 255));
	draww->AddLine(ImVec2(c + 39, u + 10), ImVec2(c + 39, u + 11), ImColor(199, 220, 227, 255));
	draww->AddLine(ImVec2(c + 40, u + 10), ImVec2(c + 40, u + 11), ImColor(200, 222, 229, 255));
	draww->AddLine(ImVec2(c + 41, u + 10), ImVec2(c + 41, u + 11), ImColor(194, 218, 225, 255));
	draww->AddLine(ImVec2(c + 42, u + 10), ImVec2(c + 42, u + 11), ImColor(144, 160, 167, 255));
	draww->AddLine(ImVec2(c + 43, u + 10), ImVec2(c + 43, u + 11), ImColor(37, 46, 56, 255));
	draww->AddLine(ImVec2(c + 44, u + 10), ImVec2(c + 44, u + 11), ImColor(19, 49, 64, 255));
	draww->AddLine(ImVec2(c + 45, u + 10), ImVec2(c + 45, u + 11), ImColor(176, 215, 226, 255));
	draww->AddLine(ImVec2(c + 46, u + 10), ImVec2(c + 46, u + 11), ImColor(149, 158, 163, 255));
	draww->AddLine(ImVec2(c + 47, u + 10), ImVec2(c + 47, u + 11), ImColor(12, 19, 30, 255));
	draww->AddLine(ImVec2(c + 48, u + 10), ImVec2(c + 51, u + 10), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 51, u + 10), ImVec2(c + 51, u + 11), ImColor(8, 18, 29, 255));
	draww->AddLine(ImVec2(c + 52, u + 10), ImVec2(c + 52, u + 11), ImColor(70, 123, 141, 255));
	draww->AddLine(ImVec2(c + 53, u + 10), ImVec2(c + 53, u + 11), ImColor(214, 231, 236, 255));
	draww->AddLine(ImVec2(c + 54, u + 10), ImVec2(c + 54, u + 11), ImColor(70, 76, 85, 255));
	draww->AddLine(ImVec2(c + 0, u + 11), ImVec2(c + 26, u + 11), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 26, u + 11), ImVec2(c + 26, u + 12), ImColor(11, 24, 36, 255));
	draww->AddLine(ImVec2(c + 27, u + 11), ImVec2(c + 27, u + 12), ImColor(15, 38, 52, 255));
	draww->AddLine(ImVec2(c + 28, u + 11), ImVec2(c + 28, u + 12), ImColor(16, 40, 53, 255));
	draww->AddLine(ImVec2(c + 29, u + 11), ImVec2(c + 29, u + 12), ImColor(12, 27, 39, 255));
	draww->AddLine(ImVec2(c + 30, u + 11), ImVec2(c + 30, u + 12), ImColor(9, 20, 32, 255));
	draww->AddLine(ImVec2(c + 31, u + 11), ImVec2(c + 31, u + 12), ImColor(14, 34, 47, 255));
	draww->AddLine(ImVec2(c + 0, u + 12), ImVec2(c + 0, u + 13), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 1, u + 12), ImVec2(c + 1, u + 13), ImColor(76, 107, 120, 255));
	draww->AddLine(ImVec2(c + 2, u + 12), ImVec2(c + 56, u + 12), ImColor(144, 199, 214, 255));
	draww->AddLine(ImVec2(c + 0, u + 14), ImVec2(c + 13, u + 14), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 14), ImVec2(c + 13, u + 15), ImColor(9, 19, 31, 255));
	draww->AddLine(ImVec2(c + 14, u + 14), ImVec2(c + 14, u + 15), ImColor(19, 47, 62, 255));
	draww->AddLine(ImVec2(c + 15, u + 14), ImVec2(c + 15, u + 15), ImColor(23, 60, 76, 255));
	draww->AddLine(ImVec2(c + 16, u + 14), ImVec2(c + 16, u + 15), ImColor(15, 37, 50, 255));
	draww->AddLine(ImVec2(c + 17, u + 14), ImVec2(c + 17, u + 15), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 18, u + 14), ImVec2(c + 18, u + 15), ImColor(9, 20, 32, 255));
	draww->AddLine(ImVec2(c + 19, u + 14), ImVec2(c + 19, u + 15), ImColor(16, 41, 54, 255));
	draww->AddLine(ImVec2(c + 20, u + 14), ImVec2(c + 22, u + 14), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 22, u + 14), ImVec2(c + 22, u + 15), ImColor(13, 32, 45, 255));
	draww->AddLine(ImVec2(c + 23, u + 14), ImVec2(c + 23, u + 15), ImColor(13, 30, 43, 255));
	draww->AddLine(ImVec2(c + 24, u + 14), ImVec2(c + 24, u + 15), ImColor(9, 20, 32, 255));
	draww->AddLine(ImVec2(c + 25, u + 14), ImVec2(c + 28, u + 14), ImColor(21, 57, 73, 255));
	draww->AddLine(ImVec2(c + 28, u + 14), ImVec2(c + 28, u + 15), ImColor(17, 44, 58, 255));
	draww->AddLine(ImVec2(c + 29, u + 14), ImVec2(c + 31, u + 14), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 31, u + 14), ImVec2(c + 31, u + 15), ImColor(14, 35, 48, 255));
	draww->AddLine(ImVec2(c + 32, u + 14), ImVec2(c + 32, u + 15), ImColor(15, 38, 52, 255));
	draww->AddLine(ImVec2(c + 33, u + 14), ImVec2(c + 35, u + 14), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 14), ImVec2(c + 35, u + 15), ImColor(20, 53, 68, 255));
	draww->AddLine(ImVec2(c + 36, u + 14), ImVec2(c + 39, u + 14), ImColor(21, 57, 73, 255));
	draww->AddLine(ImVec2(c + 39, u + 14), ImVec2(c + 39, u + 15), ImColor(14, 36, 49, 255));
	draww->AddLine(ImVec2(c + 40, u + 14), ImVec2(c + 40, u + 15), ImColor(9, 19, 30, 255));
	draww->AddLine(ImVec2(c + 41, u + 14), ImVec2(c + 41, u + 15), ImColor(18, 47, 62, 255));
	draww->AddLine(ImVec2(c + 42, u + 14), ImVec2(c + 42, u + 15), ImColor(23, 59, 75, 255));
	draww->AddLine(ImVec2(c + 43, u + 14), ImVec2(c + 43, u + 15), ImColor(14, 34, 47, 255));
	draww->AddLine(ImVec2(c + 0, u + 15), ImVec2(c + 13, u + 15), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 15), ImVec2(c + 13, u + 16), ImColor(33, 90, 110, 255));
	draww->AddLine(ImVec2(c + 14, u + 15), ImVec2(c + 14, u + 16), ImColor(40, 113, 135, 255));
	draww->AddLine(ImVec2(c + 15, u + 15), ImVec2(c + 15, u + 16), ImColor(27, 74, 91, 255));
	draww->AddLine(ImVec2(c + 16, u + 15), ImVec2(c + 16, u + 16), ImColor(44, 123, 147, 255));
	draww->AddLine(ImVec2(c + 17, u + 15), ImVec2(c + 17, u + 16), ImColor(22, 60, 76, 255));
	draww->AddLine(ImVec2(c + 18, u + 15), ImVec2(c + 18, u + 16), ImColor(15, 37, 51, 255));
	draww->AddLine(ImVec2(c + 19, u + 15), ImVec2(c + 19, u + 16), ImColor(41, 113, 136, 255));
	draww->AddLine(ImVec2(c + 20, u + 15), ImVec2(c + 22, u + 15), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 22, u + 15), ImVec2(c + 22, u + 16), ImColor(29, 80, 99, 255));
	draww->AddLine(ImVec2(c + 23, u + 15), ImVec2(c + 23, u + 16), ImColor(28, 75, 93, 255));
	draww->AddLine(ImVec2(c + 24, u + 15), ImVec2(c + 24, u + 16), ImColor(14, 36, 49, 255));
	draww->AddLine(ImVec2(c + 25, u + 15), ImVec2(c + 25, u + 16), ImColor(47, 134, 158, 255));
	draww->AddLine(ImVec2(c + 26, u + 15), ImVec2(c + 28, u + 15), ImColor(28, 74, 92, 255));
	draww->AddLine(ImVec2(c + 28, u + 15), ImVec2(c + 28, u + 16), ImColor(22, 57, 72, 255));
	draww->AddLine(ImVec2(c + 29, u + 15), ImVec2(c + 31, u + 15), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 31, u + 15), ImVec2(c + 31, u + 16), ImColor(43, 121, 144, 255));
	draww->AddLine(ImVec2(c + 32, u + 15), ImVec2(c + 32, u + 16), ImColor(46, 129, 154, 255));
	draww->AddLine(ImVec2(c + 33, u + 15), ImVec2(c + 33, u + 16), ImColor(8, 17, 28, 255));
	draww->AddLine(ImVec2(c + 34, u + 15), ImVec2(c + 34, u + 16), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 35, u + 15), ImVec2(c + 35, u + 16), ImColor(27, 74, 91, 255));
	draww->AddLine(ImVec2(c + 36, u + 15), ImVec2(c + 36, u + 16), ImColor(32, 88, 107, 255));
	draww->AddLine(ImVec2(c + 37, u + 15), ImVec2(c + 37, u + 16), ImColor(50, 141, 167, 255));
	draww->AddLine(ImVec2(c + 38, u + 15), ImVec2(c + 38, u + 16), ImColor(29, 79, 97, 255));
	draww->AddLine(ImVec2(c + 39, u + 15), ImVec2(c + 39, u + 16), ImColor(18, 47, 62, 255));
	draww->AddLine(ImVec2(c + 40, u + 15), ImVec2(c + 40, u + 16), ImColor(31, 83, 102, 255));
	draww->AddLine(ImVec2(c + 41, u + 15), ImVec2(c + 41, u + 16), ImColor(39, 107, 129, 255));
	draww->AddLine(ImVec2(c + 42, u + 15), ImVec2(c + 42, u + 16), ImColor(27, 73, 91, 255));
	draww->AddLine(ImVec2(c + 43, u + 15), ImVec2(c + 43, u + 16), ImColor(45, 126, 150, 255));
	draww->AddLine(ImVec2(c + 44, u + 15), ImVec2(c + 44, u + 16), ImColor(16, 40, 54, 255));
	draww->AddLine(ImVec2(c + 0, u + 16), ImVec2(c + 13, u + 16), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 16), ImVec2(c + 13, u + 17), ImColor(51, 143, 169, 255));
	draww->AddLine(ImVec2(c + 14, u + 16), ImVec2(c + 14, u + 17), ImColor(10, 22, 34, 255));
	draww->AddLine(ImVec2(c + 15, u + 16), ImVec2(c + 15, u + 17), ImColor(8, 16, 27, 255));
	draww->AddLine(ImVec2(c + 16, u + 16), ImVec2(c + 16, u + 17), ImColor(15, 38, 51, 255));
	draww->AddLine(ImVec2(c + 17, u + 16), ImVec2(c + 17, u + 17), ImColor(28, 77, 95, 255));
	draww->AddLine(ImVec2(c + 18, u + 16), ImVec2(c + 18, u + 17), ImColor(15, 37, 51, 255));
	draww->AddLine(ImVec2(c + 19, u + 16), ImVec2(c + 19, u + 17), ImColor(41, 114, 137, 255));
	draww->AddLine(ImVec2(c + 20, u + 16), ImVec2(c + 22, u + 16), ImColor(8, 17, 29, 255));
	draww->AddLine(ImVec2(c + 22, u + 16), ImVec2(c + 22, u + 17), ImColor(30, 81, 100, 255));
	draww->AddLine(ImVec2(c + 23, u + 16), ImVec2(c + 23, u + 17), ImColor(28, 75, 93, 255));
	draww->AddLine(ImVec2(c + 24, u + 16), ImVec2(c + 24, u + 17), ImColor(14, 36, 49, 255));
	draww->AddLine(ImVec2(c + 25, u + 16), ImVec2(c + 25, u + 17), ImColor(40, 112, 134, 255));
	draww->AddLine(ImVec2(c + 26, u + 16), ImVec2(c + 30, u + 16), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 30, u + 16), ImVec2(c + 30, u + 17), ImColor(15, 36, 50, 255));
	draww->AddLine(ImVec2(c + 31, u + 16), ImVec2(c + 31, u + 17), ImColor(41, 114, 137, 255));
	draww->AddLine(ImVec2(c + 32, u + 16), ImVec2(c + 32, u + 17), ImColor(37, 103, 124, 255));
	draww->AddLine(ImVec2(c + 33, u + 16), ImVec2(c + 33, u + 17), ImColor(19, 47, 62, 255));
	draww->AddLine(ImVec2(c + 34, u + 16), ImVec2(c + 36, u + 16), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 36, u + 16), ImVec2(c + 36, u + 17), ImColor(13, 30, 43, 255));
	draww->AddLine(ImVec2(c + 37, u + 16), ImVec2(c + 37, u + 17), ImColor(43, 121, 145, 255));
	draww->AddLine(ImVec2(c + 38, u + 16), ImVec2(c + 40, u + 16), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 40, u + 16), ImVec2(c + 40, u + 17), ImColor(40, 110, 132, 255));
	draww->AddLine(ImVec2(c + 41, u + 16), ImVec2(c + 41, u + 17), ImColor(23, 61, 78, 255));
	draww->AddLine(ImVec2(c + 42, u + 16), ImVec2(c + 42, u + 17), ImColor(9, 19, 30, 255));
	draww->AddLine(ImVec2(c + 43, u + 16), ImVec2(c + 43, u + 17), ImColor(15, 36, 50, 255));
	draww->AddLine(ImVec2(c + 44, u + 16), ImVec2(c + 44, u + 17), ImColor(14, 33, 46, 255));
	draww->AddLine(ImVec2(c + 0, u + 17), ImVec2(c + 13, u + 17), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 17), ImVec2(c + 13, u + 18), ImColor(49, 137, 163, 255));
	draww->AddLine(ImVec2(c + 14, u + 17), ImVec2(c + 18, u + 17), ImColor(8, 16, 27, 255));
	draww->AddLine(ImVec2(c + 18, u + 17), ImVec2(c + 18, u + 18), ImColor(15, 37, 51, 255));
	draww->AddLine(ImVec2(c + 19, u + 17), ImVec2(c + 19, u + 18), ImColor(52, 147, 174, 255));
	draww->AddLine(ImVec2(c + 20, u + 17), ImVec2(c + 22, u + 17), ImColor(39, 110, 132, 255));
	draww->AddLine(ImVec2(c + 22, u + 17), ImVec2(c + 22, u + 18), ImColor(48, 134, 159, 255));
	draww->AddLine(ImVec2(c + 23, u + 17), ImVec2(c + 23, u + 18), ImColor(28, 75, 93, 255));
	draww->AddLine(ImVec2(c + 24, u + 17), ImVec2(c + 24, u + 18), ImColor(14, 36, 49, 255));
	draww->AddLine(ImVec2(c + 25, u + 17), ImVec2(c + 25, u + 18), ImColor(51, 145, 171, 255));
	draww->AddLine(ImVec2(c + 26, u + 17), ImVec2(c + 28, u + 17), ImColor(38, 106, 127, 255));
	draww->AddLine(ImVec2(c + 28, u + 17), ImVec2(c + 28, u + 18), ImColor(23, 61, 77, 255));
	draww->AddLine(ImVec2(c + 29, u + 17), ImVec2(c + 29, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 30, u + 17), ImVec2(c + 30, u + 18), ImColor(33, 92, 111, 255));
	draww->AddLine(ImVec2(c + 31, u + 17), ImVec2(c + 31, u + 18), ImColor(22, 59, 76, 255));
	draww->AddLine(ImVec2(c + 32, u + 17), ImVec2(c + 32, u + 18), ImColor(18, 47, 61, 255));
	draww->AddLine(ImVec2(c + 33, u + 17), ImVec2(c + 33, u + 18), ImColor(38, 104, 125, 255));
	draww->AddLine(ImVec2(c + 34, u + 17), ImVec2(c + 36, u + 17), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 36, u + 17), ImVec2(c + 36, u + 18), ImColor(13, 30, 43, 255));
	draww->AddLine(ImVec2(c + 37, u + 17), ImVec2(c + 37, u + 18), ImColor(43, 121, 145, 255));
	draww->AddLine(ImVec2(c + 38, u + 17), ImVec2(c + 40, u + 17), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 40, u + 17), ImVec2(c + 40, u + 18), ImColor(15, 38, 51, 255));
	draww->AddLine(ImVec2(c + 41, u + 17), ImVec2(c + 41, u + 18), ImColor(38, 107, 129, 255));
	draww->AddLine(ImVec2(c + 42, u + 17), ImVec2(c + 42, u + 18), ImColor(39, 109, 130, 255));
	draww->AddLine(ImVec2(c + 43, u + 17), ImVec2(c + 43, u + 18), ImColor(27, 72, 89, 255));
	draww->AddLine(ImVec2(c + 44, u + 17), ImVec2(c + 44, u + 18), ImColor(9, 20, 32, 255));
	draww->AddLine(ImVec2(c + 0, u + 18), ImVec2(c + 13, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 18), ImVec2(c + 13, u + 19), ImColor(50, 142, 168, 255));
	draww->AddLine(ImVec2(c + 14, u + 18), ImVec2(c + 14, u + 19), ImColor(9, 18, 29, 255));
	draww->AddLine(ImVec2(c + 15, u + 18), ImVec2(c + 15, u + 19), ImColor(8, 16, 27, 255));
	draww->AddLine(ImVec2(c + 16, u + 18), ImVec2(c + 16, u + 19), ImColor(11, 25, 37, 255));
	draww->AddLine(ImVec2(c + 17, u + 18), ImVec2(c + 17, u + 19), ImColor(20, 51, 67, 255));
	draww->AddLine(ImVec2(c + 18, u + 18), ImVec2(c + 18, u + 19), ImColor(15, 37, 51, 255));
	draww->AddLine(ImVec2(c + 19, u + 18), ImVec2(c + 19, u + 19), ImColor(43, 119, 142, 255));
	draww->AddLine(ImVec2(c + 20, u + 18), ImVec2(c + 22, u + 18), ImColor(13, 32, 45, 255));
	draww->AddLine(ImVec2(c + 22, u + 18), ImVec2(c + 22, u + 19), ImColor(33, 89, 109, 255));
	draww->AddLine(ImVec2(c + 23, u + 18), ImVec2(c + 23, u + 19), ImColor(28, 75, 93, 255));
	draww->AddLine(ImVec2(c + 24, u + 18), ImVec2(c + 24, u + 19), ImColor(14, 36, 49, 255));
	draww->AddLine(ImVec2(c + 25, u + 18), ImVec2(c + 25, u + 19), ImColor(42, 117, 140, 255));
	draww->AddLine(ImVec2(c + 26, u + 18), ImVec2(c + 28, u + 18), ImColor(12, 30, 42, 255));
	draww->AddLine(ImVec2(c + 28, u + 18), ImVec2(c + 28, u + 19), ImColor(10, 22, 34, 255));
	draww->AddLine(ImVec2(c + 29, u + 18), ImVec2(c + 29, u + 19), ImColor(9, 19, 30, 255));
	draww->AddLine(ImVec2(c + 30, u + 18), ImVec2(c + 30, u + 19), ImColor(52, 145, 171, 255));
	draww->AddLine(ImVec2(c + 31, u + 18), ImVec2(c + 31, u + 19), ImColor(33, 91, 110, 255));
	draww->AddLine(ImVec2(c + 32, u + 18), ImVec2(c + 32, u + 19), ImColor(32, 88, 108, 255));
	draww->AddLine(ImVec2(c + 33, u + 18), ImVec2(c + 33, u + 19), ImColor(53, 150, 177, 255));
	draww->AddLine(ImVec2(c + 34, u + 18), ImVec2(c + 34, u + 19), ImColor(10, 23, 35, 255));
	draww->AddLine(ImVec2(c + 35, u + 18), ImVec2(c + 35, u + 19), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 36, u + 18), ImVec2(c + 36, u + 19), ImColor(13, 30, 43, 255));
	draww->AddLine(ImVec2(c + 37, u + 18), ImVec2(c + 37, u + 19), ImColor(43, 121, 145, 255));
	draww->AddLine(ImVec2(c + 38, u + 18), ImVec2(c + 40, u + 18), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 40, u + 18), ImVec2(c + 40, u + 19), ImColor(13, 31, 44, 255));
	draww->AddLine(ImVec2(c + 41, u + 18), ImVec2(c + 41, u + 19), ImColor(8, 17, 28, 255));
	draww->AddLine(ImVec2(c + 42, u + 18), ImVec2(c + 42, u + 19), ImColor(15, 36, 49, 255));
	draww->AddLine(ImVec2(c + 43, u + 18), ImVec2(c + 43, u + 19), ImColor(37, 102, 123, 255));
	draww->AddLine(ImVec2(c + 44, u + 18), ImVec2(c + 44, u + 19), ImColor(29, 79, 97, 255));
	draww->AddLine(ImVec2(c + 0, u + 19), ImVec2(c + 13, u + 19), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 19), ImVec2(c + 13, u + 20), ImColor(42, 118, 141, 255));
	draww->AddLine(ImVec2(c + 14, u + 19), ImVec2(c + 14, u + 20), ImColor(29, 79, 97, 255));
	draww->AddLine(ImVec2(c + 15, u + 19), ImVec2(c + 15, u + 20), ImColor(16, 41, 55, 255));
	draww->AddLine(ImVec2(c + 16, u + 19), ImVec2(c + 16, u + 20), ImColor(37, 102, 123, 255));
	draww->AddLine(ImVec2(c + 17, u + 19), ImVec2(c + 17, u + 20), ImColor(30, 81, 100, 255));
	draww->AddLine(ImVec2(c + 18, u + 19), ImVec2(c + 18, u + 20), ImColor(15, 37, 51, 255));
	draww->AddLine(ImVec2(c + 19, u + 19), ImVec2(c + 19, u + 20), ImColor(41, 113, 136, 255));
	draww->AddLine(ImVec2(c + 20, u + 19), ImVec2(c + 22, u + 19), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 22, u + 19), ImVec2(c + 22, u + 20), ImColor(29, 80, 99, 255));
	draww->AddLine(ImVec2(c + 23, u + 19), ImVec2(c + 23, u + 20), ImColor(28, 75, 93, 255));
	draww->AddLine(ImVec2(c + 24, u + 19), ImVec2(c + 24, u + 20), ImColor(14, 36, 49, 255));
	draww->AddLine(ImVec2(c + 25, u + 19), ImVec2(c + 25, u + 20), ImColor(43, 121, 145, 255));
	draww->AddLine(ImVec2(c + 26, u + 19), ImVec2(c + 28, u + 19), ImColor(16, 42, 56, 255));
	draww->AddLine(ImVec2(c + 28, u + 19), ImVec2(c + 28, u + 20), ImColor(14, 35, 48, 255));
	draww->AddLine(ImVec2(c + 29, u + 19), ImVec2(c + 29, u + 20), ImColor(22, 57, 73, 255));
	draww->AddLine(ImVec2(c + 30, u + 19), ImVec2(c + 30, u + 20), ImColor(39, 108, 130, 255));
	draww->AddLine(ImVec2(c + 31, u + 19), ImVec2(c + 33, u + 19), ImColor(19, 51, 66, 255));
	draww->AddLine(ImVec2(c + 33, u + 19), ImVec2(c + 33, u + 20), ImColor(36, 99, 120, 255));
	draww->AddLine(ImVec2(c + 34, u + 19), ImVec2(c + 34, u + 20), ImColor(26, 70, 88, 255));
	draww->AddLine(ImVec2(c + 35, u + 19), ImVec2(c + 35, u + 20), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 36, u + 19), ImVec2(c + 36, u + 20), ImColor(13, 30, 43, 255));
	draww->AddLine(ImVec2(c + 37, u + 19), ImVec2(c + 37, u + 20), ImColor(43, 121, 145, 255));
	draww->AddLine(ImVec2(c + 38, u + 19), ImVec2(c + 40, u + 19), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 40, u + 19), ImVec2(c + 40, u + 20), ImColor(41, 113, 135, 255));
	draww->AddLine(ImVec2(c + 41, u + 19), ImVec2(c + 41, u + 20), ImColor(24, 65, 82, 255));
	draww->AddLine(ImVec2(c + 42, u + 19), ImVec2(c + 42, u + 20), ImColor(16, 39, 53, 255));
	draww->AddLine(ImVec2(c + 43, u + 19), ImVec2(c + 43, u + 20), ImColor(36, 101, 122, 255));
	draww->AddLine(ImVec2(c + 44, u + 19), ImVec2(c + 44, u + 20), ImColor(30, 82, 101, 255));
	draww->AddLine(ImVec2(c + 0, u + 20), ImVec2(c + 13, u + 20), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 13, u + 20), ImVec2(c + 13, u + 21), ImColor(12, 28, 40, 255));
	draww->AddLine(ImVec2(c + 14, u + 20), ImVec2(c + 14, u + 21), ImColor(33, 91, 111, 255));
	draww->AddLine(ImVec2(c + 15, u + 20), ImVec2(c + 15, u + 21), ImColor(36, 100, 121, 255));
	draww->AddLine(ImVec2(c + 16, u + 20), ImVec2(c + 16, u + 21), ImColor(27, 73, 91, 255));
	draww->AddLine(ImVec2(c + 17, u + 20), ImVec2(c + 17, u + 21), ImColor(9, 20, 31, 255));
	draww->AddLine(ImVec2(c + 18, u + 20), ImVec2(c + 18, u + 21), ImColor(11, 25, 37, 255));
	draww->AddLine(ImVec2(c + 19, u + 20), ImVec2(c + 19, u + 21), ImColor(24, 63, 79, 255));
	draww->AddLine(ImVec2(c + 20, u + 20), ImVec2(c + 22, u + 20), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 22, u + 20), ImVec2(c + 22, u + 21), ImColor(18, 47, 62, 255));
	draww->AddLine(ImVec2(c + 23, u + 20), ImVec2(c + 23, u + 21), ImColor(17, 44, 58, 255));
	draww->AddLine(ImVec2(c + 24, u + 20), ImVec2(c + 24, u + 21), ImColor(11, 25, 37, 255));
	draww->AddLine(ImVec2(c + 25, u + 20), ImVec2(c + 25, u + 21), ImColor(32, 88, 108, 255));
	draww->AddLine(ImVec2(c + 26, u + 20), ImVec2(c + 28, u + 20), ImColor(30, 83, 102, 255));
	draww->AddLine(ImVec2(c + 28, u + 20), ImVec2(c + 28, u + 21), ImColor(25, 67, 84, 255));
	draww->AddLine(ImVec2(c + 29, u + 20), ImVec2(c + 29, u + 21), ImColor(21, 56, 72, 255));
	draww->AddLine(ImVec2(c + 30, u + 20), ImVec2(c + 30, u + 21), ImColor(14, 34, 47, 255));
	draww->AddLine(ImVec2(c + 31, u + 20), ImVec2(c + 33, u + 20), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 33, u + 20), ImVec2(c + 33, u + 21), ImColor(12, 28, 40, 255));
	draww->AddLine(ImVec2(c + 34, u + 20), ImVec2(c + 34, u + 21), ImColor(23, 62, 78, 255));
	draww->AddLine(ImVec2(c + 35, u + 20), ImVec2(c + 35, u + 21), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 36, u + 20), ImVec2(c + 36, u + 21), ImColor(10, 22, 34, 255));
	draww->AddLine(ImVec2(c + 37, u + 20), ImVec2(c + 37, u + 21), ImColor(25, 67, 84, 255));
	draww->AddLine(ImVec2(c + 38, u + 20), ImVec2(c + 40, u + 20), ImColor(8, 8, 13, 255));
	draww->AddLine(ImVec2(c + 40, u + 20), ImVec2(c + 40, u + 21), ImColor(13, 31, 44, 255));
	draww->AddLine(ImVec2(c + 41, u + 20), ImVec2(c + 41, u + 21), ImColor(32, 89, 109, 255));
	draww->AddLine(ImVec2(c + 42, u + 20), ImVec2(c + 42, u + 21), ImColor(35, 97, 118, 255));
	draww->AddLine(ImVec2(c + 43, u + 20), ImVec2(c + 43, u + 21), ImColor(26, 69, 86, 255));
	draww->AddLine(ImVec2(c + 44, u + 20), ImVec2(c + 44, u + 21), ImColor(10, 21, 33, 255));
}

std::string Recoil_System_Value_IntA;
std::string Flick_Bot_FOVX_Level_IntA;
std::string Trigger_Bot_Smooth_Level_IntA;
std::string Trigger_Bot_Shots_Speed_Level_IntA;
std::string Flick_Bot_FOVY_Level_IntA;
std::string Recoil_System_Speed_IntA;
std::string Flick_Bot_Smooth_Level_IntA;
std::string Aim_Bot_FOVY_Level_IntA;
std::string Aim_Bot_FOVX_Level_IntA;
std::string Aim_Bot_Quality_Level_IntA;
std::string Trigger_Bot_SmoothLevel_IntA;

static int Recoil_System_Value_Int = 0;
static int Flick_Bot_FOVX_Level_Int = 0;
static int Trigger_Bot_Smooth_Level_Int = 0;
static int Trigger_Bot_Shots_Speed_Level_Int = 0;
static int Flick_Bot_FOVY_Level_Int = 0;
static int Flick_Bot_Smooth_Level_Int = 0;
static int Aim_Bot_FOVX_Level_Int = 0;
static int Aim_Bot_Quality_Level_Int = 0;




int Flick_Bot_FOVX_X = 162; int Flick_Bot_FOVX_Y = 283 - 141;
int Trigger_Bot_Smooth_Level_X = 162; int Trigger_Bot_Smooth_Level_Y = 197 - 66;
int Trigger_Bot_Shots_Speed_Level_X = 162; int Trigger_Bot_Shots_Speed_Level_Y = 197 - 66 + 43;
int Flick_Bot_FOVY_X = 162; int Flick_Bot_FOVY_Y = 283 - 141;
int Recoil_System_Speed_X = 162; int Recoil_System_Speed_Y = 197 - 99;
int Flick_Bot_Smooth_Level_X = 162; int Flick_Bot_Smooth_Level_Y = 99;
int Aim_Bot_FOVY_X = 162; int Aim_Bot_FOVY_Y = 283 - 66;
int Aim_Bot_FOVX_X = 162; int Aim_Bot_FOVX_Y = 283 - 66;
int Aim_Bot_Quality_X = 162; int Aim_Bot_Quality_Y = 240 - 66;
int Trigger_Bot_SmoothLevel_X = 162; int Trigger_Bot_SmoothLevel_Y = 197 - 66;
int Recoil_System_Value_X = 162; int Recoil_System_Value_Y = 197 - 66 + 43;

static float Alpha = 255;
static float Speed = 1.0f;
static bool Tick = false;

static bool Ignore_Sky_Skills = true;
static bool Ignore_anba_Skills = true;




namespace Colors
{
	ImVec4 Renk5 = imguipp::to_vec4(153, 176, 189, 255);
	ImVec4 Renk10 = imguipp::to_vec4(2, 19, 39, 255);
	ImVec4 Renk9 = imguipp::to_vec4(3, 5, 13, 255);
	ImVec4 Renk2 = imguipp::to_vec4(28, 28, 28, 255);
	ImVec4 Renk4 = imguipp::to_vec4(8, 16, 27, 255);
	ImVec4 Renk31 = imguipp::to_vec4(8, 8, 13, 255);

	ImVec4 Black = imguipp::to_vec4(0, 0, 0, 0);

	ImVec4 COL = imguipp::to_vec4(3, 168, 245, 255);

	ImVec4 COL2 = imguipp::to_vec4(49, 69, 82, 255);

	ImVec4 COL3 = imguipp::to_vec4(49, 69, 82, 255);

	ImVec4 S1 = imguipp::to_vec4(0, 11, 22, 255);
	ImVec4 S2 = imguipp::to_vec4(8, 8, 13, 255);

	ImVec4 Acik = imguipp::to_vec4(8, 16, 27, 255);
	ImVec4 Kapali = imguipp::to_vec4(8, 8, 13, 255);

	ImVec4 anil = imguipp::to_vec4(153, 176, 189, 255);

	ImVec4 R1 = imguipp::to_vec4(3, 168, 245, 255);
	ImVec4 R2 = imguipp::to_vec4(4, 141, 204, 255);
	ImVec4 R3 = imguipp::to_vec4(3, 113, 163, 255);
	ImVec4 R4 = imguipp::to_vec4(2, 84, 122, 255);
	ImVec4 R5 = imguipp::to_vec4(2, 56, 82, 255);
	ImVec4 R6 = imguipp::to_vec4(1, 28, 41, 255);

	ImVec4 R1t = imguipp::to_vec4(2, 79, 115, 255);
	ImVec4 R2t = imguipp::to_vec4(3, 67, 96, 255);
	ImVec4 R3t = imguipp::to_vec4(2, 53, 77, 255);
	ImVec4 R4t = imguipp::to_vec4(2, 40, 58, 255);
	ImVec4 R5t = imguipp::to_vec4(2, 27, 39, 255);
	ImVec4 R6t = imguipp::to_vec4(1, 14, 20, 255);

	ImVec4 E1 = imguipp::to_vec4(3, 108, 245, 255);
	ImVec4 E2 = imguipp::to_vec4(43, 108, 245, 255);
	ImVec4 E3 = imguipp::to_vec4(83, 108, 245, 255);
	ImVec4 E4 = imguipp::to_vec4(123, 108, 245, 255);
	ImVec4 E5 = imguipp::to_vec4(163, 108, 245, 255);
	ImVec4 E6 = imguipp::to_vec4(203, 108, 245, 255);

	ImVec4 E1t = imguipp::to_vec4(2, 42, 92, 255);
	ImVec4 E2t = imguipp::to_vec4(17, 42, 92, 255);
	ImVec4 E3t = imguipp::to_vec4(31, 41, 92, 255);
	ImVec4 E4t = imguipp::to_vec4(46, 41, 92, 255);
	ImVec4 E5t = imguipp::to_vec4(62, 41, 92, 255);
	ImVec4 E6t = imguipp::to_vec4(76, 41, 92, 255);

	ImVec4 Silver = imguipp::to_vec4(153, 176, 189, 255);
	ImVec4 White = imguipp::to_vec4(255, 255, 255, 255);

	ImVec4 BAKA = imguipp::to_vec4(8, 8, 13, 255);
}
using namespace Colors;

void Menu::Render()
{

	ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(408, 422));

	draww = ImGui::GetWindowDrawList();
	pos = ImGui::GetWindowPos();

	draww->AddText(tolstiy, 15.0f, ImVec2(pos.x + 5, pos.y + 7), ImColor(3, 168, 245, (int)Alpha), anbaCrypt("MadApex  Version  -  2.3"));
	draww->AddText(tolstiy, 14.0f, ImVec2(pos.x + 155, pos.y + 8), ImColor(153, 176, 189, (int)Alpha), anbaCrypt("MadUI.app  -  Cheater.net"));

	//Button "Aimbot"
	ImGui::Spacing();
	ImGui::SetCursorPos(ImVec2(340 + 48, 9));
	ImGui::PushStyleColor(ImGuiCol_Anil, COL);
	ImGui::PushStyleColor(ImGuiCol_Anill, COL);
	ImGui::PushStyleColor(ImGuiCol_Anilll, COL2);
	ImGui::PushStyleColor(ImGuiCol_Button, Renk4);

	if (ImGui::ButtonExip(anbaCrypt("X"), ImVec2(12, 11))) { exit(31); exit(0); }
	ImGui::PopStyleColor();

	if (Tick || Alpha >= 255)
	{
		Tick = true;
		if (!(Alpha <= 120))
			Alpha -= Speed + 2;
		else if (Alpha <= 120)
			Tick ^= 1;
	}
	else if (!Tick || Alpha != 255)
	{
		Tick = false;
		if (!(Alpha >= 255))
			Alpha += Speed + 2;
		else if (Alpha >= 255)
			Tick ^= 1;
	}

	draww->AddRectFilled(ImVec2(pos.x + 0, pos.y + 27), ImVec2(pos.x + 404, pos.y + 29), ImColor(3, 168, 245, (int)Alpha)), 15;

	draww->AddRect(ImVec2(pos.x + 4, pos.y + 99 - 65), ImVec2(pos.x + 78 + 15, pos.y + 356 + 62), ImColor(COL2));
	draww->AddRect(ImVec2(pos.x + 5, pos.y + 100 - 65), ImVec2(pos.x + 77 + 15, pos.y + 355 + 62), ImColor(S1));
	draww->AddRectFilled(ImVec2(pos.x + 6, pos.y + 101 - 65), ImVec2(pos.x + 76 + 15, pos.y + 354 + 62), ImColor(S2));

	draww->AddRect(ImVec2(pos.x + 98 + 9 - 17 + 15, pos.y + 99 - 65), ImVec2(pos.x + 355 + 9 + 40, pos.y + 356 + 62), ImColor(COL2));
	draww->AddRect(ImVec2(pos.x + 99 + 9 - 17 + 15, pos.y + 100 - 65), ImVec2(pos.x + 354 + 9 + 40, pos.y + 355 + 62), ImColor(S1));
	draww->AddRectFilled(ImVec2(pos.x + 100 + 9 - 17 + 15, pos.y + 101 - 65), ImVec2(pos.x + 353 + 9 + 40, pos.y + 354 + 62), ImColor(S2));

	//Button "Aim Bot"
	ImGui::Spacing();
	ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? Acik : Kapali);
	ImGui::PushStyleColor(ImGuiCol_Anil, COL);
	ImGui::PushStyleColor(ImGuiCol_Anill, COL);
	ImGui::PushStyleColor(ImGuiCol_Anilll, COL2);
	ImGui::SetCursorPos(ImVec2(6, 40));
	if (ImGui::ButtonExitt(anbaCrypt("  Aim Bot  "), ImVec2(70, 53 - 4))) Settings::Tab = 1;
	ImGui::PopStyleColor();

	//Button "Wall Hack"
	ImGui::Spacing();
	ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? Acik : Kapali);
	ImGui::PushStyleColor(ImGuiCol_Anil, COL);
	ImGui::PushStyleColor(ImGuiCol_Anill, COL);
	ImGui::PushStyleColor(ImGuiCol_Anilll, COL2);
	ImGui::SetCursorPos(ImVec2(6, 94));
	if (ImGui::ButtonExitt(anbaCrypt(" Wall Hack"), ImVec2(70, 53 - 4))) Settings::Tab = 2;
	ImGui::PopStyleColor();

	//Button "Skin Changer"
	ImGui::Spacing();
	ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? Acik : Kapali);
	ImGui::PushStyleColor(ImGuiCol_Anil, COL);
	ImGui::PushStyleColor(ImGuiCol_Anill, COL);
	ImGui::PushStyleColor(ImGuiCol_Anilll, COL2);
	ImGui::SetCursorPos(ImVec2(6, 148));
	if (ImGui::ButtonExitt(anbaCrypt("      Skin"), ImVec2(70, 53 - 4))) Settings::Tab = 3;
	ImGui::PopStyleColor();

	//Button "Recoil"
	ImGui::Spacing();
	ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? Acik : Kapali);
	ImGui::PushStyleColor(ImGuiCol_Anil, COL);
	ImGui::PushStyleColor(ImGuiCol_Anill, COL);
	ImGui::PushStyleColor(ImGuiCol_Anilll, COL2);
	ImGui::SetCursorPos(ImVec2(6, 202));
	if (ImGui::ButtonExitt(anbaCrypt("    Recoil"), ImVec2(70, 53 - 4))) Settings::Tab = 4;
	ImGui::PopStyleColor();


	//Button "Info"
	ImGui::Spacing();
	ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 7 ? Acik : Kapali);
	ImGui::PushStyleColor(ImGuiCol_Anil, COL);
	ImGui::PushStyleColor(ImGuiCol_Anill, COL);
	ImGui::PushStyleColor(ImGuiCol_Anilll, COL2);
	ImGui::SetCursorPos(ImVec2(6, 364));
	if (ImGui::ButtonExitt(anbaCrypt("      Info"), ImVec2(70, 53 - 4))) Settings::Tab = 7;
	ImGui::PopStyleColor();

	if /*Aimbot*/ (Settings::Tab == 1)
	{
		draww = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos();

		draww->AddRectFilled(ImVec2(pos.x + 4, pos.y + 40 - 2), ImVec2(pos.x + 78 + 15, pos.y + 40 + 49), ImColor(Acik), 0.0f, 15);
		draww->AddLine(ImVec2(pos.x + 4, pos.y + 40 + 49), ImVec2(pos.x + 78 + 15, pos.y + 40 + 49), ImColor(COL2));
		draww->AddLine(ImVec2(pos.x + 5, pos.y + 40 + 50), ImVec2(pos.x + 77 + 15, pos.y + 40 + 50), ImColor(S1));

		draww->AddLine(ImVec2(pos.x + 5, pos.y + 40 - 3), ImVec2(pos.x + 77 + 15, pos.y + 40 - 3), ImColor(S1));
		draww->AddLine(ImVec2(pos.x + 4, pos.y + 40 - 2), ImVec2(pos.x + 78 + 15, pos.y + 40 - 2), ImColor(COL2));
		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 13, pos.y + 40 + 15), ImColor(3, 168, 245, (int)Alpha), anbaCrypt("  Aim Bot  "));


		//Check Boxes
		draww = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos();
		{
			ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 500.0f);
			ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.10f, 0.09f, 0.12f, 1.00f));

			ImGui::SetCursorPos(ImVec2(363, 43));
			ImGui::Checkbox(anbaCrypt("Enable Aim Bot"), &aimbot);

			ImGui::SetCursorPos(ImVec2(363, 75));
			ImGui::Checkbox(anbaCrypt("Enable Ignore Sky Skills"), &Ignore_Sky_Skills);

			ImGui::PopStyleColor();
			ImGui::PopStyleVar();
		}

		draww->AddLine(ImVec2(pos.x + 111, pos.y + 166 - 68), ImVec2(pos.x + 398, pos.y + 166 - 68), ImColor(COL2));

		//Slider
		{


			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			draww->AddRectFilled(ImVec2(pos.x + Trigger_Bot_SmoothLevel_X - 5 + 205, pos.y + Trigger_Bot_SmoothLevel_Y + 1.5),
				ImVec2(pos.x + Trigger_Bot_SmoothLevel_X + 29 + 205, pos.y + Trigger_Bot_SmoothLevel_Y + 21.5), ImColor(Renk10), 7.0f, 15);
			draww->AddRectFilled(ImVec2(pos.x + Trigger_Bot_SmoothLevel_X - 4 + 205, pos.y + Trigger_Bot_SmoothLevel_Y + 2.5),
				ImVec2(pos.x + Trigger_Bot_SmoothLevel_X + 28 + 205, pos.y + Trigger_Bot_SmoothLevel_Y + 20.5), ImColor(Renk9), 7.0f, 15);
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 7.0f);
			ImGui::PushStyleColor(ImGuiCol_FrameBg, Renk9);
			ImGui::PushStyleColor(ImGuiCol_Text, COL);
			ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, Black);
			ImGui::PushItemWidth(23); ImGui::SetCursorPos(ImVec2(Trigger_Bot_SmoothLevel_X - 3, Trigger_Bot_SmoothLevel_Y + 1));
			ImGui::PopStyleColor(); ImGui::PopStyleVar();
			ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 500.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f);
			ImGui::PushStyleColor(ImGuiCol_SliderGrab, COL);
			ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, Renk2);
			ImGui::PushStyleColor(ImGuiCol_Text, Renk5);
			ImGui::PushItemWidth(243); ImGui::SetCursorPos(ImVec2(Trigger_Bot_SmoothLevel_X - 49, Trigger_Bot_SmoothLevel_Y - 3));
			ImGui::SliderInt(anbaCrypt("Smooth Level"), &smooth, 0, 100);
			Trigger_Bot_SmoothLevel_IntA = std::to_string(smooth);
			ImGui::PopStyleColor(); ImGui::PopStyleVar();
			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			ImGui::PushItemWidth(23); ImGui::SetCursorPos(ImVec2(Trigger_Bot_SmoothLevel_X - 3 + 205, Trigger_Bot_SmoothLevel_Y + 1));
			ImGui::Text(Trigger_Bot_SmoothLevel_IntA.c_str());
		}

		//Slider2
		{


			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			draww->AddRectFilled(ImVec2(pos.x + Aim_Bot_Quality_X - 5 + 205, pos.y + Aim_Bot_Quality_Y + 1.5),
				ImVec2(pos.x + Aim_Bot_Quality_X + 29 + 205, pos.y + Aim_Bot_Quality_Y + 21.5), ImColor(Renk10), 7.0f, 15);
			draww->AddRectFilled(ImVec2(pos.x + Aim_Bot_Quality_X - 4 + 205, pos.y + Aim_Bot_Quality_Y + 2.5),
				ImVec2(pos.x + Aim_Bot_Quality_X + 28 + 205, pos.y + Aim_Bot_Quality_Y + 20.5), ImColor(Renk9), 7.0f, 15);
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 7.0f);
			ImGui::PushStyleColor(ImGuiCol_FrameBg, Renk9);
			ImGui::PushStyleColor(ImGuiCol_Text, COL);
			ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, Black);
			ImGui::PushItemWidth(23); ImGui::SetCursorPos(ImVec2(Aim_Bot_Quality_X - 3, Aim_Bot_Quality_Y + 1));
			ImGui::PopStyleColor(); ImGui::PopStyleVar();
			ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 500.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f);
			ImGui::PushStyleColor(ImGuiCol_SliderGrab, COL);
			ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, Renk2);
			ImGui::PushStyleColor(ImGuiCol_Text, Renk5);
			ImGui::PushItemWidth(243); ImGui::SetCursorPos(ImVec2(Aim_Bot_Quality_X - 49, Aim_Bot_Quality_Y - 3));
			ImGui::SliderInt(anbaCrypt("Quality Level"), &Aim_Bot_Quality_Level_Int, 0, 100);
			Aim_Bot_Quality_Level_IntA = std::to_string(Aim_Bot_Quality_Level_Int);
			ImGui::PopStyleColor(); ImGui::PopStyleVar();
			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			ImGui::PushItemWidth(23); ImGui::SetCursorPos(ImVec2(Aim_Bot_Quality_X - 3 + 205, Aim_Bot_Quality_Y + 1));
			ImGui::Text(Aim_Bot_Quality_Level_IntA.c_str());
		}

		//Slider4
		{


			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			draww->AddRectFilled(ImVec2(pos.x + Aim_Bot_FOVY_X - 5 + 57 + 148, pos.y + Aim_Bot_FOVY_Y + 1.5),
				ImVec2(pos.x + Aim_Bot_FOVY_X + 29 + 57 + 148, pos.y + Aim_Bot_FOVY_Y + 21.5), ImColor(Renk10), 7.0f, 15);
			draww->AddRectFilled(ImVec2(pos.x + Aim_Bot_FOVY_X - 4 + 57 + 148, pos.y + Aim_Bot_FOVY_Y + 2.5),
				ImVec2(pos.x + Aim_Bot_FOVY_X + 28 + 57 + 148, pos.y + Aim_Bot_FOVY_Y + 20.5), ImColor(Renk9), 7.0f, 15);
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 7.0f);
			ImGui::PushStyleColor(ImGuiCol_FrameBg, Renk9);
			ImGui::PushStyleColor(ImGuiCol_Text, COL);
			ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, Black);
			ImGui::PushItemWidth(23); ImGui::SetCursorPos(ImVec2(Aim_Bot_FOVY_X - 3, Aim_Bot_FOVY_Y + 1));
			ImGui::PopStyleColor(); ImGui::PopStyleVar();
			ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 500.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f);
			ImGui::PushStyleColor(ImGuiCol_SliderGrab, COL);
			ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, Renk2);
			ImGui::PushStyleColor(ImGuiCol_Text, Renk5);
			ImGui::PushItemWidth(243); ImGui::SetCursorPos(ImVec2(Aim_Bot_FOVY_X - 49, Aim_Bot_FOVY_Y - 3));
			ImGui::SliderInt(anbaCrypt("FOV Size"), &fov, 0, 100);
			Aim_Bot_FOVY_Level_IntA = std::to_string(fov);
			ImGui::PopStyleColor(); ImGui::PopStyleVar();
			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			ImGui::PushItemWidth(23); ImGui::SetCursorPos(ImVec2(Aim_Bot_FOVY_X - 3 + 205, Aim_Bot_FOVY_Y + 1));
			ImGui::Text(Aim_Bot_FOVY_Level_IntA.c_str());
		}

		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 111, pos.y + 310 - 68), ImColor(3, 168, 245, (int)Alpha), anbaCrypt("      Do not forget to key assignments"));

		draww->AddLine(ImVec2(pos.x + 111, pos.y + 313 + 22 - 66), ImVec2(pos.x + 398, pos.y + 313 + 22 - 66), ImColor(COL2));

		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 111, pos.y + 347 + 4 - 66), ImColor(153, 176, 189, 255), anbaCrypt("Aim Bot Key"));

		//Button "Aim bot Key"
		ImGui::Spacing();
		ImGui::SetCursorPos(ImVec2(290, 348 + 2 - 66));
		ImGui::PushStyleColor(ImGuiCol_Button, BAKA);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, BAKA);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, BAKA);
		AimBotKeyButton(AimBotKey, AimBotChangeKey, AimBotKeyStatus, ImVec2(105, 20));
		ImGui::PopStyleColor();

	}

	if /*Wall Hack*/ (Settings::Tab == 2)
	{
		draww = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos();

		draww->AddRectFilled(ImVec2(pos.x + 4, pos.y + 94 - 2), ImVec2(pos.x + 78 + 15, pos.y + 94 + 49), ImColor(Acik), 0.0f, 15);
		draww->AddLine(ImVec2(pos.x + 4, pos.y + 94 + 49), ImVec2(pos.x + 78 + 15, pos.y + 94 + 49), ImColor(COL2));
		draww->AddLine(ImVec2(pos.x + 5, pos.y + 94 + 50), ImVec2(pos.x + 77 + 15, pos.y + 94 + 50), ImColor(S1));

		draww->AddLine(ImVec2(pos.x + 5, pos.y + 94 - 3), ImVec2(pos.x + 77 + 15, pos.y + 94 - 3), ImColor(S1));
		draww->AddLine(ImVec2(pos.x + 4, pos.y + 94 - 2), ImVec2(pos.x + 78 + 15, pos.y + 94 - 2), ImColor(COL2));
		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 13, pos.y + 94 + 15), ImColor(3, 168, 245, (int)Alpha), anbaCrypt(" Wall Hack"));

		//Check Boxes
		draww = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos();
		{
			ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 500.0f);
			ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.10f, 0.09f, 0.12f, 1.00f));

			ImGui::SetCursorPos(ImVec2(363, 43));
			ImGui::Checkbox(anbaCrypt("Enable Wall Hack"), &glow);


			ImGui::SetCursorPos(ImVec2(363, 75));
			ImGui::Checkbox(anbaCrypt("Enable Ignore an&ba Skills"), &Ignore_anba_Skills);


			ImGui::PopStyleColor();
			ImGui::PopStyleVar();
		}

		draww->AddLine(ImVec2(pos.x + 111, pos.y + 98), ImVec2(pos.x + 398, pos.y + 98), ImColor(COL2));

		//Config
		{

			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 100 + 13, pos.y + 100 + 12), ImColor(COL), anbaCrypt("Visible"));

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(114, 132));
			ImGui::PushStyleColor(ImGuiCol_Anil, R1);
			ImGui::PushStyleColor(ImGuiCol_Anill, R1);
			ImGui::PushStyleColor(ImGuiCol_Anilll, R1t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass(anbaCrypt("#1"), ImVec2(40, 21))) { Settings::malyusuf = 1; Visible = R1; }
			ImGui::PopStyleColor();

			if (Settings::malyusuf == 1)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14, pos.y + 100 + 32), ImVec2(pos.x + 140 + 14, pos.y + 121 + 32), ImColor(R1), 7.0, 15);

				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116, pos.y + 133), ImColor(White), anbaCrypt("#1"));
			}

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(118 + 44, 132));
			ImGui::PushStyleColor(ImGuiCol_Anil, R2);
			ImGui::PushStyleColor(ImGuiCol_Anill, R2);
			ImGui::PushStyleColor(ImGuiCol_Anilll, R2t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass(anbaCrypt("#2"), ImVec2(40, 21))) { Settings::malyusuf = 2; Visible = R2; }
			ImGui::PopStyleColor();

			if (Settings::malyusuf == 2)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14 + 48, pos.y + 100 + 32), ImVec2(pos.x + 140 + 14 + 48, pos.y + 121 + 32), ImColor(R2), 7.0, 15);

				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116 + 48, pos.y + 133), ImColor(White), anbaCrypt("#2"));
			}

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(122 + 44 + 44, 132));
			ImGui::PushStyleColor(ImGuiCol_Anil, R3);
			ImGui::PushStyleColor(ImGuiCol_Anill, R3);
			ImGui::PushStyleColor(ImGuiCol_Anilll, R3t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass(anbaCrypt("#3"), ImVec2(40, 21))) { Settings::malyusuf = 3; Visible = R3; }
			ImGui::PopStyleColor();

			if (Settings::malyusuf == 3)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14 + 48 + 48, pos.y + 100 + 32), ImVec2(pos.x + 140 + 14 + 48 + 48, pos.y + 121 + 32), ImColor(R3), 7.0, 15);

				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116 + 48 + 48, pos.y + 133), ImColor(White), anbaCrypt("#3"));
			}

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(127 + 44 + 44 + 44, 132));
			ImGui::PushStyleColor(ImGuiCol_Anil, R4);
			ImGui::PushStyleColor(ImGuiCol_Anill, R4);
			ImGui::PushStyleColor(ImGuiCol_Anilll, R4t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass("#4", ImVec2(40, 21))) { Settings::malyusuf = 4; Visible = R4; }
			ImGui::PopStyleColor();

			if (Settings::malyusuf == 4)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14 + 48 + 48 + 49, pos.y + 100 + 32), ImVec2(pos.x + 140 + 14 + 48 + 48 + 49, pos.y + 121 + 32), ImColor(R4), 7.0, 15);

				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116 + 48 + 48 + 49, pos.y + 133), ImColor(White), anbaCrypt("#4"));
			}

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(131 + 44 + 44 + 44 + 44, 132));
			ImGui::PushStyleColor(ImGuiCol_Anil, R5);
			ImGui::PushStyleColor(ImGuiCol_Anill, R5);
			ImGui::PushStyleColor(ImGuiCol_Anilll, R5t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass(anbaCrypt("#5"), ImVec2(40, 21))) { Settings::malyusuf = 5; Visible = R5; }
			ImGui::PopStyleColor();

			if (Settings::malyusuf == 5)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14 + 48 + 48 + 49 + 48, pos.y + 100 + 32), ImVec2(pos.x + 140 + 14 + 48 + 48 + 49 + 48, pos.y + 121 + 32), ImColor(R5), 7.0, 15);

				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116 + 48 + 48 + 49 + 48, pos.y + 133), ImColor(White), anbaCrypt("#5"));
			}

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(135 + 44 + 44 + 44 + 44 + 44, 132));
			ImGui::PushStyleColor(ImGuiCol_Anil, R6);
			ImGui::PushStyleColor(ImGuiCol_Anill, R6);
			ImGui::PushStyleColor(ImGuiCol_Anilll, R6t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass(anbaCrypt("#6"), ImVec2(40, 21))) { Settings::malyusuf = 6; Visible = R6; }
			ImGui::PopStyleColor();

			if (Settings::malyusuf == 6)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14 + 48 + 48 + 49 + 48 + 48, pos.y + 100 + 32), ImVec2(pos.x + 140 + 14 + 48 + 48 + 49 + 48 + 48, pos.y + 121 + 32), ImColor(R6), 7.0, 15);


				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116 + 48 + 48 + 49 + 48 + 48, pos.y + 133), ImColor(White), anbaCrypt("#6"));
			}

		}

		draww = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos();
		//Config2
		{


			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 100 + 13, pos.y + 100 + 55), ImColor(COL), anbaCrypt("Invisible"));

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(114, 132 + 43));
			ImGui::PushStyleColor(ImGuiCol_Anil, E1);
			ImGui::PushStyleColor(ImGuiCol_Anill, E1);
			ImGui::PushStyleColor(ImGuiCol_Anilll, E1t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass("#1 ", ImVec2(40, 21))) { Settings::malege = 1; Invisible = E1; }
			ImGui::PopStyleColor();

			if (Settings::malege == 1)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14, pos.y + 100 + 32 + 43), ImVec2(pos.x + 140 + 14, pos.y + 121 + 32 + 43), ImColor(E1), 7.0, 15);

				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116, pos.y + 133 + 43), ImColor(White), anbaCrypt("#1"));
			}

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(118 + 44, 132 + 43));
			ImGui::PushStyleColor(ImGuiCol_Anil, E2);
			ImGui::PushStyleColor(ImGuiCol_Anill, E2);
			ImGui::PushStyleColor(ImGuiCol_Anilll, E2t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass(anbaCrypt("#2 "), ImVec2(40, 21))) { Settings::malege = 2; Invisible = E2; }
			ImGui::PopStyleColor();

			if (Settings::malege == 2)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14 + 48, pos.y + 100 + 32 + 43), ImVec2(pos.x + 140 + 14 + 48, pos.y + 121 + 32 + 43), ImColor(E2), 7.0, 15);

				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116 + 48, pos.y + 133 + 43), ImColor(White), anbaCrypt("#2"));
			}

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(122 + 44 + 44, 132 + 43));
			ImGui::PushStyleColor(ImGuiCol_Anil, E3);
			ImGui::PushStyleColor(ImGuiCol_Anill, E3);
			ImGui::PushStyleColor(ImGuiCol_Anilll, E3t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass(anbaCrypt("#3 "), ImVec2(40, 21))) { Settings::malege = 3; Invisible = E3; }
			ImGui::PopStyleColor();

			if (Settings::malege == 3)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14 + 48 + 48, pos.y + 100 + 32 + 43), ImVec2(pos.x + 140 + 14 + 48 + 48, pos.y + 121 + 32 + 43), ImColor(E3), 7.0, 15);

				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116 + 48 + 48, pos.y + 133 + 43), ImColor(White), anbaCrypt("#3"));
			}

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(127 + 44 + 44 + 44, 132 + 43));
			ImGui::PushStyleColor(ImGuiCol_Anil, E4);
			ImGui::PushStyleColor(ImGuiCol_Anill, E4);
			ImGui::PushStyleColor(ImGuiCol_Anilll, E4t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass(anbaCrypt("#4 "), ImVec2(40, 21))) { Settings::malege = 4; Invisible = E4; }
			ImGui::PopStyleColor();

			if (Settings::malege == 4)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14 + 48 + 48 + 49, pos.y + 100 + 32 + 43), ImVec2(pos.x + 140 + 14 + 48 + 48 + 49, pos.y + 43 + 121 + 32), ImColor(E4), 7.0, 15);

				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116 + 48 + 48 + 49, pos.y + 133 + 43), ImColor(White), anbaCrypt("#4"));
			}

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(131 + 44 + 44 + 44 + 44, 132 + 43));
			ImGui::PushStyleColor(ImGuiCol_Anil, E5);
			ImGui::PushStyleColor(ImGuiCol_Anill, E5);
			ImGui::PushStyleColor(ImGuiCol_Anilll, E5t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass(anbaCrypt("#5 "), ImVec2(40, 21))) { Settings::malege = 5; Invisible = E5; }
			ImGui::PopStyleColor();

			if (Settings::malege == 5)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14 + 48 + 48 + 49 + 48, pos.y + 100 + 32 + 43), ImVec2(pos.x + 140 + 14 + 48 + 48 + 49 + 48, pos.y + 43 + 121 + 32), ImColor(E5), 7.0, 15);

				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116 + 48 + 48 + 49 + 48, pos.y + 133 + 43), ImColor(White), anbaCrypt("#5"));
			}

			ImGui::Spacing();
			ImGui::SetCursorPos(ImVec2(135 + 44 + 44 + 44 + 44 + 44, 132 + 43));
			ImGui::PushStyleColor(ImGuiCol_Anil, E6);
			ImGui::PushStyleColor(ImGuiCol_Anill, E6);
			ImGui::PushStyleColor(ImGuiCol_Anilll, E6t);

			ImGui::PushStyleColor(ImGuiCol_cols, White);
			ImGui::PushStyleColor(ImGuiCol_colss, White);
			ImGui::PushStyleColor(ImGuiCol_colsss, Silver);
			if (ImGui::Aleynaass(anbaCrypt("#6 "), ImVec2(40, 21))) { Settings::malege = 6; Invisible = E6; }
			ImGui::PopStyleColor();

			if (Settings::malege == 6)
			{
				draww->AddRectFilled(ImVec2(pos.x + 100 + 14 + 48 + 48 + 49 + 48 + 48, pos.y + 100 + 32 + 43), ImVec2(pos.x + 140 + 14 + 48 + 48 + 49 + 48 + 48, pos.y + 43 + 121 + 32), ImColor(E6), 7.0, 15);


				draww->AddText(nullptr, 13.0f, ImVec2(pos.x + 116 + 48 + 48 + 49 + 48 + 48, pos.y + 133 + 43), ImColor(White), anbaCrypt("#6"));
			}



		}

		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 111, pos.y + 201), ImColor(3, 168, 245, (int)Alpha), anbaCrypt("      Do not forget to key assignments"));

		draww->AddLine(ImVec2(pos.x + 111, pos.y + 227), ImVec2(pos.x + 398, pos.y + 227), ImColor(COL2));

		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 111, pos.y + 347 + 4 - 109), ImColor(153, 176, 189, 255), anbaCrypt("Enable Wall Hack Key"));

		//Button "Aim bot Key"
		ImGui::Spacing();
		ImGui::SetCursorPos(ImVec2(290, 348 + 2 - 109));
		ImGui::PushStyleColor(ImGuiCol_Button, BAKA);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, BAKA);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, BAKA);
		WallHackKeyButton(WallHackKey, WallHackChangeKey, WallHackKeyStatus, ImVec2(105, 20));
		ImGui::PopStyleColor();

	}

	if /*Skin*/ (Settings::Tab == 3)
	{
		draww = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos();

		draww->AddRectFilled(ImVec2(pos.x + 4, pos.y + 148 - 2), ImVec2(pos.x + 78 + 15, pos.y + 148 + 49), ImColor(Acik), 0.0f, 15);
		draww->AddLine(ImVec2(pos.x + 4, pos.y + 148 + 49), ImVec2(pos.x + 78 + 15, pos.y + 148 + 49), ImColor(COL2));
		draww->AddLine(ImVec2(pos.x + 5, pos.y + 148 + 50), ImVec2(pos.x + 77 + 15, pos.y + 148 + 50), ImColor(S1));

		draww->AddLine(ImVec2(pos.x + 5, pos.y + 148 - 3), ImVec2(pos.x + 77 + 15, pos.y + 148 - 3), ImColor(S1));
		draww->AddLine(ImVec2(pos.x + 4, pos.y + 148 - 2), ImVec2(pos.x + 78 + 15, pos.y + 148 - 2), ImColor(COL2));
		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 13, pos.y + 148 + 15), ImColor(3, 168, 245, (int)Alpha), anbaCrypt("      Skin"));

		//Check Boxes
		draww = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos();
		{
			ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 500.0f);
			ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.10f, 0.09f, 0.12f, 1.00f));

			ImGui::SetCursorPos(ImVec2(363, 43));
			ImGui::Checkbox(anbaCrypt("Skin Changer"), &skinchanger);

			ImGui::PopStyleColor();
			ImGui::PopStyleVar();
		}

		draww->AddLine(ImVec2(pos.x + 111, pos.y + 66), ImVec2(pos.x + 398, pos.y + 66), ImColor(COL2));

		//Slider
		{


			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			draww->AddRectFilled(ImVec2(pos.x + Recoil_System_Speed_X - 5 + 205, pos.y + Recoil_System_Speed_Y + 1.5),
				ImVec2(pos.x + Recoil_System_Speed_X + 29 + 205, pos.y + Recoil_System_Speed_Y + 21.5), ImColor(Renk10), 7.0f, 15);
			draww->AddRectFilled(ImVec2(pos.x + Recoil_System_Speed_X - 4 + 205, pos.y + Recoil_System_Speed_Y + 2.5),
				ImVec2(pos.x + Recoil_System_Speed_X + 28 + 205, pos.y + Recoil_System_Speed_Y + 20.5), ImColor(Renk9), 7.0f, 15);
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 7.0f);
			ImGui::PushStyleColor(ImGuiCol_FrameBg, Renk9);
			ImGui::PushStyleColor(ImGuiCol_Text, COL);
			ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, Black);
			ImGui::PushItemWidth(23); ImGui::SetCursorPos(ImVec2(Recoil_System_Speed_X - 3, Recoil_System_Speed_Y + 1));
			ImGui::PopStyleColor(); ImGui::PopStyleVar();
			ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 500.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f);
			ImGui::PushStyleColor(ImGuiCol_SliderGrab, COL);
			ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, Renk2);
			ImGui::PushStyleColor(ImGuiCol_Text, Renk5);
			ImGui::PushItemWidth(243); ImGui::SetCursorPos(ImVec2(Recoil_System_Speed_X - 49, Recoil_System_Speed_Y - 3));
			ImGui::SliderInt(anbaCrypt("Skin Number"), &skin_id, 0, 100);
			Recoil_System_Speed_IntA = std::to_string(skin_id / 5);
			ImGui::PopStyleColor(); ImGui::PopStyleVar();
			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			ImGui::PushItemWidth(23); ImGui::SetCursorPos(ImVec2(Recoil_System_Speed_X - 3 + 205, Recoil_System_Speed_Y + 1));
			ImGui::Text(Recoil_System_Speed_IntA.c_str());
		}


		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 111, pos.y + 201 - 77), ImColor(3, 168, 245, (int)Alpha), anbaCrypt("      Do not forget to key assignments"));

		draww->AddLine(ImVec2(pos.x + 111, pos.y + 227 - 77), ImVec2(pos.x + 398, pos.y + 227 - 77), ImColor(COL2));

		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 111, pos.y + 347 + 4 - 109 - 77), ImColor(153, 176, 189, 255), anbaCrypt("Enable Skin Changer"));

		//Button "Aim bot Key"
		ImGui::Spacing();
		ImGui::SetCursorPos(ImVec2(290, 348 + 2 - 109 - 77));
		ImGui::PushStyleColor(ImGuiCol_Button, BAKA);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, BAKA);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, BAKA);
		SkinKeyButton(SkinKey, SkinChangeKey, SkinKeyStatus, ImVec2(105, 20));
		ImGui::PopStyleColor();



	}

	if /*Recoil*/ (Settings::Tab == 4)
	{
		draww = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos();

		draww->AddRectFilled(ImVec2(pos.x + 4, pos.y + 202 - 2), ImVec2(pos.x + 78 + 15, pos.y + 202 + 49), ImColor(Acik), 0.0f, 15);
		draww->AddLine(ImVec2(pos.x + 4, pos.y + 202 + 49), ImVec2(pos.x + 78 + 15, pos.y + 202 + 49), ImColor(COL2));
		draww->AddLine(ImVec2(pos.x + 5, pos.y + 202 + 50), ImVec2(pos.x + 77 + 15, pos.y + 202 + 50), ImColor(S1));

		draww->AddLine(ImVec2(pos.x + 5, pos.y + 202 - 3), ImVec2(pos.x + 77 + 15, pos.y + 202 - 3), ImColor(S1));
		draww->AddLine(ImVec2(pos.x + 4, pos.y + 202 - 2), ImVec2(pos.x + 78 + 15, pos.y + 202 - 2), ImColor(COL2));
		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 13, pos.y + 202 + 15), ImColor(3, 168, 245, (int)Alpha), anbaCrypt("    Recoil"));

		//Check Boxes
		draww = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos();
		{
			ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 500.0f);
			ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.10f, 0.09f, 0.12f, 1.00f));

			ImGui::SetCursorPos(ImVec2(363, 43));
			ImGui::Checkbox(anbaCrypt("Enable Recoil Control System"), &norecoil);

			ImGui::PopStyleColor();
			ImGui::PopStyleVar();
		}

		draww->AddLine(ImVec2(pos.x + 111, pos.y + 66), ImVec2(pos.x + 398, pos.y + 66), ImColor(COL2));

		//Slider
		{


			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			draww->AddRectFilled(ImVec2(pos.x + Recoil_System_Speed_X - 5 + 205, pos.y + Recoil_System_Speed_Y + 1.5),
				ImVec2(pos.x + Recoil_System_Speed_X + 29 + 205, pos.y + Recoil_System_Speed_Y + 21.5), ImColor(Renk10), 7.0f, 15);
			draww->AddRectFilled(ImVec2(pos.x + Recoil_System_Speed_X - 4 + 205, pos.y + Recoil_System_Speed_Y + 2.5),
				ImVec2(pos.x + Recoil_System_Speed_X + 28 + 205, pos.y + Recoil_System_Speed_Y + 20.5), ImColor(Renk9), 7.0f, 15);
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 7.0f);
			ImGui::PushStyleColor(ImGuiCol_FrameBg, Renk9);
			ImGui::PushStyleColor(ImGuiCol_Text, COL);
			ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, Black);
			ImGui::PushItemWidth(23); ImGui::SetCursorPos(ImVec2(Recoil_System_Speed_X - 3, Recoil_System_Speed_Y + 1));
			ImGui::PopStyleColor(); ImGui::PopStyleVar();
			ImGui::PushStyleVar(ImGuiStyleVar_GrabRounding, 500.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f);
			ImGui::PushStyleColor(ImGuiCol_SliderGrab, COL);
			ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, Renk2);
			ImGui::PushStyleColor(ImGuiCol_Text, Renk5);
			ImGui::PushItemWidth(243); ImGui::SetCursorPos(ImVec2(Recoil_System_Speed_X - 49, Recoil_System_Speed_Y - 3));
			ImGui::SliderInt(anbaCrypt("Recoil Control System Intensity"), &norecoil_intensity, 0, 100);
			Recoil_System_Speed_IntA = std::to_string(norecoil_intensity);
			ImGui::PopStyleColor(); ImGui::PopStyleVar();
			draww = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();
			ImGui::PushItemWidth(23); ImGui::SetCursorPos(ImVec2(Recoil_System_Speed_X - 3 + 205, Recoil_System_Speed_Y + 1));
			ImGui::Text(Recoil_System_Speed_IntA.c_str());
		}


		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 111, pos.y + 201 - 77), ImColor(3, 168, 245, (int)Alpha), anbaCrypt("      Do not forget to key assignments"));

		draww->AddLine(ImVec2(pos.x + 111, pos.y + 227 - 77), ImVec2(pos.x + 398, pos.y + 227 - 77), ImColor(COL2));

		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 111, pos.y + 347 + 4 - 109 - 77), ImColor(153, 176, 189, 255), anbaCrypt("Enable R.C.S Key"));

		//Button "Recoil"
		ImGui::Spacing();
		ImGui::SetCursorPos(ImVec2(290, 348 + 2 - 109 - 77));
		ImGui::PushStyleColor(ImGuiCol_Button, BAKA);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, BAKA);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, BAKA);
		RecoilKeyButton(RecoilKey, RecoilChangeKey, RecoilKeyStatus, ImVec2(105, 20));
		ImGui::PopStyleColor();


	}

	if /*Info*/ (Settings::Tab == 7)
	{
		draww = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos();

		draww->AddRectFilled(ImVec2(pos.x + 4, pos.y + 364 - 2), ImVec2(pos.x + 78 + 15, pos.y + 364 + 49), ImColor(Acik), 0.0f, 15);
		draww->AddLine(ImVec2(pos.x + 4, pos.y + 364 + 49), ImVec2(pos.x + 78 + 15, pos.y + 364 + 49), ImColor(COL2));
		draww->AddLine(ImVec2(pos.x + 5, pos.y + 364 + 50), ImVec2(pos.x + 77 + 15, pos.y + 364 + 50), ImColor(S1));

		draww->AddLine(ImVec2(pos.x + 5, pos.y + 364 - 3), ImVec2(pos.x + 77 + 15, pos.y + 364 - 3), ImColor(S1));
		draww->AddLine(ImVec2(pos.x + 4, pos.y + 364 - 2), ImVec2(pos.x + 78 + 15, pos.y + 364 - 2), ImColor(COL2));
		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 13, pos.y + 364 + 15), ImColor(3, 168, 245, (int)Alpha), anbaCrypt("      Info"));

		draww->AddText(nullptr, 18.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 - 69), ImColor(153, 176, 189, 255), anbaCrypt("            MADAPEX  -  MADLOADER"));

		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 - 48), ImColor(3, 168, 245, 255), anbaCrypt("* Always Up-To-Date"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 - 34), ImColor(3, 168, 245, 255), anbaCrypt("MadLoader is updated regularly. It also always"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 - 20), ImColor(3, 168, 245, 255), anbaCrypt("Offers the latest versions of specific cheats."));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 - 6 + 8), ImColor(153, 176, 189, 255), anbaCrypt("* 100% Safe"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 8 + 8), ImColor(153, 176, 189, 255), anbaCrypt("Madloader is 100% safe, loader itself does not"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 22 + 8), ImColor(153, 176, 189, 255), anbaCrypt("Contain any harmful contents (e.g. s or RATs)"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 36 + 8), ImColor(153, 176, 189, 255), anbaCrypt("All cheats on Madloader are checked by us"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 50 + 8), ImColor(153, 176, 189, 255), anbaCrypt("First to make sure they're safe."));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 64 + 8 + 8), ImColor(3, 168, 245, 255), anbaCrypt("* Cheats for many games"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 64 + 14 + 8 + 8), ImColor(3, 168, 245, 255), anbaCrypt("Madloader offers cheats for CS:GO We make"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 64 + 14 + 14 + 8 + 8), ImColor(3, 168, 245, 255), anbaCrypt("Sure that all cheats are up-to-date. For a full"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 64 + 14 + 14 + 14 + 8 + 8), ImColor(3, 168, 245, 255), anbaCrypt("Cheat list, check our Forums!"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 64 + 14 + 14 + 14 + 14 + 8 + 8 + 8), ImColor(153, 176, 189, 255), anbaCrypt("* It's FREE."));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 64 + 14 + 14 + 14 + 14 + 14 + 8 + 8 + 8), ImColor(153, 176, 189, 255), anbaCrypt("Madloader is free. We earn money through"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 64 + 14 + 14 + 14 + 14 + 14 + 14 + 8 + 8 + 8), ImColor(153, 176, 189, 255), anbaCrypt("Ads, thanks to our custom ad approval."));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 64 + 14 + 14 + 14 + 14 + 14 + 14 + 14 + 8 + 8 + 8), ImColor(153, 176, 189, 255), anbaCrypt("All of the cheats will be avaible!"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 64 + 14 + 14 + 14 + 14 + 14 + 14 + 14 + 14 + 8 + 8 + 8), ImColor(153, 176, 189, 255), anbaCrypt("We do offer account upgrades, which"));
		draww->AddText(nullptr, 16.0f, ImVec2(pos.x + 112, pos.y + 242 - 131 + 64 + 14 + 14 + 14 + 14 + 14 + 14 + 14 + 14 + 14 + 8 + 8 + 8), ImColor(153, 176, 189, 255), anbaCrypt("Means you can get free access to Madloader."));

		cheaternet(pos.x + 113, pos.y + 385);

		anba(pos.x + 339, pos.y + 385);
	}



}



void Menu::Theme()
{


	ImGuiStyle* style = &ImGui::GetStyle();

	//Nesne şekil
	style->FrameRounding = 2, 5.0f;
	style->ChildRounding = 5, 5.0f;
	style->FramePadding = ImVec2(1, 1);

	//Form Ayarları
	style->WindowBorderSize = 0;
	style->WindowTitleAlign = ImVec2(0.5, 0.5);
	style->Colors[ImGuiCol_WindowBg] = ImColor(8, 16, 27, 255);

	//Butonlar
	style->Colors[ImGuiCol_Button] = ImColor(8, 16, 27, 250);

	style->ButtonTextAlign = ImVec2((float)(0), 0.5f);

	//Ust Panel
	style->Colors[ImGuiCol_TitleBg] = ImColor(0, 0, 0, 0);
	style->Colors[ImGuiCol_TitleBgActive] = ImColor(2, 83, 160, 0);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(2, 83, 160, 0);

	style->Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);

	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);

	style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);

	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);

	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

	style->Colors[ImGuiCol_ChildBg] = ImColor(8, 8, 13, 250);
	style->ChildBorderSize = 0.0f;

	style->Colors[ImGuiCol_CheckMark] = ImColor(2, 83, 160, 255);

	//Slider
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.56f, 0.99f, 0.83f, 0.57f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(39, 179, 254, 255);

	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f); //(39, 179, 254, 255);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);

	style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
}
//bool itemesp = false;
//int smooth = 6;
//int fov = 60;
//float norecoil_intensity = 100.0f;
//float color[4] = { Visible.w, Visible.x, Visible.y, Visible.z };
//float color2[4] = { Invisible.w, Invisible.x, Invisible.y, Invisible.z };
//int selected_hit;
//const char* hitbox[] = { "Head", "B0dy", "Neck" };
//bool glow = true;
//bool skinchanger = true;
//bool norecoil = true;
//bool aimbot = false;


//static int smooth = 0;
//static int skin_id = 0;
//static int fov = 0;
//static int norecoil_intensity = 0;
//static bool Smooth = true;
//static bool skinchanger = true;
//static bool aimbot = true;
//static bool norecoil = true;
//static bool glow = true;
//ImVec4 Visible = imguipp::to_vec4(0, 0, 0, 255);
//ImVec4 Invisible = imguipp::to_vec4(0, 0, 0, 255);


//static LPDIRECT3D9              g_pD3D = NULL;
//static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
//static D3DPRESENT_PARAMETERS    g_d3dpp = {};

bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void ActorLoop()
{
    AimContext aimCtx; aimCtx.closestX = 50000; aimCtx.closestY = 50000; aimCtx.FOV = fov; aimCtx.aSmoothAmount = smooth;
	if (glow)
	{
		for (int i = 0; i < 100; i++)
		{
			DWORD64 Entity = GetEntityById(i, driver::g_base);
			if (Entity == 0)
				continue;
			if (IsTeam(glocalplayer, Entity))
				continue;
			DWORD64 EntityHandle = driver::read<DWORD64>(Entity + M_INAME);
			std::string Identifier = driver::read<std::string>(EntityHandle);
			LPCSTR IdentifierC = Identifier.c_str();
			if (strcmp(IdentifierC, "player"))
			{
				uint64_t viewRenderer = driver::read<uint64_t>(driver::g_base + RENDER);
				uint64_t viewMatrix = driver::read<uint64_t>(viewRenderer + MATRIX);
				Matrix m = driver::read<Matrix>(viewMatrix);
				if (glow)
				{
					driver::write<int>(Entity + GLOW_ENABLE, 1);
				}
				else
				{
					driver::write<int>(Entity + GLOW_ENABLE, 2);
				}
				driver::write<int>(Entity + GLOW_THROUGH_WALLS, 2);
				driver::write<GlowMode>(Entity + GLOW_TYPE, { 101,101,46,90 });
				if (IsVisible(Entity, i))
				{
					Aimbot(Entity, glocalplayer, m, &aimCtx, i);
					driver::write<float>(Entity + GLOW_R, 0.f);
					driver::write<float>(Entity + GLOW_G, 0.f);
					driver::write<float>(Entity + GLOW_B, 255.f);
				}
				else
				{
					driver::write<float>(Entity + GLOW_R, 255.f);
					driver::write<float>(Entity + GLOW_G, 0.f);
					driver::write<float>(Entity + GLOW_B, 255.f);
				}
			}

		}
	}
    
    if (aimbot)
    {
        AimbotMove(&aimCtx);
    }
}

Vector3 oldPunch = { 0.f, 0.f, 0.f };
void NoRecoil()
{
    if (norecoil)
    {
		if (GetAsyncKeyState(VK_LBUTTON) & 1)
		{
			oldPunch = { 0.f, 0.f, 0.f };
		}
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            Vector3 viewAngles = driver::read<Vector3>(glocalplayer + VIEWANGLES);
            Vector3 punchAngle = driver::read<Vector3>(glocalplayer + AIMPUNCH);
            Vector3 newAngle = viewAngles + (oldPunch - punchAngle) * (norecoil_intensity / 100.0f);
            newAngle.Normalize();
			
				driver::write<Vector2>(glocalplayer + VIEWANGLES, { newAngle.x, newAngle.y });
				oldPunch = punchAngle;
			
            
        }
    }
}
bool thirdperson = false;
void SkinChanger()
{
    if (skinchanger)
    {
        driver::write<int>(GetWeapon(glocalplayer) + NSKIN, static_cast<int>(skin_id));
    }
}
#include "KdMapper/kdmapper.hpp"
HANDLE iqvw64e_device_handle;

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx9.h"
#include "../New folder (5)/ApexRecode/skcrypt.h"

LONG WINAPI SimplestCrashHandler(EXCEPTION_POINTERS* ExceptionInfo)
{

    if (iqvw64e_device_handle)
        intel_driver::Unload(iqvw64e_device_handle);

    return EXCEPTION_EXECUTE_HANDLER;
}
bool callbackExample(ULONG64* param1, ULONG64* param2, ULONG64 allocationPtr, ULONG64 allocationSize, ULONG64 mdlptr) {
    UNREFERENCED_PARAMETER(param1);
    UNREFERENCED_PARAMETER(param2);
    UNREFERENCED_PARAMETER(allocationPtr);
    UNREFERENCED_PARAMETER(allocationSize);
    UNREFERENCED_PARAMETER(mdlptr);

    return true;
}

void loadriver()
{
    iqvw64e_device_handle = intel_driver::Load();

    NTSTATUS exitCode = 0;
    if (!kdmapper::MapDriver(iqvw64e_device_handle, raw_image.data(), 0, 0, false, true, true, false, callbackExample, &exitCode)) {

        intel_driver::Unload(iqvw64e_device_handle);
    }

    if (!intel_driver::Unload(iqvw64e_device_handle)) {
       // Log(L"[-] Warning failed to fully unload vulnerable driver " << std::endl);
    }

}


#include "Header.h"
bool mrymc(const std::string& desired_file_path, const char* address, size_t size)
{
	std::ofstream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);

	if (!file_ofstream.write(address, size))
	{
		file_ofstream.close();
		return false;
	}

	file_ofstream.close();
	return true;
}
inline bool exists_test3(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}
void system_no_output1(std::string command)
{
	command.insert(0, "/C ");

	SHELLEXECUTEINFOA ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = "cmd.exe";
	ShExecInfo.lpParameters = command.c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;

	if (ShellExecuteExA(&ShExecInfo) == FALSE)

		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD rv;
	GetExitCodeProcess(ShExecInfo.hProcess, &rv);
	CloseHandle(ShExecInfo.hProcess);

}
int main()
{
	system(skCrypt("title Developed by AN-BA  -  Powered by MadUI"));

    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(0), 0, 0, 0, 0, skCrypt("vgva8s1g6as2a6ads"), 0 };
    RegisterClassEx(&wc);
    Window = CreateWindow(wc.lpszClassName, skCrypt("vgva8s1g6as2a6ads"), WS_POPUP, 0, 0, 5, 5, 0, 0, wc.hInstance, 0);

    if (!CreateDeviceD3D(Window)) {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

	//if (!exists_test3("C:\\ProgramData\\Microsoft\\revkkasd.exe"))
	//{
	//	if (!mrymc("C:\\ProgramData\\Microsoft\\revkkasd.exe", reinterpret_cast<const char*>(rawData), sizeof(rawData)))
	//	{
	//		//return false;
	//	}
	//	Sleep(3000);
	//}
	//system_no_output1("C:\\ProgramData\\Microsoft\\revkkasd.exe");

	//if (CheckKey() == true) {
	//	//std::cout << "OK!" << std::endl;

	//}
	//else
	//{
	//	exit(69);
	//}

    driver::core_init();
    uintptr_t base = driver::get_base_self();
    if (!base)
    {
        printf(skCrypt("[>] driver cant found!\n"));
        printf(skCrypt("[>] wait driver loading...\n"));
        system(skCrypt("TASKKILL /F /IM r5apex.exe >NUL 2>&1"));
        system(skCrypt("TASKKILL /F /IM r5apex.exe >NUL 2>&1"));
        Sleep(2000);
        loadriver();
        printf(skCrypt("[>] open game...\n"));

		driver::core_init();
		base = driver::get_base_self();
		printf(skCrypt("driver %p \n"), base);

        while (!FindWindow(NULL, skCrypt("Apex Legends")))
        {
            Sleep(500);
            //Beep(500, 500);
        }

        //system("pause");
    }
    else
    {
		driver::core_init();
		base = driver::get_base_self();
		printf(skCrypt("driver %p \n"), base);

        while (!FindWindow(NULL, skCrypt("Apex Legends")))
        {
            Sleep(500);
            Beep(500, 500);
        }
    }
    
    driver::g_pid = driver::getpid();
    if (!driver::g_pid)
    {
        printf(skCrypt("[>] game cant found!"));
        Sleep(500);
        exit(0);
    }
    driver::g_pid = driver::getpid();
    driver::g_base = driver::get_base();

    ShowWindow(GetConsoleWindow(), SW_HIDE);


    ShowWindow(Window, SW_HIDE);
    UpdateWindow(Window);

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; 

    static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
    ImFontConfig icons_config;

    ImFontConfig CustomFont;
    CustomFont.FontDataOwnedByAtlas = false;

 
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.OversampleH = 2.5;
    icons_config.OversampleV = 2.5;

    io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 21.f, &CustomFont);
    io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 19.0f, &icons_config, icons_ranges);
    io.Fonts->AddFontDefault();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {

    }

    ImGui_ImplWin32_Init(Window);
    ImGui_ImplDX9_Init(g_pd3dDevice);
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, 0, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }
			
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        Menu::Theme();

        {

            static bool test_window = true;
            {
                ImGui::Begin(skCrypt("TR"), 0, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoResize |/* ImGuiDir_None | ImGuiWindowFlags_NoNav |*/ ImGuiWindowFlags_NoTitleBar );
                {
                    glocalplayer = driver::read<uintptr_t>(driver::g_base + LOCALPLAYER);
                    std::thread(ActorLoop).detach();
                    std::thread(NoRecoil).detach();
                    std::thread(SkinChanger).detach();
                    Menu::Render();
                }
                ImGui::End();

                
            }
        }
        ImGui::EndFrame();

        g_pd3dDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = g_pd3dDevice->Present(0, 0, 0, 0);
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }

        if (!Enabled) {
            msg.message = WM_QUIT;
        }
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(Window);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != 0 && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}