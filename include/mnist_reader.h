#ifndef _MTRX_READER_H_
#define _MTRX_READER_H_

#include "mtrx.h"

#include <string>
#include <stdexcept>

//No split between source and header files :(((
//Check differnces berween c and cpp

//typedef struct MNIST_READER_TYPE {};
enum MNIST_READER_TYPE {
    Training = 0,
    Test
};

const int Training_size = 60000;
const int Test_size = 10000;
const int Pixels_for_image = 768;

//Program exepcts input files to be unzipped and in specific location

const std::string Training_data_location = "../data/train-images.idx3-ubyte";
const std::string Training_label_location = "../data/train-labels.idx1-ubyte";
const std::string Test_data_location = "../data/t10k-images.idx3-ubyte";
const std::string Test_label_location = "../data/t10k-labels.idx1-ubyte";

class MNIST_READER{
    public:

        int Number_of_images;
        MNIST_READER_TYPE Data_set_type;

        const int Height;
        const int Width;

        Vector Label;

        MTRX Matrix;
        MNIST_READER(MNIST_READER_TYPE Type);

        void Set_type(MNIST_READER_TYPE Type);
};

#endif