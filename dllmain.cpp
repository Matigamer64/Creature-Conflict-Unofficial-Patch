#include "external/SimpleIni.h"
#include "external/picosha2.h"
#include "internal/memoryoperations.cpp"
#include <iostream>
#include <ctime>
#include <winuser.h>

std::string exe_hash;

std::map<std::string, char> CC_KEY_CODE = {
    { "ESC",                    0 },
    { "F1",                     1 },
    { "F2",                     2 },
    { "F3",                     3 },
    { "F4",                     4 },
    { "F5",                     5 },
    { "F6",                     6 },
    { "F7",                     7 },
    { "F8",                     8 },
    { "F9",                     9 },
    { "F10",                    10 },
    { "F11",                    11 },
    { "F12",                    12 },
    { "PRINT_SCREEN",           13 },
    { "PRINTSCREEN",            13 },
    { "PRTSC",                  13 },
    { "SCROLL_LOCK",            14 },
    { "SCROLLLOCK",             14 },
    { "PAUSE",                  15 },
    { "GRAVE",                  16 },
    { "`",                      16 },
    { "1",                      17 },
    { "2",                      18 },
    { "3",                      19 },
    { "4",                      20 },
    { "5",                      21 },
    { "6",                      22 },
    { "7",                      23 },
    { "8",                      24 },
    { "9",                      25 },
    { "0",                      26 },
    { "MINUS",                  27 },
    { "-",                      27 },
    { "EQUAL",                  28 },
    { "=",                      28 },
    { "BACKSLASH",              29 },
    { "BACKSPACE",              30 },
    { "INSERT",                 31 },
    { "HOME",                   32 },
    { "PAGE_UP",                33 },
    { "PAGEUP",                 33 },
    { "PGUP",                   33 },
    { "NUM_LOCK",               34 },
    { "NUMLOCK",                34 },
    { "NUMPAD_SLASH",           35 },
    { "NUMPADSLASH",            35 },
    { "NUMPAD_STAR",            36 },
    { "NUMPADSTAR",             36 },
    { "NUMPAD_ASTERISK",        36 },
    { "NUMPADASTERISK",         36 },
    { "NUMPAD_MINUS",           37 },
    { "NUMPADMINUS",            37 },
    { "TAB",                    38 },
    { "Q",                      39 },
    { "W",                      40 },
    { "E",                      41 },
    { "R",                      42 },
    { "T",                      43 },
    { "Y",                      44 },
    { "U",                      45 },
    { "I",                      46 },
    { "O",                      47 },
    { "P",                      48 },
    { "BLOCK_BEGIN",            49 },
    { "BLOCKBEGIN",             49 },
    { "[",                      49 },
    { "BLOCK_END",              50 },
    { "BLOCKEND",               50 },
    { "]",                      50 },
    { "ENTER",                  51 },
    { "DELETE",                 52 },
    { "DEL",                    52 },
    { "END",                    53 },
    { "PAGE_DOWN",              54 },
    { "PAGEDOWN",               54 },
    { "PGDN",                   54 },
    { "NUMPAD_7",               55 },
    { "NUMPAD7",                55 },
    { "NUMPAD_8",               56 },
    { "NUMPAD8",                56 },
    { "NUMPAD_9",               57 },
    { "NUMPAD9",                57 },
    { "NUMPAD_PLUS",            58 },
    { "NUMPADPLUS",             58 },
    { "CAPS_LOCK",              59 },
    { "CAPSLOCK",               59 },
    { "A",                      60 },
    { "S",                      61 },
    { "D",                      62 },
    { "F",                      63 },
    { "G",                      64 },
    { "H",                      65 },
    { "J",                      66 },
    { "K",                      67 },
    { "L",                      68 },
    { ";",                      69 },
    { "'",                      70 },
    { "NUMPAD_4",               71 },
    { "NUMPAD4",                71 },
    { "NUMPAD_5",               72 },
    { "NUMPAD5",                72 },
    { "NUMPAD_6",               73 },
    { "NUMPAD6",                73 },
    { "LEFT_SHIFT",             74 },
    { "LEFTSHIFT",              74 },
    { "LSHIFT",                 74 },
    { "Z",                      75 },
    { "X",                      76 },
    { "C",                      77 },
    { "V",                      78 },
    { "B",                      79 },
    { "N",                      80 },
    { "M",                      81 },
    { "COMMA",                  82 },
    { ",",                      82 },
    { "DOT",                    83 },
    { ".",                      83 },
    { "SLASH",                  84 },
    { "/",                      84 },
    { "RIGHT_SHIFT",            85 },
    { "RIGHTSHIFT",             85 },
    { "RSHIFT",                 85 },
    { "UP_ARROW",               86 },
    { "UPARROW",                86 },
    { "UP",                     86 },
    { "NUMPAD_1",               87 },
    { "NUMPAD1",                87 },
    { "NUMPAD_2",               88 },
    { "NUMPAD2",                88 },
    { "NUMPAD_3",               89 },
    { "NUMPAD3",                89 },
    { "NUMPAD_ENTER",           90 },
    { "NUMPADENTER",            90 },
    { "LEFT_CONTROL",           91 },
    { "LEFTCONTROL",            91 },
    { "LEFT_CTRL",              91 },
    { "LEFTCTRL",               91 },
    { "LCTRL",                  91 },
    { "LEFT_WINDOWS_KEY",       92 },
    { "LEFTWINDOWSKEY",         92 },
    { "LEFT_ALT",               93 },
    { "LEFTALT",                93 },
    { "LALT",                   93 },
    { "SPACE",                  94 },
    { "RIGHT_ALT",              95 },
    { "RIGHTALT",               95 },
    { "RALT",                   95 },
    { "RIGHT_WINDOWS_KEY",      96 },
    { "RIGHTWINDOWSKEY",        96 },
    { "QUICK_MENU",             97 },
    { "QUICKMENU",              97 },
    { "RIGHT_CONTROL",          98 },
    { "RIGHTCONTROL",           98 },
    { "RIGHT_CTRL",             98 },
    { "RIGHTCTRL",              98 },
    { "RCTRL",                  98 },
    { "LEFT_ARROW",             99 },
    { "LEFTARROW",              99 },
    { "LEFT",                   99 },
    { "DOWN_ARROW",             100 },
    { "DOWNARROW",              100 },
    { "DOWN",                   100 },
    { "RIGHT_ARROW",            101 },
    { "RIGHTARROW",             101 },
    { "RIGHT",                  101 },
    { "NUMPAD_0",               102 },
    { "NUMPAD0",                102 },
    { "NUMPAD_DoT",             103 },
    { "NUMPAD_DOT",             103 },
    { "LEFT_MOUSE_BUTTON",      104 },
    { "LEFTMOUSEBUTTON",        104 },
    { "LMOUSE",                 104 },
    { "RIGHT_MOUSE_BUTTON",     105 },
    { "RIGHTMOUSEBUTTON",       105 },
    { "RMOUSE",                 105 },
    { "MIDDLE_MOUSE_BUTTON",    106 },
    { "MIDDLEMOUSEBUTTON",      106 },
    { "MMOUSE",                 106 },
    { "MOUSE_WHEEL_UP",         107 },
    { "MOUSEWHEELUP",           107 },
    { "WHEEL_UP",               107 },
    { "WHEELUP",                107 },
    { "MOUSE_WHEEL_DOWN",       108 },
    { "MOUSEWHEELDOWN",         108 },
    { "WHEEL_DOWN",             108 },
    { "WHEELDOWN",              108 },
    { "MOUSE_HORIZONTAL",       109 },
    { "MOUSEHORIZONTAL",        109 },
    { "MOUSE_LEFT",             110 },
    { "MOUSELEFT",              110 },
    { "MOUSE_RIGHT",            111 },
    { "MOUSERIGHT",             111 },
    { "MOUSE_VERTICAL",         112 },
    { "MOUSEVERTICAL",          112 },
    { "MOUSE_UP",               113 },
    { "MOUSEUP",                113 },
    { "MOUSE_DOWN",             114 },
    { "MOUSEDOWN",              114 },
};

