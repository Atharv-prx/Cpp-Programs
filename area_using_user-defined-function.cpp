#include<iostream>

double square(double length);

int main(){

    double length;

    std::cout << "Write length of square to find out it's area\n";
    std::cin >> length;

    double area = square(length);
    std::cout << "Area of aquare is " << area;

    return 0;
}

double square(double length){
    return length*length;
}