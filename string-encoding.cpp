#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>
#include <functional>
using namespace std;

// Function to randomize sentence
vector<string> randomizeSentence(string input) {
    // Start string stream so that characters can be inserted or extracted from the stream
    stringstream inputStream(input);
    // Declare vector string
    vector<string> words;
    // Loop through input stream and push each individual word into words vector
    for (string word; inputStream >> word;) {
        words.push_back(word);
    }
    // Generate pseudo random number as the source of randomness for the shuffle function
    auto rng = default_random_engine();
    // Shuffle words into random order
    shuffle(words.begin(), words.end(), rng);
    // Return shuffled words
    return words;
}

// Function to convert string to lowercase
string lowercase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Function for ascending comparison in sort function
bool ascending(const string& lhs, const string& rhs) {
    string leftLower = lowercase(lhs);
    string rightLower = lowercase(rhs);
    // Left to right is ascending, right to left is descending
    return leftLower > rightLower;
}

// Function for sorting sentence by ascending
vector<string> sortSentence(string input) {
    // Start string stream so that characters can be inserted or extracted from the stream
    stringstream inputStream(input);
    // Declare vector string
    vector<string> words;
    // Loop through input stream and push each individual word into words vector
    for (string word; inputStream >> word;) {
        words.push_back(word);
    }
    // Sort words in ascending order determined by the first character in each word case insensitive
    sort(words.begin(), words.end(), ascending);
    // Return sorted words
    return words;
}

// Function for encoding sentence in ROT13
// Refer to ASCII table for character to number reference
string encodeString(string str) {
    string encoded;
    // Loop through entire size of string
    for (size_t i = 0; i < str.size(); ++i) {
        // Check if character is alphabetic
        if (isalpha(str[i])) {
            // Check if the current character in the string when subtracted by 'a' is less than 13
            if ((tolower(str[i]) - 'a') < 13) {
                // If yes, add 13
                encoded.append(1, str[i] + 13);
            } else {
            // If no to both, subtract 13
            encoded.append(1, str[i] - 13);
            }
        } else {
            // If its not an alphabetic character leave it unchanged
            encoded.append(1, str[i]);
        }
    }
    // Return the encoded string
    return encoded;
}

int main() {
    string sentence;

    cout << "This program will take your input and do the following:\n";
    cout << "1. Randomize the words in your sentence.\n";
    cout << "2. Sort the words in ascending order.\n";
    cout << "3. Apply ROT13 encoding to your words.\n\n";
    cout << "Please type a sentence: ";
    // If the input is a sentence and contains spaces, cin will only grab the first word, getline grabs the entire sentence
    getline(cin, sentence);
    cout << "\n";

    // Set randomSentence to returned value from randomizeSentence
    vector<string> randomSentence = randomizeSentence(sentence);
    cout << "Randomized: ";
    // Loop through each word in the random sentence and display it
    for (auto randomIterate: randomSentence)
    cout << randomIterate << " ";
    cout << "\n";

    // Set sortedSentence to returned value from sortSentence
    vector<string> sortedSentence = sortSentence(sentence);
    cout << "Sorted: ";
    // Loop through each word in the sorted sentence and display it
    for (auto sortIterate: sortedSentence)
    cout << sortIterate << " ";
    cout << "\n";

    // Set encdodedSentence to returned value of encodeString
    string encodedSentence = encodeString(sentence);
    cout << "Encoded: " << encodedSentence << "\n";

    return 0;
}