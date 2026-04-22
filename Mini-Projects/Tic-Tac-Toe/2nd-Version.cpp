// Improving check winner function
// Adding a main menu to display rules and chose between playing and exiting the game
// Adding a option to play again without restarting the program
// Adding input validation for menu and player move
// Cleaning up code and organizing it into functions

#include <iostream>
#include <ctime>

void playGame();
int menu();
void showRules();
void board(char *spaces);
void playerMove(char *spaces , char player);
void computerMove(char *spaces , char computer);
bool checkWinner(char *spaces , char player , char computer);
bool checkDraw(char *spaces);

int main(){

    int choice;

    do{
        choice = menu();

        switch(choice){
            case 1:
                playGame();
                break;

            case 2:
                showRules();
                break;

            case 3:
                std::cout << "Exiting game...\n";
                break;

            default:
                std::cout << "Invalid choice!\n";
        }

    }while(choice != 3);

    return 0;
}

void playGame(){

    char again;

        do{
            char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
            char player = 'X';
            char computer = 'O';

            board(spaces);

            while(true){

                playerMove(spaces , player);
                board(spaces);

                if(checkWinner(spaces , player , computer) || checkDraw(spaces)){
                    break;
                }

                computerMove(spaces , computer);
                std::cout << "Computer's move:\n";
                board(spaces);

                if(checkWinner(spaces , player , computer) || checkDraw(spaces)){
                    break;
                }
            }

            std::cout << "Play again? (y/n): ";
            std::cin >> again;

    }while(again == 'y' || again == 'Y');

}

int menu(){
    int choice;

    std::cout << "\n===== TIC TAC TOE =====\n";
    std::cout << "1. Play Game\n";
    std::cout << "2. Rules\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";

    if(!(std::cin >> choice)){  
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    return -1;
    }

    return choice;
}

void showRules(){
    std::cout << "\n===== RULES =====\n";
    std::cout << "1. The game is played on a 3x3 grid.\n";
    std::cout << "2. You are X, computer is O.\n";
    std::cout << "3. Take turns placing marks.\n";
    std::cout << "4. First to get 3 in a row wins.\n";
    std::cout << "5. If all 9 cells are filled, it's a draw.\n\n";
}
                        
void board(char *spaces){ //spaces will be one dimesional array that will keep track of markers on the board
                          //array decays to pointer which will print our board
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
    
} 

void playerMove(char *spaces , char player){

    int num;

    while(true){

        std::cout << "Enter where would you like to place a marker (1-9): \n";

        if(!(std::cin >> num)){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input!\n";
            continue;
        }
        num--; //decrementing by 1 one cuz array starts with 0

        if(num < 0 || num > 8){
            std::cout << "Invalid position!\n";
        }
        else if(spaces[num] != ' '){
            std::cout << "Cell already taken!\n";
        }
        else{
            spaces[num] = player;
            break;
        }

    }

}

void computerMove(char *spaces , char computer){

    int num;

    while(true){
        num = rand() % 9; //generating random number between 0 and 8
        if(spaces[num] == ' '){
            spaces[num] = computer;
            break;
        }
    }

}

bool checkWinner(char *spaces , char player , char computer){
    
    //Checking rows for winner

    if(spaces[0] == spaces[1] && spaces[1] == spaces[2] && spaces[0] != ' '){

        spaces[0] == player ? std::cout << "You won!\n" : std::cout << "Computer won!\n";
        return true;
    }

    else if(spaces[3] == spaces[4] && spaces[4] == spaces[5] && spaces[3] != ' '){

        spaces[3] == player ? std::cout << "You won!\n" : std::cout << "Computer won!\n";
        return true;
    }

    else if(spaces[6] == spaces[7] && spaces[7] == spaces[8] && spaces[6] != ' '){

        spaces[6] == player ? std::cout << "You won!\n" : std::cout << "Computer won!\n";
        return true;
    }

    //Checking columns for winner

    else if(spaces[0] == spaces[3] && spaces[3] == spaces[6] && spaces[0] != ' '){

        spaces[0] == player ? std::cout << "You won!\n" : std::cout << "Computer won!\n";
        return true;
    }

    else if(spaces[1] == spaces[4] && spaces[4] == spaces[7] && spaces[1] != ' '){

        spaces[1] == player ? std::cout << "You won!\n" : std::cout << "Computer won!\n";
        return true;
    }

    else if(spaces[2] == spaces[5] && spaces[5] == spaces[8] && spaces[2] != ' '){

        spaces[2] == player ? std::cout << "You won!\n" : std::cout << "Computer won!\n";
        return true;
    }

    //Checking diagonals for winner

    else if(spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[0] != ' '){

        spaces[0] == player ? std::cout << "You won!\n" : std::cout << "Computer won!\n";
        return true;
    }

    else if(spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[2] != ' '){

        spaces[2] == player ? std::cout << "You won!\n" : std::cout << "Computer won!\n";
        return true;
    }

    return false;
}

bool checkDraw(char *spaces){

    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
        return false;
        }
    }

    std::cout << "It's a Draw!\n";

    return true;
}
