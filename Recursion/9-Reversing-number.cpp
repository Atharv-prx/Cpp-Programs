#include <iostream>

int reverseHelper(int n, int rev);
int reverseNum(int n);

int main(){
    int num;
    std::cout << "Enter a number to reverse it: \n";
    std::cin >> num;

    std::cout << "Reverse of " << num << " is: " << reverseNum(num);

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