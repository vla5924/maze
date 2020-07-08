#include <iostream>
#include "LuaEnv.h"

int main(int argc, char* argv[])
{
    LuaEnv::execute("./../scripts/test.lua");
    int value = LuaEnv::getGlobal("x").cast<int>();
    std::cout << value;
}