#include <windows.h>

const int TARGET_X = 960;
const int TARGET_Y = 540;

DWORD WINAPI BackgroundCursorThread(LPVOID lpParam) {
    bool alreadySnapped = false;

    // Infinite loop inside the game
    while (true) {
        CURSORINFO ci = { 0 };
        ci.cbSize = sizeof(CURSORINFO);

        if (GetCursorInfo(&ci)) {
            if (ci.flags == CURSOR_SHOWING) {
                if (!alreadySnapped) {
                    SetCursorPos(TARGET_X, TARGET_Y);
                    alreadySnapped = true;
                }
            } else {
                alreadySnapped = false;
            }
        }
        Sleep(1);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, 0, BackgroundCursorThread, hModule, 0, NULL);
        break;
    }
    return TRUE;
}