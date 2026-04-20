#include <iostream>
#include <vector> // for dynamic size of array
#include <algorithm> // for shuffle
#include <random> //for randomness
#include <chrono> // for time measurement

struct Question {
    std::string question;
    std::vector <std::string> options;
    int correctIndex;
};

int main (){

    auto start = std::chrono::high_resolution_clock::now();

    std::vector <Question> quiz = {
        {"What is the color of Pikachu?",
         {"Yellow", "Red", "Green", "Blue"}, 0},

        {"What is the color of Charmander?",
         {"Blue", "Green", "Red", "Black"}, 2},

        {"What is the color of Bulbasaur?",
         {"Purple", "Green", "Yellow", "White"}, 1}};

    // shuffling ques
    
    std::random_device rd;  // randomm_device gets real random seed
    std::mt19937 g(rd());   // mt19937 - high quality random generator
    std::shuffle(quiz.begin(), quiz.end(), g);  
    
    int score = 0;
    int userAnswer;

    for (size_t i=0 ; i < quiz.size() ; i++ ){  //quiz.size() returns size_t (unsigned). This can cause warnings.
        std::cout << "\nQ" << i + 1 << ". " << quiz[i].question << "\n";

        for (int j = 0; j < quiz[i].options.size(); j++) {
            std::cout << j + 1 << ". " << quiz[i].options[j] << "\n";
        }        

        std::cout << "Enter your answer (1-4): ";
        std::cin >> userAnswer;

        if(userAnswer-1 == quiz[i].correctIndex){
            std::cout << "Correct! \n";
            score++;
        }
        else{
            std::cout << "Incorrect! Correct answer: " << quiz[i].options[quiz[i].correctIndex] << "\n";
        }
    }

    auto end = std::chrono::high_resolution_clock::now(); 

    std::chrono::duration<double> elapsed = end - start; 

    std::cout << "\nTime taken to complete quiz: " << elapsed.count() << " seconds\n";

    std::cout << "\nFinal score: " << score << "/" << quiz.size() << "\n";

    return 0;
}