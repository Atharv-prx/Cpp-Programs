#include <iostream>
int main(){

    int number;
    int last;
    int reverse = 0;

    std::cout << "Tell me a number to reverse it\n";
    std::cin >> number;

    while(number !=0){
        last = number % 10;
        reverse = reverse*10 + last;
        number = number/10;
    }

    std::cout << "The reverse is " << reverse;

    return 0;
}