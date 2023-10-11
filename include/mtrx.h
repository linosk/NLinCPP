#ifndef _MTRX_H_
#define _MTRX_H_

#include <vector>
#include <iostream>
#include <stdexcept>

class MTRX{
    public:
            //Number of rows
        	int Rows;
            // Number of columns
		    int Columns;
            //Actual matrix
		    std::vector<std::vector<int>> Matrix;

		    MTRX(int M, int N);

            //Prints all matix's elements
            void Print();            

            //Fill matrix with specified number
	 	    void Fill(int Number);

};

//Compares matrices, if any pair of elements do not match false is returned
bool Compare(MTRX A, MTRX B);

//This could be a bad practice, object returning function outside a class definition

//Creates a matrix that is a sum of other two matrices
MTRX Add(MTRX A, MTRX B);
MTRX Dot_product(MTRX A, MTRX B);

//Compare with method of MTRX
MTRX Transpose(MTRX A);

#endif