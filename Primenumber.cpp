#include <iostream>
int main(){

    int a;
    int b = 2;

    std::cout << "Write a integer to check if it is prime or not\n";
    std::cin >> a;

    if(a <= 1){
        std::cout << "Number is not prime\n";
    }
    else{
        while(b<a){
            if(a % b == 0){
            std::cout << a << " is not prime\n";
            return 0;
            }
            b++;
        }
        std::cout << a << " is prime\n";

    }

    return 0;
}