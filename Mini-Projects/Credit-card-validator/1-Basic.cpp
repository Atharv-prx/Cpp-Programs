/* *********Luhn Algorithm*********

Step -1: Double every second digit from right to left (if doubled number is 2 digit then split them and add them)
Step -2: Add all digits from step - 1 
Step -3: Add all odd numbered digits from right to left in credit card  (1st, 3rd, 5th etc)
Step -4: Sum results from step - 2 and step - 3
Step -5: If step-4 is divisible by 10 then the card number is valid otherwise it's invalid

*/

#include <iostream>

int getDigit(const int number){

    return number%10 + (number / 10 % 10);
}

int sumOddDigits(const std::string cardNumber){

    int sum=0;

    for(int i = cardNumber.size()-1 ; i >= 0 ; i -= 2 ){ 
        sum = sum + cardNumber[i]-'0'; 
    } 

    return sum;
}
int sumEvenDigits(const std::string cardNumber){

    int sum=0;

    //arrays start with 0 however if we are summing even digits from right then we need 2nd last digit

    for(int i = cardNumber.size()-2 ; i >= 0 ; i -= 2 ){ 
        sum = sum + getDigit((cardNumber[i]-'0')* 2); 
    } 

    return sum;
}

int main(){

    std::string cardNumber;
    std::cout << "Enter your credit card number to check whether it's valid: \n";
    std::cin >> cardNumber;

    int result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if(result % 10 == 0){
        std::cout << "Card number is valid!\n";
    }
    else{
        std::cout << "Card number is invalid!\n";
    }

}