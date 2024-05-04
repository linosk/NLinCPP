#include "logger.hpp" //restructure this

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

void Logger::logDebug(std::string information){
    if(isDebugEnabled)
        log(DEBUG, information);
}

void Logger::logInfo(std::string information){
    log(INFO, information);
}

void Logger::log(logType type, std::string text){
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

    logFile<<" ";
    logFile<<text;
    logFile<<"\n";

    logFile.close();
}

void Logger::logDebug(std::string information, int value){
    if(isDebugEnabled)
        log(DEBUG, information, value);
}

void Logger::logInfo(std::string information, int value){
    log(INFO, information, value);
}

void Logger::log(logType type, std::string text, int value){
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

    logFile<<" ";
    logFile<<text;
    logFile<<" ";
    logFile<<value;
    logFile<<"\n";

    logFile.close();
}

template<typename... Args>
void Logger::logTmp(logType type, Args... args){

    

}