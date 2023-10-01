#include "mtrx.h"

int main(int argc, char** argv){

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

	return 0;
}
