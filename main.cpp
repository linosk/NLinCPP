//#include "mtrx.hpp"
#include "logger.hpp"

int main(void){

    //MTRX matrix(2,3);

    Logger logger("a.log");
    logger.logText("first text");
    logger.logText("second text");

    return 0;
}