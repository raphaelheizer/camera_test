//
// Created by raphael on 06/02/23.
//
#include <stdexcept>
#include "CameraHandler.h"
#include "../../api/console/Console.h"
#include "../../api/IpUtils.h"

void CameraHandler::initialize() {
    const auto consoleOpenMessage = "Informe um IP para a câmera a ser acessada";
    Console::logln(consoleOpenMessage);

    this->setHandlingIp();
    this->initializeCamera();
}

void CameraHandler::setHandlingIp() {
    std::cin >> ip;
}

void CameraHandler::initializeCamera() {
    if (ip.empty()) {
        throw std::invalid_argument("IP inválido");
    }

    camera->setIp(ip);
    camera->initialize();

    Console::logln("A API de câmera foi inicializada com sucesso");
}

CameraHandler::~CameraHandler() = default;
