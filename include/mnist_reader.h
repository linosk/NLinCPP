#ifndef _MTRX_READER_H_
#define _MTRX_READER_H_

#include "mtrx.h"

class MNIST_READER{
    public:

        int Number_of_images;

        const int Height;
        const int Width;

        std::vector<int> Label;

        MTRX Matrix;
        MNIST_READER(int M, int N);
};

#endif