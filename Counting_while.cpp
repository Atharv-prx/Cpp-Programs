#include <iostream>
int main(){

    int number;
    int count = 0;

    std::cout << "Tell me a number to count how many digits are in it\n";
    std::cin >> number;

    if(number == 0){
        count = 1;
    }

    else{
        while(number !=0){
        number = number/10;
        count++;
    }
    }
    std::cout << "The count is " << count;

    return 0;
}