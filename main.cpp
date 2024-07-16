#include "external/SimpleIni.hpp"

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
    ini.LoadFile("ccpatch.ini");
    REPLACE_CC_PATH(std::atoi(ini.GetValue("MISC", "Relocate_Saves_To_Game_Dir")),process_path);
    float Third_Person_FOV = std::atof(ini.GetValue("GAME_PARAMETERS", "Third_Person_FOV"));
    float First_Person_FOV = std::atof(ini.GetValue("GAME_PARAMETERS", "First_Person_FOV"));
    float Sniper_Rifle_FOV = (First_Person_FOV-40.0 < 40.0) ? First_Person_FOV:First_Person_FOV-40.0;
    RENDERING_PATCHES(std::atoi(ini.GetValue("VIDEO", "Disable_Intros")),std::atoi(ini.GetValue("VIDEO", "Disable_Menu_Video")),std::atoi(ini.GetValue("VIDEO", "Disable_Cutscene_Borders")),Third_Person_FOV,First_Person_FOV,Sniper_Rifle_FOV);
    MULTIPLAYER_PATCHES(std::atoi(ini.GetValue("MULTIPLAYER", "UDP_Port")),std::atoi(ini.GetValue("MULTIPLAYER", "TCP_Port")));
    MISC_PATCHES(std::atoi(ini.GetValue("MISC", "Save_Slot")),std::atoi(ini.GetValue("MISC", "Faster_Turn_Skips")));
    LOOP_EN(std::atoi(ini.GetValue("MISC", "Faster_Turn_Skips")));
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
