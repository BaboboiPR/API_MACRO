#pragma once
#include <thread>
#include <atomic>
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

        if (GetAsyncKeyState(VK_F12) & 1) {
            is_running = false;
        }
        if (GetAsyncKeyState(VK_F10) & 1 and is_paused == false) {
            is_paused = true;
        }
    }


    void pause_check()
    {
        while (is_paused == true) {
            Sleep(1);
            listener();
        }
        while (is_running == true or is_paused == false) {
            if (GetAsyncKeyState(VK_F12) & 1) {
                is_running = false;
            }
            if (GetAsyncKeyState(VK_F10) & 1 and is_paused == false) {
                is_paused = true;
            }
        }
    }

    std::atomic <bool> is_running = true;
    std::atomic <bool> is_paused = false;
    public:


    void initialize() {
        std::thread pause_worker(&APP::pause_check,this);
        pause_worker.detach(); // It can backfire if APP is destroyed
    }

    int APP_LOOP()
    {
        initialize();
        while (is_running)
        {
                        instruction();

            printStackUsage();
            SLEEP(10);
        }
        return 0;
    }
    void instruction() {

        //press('w',10);
        //press_hold('w',10,10);
        //moveCursor(50       ,0,10);
        leftClick();
        leftClick();
        leftClick();
        leftClick();
    }
};
