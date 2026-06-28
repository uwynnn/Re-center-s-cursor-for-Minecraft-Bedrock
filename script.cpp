#include <windows.h>
#include <iostream>

int main() {
    int targetX = 960;
    int targetY = 540;

    std::cout << "Listening for game GUI... Press 'Ctrl + C' to stop." << std::endl;

    bool alreadySnapped = false;

    while (!((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState('C') & 0x8000))) {
        
        CURSORINFO ci = { 0 };
        ci.cbSize = sizeof(CURSORINFO);

        if (GetCursorInfo(&ci)) {
            if (ci.flags == CURSOR_SHOWING) {
                if (!alreadySnapped) {
                    SetCursorPos(targetX, targetY);
                    std::cout << "GUI Detected! Cursor snapped to (" << targetX << ", " << targetY << ")" << std::endl;
                    alreadySnapped = true;
                }
            } else {
                alreadySnapped = false;
            }
        }
        
        Sleep(1); 
    }

    std::cout << "\nScript stopped via Ctrl + C." << std::endl;
    return 0;
}