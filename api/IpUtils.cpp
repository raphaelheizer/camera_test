//
// Created by raphael on 06/02/23.
//
#include <regex>
#include "IpUtils.h"

using namespace std;

string IpUtils::ipPattern = R"((\w{1,5}:\/\/)*\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})";
string IpUtils::portPattern = R"(:\d{1,5})";

bool IpUtils::validate(const std::string &ip) {
    return regex_match(ip, regex(ipPattern)) || IpUtils::validateEnforcePort(ip);
}

bool IpUtils::validateEnforcePort(const std::string &ip) {
    return std::regex_match(ip, regex(ipPattern + portPattern));
}
// http://192.168.1.20/videostream.cgi?user=admin&pwd=admin
string IpUtils::toRstpUrl(const string &ip, const string &streamPath, const string &protocol) {
    const string &rstpFormat = R"(<protocol>://<ip-port>/<streamPath>)";
    string url = regex_replace(rstpFormat, regex("<ip-port>"), ip);
           url = regex_replace(url, regex("<streamPath>"), streamPath);
           url = regex_replace(url, regex("<protocol>"), protocol);

    return url;
}
