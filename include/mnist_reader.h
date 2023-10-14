#ifndef _MTRX_READER_H_
#define _MTRX_READER_H_

#include "mtrx.h"

#include <string>
#include <stdexcept>

//typedef struct MNIST_READER_TYPE {};
enum MNIST_READER_TYPE {};

int Training_size;
int Test_size;
int Pixels_for_image;

std::string Training_data_location;
std::string Training_label_location;
std::string Test_data_location;
std::string Test_label_location;

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