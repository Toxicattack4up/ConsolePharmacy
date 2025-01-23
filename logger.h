#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <ctime>

class Logger {
private:
    std::ofstream logFile;

public:
    Logger(const std::string& filename);
    ~Logger();
    void log(const std::string& message);
};

#endif // LOGGER_H