int GET_TURN_TIME(int GameLogic) {
    return (*(int*)(GameLogic)) ? *(int*)(*(int*)(GameLogic)+0xCBB8):0;
}

char GET_TURN_STATE(int GameLogic) {
    return (*(int*)(GameLogic)) ? *(int*)(*(int*)(GameLogic)+0xC3E4):-1;
}

void GET_SYSTEM(char system[]) {
    NTSTATUS(WINAPI *RtlGetVersion)(LPOSVERSIONINFOEXW);
    OSVERSIONINFOEXW osInfo;
    *(FARPROC*)&RtlGetVersion = GetProcAddress(GetModuleHandleA("ntdll"), "RtlGetVersion");
    if (NULL != RtlGetVersion) {
        osInfo.dwOSVersionInfoSize = sizeof(osInfo);
        RtlGetVersion(&osInfo);
        NTSTATUS(WINAPI *wine_get_version)();
        *(FARPROC*)&wine_get_version = GetProcAddress(GetModuleHandleA("ntdll.dll"), "wine_get_version");
        if (wine_get_version) {
            strcat(system,"Wine ");
            strcat(system,(const char *)wine_get_version());
        }
        else if (osInfo.dwPlatformId == 2) {
            strcat(system,"Windows ");
            switch(osInfo.dwMajorVersion) {
                case 5:
                    switch(osInfo.dwMinorVersion) {
                        case 0:
                            strcat(system,"2000");
                        break;
                        case 1:
                            strcat(system,"XP");
                        break;
                        case 2:
                            strcat(system,"XP 64 bit");
                        break;
                    }
                break;
                case 6:
                    switch(osInfo.dwMinorVersion) {
                        case 0:
                            strcat(system,"Vista");
                        break;
                        case 1:
                            strcat(system,"7");
                        break;
                        case 2:
                            strcat(system,"8");
                        break;
                        case 3:
                            strcat(system,"8.1");
                        break;
                    }
                break;
                case 10:
                    if(osInfo.dwBuildNumber > 22000) strcat(system,"11");
                    else strcat(system,"10");
                break;
            }
        }
    }
}

