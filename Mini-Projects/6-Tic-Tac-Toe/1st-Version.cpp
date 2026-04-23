#include <iostream>
#include <ctime>

void board(char *spaces);
void playerMove(char *spaces , char player);
void computerMove(char *spaces , char computer);
bool checkWinner(char *spaces , char player , char computer);
bool checkDraw(char *spaces);

int main(){

    char spaces[9] = {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' };
    char player = 'X';
    char computer = 'O';
    bool running = true;

    board(spaces);

    while(running){
        playerMove(spaces , player);
        board(spaces);

        if(checkWinner(spaces , player , computer)){
            running = false;
            break;
        }

        else if(checkDraw(spaces)){
            running = false;
            break;
        }

        computerMove(spaces , computer);
        board(spaces);

        if(checkWinner(spaces , player , computer)){
            running = false;
            break;
        }

        else if(checkDraw(spaces)){
            running = false;
            break;
        }

    }

    std::cout << "Thanks for playing!\n";

    return 0;
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
    do{
        std::cout << "Enter where would you like to place a marker (1-9): \n";
        std::cin >> num;
        num--; //decrementing by 1 one cuz array starts with 0

        if(spaces[num] == ' '){
            spaces[num] = player;
            break;
        }

    }while(!num > 0 || !num < 8);

}

void computerMove(char *spaces , char computer){

    int num;
    srand(time(0)); //seed for random number generator

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

    std::cout << "IT'S A TIE!\n";

    return true;
}
