#include <iostream>

int sum(int n);

int main(){
    int n;
    std::cout << "Enter a number to find the sum of first n numbers: \n";
    std::cin >> n;

    std::cout << sum(n);
    return 0;
}

int sum(int n){
    if(n==0){
        return 0; //base case
    }
    return n + sum(n-1);
}