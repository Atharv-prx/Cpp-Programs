#include <iostream>
#include <cctype> // for tolower
int main (){

    std::string questions[] = {"1. What is the colour of pikachu?;",
                               "2. What is the colour of charmander?",
                               "3. What is the colour of bulbasaur?"};

    std::string options [][4] = {{"a. Yellow", "b. Red", "c. Green", "d. Blue"},
                                {"a. Yellow", "b. Red", "c. Green", "d. Blue"},
                                {"a. Yellow", "b. Red", "c. Green", "d. Blue"}};

    char answerKey[] = {'a', 'b', 'c'};
    char answer;
    int score = 0;
    int size = sizeof(questions) / sizeof(questions[0]);

    for(int i=0 ; i < size ; i++){
        std::cout << questions[i] << '\n';

        for(int j=0 ; j < sizeof(options[i]) / sizeof(options[i][0]) ; j++){
            std::cout << options[i][j] << '\n';
        }
        do{
            std::cout << "Enter your answer (a/b/c/d): \n";
            std::cin >> answer;
            answer = tolower(answer); // to convert uppercase input to lowercase
        } while( answer < 'a' || answer > 'd');

        if(answer == answerKey[i]){
            std::cout << "Correct answer!\n";
            score++;
        }
        else{
            std::cout << "Wrong answer! The correct answer is: " << answerKey[i] << '\n';
        }
    }

    std::cout << "Your score is: " << score << "/" << size << std::endl;

    return 0;
}