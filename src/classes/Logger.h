//
// Created by gavin on 11/10/2025.
//

#ifndef SFMLCODINGPROJECT_LOGGER_H
#define SFMLCODINGPROJECT_LOGGER_H


// C++ program to implement a basic logging system.

#include <fstream>
#include <sstream>
#include <iostream>

// Enum to represent log levels
enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };

class Logger {
public:
    // Constructor: Opens the log file in append mode
    explicit Logger(const std::string& filename);
    // Destructor: Closes the log file
    ~Logger();
    // Logs a message with a given log level
    void log(LogLevel level, const std::string& message);
    bool isLogOpen();
    void closeLog();
    void openLog(const std::string& filename);
private:
    std::ofstream logFile; // File stream for the log file
    // Converts log level to a string for output
    static std::string levelToString(LogLevel level);

};


#endif //SFMLCODINGPROJECT_LOGGER_H