#include "external/SimpleIni.hpp"

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
    { "NUMPAD_7",               32 },
    { "NUMPAD7",                32 },
    { "NUMPAD_9",               33 },
    { "NUMPAD9",                33 },
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
    { "BLOCK_END",              49 },
    { "BLOCKEND",               49 },
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

int GET_TURN_TIME() {
    return (*(int*)(0x21958D0)) ? *(int*)(*(int*)(0x21958D0)+0xCBB8):0;
}

char GET_TURN_STATE() {
    return (*(int*)(0x21958D0)) ? *(int*)(*(int*)(0x21958D0)+0xC3E4):-1;
}

void REPLACE_CC_PATH(bool Relocate_Saves_To_Game_Dir, char process_path[]) {
    if (Relocate_Saves_To_Game_Dir) {
        CreateDirectoryA(process_path,0);
        memcpy((void*)0x12CA6C8, process_path, 256);
        *(char *)(0x41D55C) = 0xE9;
        *(int *)(0x41D55D) = 0x000000BF;
    }
}

void RENDERING_PATCHES(bool Disable_Intros, bool Disable_Menu_Video, bool Disable_Cutscene_Borders, float &Third_Person_FOV, float &First_Person_FOV, float &Sniper_Rifle_FOV) {
    memset((void*)(0x4F5201), 0x90, 32); //don't check aspect ratio
    if (Disable_Intros) {
        memcpy((void*)(0x54A34C), "", 6); //logos
        memcpy((void*)(0x54A364), "", 10); //gameintro
    }
    if (Disable_Menu_Video) memcpy((void*)(0x5463D4), "", 29);
    if (Disable_Cutscene_Borders) *(char *)(0x46E2AA) = 1;
    *(float* *)(0x421A43) = &Sniper_Rifle_FOV;
    *(float* *)(0x421A4B) = &First_Person_FOV;
    *(float* *)(0x421AA3) = &Third_Person_FOV;
}

void MULTIPLAYER_PATCHES(int UDP_Port, int TCP_Port) {
    *(int *)(0x49C044) = UDP_Port; //movement
    *(int *)(0x4B2F32) = TCP_Port; //chat and other logic
    *(int *)(0x4B2D96) = TCP_Port; //server list
    memset((void*)0x4F2A59, 0x90, 7); //fix @ crash
    memset((void*)0x4F2A76, 0x90, 5);
}

void MISC_PATCHES(int Save_Slot, bool Faster_Turn_Skips) {
    *(char *)(0x4DDE53) = Save_Slot;
    if (Faster_Turn_Skips) {
        memset((void*)0x44138A, 0x90, 2);
        *(int*)(0x56087C) = 20;
    }
    *(char *)(0x4CFF2B) = 2; //flip number to indicate that game loaded patch
}

void OBJECT_FIXES() {
    if (*(int*)(0x12CA6B8)) { //package sound fixes
        *(char*)(*(int*)(0x12CA6B8)+0x100*87+0xD6) = 11; /* laser blaster */
        *(char*)(*(int*)(0x12CA6B8)+0x100*91+0xD4) = 9; /* mine strike */
    }
}

void GATE_FIXES() {
    if (*(char*)(0x16A1B60)) { //check if in gate
        if (*(int*)(0x1037C40+*(int*)(0x10368CC)*0x4A0) == 124) *(char*)(0x21AADE8) = 0; //Rabid amok softlock fix
        if (*(int*)(0x1037C40+*(int*)(0x10368CC)*0x4A0) == 110) *(char*)(0x16A1B60) = 0; //Teleport crash fix related to referencing dead player
        if (*(char*)(0x21AAD44)) *(char*)(0x21AAD44) = 0; //Equity softlock fix
        if (*(int*)(0x1037C40+*(int*)(0x10368CC)*0x4A0) == 123 && GET_TURN_TIME() < 2) { //Gnaw softlock fix
            *(char*)(0x103799C+*(int*)(0x10368CC)*0x4A0) = 0;
            *(char*)(0x16A1B60) = 0;
        }
    }
}

