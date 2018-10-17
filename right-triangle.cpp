#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main() {
    int side1, side2, side3;
    cout << "This program will check to see if the sides you put in equal a right triangle.\n";
    cout << "Please enter an upper bound integer between 1 and 100 for all sides.\n";
    cout << "Side 1: ";
    cin >> side1;
    if (side1 <= 0 || side1 > 100) {
        cout << "This is not a valid input, please try again.\n";
        main();
    }
    cout << "Side 2: ";
    cin >> side2;
    if (side2 <= 0 || side2 > 100) {
        cout << "This is not a valid input, please try again.\n";
        main();
    }
    cout << "Side 3: ";
    cin >> side3;
    if (side3 <= 0 || side3 > 100) {
        cout << "This is not a valid input, please try again.\n";
        main();
    }

    int allSides[3] = {side1, side2, side3};
    vector<int> allSidesSorted (allSides, allSides+3);
    sort (allSidesSorted.begin(), allSidesSorted.end(), myobject);

    // Check to see if sides add up to less than the hypotenuse
    if (allSidesSorted[0] + allSidesSorted[1] < allSidesSorted[2]) {
        cout << "This is not a triangle, please enter the sides again.\n";
        main();
    }
    
    // Ouput side lengths that user input
    cout << "The sides you input in ascending order: ";
    for (vector<int>::iterator it=allSidesSorted.begin(); it!=allSidesSorted.end(); ++it)
    cout << " " << *it;
    cout << "\n";

    // Output hypotenuse based on user input
    cout << "Input hypotenuse based on side length: " << allSidesSorted[2] << "\n";
    // Output calculated hypotenuse
    cout << "Calculated hypotenuse based on sides input: " << allSidesSorted[0] + allSidesSorted[1] << "\n";
    // Right triangle check
    if (pow(allSidesSorted[0], 2) + pow(allSidesSorted[1], 2) == pow(allSidesSorted[2], 2)) {
        cout << "This is a right triangle.\n";
        return 0;
    } else {
        cout << "This is not a right triangle.\n";
        return 0;
    }

    /*
    Example result:
    Side 1 = 3
    Side 2 = 4
    Side 3 = 5
    3 * 3 = 9
    4 * 4 = 16
    5 * 5 = 25
    9 + 16 = 25
    This is a right triangle
    */

    return 0;
}