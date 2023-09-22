#include "validbrackets.h"

int main(){
	std::string given; 
	std::cin >> given;
	std::cout << std::boolalpha << validBrackets(given) << std::endl;
	return 0;	
}
