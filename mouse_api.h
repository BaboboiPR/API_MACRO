#pragma once
#include <windows.h>
#include "debug.h"

struct instruction_mouse
{
    int position_x;
    int position_y;
    int sleep;
};

class Mouse
{
    public:
    void moveCursor(int dx, int dy,int sleep) {
        INPUT input = {};
        input.type = INPUT_MOUSE;
        input.mi.dx = dx; // relative movement
        input.mi.dy = dy;
        input.mi.dwFlags = MOUSEEVENTF_MOVE;
        SendInput(1, &input, sizeof(INPUT));
        SLEEP(sleep);
    }
    void moveCursoir(instruction_mouse it)
    {
        BOOL result = SetCursorPos(it.position_x, it.position_y);
        if (!result)
        {
            debug::panic("Failed to move the cursor\n");
        }
        SLEEP(it.sleep);
    }
};