void HIDE_HUD() {
    if (GetAsyncKeyState(0x48) & 0x01) {
        if (*(int*)(0x4C2101) == 0xFFFFDDFB) memset((void*)0x4C2100, 0x90, 5);
        else {
            *(char *)(0x4C2100) = 0xE8;
            *(int *)(0x4C2101) = 0xFFFFDDFB;
        }
    }
}

char STRING_TO_CC_KEY_CODE(std::string Key) {
    if (Key == "") return 115;
    for (int i=0; i<Key.length(); i++) Key[i] = toupper(Key[i]);
    if (Key == "ESC") return CC_KEY_CODE[Key];
    return ((char*)(CC_KEY_CODE[Key])) ? CC_KEY_CODE[Key]:115;
}

void KEYBIND_REMAP() {
    Sleep(500);
    *(char *)(0x10BDA84) = 115; //Attempt to disable F10 keybind which causes game crash
    CSimpleIniA ini;
    if(ini.LoadFile("keybindings.ini")) {
        for(int i = 0; i < 4; i++) {
            std::string section = "KEYBINDING_";
            section = section+std::to_string(i+1);
            switch(i) {
                case 0:
                    ini.SetValue(section.c_str(), "GuiUp", "Up_Arrow");
                    ini.SetValue(section.c_str(), "GuiDown", "Down_Arrow");
                    ini.SetValue(section.c_str(), "GuiLeft", "Left_Arrow");
                    ini.SetValue(section.c_str(), "GuiRight", "Right_Arrow");
                    ini.SetValue(section.c_str(), "GuiNextWidget", "Tab");
                    ini.SetValue(section.c_str(), "GuiPageUp", "PAGE_UP");
                    ini.SetValue(section.c_str(), "GuiPageDown", "PAGE_DOWN");
                    ini.SetValue(section.c_str(), "GuiHome", "Home");
                    ini.SetValue(section.c_str(), "GuiEnd", "End");
                    ini.SetValue(section.c_str(), "GuiOK", "Enter");
                    ini.SetValue(section.c_str(), "GuiBack", "Esc");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingDelete", "Delete");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingNextAlliance", "Enter");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingNextAdvantage", "Enter");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingTeamStatistics", "Space");
                    ini.SetValue(section.c_str(), "TeamEditingDelete", "Delete");
                    ini.SetValue(section.c_str(), "TeamEditingInsert", "Insert");
                    ini.SetValue(section.c_str(), "ButtonActivate", "Enter");
                    ini.SetValue(section.c_str(), "ListBoxUp", "W");
                    ini.SetValue(section.c_str(), "ListBoxDown", "S");
                    ini.SetValue(section.c_str(), "WeaponListUp", "Up_Arrow");
                    ini.SetValue(section.c_str(), "WeaponListDown", "Down_Arrow");
                    ini.SetValue(section.c_str(), "WeaponListLeft", "Left_Arrow");
                    ini.SetValue(section.c_str(), "WeaponListRight", "Right_Arrow");
                    ini.SetValue(section.c_str(), "SettingsSliderIncrement", "Equal");
                    ini.SetValue(section.c_str(), "SettingsSliderDecrement", "Minus");
                    ini.SetValue(section.c_str(), "InventoryOpen", "RMouse");
                    ini.SetValue(section.c_str(), "InventoryWeaponInformation", "Space");
                    ini.SetValue(section.c_str(), "InventoryGoNextRow", "BlockBegin");
                    ini.SetValue(section.c_str(), "InventoryGoNextColumn", "BlockEnd");
                    ini.SetValue(section.c_str(), "InventoryGoRowPistol", "F1");
                    ini.SetValue(section.c_str(), "InventoryGoRowRifle", "F2");
                    ini.SetValue(section.c_str(), "InventoryGoRowCannon", "F3");
                    ini.SetValue(section.c_str(), "InventoryGoRowGrenade", "F4");
                    ini.SetValue(section.c_str(), "InventoryGoRowMine", "F5");
                    ini.SetValue(section.c_str(), "InventoryGoRowBonus1", "F6");
                    ini.SetValue(section.c_str(), "InventoryGoRowBonus2", "F7");
                    ini.SetValue(section.c_str(), "InventoryGoRowHandy", "F8");
                    ini.SetValue(section.c_str(), "ShopBuyWeapon", "Equal");
                    ini.SetValue(section.c_str(), "ShopRemoveWeapon", "Delete");
                    ini.SetValue(section.c_str(), "InGameMenuOpen", "Esc");
                    ini.SetValue(section.c_str(), "GamePlaceCharacter", "Enter");
                    ini.SetValue(section.c_str(), "GameForward", "W");
                    ini.SetValue(section.c_str(), "GameBackward", "S");
                    ini.SetValue(section.c_str(), "GameStrafeLeft", "A");
                    ini.SetValue(section.c_str(), "GameStrafeRight", "D");
                    ini.SetValue(section.c_str(), "GameRotateLeft", "Mouse_Left");
                    ini.SetValue(section.c_str(), "GameRotateRight", "Mouse_Right");
                    ini.SetValue(section.c_str(), "GameJump", "Space");
                    ini.SetValue(section.c_str(), "GameShot", "Enter");
                    ini.SetValue(section.c_str(), "GameUseAbility", "Enter");
                    ini.SetValue(section.c_str(), "GameChangeCamera", "R");
                    ini.SetValue(section.c_str(), "GameThirdPersonCamera", "E");
                    ini.SetValue(section.c_str(), "GameBulletCamera", "F");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraUp", "Mouse_Up");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraDown", "Mouse_Down");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraLeft", "Mouse_Left");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraRight", "Mouse_Right");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraBirdsEye", "MMouse");
                    ini.SetValue(section.c_str(), "GamePlanetCameraUp", "Mouse_Down");
                    ini.SetValue(section.c_str(), "GamePlanetCameraDown", "Mouse_Up");
                    ini.SetValue(section.c_str(), "GamePlanetCameraLeft", "Mouse_Left");
                    ini.SetValue(section.c_str(), "GamePlanetCameraRight", "Mouse_Right");
                    ini.SetValue(section.c_str(), "GamePlanetCameraZoomIn", "W");
                    ini.SetValue(section.c_str(), "GamePlanetCameraZoomOut", "S");
                    ini.SetValue(section.c_str(), "GameSelectPreviousCharacter", "Q");
                    ini.SetValue(section.c_str(), "GameSelectNextCharacter", "Tab");
                    ini.SetValue(section.c_str(), "GameSelectCharacter", "Enter");
                    ini.SetValue(section.c_str(), "GameSelectPreviousTeleport", "Q");
                    ini.SetValue(section.c_str(), "GameSelectNextTeleport", "Tab");
                    ini.SetValue(section.c_str(), "GameSelectTeleport", "Enter");
                    ini.SetValue(section.c_str(), "GameSelectPreviousPowerUp", "Q");
                    ini.SetValue(section.c_str(), "GameSelectNextPowerUp", "Tab");
                    ini.SetValue(section.c_str(), "GameSelectPowerUp", "Enter");
                    ini.SetValue(section.c_str(), "GameSelectPreviousGravestone", "Q");
                    ini.SetValue(section.c_str(), "GameSelectNextGravestone", "Tab");
                    ini.SetValue(section.c_str(), "GameSelectGravestone", "Enter");
                    ini.SetValue(section.c_str(), "GameBulletControlUp", "W");
                    ini.SetValue(section.c_str(), "GameBulletControlDown", "S");
                    ini.SetValue(section.c_str(), "GameBulletControlLeft", "A");
                    ini.SetValue(section.c_str(), "GameBulletControlRight", "D");
                    ini.SetValue(section.c_str(), "GameTimer1", "1");
                    ini.SetValue(section.c_str(), "GameTimer2", "2");
                    ini.SetValue(section.c_str(), "GameTimer3", "3");
                    ini.SetValue(section.c_str(), "GameTimer4", "4");
                    ini.SetValue(section.c_str(), "GameTimer5", "5");
                    ini.SetValue(section.c_str(), "GameTimer6", "6");
                    ini.SetValue(section.c_str(), "GameTimerPrevious", "Down_Arrow");
                    ini.SetValue(section.c_str(), "GameTimerNext", "Up_Arrow");
                    ini.SetValue(section.c_str(), "GameSkipTurn", "X");
                    ini.SetValue(section.c_str(), "GameToggleJetPack", "J");
                break;
                case 1:
                    ini.SetValue(section.c_str(), "GuiUp", "");
                    ini.SetValue(section.c_str(), "GuiDown", "");
                    ini.SetValue(section.c_str(), "GuiLeft", "");
                    ini.SetValue(section.c_str(), "GuiRight", "");
                    ini.SetValue(section.c_str(), "GuiNextWidget", "");
                    ini.SetValue(section.c_str(), "GuiPageUp", "");
                    ini.SetValue(section.c_str(), "GuiPageDown", "");
                    ini.SetValue(section.c_str(), "GuiHome", "");
                    ini.SetValue(section.c_str(), "GuiEnd", "");
                    ini.SetValue(section.c_str(), "GuiOK", "");
                    ini.SetValue(section.c_str(), "GuiBack", "");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingDelete", "");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingNextAlliance", "");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingNextAdvantage", "");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingTeamStatistics", "");
                    ini.SetValue(section.c_str(), "TeamEditingDelete", "");
                    ini.SetValue(section.c_str(), "TeamEditingInsert", "");
                    ini.SetValue(section.c_str(), "ButtonActivate", "");
                    ini.SetValue(section.c_str(), "ListBoxUp", "");
                    ini.SetValue(section.c_str(), "ListBoxDown", "");
                    ini.SetValue(section.c_str(), "WeaponListUp", "");
                    ini.SetValue(section.c_str(), "WeaponListDown", "");
                    ini.SetValue(section.c_str(), "WeaponListLeft", "");
                    ini.SetValue(section.c_str(), "WeaponListRight", "");
                    ini.SetValue(section.c_str(), "SettingsSliderIncrement", "");
                    ini.SetValue(section.c_str(), "SettingsSliderDecrement", "");
                    ini.SetValue(section.c_str(), "InventoryOpen", "Insert");
                    ini.SetValue(section.c_str(), "InventoryWeaponInformation", "");
                    ini.SetValue(section.c_str(), "InventoryGoNextRow", "");
                    ini.SetValue(section.c_str(), "InventoryGoNextColumn", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowPistol", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowRifle", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowCannon", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowGrenade", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowMine", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowBonus1", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowBonus2", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowHandy", "");
                    ini.SetValue(section.c_str(), "ShopBuyWeapon", "");
                    ini.SetValue(section.c_str(), "ShopRemoveWeapon", "");
                    ini.SetValue(section.c_str(), "InGameMenuOpen", "");
                    ini.SetValue(section.c_str(), "GamePlaceCharacter", "LMouse");
                    ini.SetValue(section.c_str(), "GameForward", "");
                    ini.SetValue(section.c_str(), "GameBackward", "");
                    ini.SetValue(section.c_str(), "GameStrafeLeft", "");
                    ini.SetValue(section.c_str(), "GameStrafeRight", "");
                    ini.SetValue(section.c_str(), "GameRotateLeft", "");
                    ini.SetValue(section.c_str(), "GameRotateRight", "");
                    ini.SetValue(section.c_str(), "GameJump", "Left_Ctrl");
                    ini.SetValue(section.c_str(), "GameShot", "LMouse");
                    ini.SetValue(section.c_str(), "GameUseAbility", "LMouse");
                    ini.SetValue(section.c_str(), "GameChangeCamera", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCamera", "");
                    ini.SetValue(section.c_str(), "GameBulletCamera", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraUp", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraDown", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraLeft", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraRight", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraBirdsEye", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraUp", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraDown", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraLeft", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraRight", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraZoomIn", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraZoomOut", "");
                    ini.SetValue(section.c_str(), "GameSelectPreviousCharacter", "");
                    ini.SetValue(section.c_str(), "GameSelectNextCharacter", "");
                    ini.SetValue(section.c_str(), "GameSelectCharacter", "LMouse");
                    ini.SetValue(section.c_str(), "GameSelectPreviousTeleport", "");
                    ini.SetValue(section.c_str(), "GameSelectNextTeleport", "");
                    ini.SetValue(section.c_str(), "GameSelectTeleport", "LMouse");
                    ini.SetValue(section.c_str(), "GameSelectPreviousPowerUp", "");
                    ini.SetValue(section.c_str(), "GameSelectNextPowerUp", "");
                    ini.SetValue(section.c_str(), "GameSelectPowerUp", "LMouse");
                    ini.SetValue(section.c_str(), "GameSelectPreviousGravestone", "");
                    ini.SetValue(section.c_str(), "GameSelectNextGravestone", "");
                    ini.SetValue(section.c_str(), "GameSelectGravestone", "LMouse");
                    ini.SetValue(section.c_str(), "GameBulletControlUp", "Mouse_Up");
                    ini.SetValue(section.c_str(), "GameBulletControlDown", "Mouse_Down");
                    ini.SetValue(section.c_str(), "GameBulletControlLeft", "Mouse_Left");
                    ini.SetValue(section.c_str(), "GameBulletControlRight", "Mouse_Right");
                    ini.SetValue(section.c_str(), "GameTimer1", "");
                    ini.SetValue(section.c_str(), "GameTimer2", "");
                    ini.SetValue(section.c_str(), "GameTimer3", "");
                    ini.SetValue(section.c_str(), "GameTimer4", "");
                    ini.SetValue(section.c_str(), "GameTimer5", "");
                    ini.SetValue(section.c_str(), "GameTimer6", "");
                    ini.SetValue(section.c_str(), "GameTimerPrevious", "");
                    ini.SetValue(section.c_str(), "GameTimerNext", "");
                    ini.SetValue(section.c_str(), "GameSkipTurn", "");
                    ini.SetValue(section.c_str(), "GameToggleJetPack", "");
                break;
                case 2:
                    ini.SetValue(section.c_str(), "GuiUp", "");
                    ini.SetValue(section.c_str(), "GuiDown", "");
                    ini.SetValue(section.c_str(), "GuiLeft", "");
                    ini.SetValue(section.c_str(), "GuiRight", "");
                    ini.SetValue(section.c_str(), "GuiNextWidget", "");
                    ini.SetValue(section.c_str(), "GuiPageUp", "");
                    ini.SetValue(section.c_str(), "GuiPageDown", "");
                    ini.SetValue(section.c_str(), "GuiHome", "");
                    ini.SetValue(section.c_str(), "GuiEnd", "");
                    ini.SetValue(section.c_str(), "GuiOK", "");
                    ini.SetValue(section.c_str(), "GuiBack", "");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingDelete", "");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingNextAlliance", "");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingNextAdvantage", "");
                    ini.SetValue(section.c_str(), "MultiplayerBriefingTeamStatistics", "");
                    ini.SetValue(section.c_str(), "TeamEditingDelete", "");
                    ini.SetValue(section.c_str(), "TeamEditingInsert", "");
                    ini.SetValue(section.c_str(), "ButtonActivate", "");
                    ini.SetValue(section.c_str(), "ListBoxUp", "");
                    ini.SetValue(section.c_str(), "ListBoxDown", "");
                    ini.SetValue(section.c_str(), "WeaponListUp", "");
                    ini.SetValue(section.c_str(), "WeaponListDown", "");
                    ini.SetValue(section.c_str(), "WeaponListLeft", "");
                    ini.SetValue(section.c_str(), "WeaponListRight", "");
                    ini.SetValue(section.c_str(), "SettingsSliderIncrement", "");
                    ini.SetValue(section.c_str(), "SettingsSliderDecrement", "");
                    ini.SetValue(section.c_str(), "InventoryOpen", "");
                    ini.SetValue(section.c_str(), "InventoryWeaponInformation", "");
                    ini.SetValue(section.c_str(), "InventoryGoNextRow", "");
                    ini.SetValue(section.c_str(), "InventoryGoNextColumn", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowPistol", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowRifle", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowCannon", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowGrenade", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowMine", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowBonus1", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowBonus2", "");
                    ini.SetValue(section.c_str(), "InventoryGoRowHandy", "");
                    ini.SetValue(section.c_str(), "ShopBuyWeapon", "");
                    ini.SetValue(section.c_str(), "ShopRemoveWeapon", "");
                    ini.SetValue(section.c_str(), "InGameMenuOpen", "");
                    ini.SetValue(section.c_str(), "GamePlaceCharacter", "");
                    ini.SetValue(section.c_str(), "GameForward", "");
                    ini.SetValue(section.c_str(), "GameBackward", "");
                    ini.SetValue(section.c_str(), "GameStrafeLeft", "");
                    ini.SetValue(section.c_str(), "GameStrafeRight", "");
                    ini.SetValue(section.c_str(), "GameRotateLeft", "");
                    ini.SetValue(section.c_str(), "GameRotateRight", "");
                    ini.SetValue(section.c_str(), "GameJump", "");
                    ini.SetValue(section.c_str(), "GameShot", "");
                    ini.SetValue(section.c_str(), "GameUseAbility", "");
                    ini.SetValue(section.c_str(), "GameChangeCamera", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCamera", "");
                    ini.SetValue(section.c_str(), "GameBulletCamera", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraUp", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraDown", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraLeft", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraRight", "");
                    ini.SetValue(section.c_str(), "GameThirdPersonCameraBirdsEye", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraUp", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraDown", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraLeft", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraRight", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraZoomIn", "");
                    ini.SetValue(section.c_str(), "GamePlanetCameraZoomOut", "");
                    ini.SetValue(section.c_str(), "GameSelectPreviousCharacter", "");
                    ini.SetValue(section.c_str(), "GameSelectNextCharacter", "");
                    ini.SetValue(section.c_str(), "GameSelectCharacter", "");
                    ini.SetValue(section.c_str(), "GameSelectPreviousTeleport", "");
                    ini.SetValue(section.c_str(), "GameSelectNextTeleport", "");
                    ini.SetValue(section.c_str(), "GameSelectTeleport", "");
                    ini.SetValue(section.c_str(), "GameSelectPreviousPowerUp", "");
                    ini.SetValue(section.c_str(), "GameSelectNextPowerUp", "");
                    ini.SetValue(section.c_str(), "GameSelectPowerUp", "");
                    ini.SetValue(section.c_str(), "GameSelectPreviousGravestone", "");
                    ini.SetValue(section.c_str(), "GameSelectNextGravestone", "");
                    ini.SetValue(section.c_str(), "GameSelectGravestone", "");
                    ini.SetValue(section.c_str(), "GameBulletControlUp", "");
                    ini.SetValue(section.c_str(), "GameBulletControlDown", "");
                    ini.SetValue(section.c_str(), "GameBulletControlLeft", "");
                    ini.SetValue(section.c_str(), "GameBulletControlRight", "");
                    ini.SetValue(section.c_str(), "GameTimer1", "");
                    ini.SetValue(section.c_str(), "GameTimer2", "");
                    ini.SetValue(section.c_str(), "GameTimer3", "");
                    ini.SetValue(section.c_str(), "GameTimer4", "");
                    ini.SetValue(section.c_str(), "GameTimer5", "");
                    ini.SetValue(section.c_str(), "GameTimer6", "");
                    ini.SetValue(section.c_str(), "GameTimerPrevious", "");
                    ini.SetValue(section.c_str(), "GameTimerNext", "");
                    ini.SetValue(section.c_str(), "GameSkipTurn", "");
                    ini.SetValue(section.c_str(), "GameToggleJetPack", "");
                break;
            }
        }
        ini.SaveFile("keybindings.ini");
        ini.LoadFile("keybindings.ini");
    }
    for(int i = 0; i < 3; i++) {
        std::string section = "KEYBINDING_"+std::to_string(i+1);
        switch(i) {
            case 0:
                offset = 2;
            break;
            case 1:
                offset = 94;
            break;
            case 2:
                offset = 186;
            break;
        }
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
            *(char *)((0x10BCFEC+4*i)+0xC*(it->nOrder-offset)) = STRING_TO_CC_KEY_CODE(std::string(ini.GetValue(section.c_str(), it->pItem)));
        }
    }
}

