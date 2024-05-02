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
            logFile<<"[INFO ]:";
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

    if(isTimeLogged){
        std::string time = getTimeFormatted();
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
            logFile<<"[INFO ]:";
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

    if(isTimeLogged){
        std::string time = getTimeFormatted();
        logFile<<time;
    }

    logFile<<" ";
    logFile<<text;
    logFile<<" ";
    logFile<<value;
    logFile<<"\n";

    logFile.close();
}

std::string Logger::getTime(void){
    time_t now = time(0);
    std::string nowString = ctime(&now);
    return nowString;
}

std::string Logger::getDayFormatted(std::string day){
    if(day[0]==' ')
        day[0] = '0';
    return day;
}

std::string Logger::getMonthFormatted(std::string month){
    std::string monthNumber = months.at(month);
    if(monthNumber.length()>1)
        return monthNumber;
    return "0"+monthNumber;
}

std::string Logger::getTimeFormatted(void){
    std::string nowString = getTime();
    std::string nowStringFormatted;
    std::string time = nowString.substr(11,8);
    std::string day = getDayFormatted(nowString.substr(8,2));
    std::string month = getMonthFormatted(nowString.substr(4,3));
    std::string year = nowString.substr(20,4);
    nowStringFormatted = "["+day+"."+month+"."+year+" "+time+"]:";
    return nowStringFormatted;
}