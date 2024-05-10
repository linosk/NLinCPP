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

        enum logType{
                INFO = 0,
                ERROR,
                DEBUG
        };

        inline static const std::unordered_map<int, std::string> months = {
                {1,"Jan"},
                {2,"Feb"},
                {3,"Mar"},
                {4,"Apr"},
                {5,"May"},
                {6,"Jun"},
                {7,"Jul"},
                {8,"Aug"},
                {9,"Sep"},
                {10,"Oct"},
                {11,"Nov"},
                {12,"Dec"},
        };

        void log(logType type, std::string text); // maybe add function logN(not this name) that would add "\n"
        void log(logType type, std::string text, int value);
        std::string getTimeAndDate(void);
        std::string getTimeAndDateFormatted(void);
        std::string getDayFromatted(std::string day);
        std::string getMonthFormatted(std::string month);

public:
        std::string logNameFile;
        std::string logNameFilePath;
        std::filesystem::path currentPath = std::filesystem::current_path();

        Logger(std::string logNameFile);

        void enableDebug(void);
        void disableDebug(void);

        //later make it a template or sth
        void logInfo(std::string information);
        void logInfo(std::string information, int value);

        void logDebug(std::string information);
        void logDebug(std::string information, int value);


};

#endif//_LOGGER_HPP_