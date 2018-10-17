#include <iostream>
#include <vector>
using namespace std;
vector<int> primeNumbers;

void prompt() {
        int user_input, x;
        std::cout << "This program will check for prime numbers\n";
        std::cout << "Please enter an integer upper bound: ";
        std::cin >> user_input;
        for (int i = 2; i < user_input; i++){ // i starts at 2 because the numbers 1 and 2 are by default prime numbers.
        x = 0; // a variable to check if a number is prime. If it gets set to 1 the number is not prime.
        for (int j = 2; j < i; j++){ // this loop divides the number by 2 up to itself and if the remainder is 0 sets x = 1.
            if (i%j == 0){
                x = 1;
                break;
            }
        }
        if (x == 0){ // if the x = 1 flag is never set the number is prime.
            std::cout << user_input << " is prime!\n";
            break;
        }
    }
}

int main() {
    int x;
    // this for loop goes through each number up to the user input upper boundary
    for (int i = 2; i < 10008; i++){// i starts at 2 because the numbers 1 and 2 are by default prime numbers.
        x = 0; // a variable to check if a number is prime. If it gets set to 1 the number is not prime.
        for (int j = 2; j < i; j++){ // this loop divides the number by 2 up to itself and if the remainder is 0 sets x = 1.
            if (i%j == 0){
                x = 1;
                break;
            }
        }
        if (x == 0){ // if the x = 1 flag is never set the number is prime.
            primeNumbers.push_back(i);
        }
    }
    prompt();
    return 0;
}