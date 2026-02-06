#pragma once

#ifdef _WIN32
#include <windows.h>
#include <cctype>
#include <string>
#include "ios.h"
struct instruction
{
    char instructions[100] = {};
    char sleep[100];
};
class Keyboard
{
    protected:
    static void press(char letter, int sleep) {
        bool uppercase = 0;
        if (std::isupper(static_cast<unsigned char>(letter)))
        {
            uppercase = true;
        }
        else
        {
            uppercase = false;
        }
        WORD vk = toupper(letter);
        if (uppercase == 0)
        {
            INPUT input[2] = {};

            // Key down
            input[0].type = INPUT_KEYBOARD;
            input[0].ki.wVk = vk;

            // Key up
            input[1].type = INPUT_KEYBOARD;
            input[1].ki.wVk = vk;
            input[1].ki.dwFlags = KEYEVENTF_KEYUP;

            SendInput(2, input, sizeof(INPUT));
        }
        else
        {
            INPUT input[4] = {};

            // Shift down
            input[0].type = INPUT_KEYBOARD;
            input[0].ki.wVk = VK_SHIFT;

            // W down
            input[1].type = INPUT_KEYBOARD;
            input[1].ki.wVk = vk;

            // W up
            input[2].type = INPUT_KEYBOARD;
            input[2].ki.wVk = vk;
            input[2].ki.dwFlags = KEYEVENTF_KEYUP;

            // Shift up
            input[3].type = INPUT_KEYBOARD;
            input[3].ki.wVk = VK_SHIFT;
            input[3].ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(4, input, sizeof(INPUT));
        }
        SLEEP(sleep);

    }
    static void press (instruction it)
    {
        int i = 0;
        while (it.instructions[i] != '\0')
        {
            press(it.instructions[i],it.sleep[i]);
        }
    }
    static void write(std::string word,int sleep)
    {
        long max_index = word.length();
        for (long i = 0; i < max_index; i++)
        {
            press(word[i],sleep);
        }

    }
    static void press_hold(char letter, int sleep,int hold) {
        bool uppercase = 0;
        if (std::isupper(static_cast<unsigned char>(letter)))
        {
            uppercase = true;
        }
        else
        {
            uppercase = false;
        }
        WORD vk = toupper(letter);
        if (uppercase == 0)
        {
            INPUT input[2] = {};

            // Key down
            input[0].type = INPUT_KEYBOARD;
            input[0].ki.wVk = vk;

            // Key up
            input[1].type = INPUT_KEYBOARD;
            input[1].ki.wVk = vk;
            input[1].ki.dwFlags = KEYEVENTF_KEYUP;

            SendInput(1, &input[0], sizeof(INPUT));
            SLEEP(hold);
            SendInput(1, &input[1], sizeof(INPUT));
        }
        else
        {
            INPUT input[4] = {};

            // Shift down
            input[0].type = INPUT_KEYBOARD;
            input[0].ki.wVk = VK_SHIFT;

            // W down
            input[1].type = INPUT_KEYBOARD;
            input[1].ki.wVk = vk;

            // W up
            input[2].type = INPUT_KEYBOARD;
            input[2].ki.wVk = vk;
            input[2].ki.dwFlags = KEYEVENTF_KEYUP;

            // Shift up
            input[3].type = INPUT_KEYBOARD;
            input[3].ki.wVk = VK_SHIFT;
            input[3].ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(4, input, sizeof(INPUT));
        }
        SLEEP(sleep);

    }
};

#endif

