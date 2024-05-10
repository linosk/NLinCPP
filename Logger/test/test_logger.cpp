#include <gtest/gtest.h>

#include "logger.hpp"

TEST(TEST_Logger,logger){
    Logger logger1;
    EXPECT_TRUE(std::filesystem::exists(".logs"));
    EXPECT_TRUE(std::filesystem::exists(".logs/common.log"));
    std::filesystem::remove(".logs/common.log");
    std::filesystem::remove_all(".logs");

    Logger logger2 = Logger("test");
    EXPECT_TRUE(std::filesystem::exists(".logs/test.log"));
    std::filesystem::remove(".logs/test.log");
    std::filesystem::remove_all(".logs");
}

TEST(TEST_Logger,logInfo){
    Logger logger = Logger("test");

    logger.logInfo({"test"});

    std::ifstream logFile(logger.logNameFilePath);

    std::string buffer;
    std::string log;
    while(getline(logFile,buffer)){
        log = log + buffer;
    }

    logFile.close();

    EXPECT_EQ(0,log.compare("[ INFO    ]: test"));

    std::filesystem::remove_all(".logs");
}


TEST(TEST_Logger,logWarning){
    Logger logger = Logger("test");

    logger.logWarning({"test"});

    std::ifstream logFile(logger.logNameFilePath);

    std::string buffer;
    std::string log;
    while(getline(logFile,buffer)){
        log = log + buffer;
    }

    logFile.close();

    EXPECT_EQ(0,log.compare("[ WARNING ]: test"));

    std::filesystem::remove_all(".logs");
}

TEST(TEST_Logger,logError){
    Logger logger = Logger("test");

    logger.logError({"test"});

    std::ifstream logFile(logger.logNameFilePath);

    std::string buffer;
    std::string log;
    while(getline(logFile,buffer)){
        log = log + buffer;
    }

    logFile.close();

    EXPECT_EQ(0,log.compare("[ ERROR   ]: test"));

    std::filesystem::remove_all(".logs");
}

TEST(TEST_Logger, enableTimeLogging){
    Logger logger = Logger("test");

    logger.enableTimeLogging();

    logger.logInfo({"test"});

    auto size = std::filesystem::file_size(logger.logNameFilePath);

    EXPECT_EQ(40,size);

    std::filesystem::remove_all(".logs");
}

TEST(TEST_Logger, enableDebug){
    Logger logger = Logger("test");

    logger.enableDebug();

    logger.logDebug({"test"});

    auto size = std::filesystem::file_size(logger.logNameFilePath);

    EXPECT_EQ(18,size);

    std::filesystem::remove_all(".logs");
}

TEST(TEST_Logger,logDebug){
    Logger logger = Logger("test");
    logger.enableDebug();

    logger.logDebug({"test"});

    std::ifstream logFile(logger.logNameFilePath);

    std::string buffer;
    std::string log;
    while(getline(logFile,buffer)){
        log = log + buffer;
    }

    logFile.close();

    EXPECT_EQ(0,log.compare("[ DEBUG   ]: test"));

    std::filesystem::remove_all(".logs");
}

TEST(TEST_Logger, enableTimeLogging_enableDebug){
    Logger logger = Logger("test");

    logger.enableDebug();
    logger.enableTimeLogging();

    logger.logDebug({"test"});

    auto size = std::filesystem::file_size(logger.logNameFilePath);

    EXPECT_EQ(40,size);

    std::filesystem::remove_all(".logs");
}

TEST(TEST_Logger, logInfo_MultipleArguments){
    Logger logger = Logger("test");

    logger.logInfo({"test","test",std::to_string(1),std::to_string(-1),std::to_string(0.1),"test"});

    std::ifstream logFile(logger.logNameFilePath);

    std::string buffer;
    std::string log;
    while(getline(logFile,buffer)){
        log = log + buffer;
    }

    logFile.close();

    EXPECT_EQ(0,log.compare("[ INFO    ]: test test 1 -1 0.100000 test"));

    std::filesystem::remove_all(".logs");
}

TEST(TEST_Logger, enableTimeLogging_enableDebug_MultipleArguments){
     Logger logger = Logger("test");

    logger.enableDebug();
    logger.enableTimeLogging();

    logger.logDebug({"test","test",std::to_string(1),std::to_string(-1),std::to_string(0.1),"test"});

    auto size = std::filesystem::file_size(logger.logNameFilePath);

    EXPECT_EQ(64,size);

    std::filesystem::remove_all(".logs");
}