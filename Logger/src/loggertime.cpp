#include "loggertime.hpp"

std::string LoggerTime::getTime(void){
    time_t now = time(0);
    std::string nowString = ctime(&now);
    return nowString;
}

std::string LoggerTime::getDayFormatted(std::string day){
    if(day[0]==' ')
        day[0] = '0';
    return day;
}

std::string LoggerTime::getMonthFormatted(std::string month){
    std::string monthNumber = months.at(month);
    if(monthNumber.length()>1)
        return monthNumber;
    return "0"+monthNumber;
}

std::string LoggerTime::getTimeFormatted(void){
    std::string nowString = getTime();
    std::string nowStringFormatted;
    std::string time = nowString.substr(11,8);
    std::string day = getDayFormatted(nowString.substr(8,2));
    std::string month = getMonthFormatted(nowString.substr(4,3));
    std::string year = nowString.substr(20,4);
    nowStringFormatted = "["+day+"."+month+"."+year+" "+time+"]:";
    return nowStringFormatted;
}