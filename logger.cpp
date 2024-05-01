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

void Logger::logInfo(std::string information){
    log(INFO, information);
}

void Logger::log(logType type, std::string text){
    std::ofstream logFile(this->logNameFilePath, std::ios::app);

    switch(type){
        case INFO:
            logFile<<"[INFO]:";
            break;
        case ERROR:
            logFile<<"[ERROR]:";
            break;
        case DEBUG:
            logFile<<"[DEBUG]:";
            break;
        default:
            break;
    }

    logFile<<" ";
    logFile<<text;
    logFile<<"\n";

    logFile.close();
}

void Logger::logInfo(std::string information, int value){
    log(INFO, information, value);
}

void Logger::log(logType type, std::string text, int value){
    std::ofstream logFile(this->logNameFilePath, std::ios::app);

    switch(type){
        case INFO:
            logFile<<"[INFO]:";
            break;
        case ERROR:
            logFile<<"[ERROR]:";
            break;
        case DEBUG:
            logFile<<"[DEBUG]:";
            break;
        default:
            break;
    }

    logFile<<" ";
    logFile<<text;
    logFile<<" ";
    logFile<<value;
    logFile<<"\n";

    logFile.close();
}

//is pretty much c-style logging, change it later, its ok for now
/*
void Logger::log(logType type, std::string log, ...){

    va_list args;
    va_start(args, log);

    std::ofstream logFile(this->logNameFilePath, std::ios::app);

    switch(type){
        case INFO:
            logFile<<"[INFO]: ";
            break;
        case ERROR:
            logFile<<"[ERROR]: ";
            break;
        case DEBUG:
            logFile<<"[DEBUG]: ";
            break;
        default:
            break;
    }

    int index = 0;
    while(index<log.length()){
        if(log[index] == '%'){
            char specifier = log[index+1];
            switch(specifier){
                case 'd':
                    logFile<<va_arg(args,int);
                    break;
                default:
                    break;
            }
            index+=2;
        }
        else{
            logFile<<log[index];
            index++;
        }
    }

    logFile<<"\n";

    logFile.close();
}
*/