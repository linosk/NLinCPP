#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <string>
#include <unordered_map>
#include <ctime>
#include <filesystem>
#include <fstream>

class Logger{

private:
        inline static const std::string logNameDir = ".logs";
        bool isDebugEnabled = false;
        bool isTimeLogged = false;

        enum logType{
                INFO = 0,
                ERROR,
                DEBUG
        };

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

        void log(logType type, std::string text); // maybe add function logN(not this name) that would add "\n"
        void log(logType type, std::string text, int value);
        std::string getTime(void);
        std::string getTimeFormatted(void);
        std::string getDayFormatted(std::string day);
        std::string getMonthFormatted(std::string month);

public:
        std::string logNameFile;
        std::string logNameFilePath;
        std::filesystem::path currentPath = std::filesystem::current_path();

        Logger(std::string logNameFile);

        void enableDebug(void);
        void disableDebug(void);

        void enableTimeLogging(void);
        void disableTimeLogging(void);

        //later make it a template or sth
        void logInfo(std::string information);
        void logInfo(std::string information, int value);

        void logDebug(std::string information);
        void logDebug(std::string information, int value);


};

#endif//_LOGGER_HPP_