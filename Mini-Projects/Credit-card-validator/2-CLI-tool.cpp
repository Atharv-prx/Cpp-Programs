// This program has ---->
//1- input validation 
//2- tells card type
//3- masks card 
//4- menu system
//5- Check for spaces in card number

#include <iostream>
#include <cctype>
#include <limits> // for cin.ignore() and numeric_limits

int getDigit(const int number){
    return number%10 + (number / 10 % 10);
}

int sumOddDigits(const std::string cardnum){

    int sum=0;

    for(int i = cardnum.size()-1 ; i >= 0 ; i -= 2 ){ 
        sum += cardnum[i]-'0'; 
    } 

    return sum;
}

int sumEvenDigits(const std::string cardnum){

    int sum=0;

    for(int i = cardnum.size()-2 ; i >= 0 ; i -= 2 ){ 
        sum += getDigit((cardnum[i]-'0')* 2); 
    } 

    return sum;
}

bool isValidCard(const std::string& cardnum) {
    int result = sumEvenDigits(cardnum) + sumOddDigits(cardnum);
    return (result % 10 == 0);
}

//removing spaces from input 
std::string cleaninput(std::string cardnum){

    std::string cleaned = "";
    for (char c : cardnum) {
        if (isdigit(c)) {
            cleaned += c;
        }
    }
    return cleaned;
}

//Masking Card Number
std::string mask(const std::string& cardnum ){
    
    std::string masked = "";
    int n = cardnum.size();

    for( int i = 0 ; i < n ; i++ ){
        if(i < n-4){
            masked +=  '*';
        }
        else{
            masked += cardnum[i];
        }
        //  spacing every 4 digits
        if ((i + 1) % 4 == 0 && i != n - 1)
            masked += ' ';
    }

    return masked;
}

// Detect card type
std::string cardType(const std::string& cardnum) {

    if(cardnum.empty()) return "Unknown";   // avoid crash

    if (cardnum[0] == '4')
        return "Visa";

    if (cardnum.substr(0, 2) >= "51" && cardnum.substr(0, 2) <= "55")
        return "MasterCard";

    if (cardnum.substr(0, 2) == "34" || cardnum.substr(0, 2) == "37")
        return "American Express";

    if (cardnum.substr(0, 4) == "6011")
        return "Discover";

    return "Unknown";
}

int main(){

    std::string input;

    while(true){
        std::cout << "*******Main menu*******\n";
        std::cout << "1. Validate card\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter choice (1/2)\n";

        int choice;
        std::cin >> choice;

        if(choice == 2) break;

        if(choice == 1){

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            //clear buffer before getline

            std::cout <<"Enter a card number\n";
            std::getline(std::cin, input);

            std::string cardnum = cleaninput (input);

            if(cardnum.empty()){
                std::cout << "Invalid Input!";
                continue;
            }

            bool valid = isValidCard(cardnum);

            std::cout << "Card: " << mask(cardnum) << '\n';
            std::cout << "Card Type: " << cardType(cardnum) << '\n';
            std::cout << "Status: " << (valid ? "Valid!" : "Invalid!") << '\n';

        }
        else {
            std::cout << "Invalid choice\n";
        }
    }
    std::cout << "Exiting";

    return 0; 

}