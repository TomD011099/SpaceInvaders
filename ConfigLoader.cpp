#include "ConfigLoader.h"

ConfigLoader::ConfigLoader(const std::string &path) {
    doc.LoadFile(path.c_str());
}

std::map<std::string, double> ConfigLoader::load() {
    parse(doc.FirstChildElement("Settings"), "", true);

    return parsedMap;
}

void ConfigLoader::parse(tinyxml2::XMLNode* root, const std::string &path, bool first) {
    tinyxml2::XMLElement* e = root->ToElement();

    if (e->FirstChild()->NoChildren()) {
        std::string val(e->GetText());
        double valD = std::stod(val);
        parsedMap.insert(std::pair<std::string, double>(path, valD));
    } else {
        for (tinyxml2::XMLNode* node = root->FirstChildElement(); node; node = node->NextSibling()) {
            if (first) {
                parse(node, node->ToElement()->Name(), false);
            } else {
                std::string name(node->ToElement()->Name());
                std::string out = path;
                parse(node, out.append(".").append(name), false);
            }
        }
    }
}