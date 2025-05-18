#include <Psapi.h>

template <typename T>
void WriteValue(int addr, T data) 
{
    unsigned long oldProtect;

    VirtualProtect((int*)addr, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
    *((T *)addr) = data;
    VirtualProtect((int*)addr, 4, oldProtect, &oldProtect);
}

void WriteBuf(int addr, void * data, int len) 
{
    unsigned long oldProtect;

    VirtualProtect((int*)addr, len, PAGE_EXECUTE_READWRITE, &oldProtect);
    memcpy((int *)addr, data, len);
    VirtualProtect((int*)addr, len, oldProtect, &oldProtect);
}

void WriteNOP(int addr, int len) 
{
    unsigned long oldProtect;
    
    VirtualProtect((int*)addr, len, PAGE_EXECUTE_READWRITE, &oldProtect);
    memset((int*)addr, 0x90, len);
    VirtualProtect((int*)addr, len, oldProtect, &oldProtect);
}

template <typename T>
void WritePointer(int addrTgt, T * addrSrc) 
{
    unsigned long oldProtect;

    VirtualProtect((int*)addrTgt, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
    *(T* *)(addrTgt) = addrSrc;
    VirtualProtect((int*)addrTgt, 4, oldProtect, &oldProtect);
}

void WriteRelJump(int jumpSrc, int jumpTgt) 
{
    //jmp rel32
    WriteValue<char>(jumpSrc, 0xE9);
    WriteValue<int>(jumpSrc + 1, jumpTgt - jumpSrc - 1 - 4);
}

void WriteRelCall(int jumpSrc, int jumpTgt) 
{
    //call rel32
    WriteValue<char>(jumpSrc, 0xE8);
    WriteValue<int>(jumpSrc + 1, jumpTgt - jumpSrc - 1 - 4);
}

void WriteRelJnz(int jumpSrc, int jumpTgt) 
{
    //jnz rel32
    WriteValue<short>(jumpSrc, 0x850F);
    WriteValue<int>(jumpSrc + 2, jumpTgt - jumpSrc - 2 - 4);
}

void WriteRelJle(int jumpSrc, int jumpTgt) 
{
    //jle rel32
    WriteValue<short>(jumpSrc, 0x8E0F);
    WriteValue<int>(jumpSrc + 2, jumpTgt - jumpSrc - 2 - 4);
}

HMODULE GetModule() {
    HMODULE lphModule[1024];
    DWORD lpcbNeeded(NULL);
    if (!EnumProcessModules(GetCurrentProcess(), lphModule, sizeof(lphModule), &lpcbNeeded)) return NULL;
    TCHAR szModName[MAX_PATH];
    if (!GetModuleFileNameEx(GetCurrentProcess(), lphModule[0], szModName, sizeof(szModName) / sizeof(TCHAR))) return NULL;
    return lphModule[0];
}

int GetBaseAddress() {
    return (int)GetModule();
}

int GetPattern(char * pattern, char* mask) {
    MODULEINFO modInfo = {0};
    GetModuleInformation(GetCurrentProcess(), GetModule(), &modInfo, sizeof(MODULEINFO));
    int base = (int)modInfo.lpBaseOfDll;
    int size = (int)modInfo.SizeOfImage;
    int patternLength = (int)strlen(mask);
    for(int i = 0; i < size - patternLength; i++) {
        bool found = true;
        for(int j = 0; j < patternLength; j++) {
            found &= mask[j] == '?' || pattern[j] == *(char *)(base+i+j);
        }
        if(found) return base+i;
    }
    return NULL;
}
