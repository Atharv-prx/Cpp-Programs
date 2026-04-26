#include <iostream>

int main(){

    int lines = 4;

    for (int i=0 ; i<lines ; i++){
        for(int j=0 ; j<(i+1) ; j++){
            std::cout << "* ";
        }
        std::cout << '\n';
    }
    return 0;
}