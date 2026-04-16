#include <iostream>
int main(){

    int number;
    int sum=0;
    int last;

    std::cout << "Write a number to find sum of their digits and also to find wheather the sum is even or odd\n";
    std::cin >> number;

    while (number !=0){
        last = number % 10;
        sum = sum + last;
        number = number/10;
    }

    std::cout << "Sum of your number is " << sum << " and";

    if (sum % 2 == 0){
        std::cout << " it is even.\n";
    }
    else{
        std::cout << " it is odd.\n";
    }

    return 0;
}