#include "../include/vector.h"
#include <cctype>
#include <cstddef>
#include <string>

Vector::Vector(): data(NULL), vectorSize(0), capacity(0){}
Vector::~Vector(){ delete[] data;}
Vector::Vector(std::string number){ set(number);}
Vector::Vector(const size_t capacity){
    this -> vectorSize = 0;
    this -> capacity = capacity;
    reserve(capacity);
}
//Vector::Vector(int given){std::string number = std::to_string(given);}  //new
size_t Vector::size() const {return vectorSize;}

bool Vector::isEmpty() const{ return vectorSize == 0;}

int Vector::push_back(unsigned char given){
    if(vectorSize >= capacity) reserve(capacity + 8);
    data[vectorSize++] = given;
    return 1;
}

int Vector::reserve(size_t ncapacity){
    unsigned char* buffer = new unsigned char[capacity];
    for(size_t cycle = 0; cycle < vectorSize; cycle++) buffer[cycle] = data[cycle];
    capacity = ncapacity;
    if(data != nullptr) delete[] data;
    data = buffer;
    return 1;
}

int Vector::reverse(){ 
    unsigned char* buffer = new unsigned char[vectorSize];
    for(size_t cycle = 0; cycle < vectorSize; cycle++) buffer[cycle] = data[vectorSize - 1 - cycle];
    delete[] data;
    data = buffer;
    return 1;
}

int Vector::clear() {
    if(data != nullptr) delete[] data;
    vectorSize = 0;
    capacity = 0;
    data = nullptr;
    return 1;
}

void Vector::set(std::string number){
    for(int cycle = 0; cycle < number.length(); cycle++){
        unsigned char now = number[cycle];
        if(now == ' ') number.erase(number.begin() + 1);
        else break;
    }
    size_t length = number.length();
    vectorSize = 0;
    capacity = length;
    reserve(capacity);
    for(size_t cycle = 0; cycle < length; cycle++){
        unsigned char now = number[cycle];
        push_back(toupper(now));
    }
}

unsigned char Vector::operator[](size_t index){
    if(index >= vectorSize || index < 0) return '\0';
    return data[index];
}