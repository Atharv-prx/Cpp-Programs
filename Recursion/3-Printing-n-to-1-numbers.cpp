#include<iostream>

void print(int n);
int main(){
    print(10);
}

void print (int n){
    if(n>0){
        std::cout << n << ' ';
        print(n-1);
    }
}