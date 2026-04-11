#include <iostream>
#include <cmath>

int main() {

    double x;
    double y;
    double z;

std::cout << "Hey! This is a hypotenus calculator\n";
std::cout << "Can you enter the length of the perpendicular\n";
std::cin >> x;

std::cout << "Can you also enter the length of base\n";
std::cin>> y;

z = sqrt(x*x + y*y);

std::cout<< "The Hypotenus of the triangle is " << z ;

    return 0;
}