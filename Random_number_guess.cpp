#include<iostream>
#include<ctime>
#include<cstdlib>
int main(){

    int guess;
    int num;
    int tries = 0;

    srand(time(0));
    num = (rand() % 100) + 1;

    std::cout << "Welcome to random number guessing game\n";

    do{
        std::cout << "Guess a number between 1-100\n";
        std::cin >> guess;
        tries++;

        if(guess > num){
            std::cout << "Random number is less than your guess\n";
        }
        else if (guess<num){
            std::cout << "Random number is greater than your guess\n";
        }
        else {
            std::cout << "Correct!\n" << "Number of tries you did: " << tries;
        }

    }while(guess != num);

    return 0;
}