cmake_minimum_required(VERSION 3.24)
project(camera_test)

add_executable(camera_test main.cpp api/console/Console.cpp api/console/Console.h api/IpUtils.cpp api/IpUtils.h api/camera/Camera.h api/camera/OpenCvCamera.cpp api/camera/OpenCvCamera.h modules/camera_handler/CameraHandler.h modules/camera_handler/CameraHandler.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(camera_test ${OpenCV_LIBS})
