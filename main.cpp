#include "external/SimpleIni.hpp"

inline int GET_TURN_TIME() {
    return (*(int*)(0x21958D0)) ? *(int*)(*(int*)(0x21958D0)+0xCBB8):0;
}

inline char GET_TURN_STATE() {
    return (*(int*)(0x21958D0)) ? *(int*)(*(int*)(0x21958D0)+0xC3E4):-1;
}

DWORD WINAPI Loop_ENG(LPVOID lpParameter) {
    CSimpleIniA ini;
    ini.LoadFile("ccpatch.ini");
    if (std::atoi(ini.GetValue("MISC", "Relocate_Saves_To_Game_Dir"))) {
        char process_path[256];
        strcat(process_path,".\\save\\");
        CreateDirectoryA(process_path,0);
        memcpy((void*)0x12CA6C8, process_path, 256);
        VirtualProtectEx(GetCurrentProcess(),(void*)0x41D55C, 148, PAGE_EXECUTE_READWRITE, NULL);
        memset((void*)0x41D55C, 0x90, 148);
    }
    memset((void*)(0x4F5201), 0x90, 32); //don't check aspect ratio
    if (std::atoi(ini.GetValue("VIDEO", "Disable_Intros"))) {
        memcpy((void*)(0x54A34C), "", 6); //logos
        memcpy((void*)(0x54A364), "", 10); //gameintro
    }
    if (std::atoi(ini.GetValue("VIDEO", "Disable_Menu_Video"))) memcpy((void*)(0x5463D4), "", 29);
    if (std::atoi(ini.GetValue("VIDEO", "Disable_Cutscene_Borders"))) *(char *)(0x46E2AA) = 1;
    *(char *)(0x4DDE53) = std::atoi(ini.GetValue("MISC", "Save_Slot"));
    float THIRD_PERSON_FOV_VAR = std::atof(ini.GetValue("GAME_PARAMETERS", "Third_Person_FOV"));
    float FIRST_PERSON_FOV_VAR = std::atof(ini.GetValue("GAME_PARAMETERS", "First_Person_FOV"));
    int FASTER_TURN_SKIPS_VAR = std::atoi(ini.GetValue("MISC", "Faster_Turn_Skips"));
    float SNIPER_RIFLE_FOV_VAR = (FIRST_PERSON_FOV_VAR-40.0 < 40.0) ? FIRST_PERSON_FOV_VAR:FIRST_PERSON_FOV_VAR-40.0; 
    *(float* *)(0x421A43) = &SNIPER_RIFLE_FOV_VAR;
    *(float* *)(0x421A4B) = &FIRST_PERSON_FOV_VAR;
    *(float* *)(0x421AA3) = &THIRD_PERSON_FOV_VAR;
    *(char *)(0x4CFF2B) = 2; //flip number to indicate that game loaded patch
    if (FASTER_TURN_SKIPS_VAR) {
        memset((void*)0x44138A, 0x90, 2);
        *(int*)(0x56087C) = 20;
    }
    *(int *)(0x49C044) = std::atoi(ini.GetValue("MULTIPLAYER", "UDP_Port")); //movement
    *(int *)(0x4B2F32) = std::atoi(ini.GetValue("MULTIPLAYER", "TCP_Port")); //chat and other logic
    *(int *)(0x4B2D96) = std::atoi(ini.GetValue("MULTIPLAYER", "TCP_Port")); //server list
    memset((void*)0x4F2A59, 0x90, 7); //fix @ crash
    memset((void*)0x4F2A76, 0x90, 5);
    while (true) {
        Sleep(50);
        *(float*)(0x21F5AA8) = (*(float*)(0x12B4C60))/(*(float*)(0x12B4C64)); //display aspect ratio fix on resolution change
        if (*(char*)(0x1036CE4)) {
            if (*(int*)(0x12CA6B8)) {
                *(char*)(*(int*)(0x12CA6B8)+0x100*87+0xD6) = 11; /* laser blaster */
                *(char*)(*(int*)(0x12CA6B8)+0x100*91+0xD4) = 9; /* mine strike */
            }
            if (*(char*)(0x16A1B60)) { //check if in gate
                if (*(int*)(0x1037C40+*(int*)(0x10368CC)*0x4A0) == 124) *(char*)(0x21AADE8) = 0; //Rabid amok softlock fix
                if (*(int*)(0x1037C40+*(int*)(0x10368CC)*0x4A0) == 110) *(char*)(0x16A1B60) = 0; //Teleport crash fix related to referencing dead player
                if (*(char*)(0x21AAD44)) *(char*)(0x21AAD44) = 0; //Equity softlock fix
                if (*(int*)(0x1037C40+*(int*)(0x10368CC)*0x4A0) == 123 && GET_TURN_TIME() < 2) { //Gnar softlock fix
                    *(char*)(0x103799C+*(int*)(0x10368CC)*0x4A0) = 0;
                    *(char*)(0x16A1B60) = 0;
                }
            }
            if (GetAsyncKeyState(0x48) & 0x01) { //hide hud
                if (*(int*)(0x4C2101) == 0xFFFFDDFB) memset((void*)0x4C2100, 0x90, 5);
                else {
                    *(char *)(0x4C2100) = 0xE8;
                    *(int *)(0x4C2101) = 0xFFFFDDFB;
                }
            }
            *(float*)(0x218DF84) = (FASTER_TURN_SKIPS_VAR && (GET_TURN_STATE() == 4 || GET_TURN_STATE() == 16 || GET_TURN_STATE() == 17 || GET_TURN_STATE() == 20)) ? 5.0:1.0; //speedup game when it is AI turn, singleplayer AI only
        }
    }
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID lpReserved) {
    DisableThreadLibraryCalls(module);
    HANDLE hThread = nullptr;

    switch (reason) {
        case DLL_PROCESS_ATTACH: {
            SetProcessDPIAware();
            hThread = CreateThread(nullptr, 0, Loop_ENG, nullptr, 0, nullptr);
            CloseHandle(hThread);
            // Check if thread is invalid
            // Close thread handle when execution completed
            //CloseHandle(hThread);
            break;
        }
        case DLL_PROCESS_DETACH: {
            FreeLibraryAndExitThread(module,0);
            break;
        }
    }
    return TRUE;
}
