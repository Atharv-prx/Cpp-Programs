#include <iostream>

int main(){
    int lines = 5;
    for(int i = 0 ; i<lines ; i++){
        //spaces
        for(int j=0 ; j < (lines-i-1); j++){
            std::cout << " ";
        }
        //nums
        for(int j = 1 ; j <= i+1 ; j++){
            std::cout << j;
        }
        //reverse nums
        for(int z = i ; z >= 1 ; z--){
            std::cout << z;
        }
    std::cout << '\n';
    }
    return 0;
}