#include <iostream>
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions
#include <cctype> // for toupper function
#include <limits> // for numeric_limits


char userchoice(){

    char player;
    do{
        std::cout << "Rock Paper Scissors game\n";
        std::cout << "Choose one of the following\n";
        std::cout << "R for Rock\n";
        std::cout << "S for Scissors\n";
        std::cout << "P for Paper\n";
        std::cin >> player;
        player = toupper(player); // to convert lowercase to uppercase
    }while (player != 'R' && player != 'S' && player != 'P' );
        
    return player;
}

char computerchoice(){

    int num = (rand() % 3) + 1 ; 

    switch(num){
        case 1 : return 'R';
        case 2 : return 'S';
        case 3 : return 'P';
    }
    return 'R'; // to avoid warning but it will never execute

}

void showchoice(char choice){
    switch(choice){
        case 'R' : std::cout << "Rock\n";
        break;
        case 'S' : std::cout << "Scissors\n";
        break;
        case 'P' : std::cout << "Paper\n";
        break;
    }

}

void winner(char player, char computer){
    if(player == computer){
        std::cout << "It's a tie\n";
    }
    else if(
        (player == 'R' && computer == 'S') ||
        (player == 'S' && computer == 'P') ||
        (player == 'P' && computer == 'R')
    ){
        std::cout << "You win this round\n";
    }
    else{
        std::cout << "Computer wins this round\n";
    }

}

int main(){

    srand(time(NULL));

    int choice;

    do{
        std::cout << "\n===== MAIN MENU =====\n";
        std::cout << "Press 1 to Play Game\n";
        std::cout << "Press 2 to View Rules\n";
        std::cout << "Press 3 to Exit\n";
        std::cout << "Enter your choice: ";
        if(!(std::cin >> choice)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nInvalid input. Enter a number.\n";
        continue;
}

        switch(choice){

            case 1: {
                // GAME STARTS HERE
                char player;
                char computer;
                int playerScore = 0;
                int computerScore = 0;

                std::cout << "\n=== First to 3 points wins the game ===\n";

                do{
                    player = userchoice();
                    std::cout << "Your choice is ";
                    showchoice(player);

                    computer = computerchoice();
                    std::cout << "Computer choice is: ";
                    showchoice(computer);

                    winner(player, computer);

                    // score logic
                    if(player != computer){
                        if(
                            (player == 'R' && computer == 'S') ||
                            (player == 'S' && computer == 'P') ||
                            (player == 'P' && computer == 'R')
                        ){
                            playerScore++;
                        }
                        else{
                            computerScore++;
                        }
                    }

                    std::cout << "\nScore -> You: " << playerScore
                              << " | Computer: " << computerScore << "\n";

                    if(playerScore < 3 && computerScore < 3){
                        std::cout << "\nPress any key then enter to continue...";
                        std::cin.ignore();
                        std::cin.get();
                    }

                } while(playerScore < 3 && computerScore < 3);

                // final winner
                if(playerScore == 3){
                    std::cout << "\nYou won the game!\n";
                    std::cout << "\nPress any key then enter to return to menu...";
                    std::cin.ignore();
                    std::cin.get();
                    break;                    
                }
                else{
                    std::cout << "\nComputer won the game!\n";
                    std::cout << "\nPress any key then enter to return to menu...";
                    std::cin.ignore();
                    std::cin.get();
                    break;

                }

                break;
            }

            case 2:
                std::cout << "\n=== RULES ===\n";
                std::cout << "Rock beats Scissors\n";
                std::cout << "Scissors beats Paper\n";
                std::cout << "Paper beats Rock\n";
                std::cout << "First to 3 wins the match\n";

                std::cout << "\nPress any key then enter to return to menu...";
                std::cin.ignore();
                std::cin.get();
                break;

            case 3:
                std::cout << "\nExiting game...\n";
                break;

            default:
                std::cout << "\nInvalid choice. Try again.\n";
        }

    } while(choice != 3);

    std::cout << "Goodbye!\n";

    return 0;
}