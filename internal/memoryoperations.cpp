#include "memoryoperations.hpp"

void WriteByte(int addr, int data) 
{
    unsigned long oldProtect;

    VirtualProtect((int*)addr, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
    *((char *)addr) = data;
    VirtualProtect((int*)addr, 4, oldProtect, &oldProtect);
}

void WriteShort(int addr, int data) 
{
    unsigned long oldProtect;

    VirtualProtect((int*)addr, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
    *((short *)addr) = data;
    VirtualProtect((int*)addr, 4, oldProtect, &oldProtect);
}

void WriteInt(int addr, int data) 
{
    unsigned long oldProtect;

    VirtualProtect((int*)addr, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
    *((int *)addr) = data;
    VirtualProtect((int*)addr, 4, oldProtect, &oldProtect);
}

void WriteFloat(int addr, float data) 
{
    unsigned long oldProtect;

    VirtualProtect((int*)addr, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
    *((float *)addr) = data;
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

void WriteFloatPointer(int addrTgt, float * addrSrc) {
    unsigned long oldProtect;

    VirtualProtect((int*)addrTgt, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
    *(float* *)(addrTgt) = addrSrc;
    VirtualProtect((int*)addrTgt, 4, oldProtect, &oldProtect);
}

void WriteRelJump(int jumpSrc, int jumpTgt) 
{
    //jmp rel32
    WriteByte(jumpSrc, 0xE9);
    WriteInt(jumpSrc + 1, jumpTgt - jumpSrc - 1 - 4);
}

void WriteRelCall(int jumpSrc, int jumpTgt) 
{
    //call rel32
    WriteByte(jumpSrc, 0xE8);
    WriteInt(jumpSrc + 1, jumpTgt - jumpSrc - 1 - 4);
}

void WriteRelJnz(int jumpSrc, int jumpTgt) 
{
    //jnz rel32
    WriteShort(jumpSrc, 0x850F);
    WriteInt(jumpSrc + 2, jumpTgt - jumpSrc - 2 - 4);
}

void WriteRelJle(int jumpSrc, int jumpTgt) 
{
    //jle rel32
    WriteShort(jumpSrc, 0x8E0F);
    WriteInt(jumpSrc + 2, jumpTgt - jumpSrc - 2 - 4);
}