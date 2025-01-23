#include "logger.h"
#include <sstream>
#include <iomanip>

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Не удалось открыть файл журнала.");
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const std::string& message) {
    if (logFile.is_open()) {
        std::time_t now = std::time(nullptr);
        char dt[26];
        ctime_s(dt, sizeof(dt), &now);
        dt[strlen(dt) - 1] = '\0'; // Remove newline character
        logFile << "[" << dt << "] " << message << "\n";
        logFile.flush();
    }
}