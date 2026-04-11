#include <iostream>
int main(){

    int number;
    int last;
    int reverse = 0;

    std::cout << "Tell me a number to check whether it is a palindrome\n";
    std::cin >> number;

    int original = number;

    while(number !=0){
        last = number % 10;
        reverse = reverse*10 + last;
        number = number/10;
    }
    if(reverse == original){
        std::cout << "Your number was a palindrome! \n";
    }
    else{
        std::cout << "Your number was NOT a palindrome.\n";
    }

    return 0;
}