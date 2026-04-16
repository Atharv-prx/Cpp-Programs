//rand generated pseudo random number (but close)

#include <iostream>
#include<ctime>
#include <cstdlib>
int main(){

    srand(time(NULL));

    int num = (rand() % 5) + 1 ; 

    std::cout << num;

    return 0;
}