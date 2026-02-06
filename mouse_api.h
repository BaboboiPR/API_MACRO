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
    void moveCursor(int x, int y,int sleep) {
        BOOL result = SetCursorPos(x, y);
        if (!result)
        {
            debug::panic("Failed to move the cursor\n");
        }


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