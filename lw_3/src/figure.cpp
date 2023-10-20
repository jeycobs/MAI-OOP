#include "../include/figure.h"
#include <istream>
#include <iterator>

Figure::Figure(){
    massive.add(NULL);
}

Figure::~Figure(){
    massive.clear();
}



std::ostream& Figure::operator <<(int top){
    try{
        std::cout << "x1: " << massive[top * 2 - 2] << " y1: " << massive[top * 2 - 1] << std::endl;
    }catch(const std::invalid_argument &error){
        std::cout << "Not found top " << error.what() << std::endl;
    }
}

std::istream& Figure::operator >>(int index){
    massive.add(index);
}

Figure::operator double(){

}