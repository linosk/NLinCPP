#include <vector>

class Matrix{
	public:
		int Rows;
		int Columns;

		std::vector<std::vector<int>> MAT;

		Matrix(int Rows, int Columns) : MAT(Rows, std::vector<int>(Columns)){

		}

};

int main(int argc, char** argv){

	Matrix(3,3);

	return 0;
}
