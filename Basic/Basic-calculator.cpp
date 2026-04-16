#include <iostream>
int main(){

    char op;
    double a;
    double b;
    double r;

    std::cout << "Hey! this is a calculator\n";
    std::cout << "Enter what operation would you like to do (+,-,/,*)\n";
    std::cin >> op;

    std::cout << "Enter 1st number\n";
    std::cin >> a;
    
    std::cout << "Enter 2nd number\n";
    std::cin >> b;

    switch(op){

        case '+': r = a+b;
        break;
        case '-': r = a-b;
        break;
        case '*': r = a*b;
        break;
        case '/':
        if(b != 0){
            r = a/b;
        }
        else{
            std::cout << "Can't dicide by 0\n";
            return 0;
        }
        break;
     default:std::cout << "Invalid operator\n";
        return 0;
    }
    std::cout << "Answer is: " << r;

    return 0;  
}