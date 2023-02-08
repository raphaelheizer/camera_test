//
// Created by raphael on 06/02/23.
//

#include <string>
#pragma once

class Camera {
public:
    virtual void initialize() = 0;

    virtual void handleCapture() = 0;

    virtual void setIp(std::string ip) = 0;

    ~Camera() = default;
};
