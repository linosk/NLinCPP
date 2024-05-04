#include <gtest/gtest.h>

#include "logger.hpp"

TEST(TEST_LOGGER,logger){
    Logger logger1;
    EXPECT_TRUE(std::filesystem::exists(".logs"));
    EXPECT_TRUE(std::filesystem::exists(".logs/common.log"));
    std::filesystem::remove(".logs/common.log");
    std::filesystem::remove_all(".logs");

    Logger logger2 = Logger("test.log");
    EXPECT_TRUE(std::filesystem::exists(".logs/test.log"));
    std::filesystem::remove(".logs/test.log");
    std::filesystem::remove_all(".logs");
}

TEST(TEST_Logger,logInfo){
    Logger logger1;
    logger1.logInfo({"test log"});
}

TEST(TEST_Logger,logWarning){
    
}

TEST(TEST_Logger,logError){
    
}

TEST(TEST_Logger,logDebug){
    
}
