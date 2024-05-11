#include "mnistreader.hpp"

MnistReader::MnistReader(mnistReaderType dataType) : mtrx(1,1,"mtrx"), logger("mnistreader"){

}

void MnistReader::setType(mnistReaderType dataType){

    this->type = dataType;

    switch(this->type){
        case 0:{
            this->numberOfImages = trainingSize;
        }
        break;
        case 1:{

        }
        break;
        default:{
            logger.logError({std::to_string(dataType),"is not valid type."});
            break;
        }
    }
 
}
