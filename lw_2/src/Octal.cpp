#include "../include/Octal.hpp"
#include <initializer_list>
#include <memory>
#include <exception>
#include <ostream>
Octal::Octal(){
    data = new unsigned char[sizeof(unsigned char)];
}
Octal::~Octal(){
    delete[] data;
}
Octal::Octal(const Octal &given){
    size = given.size;
    unsigned char *newData = new unsigned char[size * sizeof(unsigned char)];
    try{
        std::uninitialized_copy(given.data,given.data + given.size,newData);
    } catch(const std::exception &error){
        delete[] newData;
        throw;
    }
    data = newData;
}

void Octal::setting_the_size() {
    int rb = size;
    for (int cycle = size; cycle > 0; cycle--) {
        if (data[cycle - 1] != '0') {
            rb = cycle;
            break;
        }
        rb = cycle;
    }

    if (rb == 0) {
        delete[] data;
        data = new unsigned char[1];
        size = 1;
        return;
    }

    auto *tempData = new unsigned char[rb];
    for (int cycle{0}; cycle < rb; cycle++) //334324
        tempData[cycle] = data[cycle];

    delete[] data;
    data = tempData;
    size = rb;
}
    

Octal::Octal(const std::initializer_list<unsigned char> &given){
    data = new unsigned char[given.size()];
    size_t s = 0;
    for(unsigned char cycle : given){    //*
        if(cycle - '0' >= 8){
            delete[] data;
            throw;  //логическая ошибка
        }
        data[s] = cycle;
        s++;
    }
    size = given.size();
    setting_the_size();
}

bool Octal::operator==(const Octal &ex){
    if(size != ex.size) return false;
    for(int cycle = 0; cycle < size; cycle++){
        if(data[cycle] != ex.data[cycle]) return false;
    }
    return true;
}

bool Octal::operator!=(const Octal &ex){
    return !(*this == ex);
}

Octal &Octal::operator=(const Octal &given){
    if(this == &given){
        return *this;
    }

    data = new unsigned char[size];
    for(int cycle = 0; cycle < size; cycle++){
        data[cycle] = given.data[cycle];
    }
    return *this;
}

Octal::Octal(Octal &&given) noexcept{
    data = given.data;
    size = given.size;
    given.data = nullptr;
    given.size = 0;
    setting_the_size();
}

Octal::Octal(const std::string &ex){
  
    data = new unsigned char[ex.size()];
    int p = 0;
    for(int cycle = ex.size(); cycle > 0; cycle--){
        if(ex[cycle - 1] - '0' >= 8){
            delete[] data;
            throw;
        }
        data[p] = static_cast<unsigned char>(ex[cycle - 1]);
        p++;
    }
    size = ex.size();
    setting_the_size();
}

std::ostream &operator<<(std::ostream &out, const Octal &ex){
    for(int cycle = ex.size;cycle > 0; cycle--){
        out << ex.data[cycle - 1];
    }
    return out;

}

bool Octal::operator>(const Octal &given) const{
    if(size > given.size) return true;
    if(size < given.size) return false; // ***
    for(int cycle = size; cycle > 0; cycle--){
        if(data[cycle - 1] > given.data[cycle - 1]) return true;
        if(data[cycle - 1] < given.data[cycle - 1]) return false;
    }
    return false;
}

bool Octal::operator<(const Octal &given) const {
    if (size > given.size) return false;
    if (size < given.size) return true;

    for (int cycle = size; cycle > 0; cycle--) {
        if (data[cycle - 1] > given.data[cycle - 1]) return false;
        if (data[cycle - 1] < given.data[cycle - 1]) return true;
    }

    return false;
}

Octal Octal::operator+(const Octal &given) const {
    
    Octal temp(*this);
    temp += given;
    return temp;
}

Octal Octal::operator-(const Octal &given) const{
    Octal temp(*this);
    temp -= given;
    return temp;
}

Octal &Octal::operator+=(const Octal &given) {  //!!!!
    size_t maxSize = std::max(size, given.size);
    auto *tempData = new unsigned char[maxSize + 1];
    tempData[maxSize] = '0';
    int64_t now = 0;

    for (int cycle = 0; cycle < maxSize; cycle++) {
        if (cycle < size) {
            now += data[cycle] - '0';
        }
        if (cycle < given.size) {
            now += given.data[cycle] - '0';
        }
        tempData[cycle] = (now % 8) + '0';
        now /= 8;
    }
    if (now != 0) {
        tempData[maxSize] = now + '0';
    }

    delete[] data;
    size = maxSize + 1;
    data = tempData;
    setting_the_size();
    return *this;
}

Octal &Octal::operator-=(const Octal &given) {
    if (*this < given) throw;
    int g = 0;
    for (int cycle = 0; cycle < given.size; cycle++) {
        int now = data[cycle] - given.data[cycle] - g;
        if (now < 0) {
            now = (8 + now) % 8;
            g = 1;
        } else {
            g = 0;
        }
        data[cycle] = now + '0';
    }
    for (int cycle = given.size; cycle < size;cycle++) {
        int now = data[cycle] - g - '0';
        if (now < 0) {
            now = (8 + now) % 8;
            g = 1;
        } else {
            g = 0;
        }
        data[cycle] = now + '0';
    }

    if (g > 0)
        throw ;

    setting_the_size();
    return *this;
}
