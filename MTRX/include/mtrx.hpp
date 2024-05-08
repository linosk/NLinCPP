#ifndef _MTRX_HPP_ // maybe better name?
#define _MTRX_HPP_

#include <string>
#include <vector>
#include <functional>

#include "logger.hpp"

class MTRX{

private:

    typedef std::vector<int> Vector;
    typedef std::vector<Vector> Matrix;
    struct Dimensions{
        int rows;
        int columns;
    };

    int rows;
    int columns;

    
    Matrix matrix{};
    std::string name;

    Logger logger;

public:


    bool canBeAdded(const Dimensions dimensionsFirst, const Dimensions dimensionsSecond);
    bool canBeDotted(const Dimensions dimensionsFirst, const Dimensions dimensionsSecond);

    Dimensions dimensions;
    //Dimensions dimensions;
    MTRX(int m = 0, int n = 0, std::string id = "");
    void fillMatrix(int val);
    Dimensions getDimensions(void);

    bool addMatrices(const MTRX A, const MTRX B, const std::string id = "");
    bool dotProduct(const MTRX A, const MTRX B, const std::string id = "");

    // /MTRX(&addMatrices);

    //MTRX(MTRX A,MTRX B,std::function<>);

/*
private:

    typedef std::vector<int> Vector;
    typedef std::vector<Vector> Matrix;
    struct Dimensions{
        int rows;
        int columns;
    };

    int rows;
    int columns;
    Dimensions dimensions; 
    Matrix matrix{};

    Logger logger;

    bool canBeAdded(Dimensions dimensionsFirst, Dimensions dimensionsSecond);
    bool canBeDotted(Dimensions dimensionsFirst, Dimensions dimensionsSecond);
    //basically id, necessary for logging purposes
    std::string name;

public:

    MTRX(int m, int n);
    MTRX(int m, int n, std::string name);

    void loopMatrix(void);
    void fillMatrix(int val);
    Dimensions getDimensions(void);
    //void printMatrix(void); ---- ?*/
};

#endif//_MTRX_HPP_