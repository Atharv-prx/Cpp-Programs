#include <iostream>
int main(){

    int line=4;
    int n=1;

    for(int i=0 ; i < line ; i++){
        for(int j=0 ; j <line ; j++){
            std::cout << n << " ";
            n++;
        }
        std::cout << '\n';
    }
    return 0;
}