void VERSION_REPORT() {
    char system[64] = "";
    GET_SYSTEM(system);
    std::cout << "PLATFORM: " << system << std::endl;
}

void GET_EXE_HASH() {
    char executable_path[256];
    GetModuleFileNameA(NULL, executable_path, 256);
    std::ifstream f(executable_path, std::ios::binary);
    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(f, hash.begin(), hash.end());
    exe_hash = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
}

void LOG_INIT() {
    char process_path[256];
    GetCurrentDirectory(256, process_path);
    time_t Log_Creation_Time = time(0);
    GET_EXE_HASH();
    std::cout << "--- Welcome to Creature Conflict: The Clan Wars unofficial patch Build date: 18.11.2024 ---" << std::endl;
    std::cout << "RUNNING DIRECTORY: " << process_path << std::endl;
    std::cout << "EXECUTABLE SHA256 HASH: " << exe_hash << std::endl;
    std::cout << "LOG FILE CREATED: " << ctime(&Log_Creation_Time);
    VERSION_REPORT();
    std::cout << "--- ---" << std::endl;
}

void CREATE_PATCH_CONFIG() {
    CSimpleIniA ini;
    if(ini.LoadFile("ccpatch.ini")) {
        std::cout << "Missing patch config, creating new one..." << std::endl;
        ini.SetValue("GAME_PARAMETERS", "ThirdPersonFOV", "75");
        ini.SetValue("GAME_PARAMETERS", "FirstPersonFOV", "75");
        ini.SetValue("VIDEO", "DisableIntros", "0");
        ini.SetValue("VIDEO", "DisableMenuVideo", "0");
        ini.SetValue("VIDEO", "DisableCutsceneBorders", "0");
        ini.SetValue("MISC", "RelocateSavesToGameDir", "0");
        ini.SetValue("MISC", "WriteLogFile", "1");
        ini.SaveFile("ccpatch.ini");
    }
}

void REPLACE_CC_PATH(bool Relocate_Saves_To_Game_Dir) {
    char process_path[256];
    GetCurrentDirectory(256, process_path);
    strcat(process_path,"\\save\\");
    if (Relocate_Saves_To_Game_Dir) {
        std::cout << "Changing game config and save file directory..." << std::endl;
        CreateDirectoryA(process_path,0);
        int JumpOverDirFunc = GetPattern("\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x0C\x85\xC0\x0F\x84\x81", "x????x????xxxxxxxx");
        WriteBuf(*(int*)(GetPattern("\x68\x00\x00\x00\x00\x89\x84\x24\x14", "x????xxxx")+1), process_path, 256);
        WriteByte(JumpOverDirFunc, 0xE9);
        WriteInt(JumpOverDirFunc+1, 0x000000BF);
    }
}

void RENDERING_PATCHES(bool Disable_Intros, bool Disable_Menu_Video, bool Disable_Cutscene_Borders, float &Third_Person_FOV, float &First_Person_FOV, float &Sniper_Rifle_FOV) {
    std::cout << "Removing arbitrary resolution block list..." << std::endl;
    if (Disable_Intros) {
        std::cout << "Disabling intros..." << std::endl;
        WriteBuf(GetPattern("\x6C\x6F\x67\x6F\x73\x00", "xxxxxx"), (void *)"", 6); //logos
        WriteBuf(GetPattern("\x73\x72\x74\x00\x00\x00\x67\x61\x6D\x65", "xxxxxxxxxx")+6, (void *)"", 10); //gameintro
    }
    if (Disable_Menu_Video) {
        std::cout << "Disabling menu video..." << std::endl;
        WriteBuf(GetPattern("\x2E\x2E\x5C\x64\x61\x74\x61\x5C\x6D\x6F\x76\x69\x65\x5c\x6D", "xxxxxxxxxxxxxxx"), (void *)"", 29);
    }
    if (Disable_Cutscene_Borders) {
        std::cout << "Removing cutscene borders..." << std::endl;
        WriteByte(GetPattern("\x6A\x19\x8B\xCE\xE8\x00\x00\x00\x00\x6A", "xxxxx????x")+1, 1);
    }
    std::cout << "Patching camera fields of view" << std::endl;
    WriteNOP(GetPattern("\x8D\x14\x8D\x00\x00\x00\x00\x8D\x34\x40", "xxxxxxxxxx"), 32); //don't check aspect ratio
    WriteFloatPointer(GetPattern("\x8B\x15\x00\x00\x00\x00\xEB\x5E", "xx????xx")+2, &Sniper_Rifle_FOV);
    WriteFloatPointer(GetPattern("\x8B\x0D\x00\x00\x00\x00\x89\x4C\x24\x04\x8B", "xx????xxxxx")+2, &First_Person_FOV);
    WriteFloatPointer(GetPattern("\x8B\x15\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x83\x79", "xx????xx????xx")+2, &Third_Person_FOV);
}

