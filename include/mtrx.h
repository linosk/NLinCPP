#ifndef _MTRX_H_
#define _MTRX_H_

#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <filesystem>
#include <fstream>

//Not sure if i like this (no split between .h and .cpp file)
typedef struct Dimensions{
    int Number_rows;
    int Number_columns;
} Dimensions;

typedef std::vector<char> Vector_char;
typedef std::vector<int> Vector_int;
typedef std::vector<float> Vector_float;
typedef std::vector<double> Vector_double;

typedef std::vector<Vector_double> Matrix;

//A bit of a mess cause by default the matrix's value are double
class MTRX{
    public:
            //Number of rows
        	int Rows;
            // Number of columns
		    int Columns;
            //Actual matrix
		    Matrix Matrix_proper;

		    MTRX(int M, int N);

            //Prints all matix's elements
            void Print();            

            //Fill matrix with specified number
	 	    void Fill(int Number);

            Dimensions Get_size();

            void Resize(int New_rows, int New_columns);

            int Read_from_file(std::string Path);

            int From_char_to_double(std::ifstream &File);

};

//Compares matrices, if any pair of elements do not match false is returned
bool Compare(MTRX A, MTRX B);

//This could be a bad practice, object returning function outside a class definition

//MAYBE JUST PASS MATRIX_PROPER
//Creates a matrix that is a sum of other two matrices
MTRX Add(MTRX A, MTRX B);
MTRX Dot_product(MTRX A, MTRX B);

//Compare with method of MTRX
MTRX Transpose(MTRX A);

#endif