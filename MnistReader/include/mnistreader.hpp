#ifndef _MNISTREADER_HPP_
#define _MNISTREADER_HPP_

#include <string>

#include "logger.hpp"
#include "mtrx.hpp"

class MnistReader{

private:
    static constexpr int trainingSize = 60000;
    static constexpr int testSize = 10000;
    static constexpr int imageSize = 768;

    const std::string trainingDataLocation = "data/train-images.idx3-ubyte";
    const std::string trainingLabelLocation = "data/train-labels.idx1-ubyte";
    const std::string testDataLocation = "data/t10k-images.idx3-ubyte";
    const std::string testLabelLocation = "data/t10k-labels.idx1-ubyte";

    Logger logger;
    MTRX mtrx;

    int numberOfImages;
    int pixelsPerImage;

    enum mnistReaderType{
        Training = 0,
        Test
    };

    void setType(mnistReaderType dataType);

public:

    mnistReaderType type;

    MnistReader(mnistReaderType dataType);

};

#endif//_MNISTREADER_HPP_