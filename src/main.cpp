#include "mnist_reader.h"

#include <iostream>

int main(int argc, char** argv){

/*
	MTRX M(2,4);

	std::cout<<M.Rows<<std::endl;
	std::cout<<M.Columns<<std::endl;

	M.Print();

	M.Fill(1);

	M.Print();

	MTRX A(2,2);
	A.Fill(1);
	MTRX B(2,2);
	B.Fill(2);

	MTRX C = Add(A,B);

	C.Print();
*/

	//MTRX A(1,2);
    //A.Fill(1);
	//A.Print();
	//std::cout<<A.Rows<<std::endl;
    //MTRX B(2,2);
    //B.Fill(2);
	//B.Print();
	//std::cout<<B.Columns<<std::endl;
    //MTRX C(1,2);
    //C.Fill(4);
    //MTRX D = Dot_product(A,B);
	//D.Print();
/*
	MTRX A(2,3);
    A.Matrix_proper[0][0] = 0;
    A.Matrix_proper[0][1] = 1;
    A.Matrix_proper[0][2] = 2;
    A.Matrix_proper[1][0] = 3;
    A.Matrix_proper[1][1] = 4;
    A.Matrix_proper[1][2] = 5;

    //A.Transponse();

	MTRX C = Transpose(A);

    MTRX B(3,2);
    B.Matrix_proper[0][0] = 0;
    B.Matrix_proper[0][1] = 3;
    B.Matrix_proper[1][0] = 1;
    B.Matrix_proper[1][1] = 4;
    B.Matrix_proper[2][0] = 2;
    B.Matrix_proper[2][1] = 5;

	C.Print();
	B.Print();

	std::cout<<A.Rows;
	std::cout<<A.Columns;

	std::cout<<B.Rows;
	std::cout<<B.Columns;

	std::cout<<C.Rows;
	std::cout<<C.Columns;
	*/

	MNIST_READER Training_set((MNIST_READER_TYPE)2);
	std::cout<<Training_set.Number_of_images<<std::endl;

	MNIST_READER Test_set(Test);
	std::cout<<Test_set.Number_of_images<<std::endl;


	return 0;
}
