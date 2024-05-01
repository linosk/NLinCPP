#ifndef _MTRX_HPP_ // maybe better name?
#define _MTRX_HPP_

#include <vector>

#include "logger.hpp"

class MTRX{

private:
    typedef std::vector<int> Vector;
    typedef std::vector<Vector> Matrix;

    int rows;
    int columns;
    Matrix matrix{};

    Logger logger;

public:
    
    MTRX(int m, int n);

    void fillMatrix(int val);
    void printMatrix(void);
};

#endif//_MTRX_HPP_