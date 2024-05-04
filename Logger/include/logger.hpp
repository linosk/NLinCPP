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

        //void log(logType type, std::string text); // maybe add function logN(not this name) that would add "\n"
        //void log(logType type, std::string text, int value);

        // template<typename... Args>
        // void logTmp(logType type, Args... args);

        void log(const logType type, const std::initializer_list<std::string>& args);

public:
        std::string logNameFile;
        std::string logNameFilePath;
        std::filesystem::path currentPath = std::filesystem::current_path();

        Logger(std::string logNameFile = "common.log");

        void enableDebug(void);
        void disableDebug(void);

        void enableTimeLogging(void);
        void disableTimeLogging(void);

        //later make it a template or sth
        //void logInfo(std::string information);
        //void logInfo(std::string information, int value);

        //void logDebug(std::string information);
        //void logDebug(std::string information, int value);

        // template<typename... Args>
        // void logInfoTmp(Args&&... args);

        // template<typename T>
        // int countArgs(T&&);

        // template<typename T>
        // int countArgs(T&&){
                // return 1;
        // }

        // template<typename... Args>
        // int sa(Args... args){
                // return 1 + countArgs(std::forward<Args>(args)...);
        // }
        // template<typename... Args>
        // int sa(const Args&... args){
                // constexpr auto size = sizeof...(Args);
                // return size;
        // }

        // int w(const std::string&... args){
                // 
        // }

        void logInfo(const std::initializer_list<std::string>& args);

};

#endif//_LOGGER_HPP_