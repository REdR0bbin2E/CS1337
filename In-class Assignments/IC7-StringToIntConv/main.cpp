#include <iostream>
#include <string>
using namespace std;

string dollarFormat(string UnfAmt); // function prototype

int main() {
    string userInput = "";

    cout << "Enter an amount: ";
    cin >> userInput;

    cout << dollarFormat(userInput) << endl;
    return 0;
}

string dollarFormat(string UnfAmt) {
    int positionOfPeriod = -1;
    string newUserInput = "$";
    int numberOfNumbersBeforeDecimal = 0;
    int holder = 0;

    // Find position of the decimal point
    for (int i = 0; i < UnfAmt.length(); i++) {
        if (UnfAmt.at(i) == '.') {
            positionOfPeriod = i;
            numberOfNumbersBeforeDecimal = i;
            break;
        }
    }

    // If no decimal point found
    if (positionOfPeriod == -1) {
        positionOfPeriod = UnfAmt.length();
        numberOfNumbersBeforeDecimal = UnfAmt.length();
    }

    // Format before the decimal point
    if (numberOfNumbersBeforeDecimal % 3 == 0) {
        for (int i = 0; i < numberOfNumbersBeforeDecimal; i++) {
            newUserInput += UnfAmt.at(i);
            if (++i < numberOfNumbersBeforeDecimal) newUserInput += UnfAmt.at(i);
            if (++i < numberOfNumbersBeforeDecimal) newUserInput += UnfAmt.at(i);

            if (i < numberOfNumbersBeforeDecimal - 1) {
                newUserInput += ",";
            }
        }
    } else {
        holder = numberOfNumbersBeforeDecimal % 3 - 1;
        for (int s = 0; s < numberOfNumbersBeforeDecimal; s++) {
            if (s <= holder) {
                newUserInput += UnfAmt.at(s);
            } else if (s % 3 == 0 || s > holder) {
                newUserInput += ",";
                newUserInput += UnfAmt.at(s);
                if (++s < numberOfNumbersBeforeDecimal) newUserInput += UnfAmt.at(s);
                if (++s < numberOfNumbersBeforeDecimal) newUserInput += UnfAmt.at(s);
            }
        }
    }

    // Add the decimal part (if any)
    for (int i = 0; i < UnfAmt.length() - positionOfPeriod; i++) {
        if (i == 0) newUserInput += ".";
        newUserInput += UnfAmt.at(++positionOfPeriod);
    }

    return newUserInput;
}
