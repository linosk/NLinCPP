#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <string>
#include <unordered_map>
#include <ctime>
#include <filesystem>
#include <fstream>

#include "loggertime.hpp"

template<typename... Args> // is this good?

class Logger{



private:
        inline static const std::string logNameDir = ".logs";
        bool isDebugEnabled = false;
        bool isTimeLogged = false;

        enum logType{
                INFO = 0,
                WARNING,
                ERROR,
                DEBUG
        };

        LoggerTime loggertime;

        void log(logType type, std::string text); // maybe add function logN(not this name) that would add "\n"
        void log(logType type, std::string text, int value);
        //template<typename... Args>
        void logTmp(logType type, Args... args);

public:
        std::string logNameFile;
        std::string logNameFilePath;
        std::filesystem::path currentPath = std::filesystem::current_path();

        Logger(std::string logNameFile = "default");

        void enableDebug(void);
        void disableDebug(void);

        void enableTimeLogging(void);
        void disableTimeLogging(void);

        //later make it a template or sth
        void logInfo(std::string information);
        void logInfo(std::string information, int value);

        void logDebug(std::string information);
        void logDebug(std::string information, int value);

};

#endif//_LOGGER_HPP_