void MULTIPLAYER_PATCHES() {
    std::cout << "Making @ character harmless to multiplayer chats..." << std::endl;
    WriteNOP(GetPattern("\x8A\x48\x2B\x84\xC9\x75", "xxxxxx"), 7); //fix @ crash
    WriteNOP(GetPattern("\x8B\x40\x30\x03\x0A", "xxxxx"), 5);
}

void GATE_FIXES(int GameLogic, int InGate, int UnitPowerUp, int UnitControlled, int UnitFrozen, int IsAnyoneRabidAmok, int IsAnyoneUsingEquity) {
    if (*(char*)(InGate)) { //check if in gate
        if (*(int*)(UnitPowerUp+*(int*)(UnitControlled)*0x4A0) == 124) WriteByte(IsAnyoneRabidAmok, 0); //Rabid amok softlock fix
        if (*(int*)(UnitPowerUp+*(int*)(UnitControlled)*0x4A0) == 110) WriteByte(InGate, 0); //Teleport crash fix related to referencing dead player
        if (*(char*)(IsAnyoneUsingEquity)) WriteByte(IsAnyoneUsingEquity, 0); //Equity softlock fix
        if (*(int*)(UnitPowerUp+*(int*)(UnitControlled)*0x4A0) == 123 && GET_TURN_TIME(GameLogic) < 2) { //Gnaw softlock fix
            WriteByte(UnitFrozen+*(int*)(UnitControlled)*0x4A0, 0);
            WriteByte(InGate, 0);
        }
    }
}

void OBJECT_FIXES(int GameLogic, int InGate, int UnitPowerUp, int UnitControlled, int UnitFrozen, int IsAnyoneRabidAmok, int IsAnyoneUsingEquity, int ObjectTemplate) {
    if (*(int*)(ObjectTemplate)) { //package sound fixes
        if (
            !(*(char*)(*(int*)(ObjectTemplate)+0x100*87+0xD6) == 11) ||
            !(*(char*)(*(int*)(ObjectTemplate)+0x100*91+0xD4) == 9) ||
            !(*(char*)(*(int*)(ObjectTemplate)+0x100*136+0xD3) == 12)
        )
        std::cout << "Fixing object behaviours..." << std::endl;
        WriteByte(*(int*)(ObjectTemplate)+0x100*87+0xD6, 11); // Laser Blaster package missing pickup sound
        WriteByte(*(int*)(ObjectTemplate)+0x100*91+0xD4, 9); // Mine Strike package missing spawn sound
        WriteByte(*(int*)(ObjectTemplate)+0x100*136+0xD3, 12); // Teleport package missing bounce sound, fixes pickup sound sometimes being wrong
    }
    GATE_FIXES(GameLogic, InGate, UnitPowerUp, UnitControlled, UnitFrozen, IsAnyoneRabidAmok, IsAnyoneUsingEquity);
}

void WEAPON_FIXES(int WeaponTemplate) {
    if (*(int*)(WeaponTemplate)) {
        if (
            !(*(char*)(*(int*)(WeaponTemplate)+0x1D0*46+0x7B) == 3) ||
            !(*(char*)(*(int*)(WeaponTemplate)+0x1D0*50+0x1AC) == 3) ||
            !(*(char*)(*(int*)(WeaponTemplate)+0x1D0*65+0x31) == 1)
        )
        std::cout << "Fixing weapon behaviours..." << std::endl;
        WriteByte(*(int*)(WeaponTemplate)+0x1D0*46+0x7B, 3); // ticking briefcase, fix lack of collision with characters
        WriteByte(*(int*)(WeaponTemplate)+0x1D0*50+0x1AC, 3); // casserole, fix swinging being silent
        WriteByte(*(int*)(WeaponTemplate)+0x1D0*65+0x31, 1); // ultrasonic grenade, fix the oddity of not being able to change ttl like other grenades
    }
}

