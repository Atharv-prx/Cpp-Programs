#include <iostream>

int findMin(int arr[], int size);

int main(){
    
    int Num[] = {5, 10, 3, 8, 2};
    int size = sizeof(Num) / sizeof(Num[0]);

    int min = findMin(Num, size);

    std::cout << "Minimum element: " << min << '\n';
    return 0;
}

int findMin(int arr[], int size){
    // Base case
    if(size == 1){
        return arr[0];
    }

    // Recursive call: min of remaining elements
    int minOfRest = findMin(arr + 1, size - 1);

    // Compare current element with min of rest
    return (arr[0] < minOfRest) ? arr[0] : minOfRest;
}