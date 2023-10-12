#ifndef _MTRX_READER_H_
#define _MTRX_READER_H_

#include "mtrx.h"

class MNIST_READER{
    public:

        const int Height;
        const int Width;

        MTRX Matrix;
        MNIST_READER(int M, int N);
};

#endif