#include <iostream>

int main(){

    int lines = 4;

    for (int i=0 ; i<lines ; i++){
        for(int j=0 ; j<i ; j++){
            std::cout << " ";
        }
        for(int z=0 ; z<(lines-i) ; z++){
            std::cout << (i+1); 
            }
        std::cout << '\n';
    }
    return 0;
}