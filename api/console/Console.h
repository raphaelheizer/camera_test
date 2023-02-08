//
// Created by raphael on 06/02/23.
//

#ifndef CAMERA_TEST_CONSOLE_H
#define CAMERA_TEST_CONSOLE_H

#include <string>
#include <iostream> // header in standard library

class Console {
public:
    static void log(const std::string &message);

    static void logln(const std::string &message);
};

#endif //CAMERA_TEST_CONSOLE_H