void MISC_PATCHES() {
    WriteByte(GetPattern("\x0C\xE8\x00\x00\x00\x00\x33\xDB\x53\x6A", "xx????xxxx")+0xA, 2); //flip number to indicate that game loaded patch
}

void HIDE_HUD(int HideHud) {
    if (GetAsyncKeyState(0x48) & 0x01) {
        if (*(int*)(HideHud+1) == 0xFFFFDDFB) WriteNOP(HideHud, 5);
        else {
            WriteByte(HideHud, 0xE8);
            WriteInt(HideHud+1, 0xFFFFDDFB);
        }
    }
}

char STRING_TO_CC_KEY_CODE(std::string Key) {
    for (int i=0; i<Key.length(); i++) Key[i] = toupper(Key[i]);
    return (Key == "") ? 115:(Key == "ESC") ? CC_KEY_CODE[Key]:((char*)(CC_KEY_CODE[Key])) ? CC_KEY_CODE[Key]:115;
}

void KEYBIND_REMAP() {
    Sleep(500);
    CSimpleIniA ini;
    CSimpleIniA::TNamesDepend Keys;
    CSimpleIniA::TNamesDepend::const_iterator it;
    int keybind = (*(int*)(GetPattern("\xBA\x00\x00\x00\x00\xB3\x01\xEB", "x????xxx")+1))+8;
    std::cout << "Disabling F10 key crash functionality..." << std::endl;
    WriteByte(keybind+0xA98, 115);
    if(ini.LoadFile("keybindings.ini")) {
        std::cout << "Missing keybind config, creating new one... " << std::endl;
        for(int i = 0; i < 3; i++) {
            std::string section = "KEYBINDING_"+std::to_string(i+1);
            ini.SetValue(section.c_str(), "GuiUp", !i ? "Up_Arrow":"");
            ini.SetValue(section.c_str(), "GuiDown", !i ? "Down_Arrow":"");
            ini.SetValue(section.c_str(), "GuiLeft", !i ? "Left_Arrow":"");
            ini.SetValue(section.c_str(), "GuiRight", !i ? "Right_Arrow":"");
            ini.SetValue(section.c_str(), "GuiNextWidget", !i ? "Tab":"");
            ini.SetValue(section.c_str(), "GuiPageUp", !i ? "Page_Up":"");
            ini.SetValue(section.c_str(), "GuiPageDown", !i ? "Page_Down":"");
            ini.SetValue(section.c_str(), "GuiHome", !i ? "Home":"");
            ini.SetValue(section.c_str(), "GuiEnd", !i ? "End":"");
            ini.SetValue(section.c_str(), "GuiOK",  !i ? "Enter":"");
            ini.SetValue(section.c_str(), "GuiBack", !i ? "Esc":"");
            ini.SetValue(section.c_str(), "MultiplayerBriefingDelete", !i ? "Delete":"");
            ini.SetValue(section.c_str(), "MultiplayerBriefingNextAlliance", !i ? "Enter":"");
            ini.SetValue(section.c_str(), "MultiplayerBriefingNextAdvantage", !i ? "Enter":"");
            ini.SetValue(section.c_str(), "MultiplayerBriefingTeamStatistics", (i == 0) ? "Space": (i == 1) ? "RMouse":"");
            ini.SetValue(section.c_str(), "TeamEditingDelete", !i ? "Delete":"");
            ini.SetValue(section.c_str(), "TeamEditingInsert", !i ? "Insert":"");
            ini.SetValue(section.c_str(), "ButtonActivate", !i ? "Enter":"");
            ini.SetValue(section.c_str(), "ListBoxUp", !i ? "W":"");
            ini.SetValue(section.c_str(), "ListBoxDown", !i ? "S":"");
            ini.SetValue(section.c_str(), "WeaponListUp", !i ? "Up_Arrow":"");
            ini.SetValue(section.c_str(), "WeaponListDown", !i ? "Down_Arrow":"");
            ini.SetValue(section.c_str(), "WeaponListLeft", !i ? "Left_Arrow":"");
            ini.SetValue(section.c_str(), "WeaponListRight", !i ? "Right_Arrow":"");
            ini.SetValue(section.c_str(), "SettingsSliderIncrement", (i == 0) ? "Equal": (i == 1) ? "Wheel_Up":"");
            ini.SetValue(section.c_str(), "SettingsSliderDecrement", (i == 0) ? "Minus": (i == 1) ? "Wheel_Down":"");
            ini.SetValue(section.c_str(), "InventoryOpen", (i == 0) ? "RMouse": (i == 1) ? "Insert":"");
            ini.SetValue(section.c_str(), "InventoryWeaponInformation", !i ? "Space":"");
            ini.SetValue(section.c_str(), "InventoryGoNextRow", !i ? "BlockBegin":"");
            ini.SetValue(section.c_str(), "InventoryGoNextColumn", !i ? "BlockEnd":"");
            ini.SetValue(section.c_str(), "InventoryGoRowPistol", !i ? "F1":"");
            ini.SetValue(section.c_str(), "InventoryGoRowRifle", !i ? "F2":"");
            ini.SetValue(section.c_str(), "InventoryGoRowCannon", !i ? "F3":"");
            ini.SetValue(section.c_str(), "InventoryGoRowGrenade", !i ? "F4":"");
            ini.SetValue(section.c_str(), "InventoryGoRowMine", !i ? "F5":"");
            ini.SetValue(section.c_str(), "InventoryGoRowBonus1", !i ? "F6":"");
            ini.SetValue(section.c_str(), "InventoryGoRowBonus2", !i ? "F7":"");
            ini.SetValue(section.c_str(), "InventoryGoRowHandy", !i ? "F8":"");
            ini.SetValue(section.c_str(), "ShopBuyWeapon", !i ? "Equal":"");
            ini.SetValue(section.c_str(), "ShopRemoveWeapon", !i ? "Delete":"");
            ini.SetValue(section.c_str(), "InGameMenuOpen", !i ? "Esc":"");
            ini.SetValue(section.c_str(), "GamePlaceCharacter", (i == 0) ? "Enter": (i == 1) ? "LMouse":"");
            ini.SetValue(section.c_str(), "GameForward", !i ? "W":"");
            ini.SetValue(section.c_str(), "GameBackward", !i ? "S":"");
            ini.SetValue(section.c_str(), "GameStrafeLeft", !i ? "A":"");
            ini.SetValue(section.c_str(), "GameStrafeRight", !i ? "D":"");
            ini.SetValue(section.c_str(), "GameRotateLeft", !i ? "Mouse_Left":"");
            ini.SetValue(section.c_str(), "GameRotateRight", !i ? "Mouse_Right":"");
            ini.SetValue(section.c_str(), "GameJump", (i == 0) ? "Space": (i == 1) ? "Left_Ctrl":"");
            ini.SetValue(section.c_str(), "GameShot", (i == 0) ? "Enter": (i == 1) ? "LMouse":"");
            ini.SetValue(section.c_str(), "GameUseAbility", (i == 0) ? "Enter": (i == 1) ? "LMouse":"");
            ini.SetValue(section.c_str(), "GameChangeCamera", !i ? "R":"");
            ini.SetValue(section.c_str(), "GameThirdPersonCamera", !i ? "E":"");
            ini.SetValue(section.c_str(), "GameBulletCamera", !i ? "F":"");
            ini.SetValue(section.c_str(), "GameThirdPersonCameraUp", !i ? "Mouse_Up":"");
            ini.SetValue(section.c_str(), "GameThirdPersonCameraDown", !i ? "Mouse_Down":"");
            ini.SetValue(section.c_str(), "GameThirdPersonCameraLeft", !i ? "Mouse_Left":"");
            ini.SetValue(section.c_str(), "GameThirdPersonCameraRight", !i ? "Mouse_Right":"");
            ini.SetValue(section.c_str(), "GameThirdPersonCameraBirdsEye", !i ? "MMouse":"");
            ini.SetValue(section.c_str(), "GamePlanetCameraUp", !i ? "Mouse_Down":"");
            ini.SetValue(section.c_str(), "GamePlanetCameraDown", !i ? "Mouse_Up":"");
            ini.SetValue(section.c_str(), "GamePlanetCameraLeft", !i ? "Mouse_Left":"");
            ini.SetValue(section.c_str(), "GamePlanetCameraRight", !i ? "Mouse_Right":"");
            ini.SetValue(section.c_str(), "GamePlanetCameraZoomIn", !i ? "W":"");
            ini.SetValue(section.c_str(), "GamePlanetCameraZoomOut", !i ? "S":"");
            ini.SetValue(section.c_str(), "GameSelectPreviousCharacter", !i ? "Q":"");
            ini.SetValue(section.c_str(), "GameSelectNextCharacter", !i ? "Tab":"");
            ini.SetValue(section.c_str(), "GameSelectCharacter", (i == 0) ? "Enter": (i == 1) ? "LMouse":"");
            ini.SetValue(section.c_str(), "GameSelectPreviousTeleport", !i ? "Q":"");
            ini.SetValue(section.c_str(), "GameSelectNextTeleport", !i ? "Tab":"");
            ini.SetValue(section.c_str(), "GameSelectTeleport", (i == 0) ? "Enter": (i == 1) ? "LMouse":"");
            ini.SetValue(section.c_str(), "GameSelectPreviousPowerUp", !i ? "Q":"");
            ini.SetValue(section.c_str(), "GameSelectNextPowerUp", !i ? "Tab":"");
            ini.SetValue(section.c_str(), "GameSelectPowerUp", (i == 0) ? "Enter": (i == 1) ? "LMouse":"");
            ini.SetValue(section.c_str(), "GameSelectPreviousGravestone", !i ? "Q":"");
            ini.SetValue(section.c_str(), "GameSelectNextGravestone", !i ? "Tab":"");
            ini.SetValue(section.c_str(), "GameSelectGravestone", (i == 0) ? "Enter": (i == 1) ? "LMouse":"");
            ini.SetValue(section.c_str(), "GameBulletControlUp", (i == 0) ? "W": (i == 1) ? "Mouse_Up":"");
            ini.SetValue(section.c_str(), "GameBulletControlDown", (i == 0) ? "S": (i == 1) ? "Mouse_Down":"");
            ini.SetValue(section.c_str(), "GameBulletControlLeft", (i == 0) ? "A": (i == 1) ? "Mouse_Left":"");
            ini.SetValue(section.c_str(), "GameBulletControlRight", (i == 0) ? "D": (i == 1) ? "Mouse_Right":"");
            ini.SetValue(section.c_str(), "GameTimer1", !i ? "1":"");
            ini.SetValue(section.c_str(), "GameTimer2", !i ? "2":"");
            ini.SetValue(section.c_str(), "GameTimer3", !i ? "3":"");
            ini.SetValue(section.c_str(), "GameTimer4", !i ? "4":"");
            ini.SetValue(section.c_str(), "GameTimer5", !i ? "5":"");
            ini.SetValue(section.c_str(), "GameTimer6", !i ? "6":"");
            ini.SetValue(section.c_str(), "GameTimerPrevious", !i ? "Down_Arrow":"");
            ini.SetValue(section.c_str(), "GameTimerNext", !i ? "Up_Arrow":"");
            ini.SetValue(section.c_str(), "GameSkipTurn", !i ? "X":"");
            ini.SetValue(section.c_str(), "GameToggleJetPack", !i ? "J":"");
        }
        ini.SaveFile("keybindings.ini");
        ini.LoadFile("keybindings.ini");
    }
    std::cout << "Patching keybinds... " << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << "Patched keybind row: " << i+1 << std::endl;
        std::string section = "KEYBINDING_"+std::to_string(i+1);
        int offset = (i == 0) ? 2:(i==1) ? 94:(i==2) ? 186:0;
        ini.GetAllKeys(section.c_str(),Keys);
        Keys.sort(CSimpleIniA::Entry::LoadOrder());
        for (it = Keys.begin(); it != Keys.end(); it++) {
            switch(it->nOrder) {
                case 18:
                case 110:
                case 202:
                    offset = offset-4;
                break;
                case 39:
                case 131:
                case 223:
                    offset = offset-1;
                break;
                case 42:
                case 134:
                case 226:
                    offset = offset-2;
                break;
            }
            WriteByte((keybind+4*i)+0xC*(it->nOrder-offset),STRING_TO_CC_KEY_CODE(std::string(ini.GetValue(section.c_str(), it->pItem))));
        }
    }
}

