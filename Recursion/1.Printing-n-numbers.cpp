#include <iostream>
void print(int times , int n);

int main(){
    int n;
    int times;

    std::cout << "Enter a number: \n";
    std::cin >> n;
    std::cout << "How many times would you want that number to be printed: \n";
    std::cin >> times;

    print(times,n);

}
void print (int times, int n){
    if(times > 0){
        std::cout << n << '\n';
        print(times-1, n);
    }
}