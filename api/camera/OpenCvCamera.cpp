//
// Created by raphael on 06/02/23.
//
#pragma once

#include <stdexcept>
#include "OpenCvCamera.h"
#include "../IpUtils.h"
#include "../console/Console.h"

void OpenCvCamera::initialize() {
    if (connectIp.empty())
        throw std::invalid_argument("Informe o IP");

    if (connectIp == "127.0.0.1") {
        this->connectCamera();
    } else {
        this->connectIpCamera();
    }
}

void OpenCvCamera::connectCamera() {
    namedWindow(cameraWindowName);
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        Console::logln("Nenhuma câmera detectada para o dispositivo local. Existe uma câmera configurada?");
        return;
    }

    while (true) {
        cap >> image;
        if (image.empty()) break;

        imshow(cameraWindowName, image);

        char wk = (char) waitKey(25);
        if (wk == 27) {
            break;
        }
    }
}

void OpenCvCamera::connectIpCamera() {
    string rstpIp = IpUtils::toRstpUrl(connectIp, "videostream.cgi?user=admin&pwd=123456");
    connectIp = rstpIp;

    Console::logln("Conectando a " + rstpIp);

    cv::VideoCapture cap(rstpIp);

    if (!cap.isOpened())
        throw std::invalid_argument("Error: Could not access the camera");

    cv::Mat frame;

    while (true) {
        cap >> frame;
        if (frame.empty())
            break;
        cv::imshow("Live Stream", frame);
        if (cv::waitKey(10) == 27)
            break;
    }

    cap.release();
    cv::destroyAllWindows();
}

void OpenCvCamera::handleCapture() {

}

void OpenCvCamera::setIp(std::string ip) {
    bool isIpValid = IpUtils::validate(ip);
    if (!isIpValid) {
        connectIp = "";
        throw std::invalid_argument("Formato de IP inválido. Formato esperado: 000.000.000.000:00000");
    }
    connectIp = ip;
}
