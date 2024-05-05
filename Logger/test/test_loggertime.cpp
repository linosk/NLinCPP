#include <gtest/gtest.h>

#include "loggertime.hpp"

#include <iostream>

TEST(TEST_LoggerTime,getTime){
    LoggerTime loggertime;

    std::string time = loggertime.getTimeFormatted();

    EXPECT_EQ(22,time.length());
    EXPECT_EQ('[',time[0]);
    EXPECT_EQ('.',time[3]);
    EXPECT_EQ('.',time[6]);
    EXPECT_EQ(' ',time[11]);
    EXPECT_EQ(':',time[14]);
    EXPECT_EQ(':',time[17]);
    EXPECT_EQ(']',time[20]);
    EXPECT_EQ(':',time[21]);

    int year = std::stoi(time.substr(7,4));
    EXPECT_LE(year,2024);

    int month = std::stoi(time.substr(4,2));
    EXPECT_TRUE((month>=1)&&(month<=12));

    int day = std::stoi(time.substr(1,2));

    if(month==2)
        EXPECT_LE(day,29);
    
    if(month==4 || month==6 || month==9 || month == 11)
        EXPECT_LE(day,30);

    if(month==1 || month==3 || month==5 || month==7 || month==8|| month==10 || month==12)
        EXPECT_LE(day,31);

    int hour = std::stoi(time.substr(12,2));
    EXPECT_LE(hour,23);

    int minute = std::stoi(time.substr(15,2));
    EXPECT_LE(minute,59);

    int second = std::stoi(time.substr(18,2));
    EXPECT_LE(second,59);
}