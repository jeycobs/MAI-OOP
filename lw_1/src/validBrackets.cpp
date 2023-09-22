#include "../include/validbrackets.h"

bool validBrackets(std::string given){
    int counter = 0;
    for(int cycle = 0; cycle < given.size(); cycle++){
        if(given[cycle] == '(') counter++;
        else counter --;
        if (counter < 0) return false;
    }
    return (counter == 0);
}
