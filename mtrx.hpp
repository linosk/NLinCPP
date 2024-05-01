#ifndef _MTRX_HPP_ // maybe better name?
#define _MTRX_HPP_

#include <vector>

typedef std::vector<int> Vector;
typedef std::vector<Vector> Matrix;

class MTRX{

public:
    int rows;
    int columns;

    Matrix matrix{};
    
    MTRX(int m, int n);

    void printMatrix(void);
};

#endif//_MTRX_HPP_