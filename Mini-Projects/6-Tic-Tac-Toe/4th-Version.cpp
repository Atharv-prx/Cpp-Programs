//Adding level difficulty 
//Using Minmax Algorithm for computer move

#include <iostream>
#include <ctime>

void playGame();
int menu();
void showRules();
void board(char *spaces);
void playerMove(char *spaces , char player);
void easyMove(char *spaces , char computer);
void mediumMove(char *spaces , char computer);
void hardMove(char *spaces , char computer);
bool checkWinner(char *spaces , char player , char computer);
bool checkDraw(char *spaces);
bool isWinner(char *spaces, char symbol);
int chooseDifficulty();

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

    int difficulty = chooseDifficulty();

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

                if(difficulty == 1){
                    easyMove(spaces , computer);
                }
                else if(difficulty == 2){
                    mediumMove(spaces , computer);
                }
                else{
                    hardMove(spaces , computer);
                }

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

void easyMove(char *spaces , char computer){
    
    int num;

    while(true){
        num = rand() % 9; //generating random number between 0 and 8
        if(spaces[num] == ' '){
            spaces[num] = computer;
            break;
        }
    }
}

void mediumMove(char *spaces , char computer){

    char player = 'X';

    // 1. Try to WIN
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            spaces[i] = computer;

            if(isWinner(spaces, computer)){
                std::cout << "Computer plays (winning move)\n";
                return;
            }

            spaces[i] = ' ';
        }
    }

    // 2. BLOCK player
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            spaces[i] = player;

            if(isWinner(spaces, player)){
                spaces[i] = computer;
                std::cout << "Computer blocks your move\n";
                return;
            }

            spaces[i] = ' ';
        }
    }

    // 3. RANDOM
    int num;
    while(true){
        num = rand() % 9;

        if(spaces[num] == ' '){
            spaces[num] = computer;
            std::cout << "Computer plays randomly\n";
            break;
        }
    }
}

int minimax(char *spaces, bool isMaximizing){

    char player = 'X';
    char computer = 'O';

    // Base cases
    if(isWinner(spaces, computer)) return 10;  //Stop recusrion when computer wins-good
    if(isWinner(spaces, player)) return -10;   //Stop recursion when player wins-bad

    // Draw case - no more moves left
    bool movesLeft = false;
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            movesLeft = true;
            break;
        }
    }
    if(!movesLeft) return 0;

    if(isMaximizing){  //Recursive part - AI tries to maximize score
        int bestScore = -1000;

        for(int i = 0; i < 9; i++){ //Try all moves
            if(spaces[i] == ' '){
                spaces[i] = computer;

                int score = minimax(spaces, false); //After AI turn, player turn

                spaces[i] = ' '; // undo move

                if(score > bestScore){ //Maximizing score for computer
                    bestScore = score;
                }
            }
        }
        return bestScore;
    }
    else{ //Player's turn, minimizing score for computer
        int bestScore = 1000;

        for(int i = 0; i < 9; i++){
            if(spaces[i] == ' '){
                spaces[i] = player;

                int score = minimax(spaces, true); //After player turn, AI turn again

                spaces[i] = ' '; // undo move

                if(score < bestScore){ //Minimizing score for computer
                    bestScore = score;
                }
            }
        }
        return bestScore;
    }
}

int findBestMove(char *spaces){

    int bestScore = -1000;
    int bestMove = -1;

    for(int i = 0; i < 9; i++){  // Only checks empty spaces for best move
        if(spaces[i] == ' '){
            spaces[i] = 'O';

            int score = minimax(spaces, false); // Computer is maximizing player, so we call minimax with false to evaluate opponent's response

            spaces[i] = ' '; // undo, without this board gets permanently changed

            if(score > bestScore){ //Picking best move for computer
                bestScore = score;
                bestMove = i;
            }
        }
    }

    return bestMove;
}

void hardMove(char *spaces , char computer){
    int bestMove = findBestMove(spaces);

    if(bestMove != -1){
        spaces[bestMove] = computer;
        std::cout << "Computer plays optimal move\n";
    }
}

bool checkWinner(char *spaces , char player , char computer){
    
    if(isWinner(spaces, player)){
        std::cout << "You won!\n";
        return true;
    }

    if(isWinner(spaces, computer)){
        std::cout << "Computer won!\n";
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

bool isWinner(char *spaces, char symbol){

    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for(auto &combo : wins){
        if(spaces[combo[0]] == symbol &&
           spaces[combo[1]] == symbol &&
           spaces[combo[2]] == symbol){
            return true;
        }
    }

    return false;
}

int chooseDifficulty(){
    int choice;

    std::cout << "\nChoose Difficulty Level:\n";
    std::cout << "1. Easy\n";
    std::cout << "2. Medium\n";
    std::cout << "3. Hard\n";
    std::cout << "Enter your choice: ";

    if(!(std::cin >> choice)){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return -1;
    }

    return choice;    
}
