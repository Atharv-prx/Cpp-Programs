#include <iostream>

int reverseHelper(int n, int rev);
int reverseNum(int n);

int main(){
    int num;
    std::cout << "Enter a number to check if it is a palindrome: \n";
    std::cin >> num;

    if (num < 0) {
    std::cout << "Negative numbers are not palindrome.\n";
    return 0;
    }

    if (num == reverseNum(num)) {
        std::cout << num << " is a palindrome." << std::endl;
    } else {
        std::cout << num << " is not a palindrome." << std::endl;
    }

    return 0;
    
}

int reverseHelper(int n, int rev) {
    if (n == 0) return rev;

    int last = n % 10;
    return reverseHelper(n / 10, rev * 10 + last);
}

int reverseNum(int n) {
    return reverseHelper(n, 0);
}