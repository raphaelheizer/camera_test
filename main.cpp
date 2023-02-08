#include <iostream>
#include "api/console/Console.h"
#include "modules/camera_handler/CameraHandler.h"

int main() {
    auto *camera = new OpenCvCamera();
    auto *cameraHandler = new CameraHandler(camera);
    cameraHandler->initialize();

    return 0;
}
