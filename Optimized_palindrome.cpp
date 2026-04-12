#include <iostream>

int ispalindrome(int n){

    if(n < 0 || (n % 10 == 0 && n != 0)) return 0;

    int half=0;

    while (n>half){
        half = half*10 + n%10;
        n = n/10;
    }
    return (n == half || n == half / 10); 
}

int main(){
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    if (ispalindrome(number) == 1) {
        std::cout << "Palindrome\n";
    } else {
        std::cout << "Not a palindrome\n";
    }

    return 0; 
} 