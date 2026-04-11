#include <iostream>
int main(){

    int row;
    int column;
    char symbol;

    std::cout << "How many rows \n";
    std::cin >> row;
    std::cout << "How many coloumn \n";
    std::cin >> column;
    std::cout << "What symbol would you like to make your rectangle with \n";
    std::cin >> symbol;

    for(int i=1; i<=row; i++){

        for(int j=1;j <= column; j++){
        std::cout << symbol << ' ';
        }
        std::cout << '\n'; 

    }
    return 0;
}