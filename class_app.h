#pragma once
#include <thread>
#include <atomic>
#include <mutex>
#include "keyboard_api.h"
#include <windows.h>
#include "debug.h"
#include "mouse_api.h"

class APP:Keyboard, debug,Mouse
{
    std::atomic <bool> is_running = true;
    std::atomic <bool> is_paused = false;
    //Stop state
    //wait state
    std::mutex mutex_;

    void listener()
    {

        if (GetAsyncKeyState(VK_F12) & 1) {
            std::cerr << "Stopped" << std::endl;
            is_running = false;
        }
        if (GetAsyncKeyState(VK_F10) & 1 and is_paused == false) {
            std::cerr << "Paused" << std::endl;
            is_paused = true;
            Sleep(1000);
        }
        else if (GetAsyncKeyState(VK_F10) & 1 and is_paused == true) {
            std::cerr << "UnPaused" << std::endl;
            is_paused = false;
            Sleep(1000);
        }

    }


    void pause_check()
    {
        while (true) {
            {
                mutex_.lock();
                listener();
                mutex_.unlock();
            }
        }

    }


    public:


    void initialize() {
        std::thread pause_worker(&APP::pause_check,this);
        pause_worker.detach(); // It can backfire if APP is destroyed
    }

    int APP_LOOP()
    {
        initialize();
        while (is_running==true)
        {
            while (is_paused == false and is_running == true) {
                {
                    mutex_.lock();
                    instruction();
                    mutex_.unlock();
                }
                SLEEP(10);
            }

        }
        return 0;
    }
    void app_macros() {
        bss:{
            press('2',30*999);//   stingers
            press('7',10*999);// keep snowflakes
            press('5',30*999);
        }
    }
    void instruction() {
            //press_hold('w',10,1000);
            press_hold(' ',10,1000);
            //press_hold('1',1000,100);

    }
};
