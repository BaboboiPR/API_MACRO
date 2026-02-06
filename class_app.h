#pragma once
#include "keyboard_api.h"
#include <windows.h>
#include "debug.h"
#include "mouse_api.h"
class APP:Keyboard, debug,Mouse
{
    private:
    //Stop state
    //wait state
    void listener()
    {
        if (GetAsyncKeyState(VK_F12) & 0x8000) {
            is_running = false;
        }
        if (GetAsyncKeyState(VK_F10) & 0x8000 and is_paused == false) {
            is_paused = true;
        }
    }

    void pause_check()
    {
        while (is_paused == true) {
            Sleep(10);
            listener();
        }
    }

    bool is_running = true;
    bool is_paused = false;
    public:

    int APP_LOOP()
    {
        while (is_running)
        {
            listener();
            instruction();
            printStackUsage();
            SLEEP(10);
        }
        return 0;
    }
    void instruction() {

        //press('w',10);
        //press_hold('w',10,10);
        moveCursor(50       ,0,10);
    }
};
