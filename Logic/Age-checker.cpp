#include <iostream>

bool checkAge(int age){
    if(age >= 18){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    int age;

    std::cout << "Enter your age\n";
    std::cin >> age;

    if (checkAge(age)){
        std::cout << "You are an adult\n";
    }
    else{
        std::cout << "You are a child\n";
    }
    return 0;
}