#include <iostream>
#include <QApplication>
#include "LuaEnv.h"
#include "GameWindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    LuaEnv::execute("./../scripts/test.lua");
    int value = LuaEnv::getGlobal("x").cast<int>();
    std::cout << value;

    GameWindow w;
    w.show();

    return a.exec();
}