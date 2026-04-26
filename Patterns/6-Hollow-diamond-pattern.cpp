#include <iostream>

int main(){

    int lines = 4;

    for(int i=0 ; i < lines ; i++){
        //Spaces
        for(int j=0 ; j<(lines-i-1) ; j++){
            std::cout << " ";
        }
        std::cout << "*";

        if(i != 0){
            //Spaces
            for(int j=0 ; j<(2*i-1) ; j++){
                std::cout << " ";
            }
            std::cout << "*";
        }
        std::cout << '\n';

    }
    for(int i=0 ; i <(lines-1) ; i++){
        //Spaces
        for(int j=0 ; j<i+1 ; j++){
            std::cout << " ";
        }
        std::cout << "*";

        if(i != lines-2){
            //Spaces
            for(int j=0 ; j < 2*(lines-i)-5 ; j++){
                std::cout << " ";
            }
            std::cout << "*";
        }
        std::cout << '\n';
    }
    return 0;
}