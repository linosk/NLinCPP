#include <vector>
#include <iostream>
#include <stdexcept>

class MTRX{
	public:
		int Rows;
		int Columns;
		std::vector<std::vector<int>> Matrix;

		MTRX(int M, int N) : Rows(M), Columns(N), Matrix(M,std::vector<int>(N,0)){}

		//Not an actual idea how does it work
	 	void Fill(int Number){
			 for(auto& i : Matrix){
				 for(auto& j:i){
					 j = Number;
				 }
			 }
		 }

		void Print_values(){
			for(auto i : Matrix){
				for(auto j : i){
					std::cout<<j;
				}
			std::cout<<std::endl;
			}
		}

		void Print(){
			for(int i=0;i<Rows;i++){
				for(int j=0;j<Columns;j++){
					std::cout<<Matrix[i][j];
				}
				std::cout<<std::endl;
			}
		}

};


//This could be a bad practice, object returning function outside a class definition
MTRX Add(MTRX A, MTRX B){

	if((A.Rows != B.Rows) || (A.Columns != B.Columns)){
		throw std::invalid_argument("Matrices's dimensions did not match.");
	}

	MTRX C(A.Rows,B.Columns);

	for(auto& i : C.Matrix){
		for(auto& j : i){
 // Calculate the corresponding sum from A.Matrix and B.Matrix
			int a = &i - &C.Matrix[0];// Calculate the row index
			int b = &j - &i[0];// Calculate the column index
			j = A.Matrix[a][b] + B.Matrix[a][b];
		}
	}

	return C;
};

int main(int argc, char** argv){

	MTRX M(2,4);

	std::cout<<M.Rows<<std::endl;
	std::cout<<M.Columns<<std::endl;

	M.Print();

	M.Fill(1);

	M.Print_values();

	MTRX A(2,2);
	A.Fill(1);
	MTRX B(2,2);
	B.Fill(2);

	MTRX C = Add(A,B);

	C.Print_values();

	return 0;
}
