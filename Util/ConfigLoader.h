#ifndef SPACEINVADERS_CONFIGLOADER_H
#define SPACEINVADERS_CONFIGLOADER_H

#include "tinyxml2.h"
#include <iostream>
#include <map>

class ConfigLoader {
private:
    tinyxml2::XMLDocument doc;
    std::map<std::string, std::string> parsedMap;

    void parse(tinyxml2::XMLNode*, const std::string &, bool);

public:
    ConfigLoader(const std::string &);

    std::map<std::string, std::string> load();
};

#endif