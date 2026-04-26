#include <iostream>

int main(){

    int lines = 4;
    int num = 1;

    for (int i=0 ; i<lines ; i++){
        for(int j=0 ; j<(i+1) ; j++){
            std::cout << num << " ";
            num++;
        }
        std::cout << '\n';
    }
    return 0;
}