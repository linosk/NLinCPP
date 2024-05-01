#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <string>
#include <filesystem>
#include <fstream>
#include <cstdarg>

class Logger{

public:
        std::string logNameFile;
        std::string logNameFilePath;
        std::filesystem::path currentPath = std::filesystem::current_path();

        Logger(std::string logNameFile);

        void logInfo(std::string log);

private:
        inline static const std::string logNameDir = ".logs";

};

#endif//_LOGGER_HPP_