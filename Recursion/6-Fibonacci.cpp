#include <iostream>
int fibonacci(int n);

int main(){
    int n;
    std::cout << "Enter a number to find its Fibonacci: \n";
    std::cin >> n;

    std::cout << fibonacci(n);

    return 0;
}

int fibonacci(int n){
    if(n==0){
        return 0; //base case
    }
    if(n==1){
        return 1; //base case
    }
    return fibonacci(n-1) + fibonacci(n-2); //recursive case
}