#ifndef _LOGGERTIME_HPP_//maybe better name
#define _LOGGERTIME_HPP_

#include <unordered_map>
#include <string>
#include <ctime>

class LoggerTime{

private:

    inline static const std::unordered_map<std::string,std::string> months = {
            {"Jan","1"},
            {"Feb","2"},
            {"Mar","3"},
            {"Apr","4"},
            {"May","5"},
            {"Jun","6"},
            {"Jul","7"},
            {"Aug","8"},
            {"Sep","9"},
            {"Oct","10"},
            {"Nov","11"},
            {"Dec","12"},
    };

    std::string getTime(void);
    std::string getDayFormatted(std::string day);
    std::string getMonthFormatted(std::string month);

public:

    std::string getTimeFormatted(void);

};

#endif//_LOGGERTIME_HPP_