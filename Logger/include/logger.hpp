#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <string>
#include <unordered_map>
#include <ctime>
#include <filesystem>
#include <fstream>

#include "loggertime.hpp"

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

        void log(const logType type, const std::initializer_list<std::string>& args);

public:
        std::string logNameFile;
        std::string logNameFilePath;
        std::filesystem::path currentPath = std::filesystem::current_path();

        Logger(std::string logNameFile = "common");

        void enableDebug(void);
        void disableDebug(void);

        void enableTimeLogging(void);
        void disableTimeLogging(void);

        void logInfo(const std::initializer_list<std::string>& args);
        void logWarning(const std::initializer_list<std::string>& args);
        void logError(const std::initializer_list<std::string>& args);
        void logDebug(const std::initializer_list<std::string>& args);

};

#endif//_LOGGER_HPP_