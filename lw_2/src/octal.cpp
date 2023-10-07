#include "../include/octal.h"
#include <math.h>
Octal::Octal() {
    content.push_back(0);
    //decimal = 0;
}
//Octal::Octal(int decimal){ set(decimal);}

Octal::Octal(int number){
    set(number);
}
Octal::~Octal(){content.clear();}
void Octal::print(){
    for(int cycle = 0; cycle < content.size(); cycle++){
        std::cout << content[cycle] << std::endl;
    }
    std::cout << "\n";
}

int Octal::decimalSystemTranslate(Vector content){
    int result = 0;
    int power = 0;
       for (int cycle = content.size() - 1; cycle >= 0; cycle--) {
        result += (content[cycle] - '0') * std::pow(8, power);
        power++;
    }
    return result;
}
 bool Octal::moreOrEquals(Vector content1, Vector content2){
    int fDecimal = decimalSystemTranslate(content1);
    int sDecimal = decimalSystemTranslate(content2);
    if(fDecimal >= sDecimal) return true;
    else return false;
}

void Octal::set(int number){
    //std::string given = number;
    if(number == 0){
        content.push_back(0);
        return;
    }
    while(number > 0){
        int now = number % 8;
        content.push_back(now);
        now /= 8;
    }
    content.reverse();
    content.clear();
    
}


