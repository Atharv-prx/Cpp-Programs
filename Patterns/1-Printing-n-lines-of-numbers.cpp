#include <iostream>
int main(){

    int line;
    int num;

    std::cout << "Enter how many lines would you like to print: ";
    std::cin >> line;

    std::cout << "Enter till how many number would you like to print: ";
    std::cin >> num;

    for(int i=0 ; i <= line ; i++){
        for(int j=0 ; j <=num ; j++){
            std::cout << j;
        }
        std::cout << '\n';
    }
    return 0;
}