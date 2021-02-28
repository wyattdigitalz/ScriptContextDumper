// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "windows.h"
#include <stdint.h>
#include "memory.h"
#include <string>
#include <fstream>

using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
        /* random c++ shit */
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    uint32_t ScriptContext = *((uint32_t*)(Memory::scan("\xC7\x07\x00\x00\x00\x00\xC7\x47\x00\x00\x00\x00\x00\x8B\x87", "xx????xx?????xx") + 2)); /*scan memory from lego game lmao*/
    string outcontext = to_string(ScriptContext);
    string msgboxcaptionlol = "Script Context Found!";
    
    std::wstring conversion1 = std::wstring(outcontext.begin(), outcontext.end());
    LPCWSTR ScriptContextOutput = conversion1.c_str();

    std::wstring conversion2 = std::wstring(msgboxcaptionlol.begin(), msgboxcaptionlol.end());
    LPCWSTR MSGBoxCaption = conversion2.c_str();

    MessageBox(0, ScriptContextOutput, MSGBoxCaption, MB_OK);

    exit(0);
}

