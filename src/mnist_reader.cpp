#include "mnist_reader.h"

/*
enum MNIST_READER_TYPE {
    Training = 0,
    Test
};

const int Training_size = 60000;
const int Test_size = 10000;
const int Pixels_for_image = 768;

//Program exepcts input files to be unzipped and in specific location

const std::string Training_data_location = "../data/train-images.idx3-ubyte";
const std::string Training_label_location = "../data/train-labels.idx1-ubyte";
const std::string Test_data_location = "../data/t10k-images.idx3-ubyte";
const std::string Test_label_location = "../data/t10k-labels.idx1-ubyte";

MNIST_READER::MNIST_READER(MNIST_READER_TYPE Type) :  
Label(1),
Matrix(1,1),
Height(28), 
Width(28),
Data_set_type(Type){

    Set_type(Type);

}

void MNIST_READER::Set_type(MNIST_READER_TYPE Type){
    
    switch(Type){
        case 0:{

            Number_of_images = Training_size;
            Label.resize(Training_size,0);

            break;
        }
        case 1:{

            Data_set_type = Type;
            Number_of_images = Training_size;
            Label.resize(Training_size,0);

            break;
        }
        default:{
            		
            throw std::invalid_argument("Choose other dataset type.");

            break;
        }
    }

}
*/