//
// Created by raphael on 06/02/23.
//

#ifndef CAMERA_TEST_OPENCVCAMERA_H
#define CAMERA_TEST_OPENCVCAMERA_H
#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include "Camera.h"
#include <iostream>

using namespace cv;
using namespace std;

class OpenCvCamera : public Camera {
private:
    string cameraWindowName;
    string connectIp;
    Mat image;

public:
    OpenCvCamera() : cameraWindowName("camera_view") {}

    void initialize() override;

    void handleCapture() override;

    void setIp(string ip) override;

private:
    ~OpenCvCamera() = default;

    void connectCamera();

    void connectIpCamera();
};

#endif //CAMERA_TEST_OPENCVCAMERA_H
