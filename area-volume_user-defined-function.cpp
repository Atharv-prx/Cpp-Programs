#include<iostream>

double square(double length);
double cube(double length);

int main(){

    double length;
    int num;

    std::cout << "Welcome to volume/area finder for square\n";

    do{
        std::cout << "Type 1 to find out area\n";
        std::cout << "Type 2 to find out volume\n";
        std::cout << "Type 3 to Exit\n";
        std::cin >> num;

        if(num == 1){

            std::cout << "Enter length of side\n";
            std::cin >> length;

            double area = square(length);
            std::cout << "Area of square is " << area << '\n';
        }
        else if(num == 2){

            std::cout << "Enter length of side\n";
            std::cin >> length;

            double volume = cube(length);
            std::cout << "Volume of cube is " << volume << '\n';
        }
        else if(num == 3){
            std::cout << "Thanks for testing\n";
        }
        else{
            std::cout << "Enter a valid number (1 or 2)\n";
        }
    }while (num != 3);

    return 0;
}

double square(double length){
    return length*length;
}
double cube(double length){
    return length*length*length;
}