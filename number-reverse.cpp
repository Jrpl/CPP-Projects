#include <iostream>
#include <string>

using namespace std;

class Numbers {

    // Access specifier
    public:

    // Data members
    int inputNum;
    string inputNumString;
    int outputNum;

    // Trim function
    void trimRight(string str) {
        // find_last_not_of searches our string for any characters that DO NOT match our arguments
        size_t found = str.find_last_not_of('0');
        // look for where found does not equal the greatest value of our size
        if (found!=string::npos) {
            // remove the value
            str.erase(found+1);
        } else {
            // empty the string
            str.clear();
        }
    }

    // Reverse function
    int reverse(int inputNum) {
        // check to see if the input value is negative
        bool isNegative = inputNum < 0;
        // if its negative execute the folowing and return a negative output
        if (isNegative) {
            // convert the negative number to a posotive
            int inputNumPositive = abs(inputNum);
            // convert the input to a string
            inputNumString = to_string(inputNumPositive);
            // trim the string from the end
            trimRight(inputNumString);
            // convert the string back to an integer
            inputNumPositive = stoi(inputNumString);
            outputNum = 0;
            // while loop to keep repeating as long as the input number is still greater than 0
            while(inputNumPositive > 0) {
                // Multiply the output by 10 and add remainder of the input
                outputNum = outputNum*10 + inputNumPositive%10;
                // Divide the input by 10 to remove the last number
                inputNumPositive = inputNumPositive/10;

                /*
                Example:
                
                inputNum = 123;
                outputNum = 0;
                
                outputNum = 0*10 + 123%10; This sets output num to 3
                inputNum = 123/10; This sets output num to 12

                Then you repeat that process until inputNum becomes 0 which breaks the while loop
                */
            }
            // return outputNum as a negative
            return outputNum *= -1;
        } 
        // if its not negative execute the following and return a posotive output
        else {
            // convert the input to a string
            inputNumString = to_string(inputNum);
            // trim the string from the end
            trimRight(inputNumString);
            // convert the string back to an integer
            inputNum = stoi(inputNumString);
            outputNum = 0;
            // while loop to keep repeating as long as the input number is still greater than 0
            while(inputNum > 0) {
                // Multiply the output by 10 and add remainder of the input
                outputNum = outputNum*10 + inputNum%10;
                // Divide the input by 10 to remove the last number
                inputNum = inputNum/10;

                /*
                Example:
                
                inputNum = 123;
                outputNum = 0;
                
                outputNum = 0*10 + 123%10; This sets output num to 3
                inputNum = 123/10; This sets output num to 12

                Then you repeat that process until inputNum becomes 0 which breaks the while loop
                */
            }
            return outputNum;
        }
    }
};

int main() {
    // Declare the class as number
    Numbers number;
    cout << "This program will reverse the numbers you input.\n";
    cout << "Please input any number: ";
    // Access the inputNum data member and set it to whatever the user inputs
    cin >> number.inputNum;
    // Access the reverse function in the Numbers class and reverse the inputNum data member
    number.reverse(number.inputNum);
    // Output the original input
    cout << "Input Number: " << number.inputNum << "\n";
    // Output the reversed number
    cout << "Output Number: " << number.outputNum << "\n";
    return 0;
};