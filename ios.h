#pragma once
#include <fstream>
#include <string>
#include "keyboard_api.h"
#include <iostream>

void log(std::string input,std::string ms)
{
    std::cerr<<"log: "<<input[0]<<" "<<ms << std::endl;
}
void READ_AND_EXECUTE_FILE(std::string file)
{
    std::ifstream file_(file);
    std::string input;
    std::string ms;
    while (file_ >> input)
    {
        if (input == "press")
        {
            file_ >> input;
            file_ >> ms;
        }
        else if (input == "write")
        {
            file_ >> input;
            file_ >> ms;
        }
        log(input,ms);
    }
    file_.close();
}

#ifdef WIN32
void SLEEP(int ms){
    Sleep(ms);
}
#endif