void LOOP() {
    int WeaponTemplate = *(int*)(GetPattern("\x8B\x0D\x00\x00\x00\x00\x8B\x54\x08\x2C\x83\xC4\x04\x83\xFA\x02\x0F", "xx????xxxxxxxxxxx")+2);
    int ObjectTemplate = *(int*)(GetPattern("\x8B\x0D\x00\x00\x00\x00\xC1\xE0\x08\x8B\x54", "xx????xxxxx")+2);
    int IsAnyoneUsingEquity = *(int*)(GetPattern("\x38\x1D\x00\x00\x00\x00\x75\x09", "xx????xx")+2);
    int IsAnyoneRabidAmok = *(int*)(GetPattern("\xA0\x00\x00\x00\x00\x84\xC0\x75\x28", "x????xxxx")+1);
    int UnitFrozen = *(int*)(GetPattern("\x8A\x88\x00\x00\x00\x00\x84\xC9\x75\x21", "xx????xxxx")+2);
    int UnitControlled = *(int*)(GetPattern("\xA1\x00\x00\x00\x00\x56\x50\xE8", "x????xxx")+1);
    int UnitPowerUp = *(int*)(GetPattern("\x8B\x82\x00\x00\x00\x00\x83\xC0\x8C", "xx????xxx")+2);
    int InGate = *(int*)(GetPattern("\xA0\x00\x00\x00\x00\x84\xC0\x75\x2C\x83", "x????xxxxx")+1);
    int GameLogic = *(int*)(GetPattern("\x8B\x0D\x00\x00\x00\x00\x8A\x41\x59\x84\xC0\x75\x1C", "xx????xxxxxxx")+2);
    int GameSpeed = *(int*)(GetPattern("\xD9\x05\x00\x00\x00\x00\x89\x0D\x00\x00\x00\x00\xD8", "xx????xx????x")+2);
    int UnitCount = *(int*)(GetPattern("\xA1\x00\x00\x00\x00\x53\x56\x83", "x????xxx")+1);
    int GameSaveSettings = *(int*)(GetPattern("\xA0\x00\x00\x00\x00\x24\x02\xF6", "x????xxx")+1);
    int LowCharFramerateAnimDist = *(int*)(GetPattern("\xD8\x1D\x00\x00\x00\x00\xDF\xE0\xF6\xC4\x41\x75\x29\x8B\x96", "xx????xxxxxxxxx")+2);
    int ResolutionX = *(int*)(GetPattern("\x8B\x0D\x00\x00\x00\x00\x50\x51\x8D\x54\x24\x0C", "xx????xxxxxx")+2);
    int ResolutionY = ResolutionX+4;
    int RenderAspectRatio = *(int*)(GetPattern("\xD9\x40\x04\x8B\x15", "xxxxx")+5);
    int HideHud = GetPattern("\x8B\xCE\xE8\x00\x00\x00\x00\x8B\xCE\xE8\x00\x00\x00\x00\x5F\x5E\x83", "xxx????xxx????xxx")+2;
    while (true) {
        Sleep(50);
        WriteFloat(RenderAspectRatio, (*(float*)(ResolutionX))/(*(float*)(ResolutionY))); //display aspect ratio fix on resolution change
        WriteFloat(LowCharFramerateAnimDist, (!((*(char *)(GameSaveSettings) >> 3) & 1) & ((*(char *)(GameSaveSettings) >> 4) & 1)) ? 128:64); //change distance from which characters are animated at lower framerate on high settings
        if (*(char*)(UnitCount)) { //check if game started by checking whether there is atleast one character
            OBJECT_FIXES(GameLogic, InGate, UnitPowerUp, UnitControlled, UnitFrozen, IsAnyoneRabidAmok, IsAnyoneUsingEquity, ObjectTemplate);
            WEAPON_FIXES(WeaponTemplate);
            HIDE_HUD(HideHud);
        }
    }
}

