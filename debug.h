#pragma once
#include <windows.h>
#include <iostream>
class debug
{
    public:
    void printStackUsage()
    {
        int x;
        static void* stackBase = &x; // approximate top at first call

        std::ptrdiff_t used =
            (char*)stackBase - (char*)&x;

        std::cout << "Approx stack used: "
                  << used / 1024
                  << " KB\n";
    }
    static void panic(std::string msg)
    {
        std::cerr << msg;
    }
};
