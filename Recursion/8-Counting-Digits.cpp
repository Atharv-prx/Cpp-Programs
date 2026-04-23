#include <iostream>

int countDigits(int n);

int main(){
    int num;
    std::cout << "Enter a number to count its digits: \n";
    std::cin >> num;

    std::cout << "Number of digits in " << num << " is: " << countDigits(num);

    return 0;
}

int countDigits(int n){
    if(n==0){
        return 0; //base case
    }
    return 1 + countDigits(n/10);
}