void LOOP_EN(bool Faster_Turn_Skips) {
    while (true) {
        Sleep(50);
        *(float*)(0x21F5AA8) = (*(float*)(0x12B4C60))/(*(float*)(0x12B4C64)); //display aspect ratio fix on resolution change
        if (*(char*)(0x1036CE4)) { //check if game started by checking whether there is atleast one character
            OBJECT_FIXES();
            GATE_FIXES();
            HIDE_HUD();
            *(float*)(0x218DF84) = (Faster_Turn_Skips && (GET_TURN_STATE() == 4 || GET_TURN_STATE() == 16 || GET_TURN_STATE() == 17 || GET_TURN_STATE() == 20)) ? 5.0:1.0; //speedup game when it is AI turn, singleplayer AI only
        }
    }
}

DWORD WINAPI Init(LPVOID lpParameter) {
    CSimpleIniA ini;
    char process_path[256];
    strcat(process_path,".\\save\\");
    if(ini.LoadFile("ccpatch.ini")) {
        ini.SetValue("GAME_PARAMETERS", "ThirdPersonFOV", "75");
        ini.SetValue("GAME_PARAMETERS", "FirstPersonFOV", "75");
        ini.SetValue("VIDEO", "DisableIntros", "0");
        ini.SetValue("VIDEO", "DisableMenuVideo", "0");
        ini.SetValue("VIDEO", "DisableCutsceneBorders", "0");
        ini.SetValue("MULTIPLAYER", "UDPPort", "18888");
        ini.SetValue("MULTIPLAYER", "TCPPort", "18889");
        ini.SetValue("MISC", "FasterTurnSkips", "0");
        ini.SetValue("MISC", "RelocateSavesToGameDir", "0");
        ini.SetValue("MISC", "SaveSlot", "-1");
        ini.SaveFile("ccpatch.ini");
    }
    ini.LoadFile("ccpatch.ini");
    REPLACE_CC_PATH(std::atoi(ini.GetValue("MISC", "RelocateSavesToGameDir")),process_path);
    float Third_Person_FOV = std::atof(ini.GetValue("GAME_PARAMETERS", "ThirdPersonFOV"));
    float First_Person_FOV = std::atof(ini.GetValue("GAME_PARAMETERS", "FirstPersonFOV"));
    float Sniper_Rifle_FOV = (First_Person_FOV-40.0 < 40.0) ? First_Person_FOV:First_Person_FOV-40.0;
    RENDERING_PATCHES(std::atoi(ini.GetValue("VIDEO", "DisableIntros")),std::atoi(ini.GetValue("VIDEO", "DisableMenuVideo")),std::atoi(ini.GetValue("VIDEO", "DisableCutsceneBorders")),Third_Person_FOV,First_Person_FOV,Sniper_Rifle_FOV);
    MULTIPLAYER_PATCHES(std::atoi(ini.GetValue("MULTIPLAYER", "UDPPort")),std::atoi(ini.GetValue("MULTIPLAYER", "TCPPort")));
    MISC_PATCHES(std::atoi(ini.GetValue("MISC", "SaveSlot")),std::atoi(ini.GetValue("MISC", "FasterTurnSkips")));
    KEYBIND_REMAP();
    LOOP_EN(std::atoi(ini.GetValue("MISC", "FasterTurnSkips")));
    return 0;
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID lpReserved) {
    DisableThreadLibraryCalls(module);
    HANDLE hThread = nullptr;

    switch (reason) {
        case DLL_PROCESS_ATTACH: {
            SetProcessDPIAware();
            hThread = CreateThread(nullptr, 0, Init, nullptr, 0, nullptr);
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
