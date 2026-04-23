#include <iostream>

void printArray(std::string pokemon[], int size);

int main(){
    
    std::string pokemon[] = {"Pikachu", "Bulbasaur", "Charmander", "Squirtle"};
    int size = sizeof(pokemon) / sizeof(pokemon[0]);
    printArray(pokemon, size);
    return 0;
}

void printArray(std::string pokemon[], int size){
    if(size == 0){
        return; //base case
    }
    std::cout << pokemon[0] << '\n'; //print first element
    printArray(pokemon + 1, size - 1); //recursive call with next element and reduced size
}