#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <string>
#include <filesystem>
#include <fstream>

class Logger{

private:
        inline static const std::string logNameDir = ".logs";

        enum logType{
                INFO = 0,
                ERROR,
                DEBUG
        };

        void log(logType type, std::string text); // maybe add function logN(not this name) that would add "\n"
        void log(logType type, std::string text, int value);

public:
        std::string logNameFile;
        std::string logNameFilePath;
        std::filesystem::path currentPath = std::filesystem::current_path();

        Logger(std::string logNameFile);

        //later make it a template or sth
        void logInfo(std::string information);
        void logInfo(std::string information, int value);

};

#endif//_LOGGER_HPP_