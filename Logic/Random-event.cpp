#include <iostream>
#include<ctime>
#include <cstdlib>
int main(){

    srand(time(0));
    int randnum = (rand() % 5) + 1;

    switch(randnum){

        case 1: std::cout << "You win sticker\n";
        break;
        case 2: std::cout << "You win tickets\n";
        break;
        case 3: std::cout << "You win free lunch\n";
        break;
        case 4: std::cout << "You win gift card\n";
        break;
        case 5: std::cout << "You win concert ticket\n";
        break;

    }
    return 0;
}