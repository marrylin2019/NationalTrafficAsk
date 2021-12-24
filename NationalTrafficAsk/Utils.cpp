#include "Utils.h"

std::vector<std::string> split(const std::string &prime, const std::string &sign)
{
    std::vector<std::string> result;
    std::string::size_type pos1, pos2;
    pos2 = prime.find(sign);
    pos1 = 0;
    while (std::string::npos != pos2)
    {
        result.push_back(prime.substr(pos1, pos2 - pos1));

        pos1 = pos2 + sign.size();
        pos2 = prime.find(sign, pos1);
    }
    if (pos1 != prime.length())
        result.push_back(prime.substr(pos1));
    return result;
}

