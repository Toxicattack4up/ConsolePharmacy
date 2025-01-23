#include "utils.h"
#include <sstream>
#include <iomanip>

// ������� ����������� ������� (�� SHA-256)
std::string hashPassword(const std::string& password) {
    std::stringstream ss;
    for (char c : password) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c) + 42; // ������� ��������
    }
    return ss.str();
}

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}