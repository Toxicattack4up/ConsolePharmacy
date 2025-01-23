#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

std::string hashPassword(const std::string& password);
std::vector<std::string> splitString(const std::string& str, char delimiter);

#endif // UTILS_H