//
// Created by raphael on 06/02/23.
//

#ifndef CAMERA_TEST_CAMERAHANDLER_H
#define CAMERA_TEST_CAMERAHANDLER_H

#include "../../api/camera/Camera.h"
#include "../../api/camera/OpenCvCamera.h"

class CameraHandler {
private:
    std::string ip;
    Camera* camera;

public:
    explicit CameraHandler(OpenCvCamera* camera) : camera(camera) {}

    void initialize();

    void initializeCamera();

    void setHandlingIp();

    ~CameraHandler();
};

#endif //CAMERA_TEST_CAMERAHANDLER_H
