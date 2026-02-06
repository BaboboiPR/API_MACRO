#pragma once
#include "keyboard_api.h"
#include <windows.h>
#include "debug.h"
#include "mouse_api.h"
class APP:Keyboard, debug,Mouse
{
    private:
    //Stop state
    void listener()
    {
        if (GetAsyncKeyState(VK_F12) & 0x8000) {
            is_running = false;
        }
    }

    bool is_running = true;
    public:

    int APP_LOOP()
    {
        instruction k{{'o'},{10}};
        while (is_running)
        {
            listener();
            //press('w',100);
            //press(k);
            moveCursor(100,100,100);
            moveCursor(500,300,100);
            printStackUsage();
            SLEEP(10);
        }
        return 0;
    }

};