DWORD WINAPI Init(LPVOID lpParameter) {
    CSimpleIniA ini;
    ini.LoadFile("ccpatch.ini");
    float Third_Person_FOV = std::atof(ini.GetValue("GAME_PARAMETERS", "ThirdPersonFOV"));
    float First_Person_FOV = std::atof(ini.GetValue("GAME_PARAMETERS", "FirstPersonFOV"));
    float Sniper_Rifle_FOV = (First_Person_FOV-40.0 < 40.0) ? First_Person_FOV:First_Person_FOV-40.0;
    RENDERING_PATCHES(std::atoi(ini.GetValue("VIDEO", "DisableIntros")),std::atoi(ini.GetValue("VIDEO", "DisableMenuVideo")),std::atoi(ini.GetValue("VIDEO", "DisableCutsceneBorders")),Third_Person_FOV,First_Person_FOV,Sniper_Rifle_FOV);
    MULTIPLAYER_PATCHES();
    MISC_PATCHES();
    KEYBIND_REMAP();
    LOOP();
    return 0;
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID lpReserved) {
    DisableThreadLibraryCalls(module);
    switch (reason) {
        case DLL_PROCESS_ATTACH: {
            NTSTATUS(WINAPI *set_process_dpi_aware)();
            *(FARPROC*)&set_process_dpi_aware = GetProcAddress(GetModuleHandleA("User32.dll"), "SetProcessDPIAware");
            set_process_dpi_aware();
            CREATE_PATCH_CONFIG();
            CSimpleIniA ini;
            ini.LoadFile("ccpatch.ini");
            if (std::atoi(ini.GetValue("MISC", "WriteLogFile"))) freopen("debug.txt", "w", stdout);
            LOG_INIT();
            REPLACE_CC_PATH(std::atoi(ini.GetValue("MISC", "RelocateSavesToGameDir")));
            HANDLE hThread = CreateThread(nullptr, 0, Init, nullptr, 0, nullptr);
            CloseHandle(hThread);
            break;
        }
        case DLL_PROCESS_DETACH: {
            FreeLibraryAndExitThread(module,0);
            break;
        }
    }
    return TRUE;
}
