//
// Created by raphael on 06/02/23.
//
#include "Console.h"
#include <string>
#include <iostream>

using namespace std;

void Console::log(const std::string &message) {
    cout << message;
}

void Console::logln(const string &message) {
    Console::log(message);
    cout << endl;
}
