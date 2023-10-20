#include "../include/vector.h"
#include <cstddef>
#include <sstream>
#include <string>
Vector::Vector(){
    data = NULL;
    vector_size = 0;
    capacity = 0;
}

Vector::~Vector(){
    delete[] data;
}

Vector::Vector(const Vector& a){
            vector_size = a.vector_size;
            capacity = a.capacity;
            data = NULL;
            if(vector_size != 0){
                data = new unsigned char[vector_size];
            }else data = 0;
            for(int cycle = 0; cycle < vector_size; cycle++){
                data[cycle] = a.data[cycle];
            }
        };
size_t Vector::size() const{
    return vector_size;
}

bool Vector::isEmpty(){
    return vector_size == 0;
}

void Vector::clear(){
    if(data != nullptr) delete[] data;
    data = NULL;
    vector_size = 0;
    capacity = 0;
}

void Vector::resize(int size){
  
    if(size > capacity){
        
        int new_capacity =  std::max(size, int(vector_size * 2));
        unsigned char* new_data = new unsigned char[new_capacity];
       
        for(int cycle = 0; cycle < vector_size;cycle++) new_data[cycle] = data[cycle];
        
        delete[] data;
        data = new_data;
        
        capacity = new_capacity;
        
    }
        vector_size = size;
    
}
void Vector::add(int newElement){
    
    Vector::resize(vector_size + 1);
   
    data[vector_size - 1] = newElement;
    
}

void Vector::reverse(){
    unsigned char* now = new unsigned char[vector_size];
    for(int cycle = 0; cycle < vector_size; cycle++){
       
      
        now[cycle] = data[vector_size - cycle - 1];
    }
    delete[] data;
    data = now;
}

std::string Vector::print() const{
    std::stringstream print_data;
    for(int cycle = 0; cycle < vector_size; cycle++){
        print_data << data[cycle];
    }
    return print_data.str();
}
unsigned char & Vector::operator[](int index){
    return data[index];
}