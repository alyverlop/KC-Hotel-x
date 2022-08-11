#include <iostream>
#include <string>

using namespace std;

bool IsNumber(string input) {
    for (char const& c : input) { //scrolls through each char of string to make sure its a number
        if (isdigit(c) == 0) {
            return false; //returns false if not a number
        }
    }
    return true;
}
