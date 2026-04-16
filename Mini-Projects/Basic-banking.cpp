#include<iostream>
#include<iomanip>

void showbalance(double balance);
double deposit();
double withdraw(double balance);

int main(){

    double balance=0;
    int choice=0;
    
    do{
        std::cout << "Enter what would you like to do\n";
        std::cout << "Press 1 - To deposit money\n";
        std::cout << "Press 2 - To withdraw money\n";
        std::cout << "Press 3 - To show balance\n";
        std::cout << "Press 4 - Exit\n";

        std::cin >> choice;

        if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        choice = 0;
        }


        switch(choice){

            case 1: balance = balance + deposit();
            showbalance(balance);
            break;

            case 2: balance = balance - withdraw(balance);
            showbalance(balance);
            break;

            case 3: showbalance(balance);
            break;

            case 4: std::cout << "Thanks for visiting\n";
            break;

            default: std::cout << "Invalid choice \n";

        }
    } while (choice != 4);

    return 0;
}

void showbalance(double balance){
    std::cout << "Your balance is " << std::fixed << std::setprecision(2) << balance << '\n';
}
double deposit(){
    double amount=0;

    std::cout << "Enter amount to deposit\n";
    std::cin >> amount;

    if(amount > 0){
    return amount;
    }
    else {
        std::cout <<"That's not a valid amount\n";
        return 0;
    }
}
double withdraw(double balance){
    double amount;
    std::cout << "Enter amount to withdraw\n";
    std::cin >> amount;

    if (amount > balance){
        std::cout << "Insufficient balance\n";
        return 0;
    }
    else if(amount<0){
        std::cout << "That's not a valid amount\n";
        return 0;
    }
    else {
        return amount;
    }
}