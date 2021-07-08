#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <string>

bool is_number(const std::string& s)
{
    for (char const &c : s) { if (std::isdigit(c) == 0) return false; }
    return true;
}
bool is_roman(const std::string& s)
{
    return !s.empty() && s.find_first_not_of("IVXLCDMivxlcdm") == std::string::npos;
}
int main() {
    bool running = true;
    while(running){
        std::cout << "Please enter a roman numeral or an integer between 1 and 3999 (or enter EXIT to quit): \n";
        std::string input;
        std::getline(std::cin, input);
        if(input.empty() || input == "") {
            // Do nothing and let it repeat.
        } else if(is_number(input)){
            int number = std::stoi(input);
            if (number > 0 && number < 4000) {
                // Convert Number to Roman
                std::string romanOut = "";
                while(number > 0){
                    if (number >= 1000) {
                        romanOut = romanOut + "M";
                        number -= 1000;
                    } else if (number >= 900) {
                        romanOut = romanOut + "CM";
                        number -= 900;
                    } else if (number >= 500) {
                        romanOut = romanOut + "D";
                        number -= 500;
                    } else if (number >= 400) {
                        romanOut = romanOut + "CD";
                        number -= 400;
                    } else if (number >= 100) {
                        romanOut = romanOut + "C";
                        number -= 100;
                    } else if (number >= 90) {
                        romanOut = romanOut + "XC";
                        number -= 90;
                    } else if (number >= 50) {
                        romanOut = romanOut + "L";
                        number -= 50;
                    } else if (number >= 40) {
                        romanOut = romanOut + "XL";
                        number -= 40;
                    } else if (number >= 10) {
                        romanOut = romanOut + "X";
                        number -= 10;
                    } else if (number >= 9) {
                        romanOut = romanOut + "IX";
                        number -= 9;
                    } else if (number >= 5) {
                        romanOut = romanOut + "V";
                        number -= 5;
                    } else if (number >= 4) {
                        romanOut = romanOut + "IV";
                        number -= 4;
                    } else if (number >= 1) {
                        romanOut = romanOut + "I";
                        number -= 1;
                    }
                }
                std::cout << input + " converts to " + romanOut + "\n\n";
                
            } else {
                std::cout << "Number is out of range.\n\n";
            }
        } else if(is_roman(input)){
            // Convert Roman to Number
            std::transform(input.begin(), input.end(), input.begin(), ::toupper);
            int size = input.length();
            int i = 0;
            int intOut = 0;
            input = input + " "; //add an additional character to avoid out of bounds errors.
            while(i < size){
                char letter = input.at(i);
                char next = input.at(i+1);
                if(letter == 'M') {
                    intOut += 1000;
                } else if(letter == 'D') {
                    intOut += 500;
                } else if(letter == 'C') {
                    if(next == 'D'){
                        intOut += 400;
                        i++;
                    } else if (next == 'M') {
                        intOut += 900;
                        i++;
                    } else {
                        intOut += 100;
                    }
                } else if(letter == 'L') {
                    intOut += 50;
                } else if(letter == 'X') {
                    if(next == 'L'){
                        intOut += 40;
                        i++;
                    } else if (next == 'C') {
                        intOut += 90;
                        i++;
                    } else {
                        intOut += 10;
                    }
                } else if(letter == 'V') {
                    intOut += 5;
                } else if(letter == 'I') {
                    if(next == 'V'){
                        intOut += 4;
                        i++;
                    } else if (next == 'X') {
                        intOut += 9;
                        i++;
                    } else {
                        intOut += 1;
                    }
                }
                i++;
            }
            if (intOut > 0 && intOut < 4000) {
                // std::string output = ; 
                std::cout << input + " converts to " + std::to_string(intOut) + "\n\n";
            } else {
                std::cout << "\"" + input + "\" is an Invalid input.\n\n";
            }
        } else if(input == "EXIT") {
            running = false;
        } else {
            std::cout << "\"" + input + "\" is an Invalid input.\n\n";
        }
    }
}