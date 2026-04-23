#include <iostream>

int findMax(int arr[], int size);

int main(){
    
    int Num[] = {5, 10, 3, 8, 2};
    int size = sizeof(Num) / sizeof(Num[0]);

    int max = findMax(Num, size);

    std::cout << "Maximum element: " << max << '\n';
    return 0;
}

int findMax(int arr[], int size){
    // Base case
    if(size == 1){
        return arr[0];
    }

    // Recursive call: max of remaining elements
    int maxOfRest = findMax(arr + 1, size - 1);

    // Compare current element with max of rest
    return (arr[0] > maxOfRest) ? arr[0] : maxOfRest;
}