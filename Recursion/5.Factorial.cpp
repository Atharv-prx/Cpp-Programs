#include <iostream>

int factorial(int n);

int main(){
    int n;
    std::cout << "Enter a number to find its factorial: \n";
    std::cin >> n;

    std::cout << factorial(n);

    return 0;
}

int factorial(int n){
    if (n==0){
        return 1; //base case
    }
    return n*factorial(n-1);
}