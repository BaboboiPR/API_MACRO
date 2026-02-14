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
    inline void leftClick() {
        INPUT inputs[2] = {};

        inputs[0].type = INPUT_MOUSE;
        inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

        inputs[1].type = INPUT_MOUSE;
        inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

        SendInput(2, inputs, sizeof(INPUT));
    }
    inline void rightClick() {
        INPUT inputs[2] = {};

        inputs[0].type = INPUT_MOUSE;
        inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

        inputs[1].type = INPUT_MOUSE;
        inputs[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;

        SendInput(2, inputs, sizeof(INPUT));
    }

    void moveCursor(int dx, int dy,int sleep) {
        INPUT input = {};
        input.type = INPUT_MOUSE;
        input.mi.dx = dx; // relative movement
        input.mi.dy = dy;
        input.mi.dwFlags = MOUSEEVENTF_MOVE;
        SendInput(1, &input, sizeof(INPUT));
        SLEEP(sleep);
    }

    void moveCursor(instruction_mouse it)
    {
        BOOL result = SetCursorPos(it.position_x, it.position_y);
        if (!result)
        {
            debug::panic("Failed to move the cursor\n");
        }
        SLEEP(it.sleep);
    }
};