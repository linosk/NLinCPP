#include <array>

class Matrix{
	public:
		int Rows;
		int Columns;
		//std::array<std::array<int,Matrix::Columns>,Matrix::Rows> Matrix;
		std::array < std::array<int, Matrix::Rows>, 3 > array_name ;
		
};

int main(int argc, char** argv){
	return 0;
}
