#include "logger.hpp"

Logger::Logger(std::string logNameFile){

    if(!std::filesystem::exists(logNameDir)){
        std::filesystem::create_directories(logNameDir);
    }

    this->logNameFilePath = logNameDir + "/" + logNameFile; //linux style paths, wont run on windows

    if(!std::filesystem::exists(this->logNameFilePath)){

        std::ofstream logFile(this->logNameFilePath, std::ios::app);
        logFile.close();
    }
}

void Logger::logInfo(std::string log){ //todo std::string& format, ...

    std::ofstream logFile(this->logNameFilePath, std::ios::app);
    logFile<<log+"\n";
    logFile.close();
}