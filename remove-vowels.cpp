#include <string>
#include <iostream>

using namespace std;

/*
Trim function that will take the string input by the user and remove all vowels
Input is any variable of the type string
Returns the input text without vowels
*/
string trim(string text) {
    //Contains all the vowels that would need to be removed from the input text
    char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    //For loop that loops through the array of vowels
    for (int i=0; i<10; i++) {
        /*
        The remove function takes 3 inputs which are first, last, and value
        The (first, last) inputs are the range of elements which will be iterated through
        The value input is the value that will be removed
        Unfortunately the remove function does not delete the elements from our string, 
        it simply moves the elements not being removed to the front.
        To actually delete the elements we need the erase function
        Remove returns an iterator pointing to the element and then erase deletes the element from the container
        This is called the "Erase-remove idiom", more info can be found here: 
        https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
        */
        text.erase(remove(text.begin(), text.end(), vowels[i]), text.end());
    }
    return text;
}

/*
Primary function that contains the prompts, input, and output
Does not take any form of input
Returns 0 to indicate that the program has finished executing
*/
int main() {
    //Declare the string variable input which will contain our user's input later
    string input;
    cout << "This program will remove all vowels from your input.\n";
    cout << "Input: ";
    //If the input is a sentence and contains spaces, cin will only grab the first word, getline grabs the entire sentence
    getline(cin, input);
    //Assign the variable output to the returned value from the trim function
    string output = trim(input);
    cout << "Output: " << output << "\n";
    return 0;
}