#pragma once
#include <ImageHlp.h>

void WriteByte(int addr, int data);
void WriteShort(int addr, int data);
void WriteInt(int addr, int data);
void WriteFloat(int addr, float data);
void WriteBuf(int addr, void * data, int len);
void WriteNOP(int addr, int len);
void WriteFloatPointer(int addrTgt, float * addrSrc);
void WriteIntPointer(int addrTgt, int * addrSrc);

// 5 bytes
void WriteRelJump(int jumpSrc, int jumpTgt);
void WriteRelCall(int jumpSrc, int jumpTgt);

// 6 bytes
void WriteRelJnz(int jumpSrc, int jumpTgt);
void WriteRelJle(int jumpSrc, int jumpTgt);

HMODULE GetModule();
int GetBaseAddress();
int GetPattern(char * pattern, char* mask);