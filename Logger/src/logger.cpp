#include "logger.hpp" //restructure this

Logger::Logger(std::string logNameFile){
    //maybe add try and catch?
    if(!std::filesystem::exists(logNameDir)){
        std::filesystem::create_directories(logNameDir);
    }

    this->logNameFilePath = logNameDir + "/" + logNameFile + ".log"; //linux style paths, wont run on windows

    if(!std::filesystem::exists(this->logNameFilePath)){

        std::ofstream logFile(this->logNameFilePath, std::ios::app);
        logFile.close();
    }
}

void Logger::enableDebug(void){
    isDebugEnabled = true;
}

void Logger::disableDebug(void){
    isDebugEnabled = false;
}

void Logger::enableTimeLogging(void){
    isTimeLogged = true;
}

void Logger::disableTimeLogging(void){
    isTimeLogged = false;
}

void Logger::log(const logType type, const std::initializer_list<std::string>& args){

    std::ofstream logFile(this->logNameFilePath, std::ios::app);

    switch(type){
        case INFO:
            logFile<<"[ INFO    ]:";
            break;
        case WARNING:
            logFile<<"[ WARNING ]:";
            break;
        case ERROR:
            logFile<<"[ ERROR   ]:";
            break;
        case DEBUG:
            logFile<<"[ DEBUG   ]:";
            break;
        default:
            break;
    }

    if(isTimeLogged){
        std::string time = loggertime.getTimeFormatted();
        logFile<<time;
    }

    for(const auto& arg : args){
        logFile<<" ";
        logFile<<arg;
    }
    logFile<<"\n";
    logFile.close();

    logFile.close();
}

void Logger::logInfo(const std::initializer_list<std::string>& args){
    log(INFO,args);
}

void Logger::logWarning(const std::initializer_list<std::string>& args){
    log(WARNING,args);
}

void Logger::logError(const std::initializer_list<std::string>& args){
    log(ERROR,args);
}

void Logger::logDebug(const std::initializer_list<std::string>& args){
    if(isDebugEnabled){
        log(DEBUG,args);
    }
}