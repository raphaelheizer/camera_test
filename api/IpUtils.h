//
// Created by raphael on 06/02/23.
//

#ifndef CAMERA_TEST_IPUTILS_H
#define CAMERA_TEST_IPUTILS_H

#include <string>

using namespace std;

class IpUtils {
private:
    static string ipPattern;
    static string portPattern;
public:
    static bool validate(const string &ip);

    static string toRstpUrl(const string &ip, const string &streamPath, const string &protocol = "http");

    static bool validateEnforcePort(const string &ip);
};

#endif //CAMERA_TEST_IPUTILS_H
