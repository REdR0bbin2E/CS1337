#include <iostream>
#include <string>
// Including necessary libraries

using namespace std;
// Using the namespace std to avoid prefixing with std::

bool isPalindrome(string str) {
    /* Function that checks if the user input is a palindrome or not */

    int strLength = str.length();
    int count = 0;
    // Declaring and initializing local variables for the length of user input and a counter

    if (str.length() % 2 == 0) {
        // Checks if the palindrome has an even number of characters
        for (int i = 0; i < static_cast<int>(str.length() / 2); i++) {
            // Iterates through the palindrome, checking if each character corresponds to its counterpart
            if (str[i] == str[--strLength]) {
                count += 1;
            } else {
                // Returns false if it isn't a palindrome
                cout << "The given string is not a palindrome.\n";
                return false;
            }
        }

        if (count == strLength) {
            // Returns true if it is a palindrome
            cout << "The given string is a palindrome.\n";
            return true;
        }

    } else {
        // Checks odd length user string inputs
        count = 0;
        strLength = str.length();
        
        for (int i = 0; i < static_cast<int>(strLength / 2)+1; i++) {
            if (str[i] == str[--strLength]) {
                count += 1;
            } else {
                // Returns false if it isn't a palindrome
                cout << "The given string is not a palindrome.\n";
                return false;
            }
        }
        if (count == static_cast<int>(str.length() / 2)) {
            // Returns true if it is a palindrome
            cout << "The given string is a palindrome.\n";
            return true;
        }
    }

    return true; // Default return value
}

int main() {
    string str;

    cout << "Enter the name of the string: ";
    cin >> str;

    isPalindrome(str);

    return 0;
}
