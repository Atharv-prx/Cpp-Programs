#include <iostream>
int main(){

    double temp;
    char op;

    std::cout << "What conversion would you like to do\n";
    std::cout << "Type F to convert celsius into fahrenheit\n";
    std::cout << "Type C to convert fahrenheit into celsius\n";
    std::cin >> op;
    std::cout << "Enter Temperature\n";
    std::cin >> temp;

    if(op == 'F' || op == 'f') {
        temp = (temp*1.8) + 32;
        std::cout << "Temperature is " << temp << " degree fahrenheit.\n";
        }
    else if(op == 'C' || op == 'c') {
        temp = (temp-32) / 1.8;
        std::cout << "Temperature is " << temp << " degree celsius.\n";
        }
    else {
        std::cout << "Please enter F or C\n";
    }
        return 0;
    }
    /* (needs <iomanip> header file) 
    
    std::fixed = forces numbers to show in a fixed format
    std::setprecision(n) = forces to show only n number of digits after decimal

    if (op != 'F' && op != 'f' && op != 'C' && op != 'c') {
        std::cout << "Invalid choice! Please enter F or C.\n";
        return 1;
    }

    std::cout << "Enter temperature:\n";
    std::cin >> temp;

    if (std::cin.fail()) {
        std::cout << "Invalid input! Please enter a numeric value.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(2);

    if (op == 'F' || op == 'f') {
        temp = (temp * 1.8) + 32;
        std::cout << "Temperature is " << temp << " °F\n";
    }
    else {
        temp = (temp - 32) / 1.8;
        std::cout << "Temperature is " << temp << " °C\n";
    }

    */