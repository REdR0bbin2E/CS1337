#include <iostream> //including my preprocessor directives for files and cin/cout etc
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

const int MAXPRODUCTS = 100; //creating my global and const variables for the parallel arrays
string names[MAXPRODUCTS];
double prices[MAXPRODUCTS];
string codes[MAXPRODUCTS];
int numProducts = 0;

int findItem(string inputCode); //making my prototypes for the different functions
void readConfiguration();
void display();
void process();

int main() { //my main func that calls readCon Display and Process func
   readConfiguration();
   display();
   process();
}

void readConfiguration() { 
    ifstream file("menu.txt"); //opening the menu.txt file
    
    
    string line = "";
    while (getline(file, line) && numProducts < MAXPRODUCTS) { //taking in each line and assigning each corresponding part to each arrays index
        istringstream iss(line);
        iss >> codes[numProducts];
        iss >> names[numProducts];
        iss >> prices[numProducts];
       
        numProducts++;
    }
    file.close(); //closing the menu.txt file
    
    cout << numProducts << " items loaded.\n";
}

void display() { //displays the menu for each order and its cost
    cout << endl;
    cout << left << setw(8) << "Codes"
         << setw(25) << "Item Name"
         << setw(8) << "Prices" << endl;
    cout << "--------------------------------------------------" << endl;
    
    for (int i = 0; i < numProducts; i++) {
        cout << left << setw(8) << codes[i]
             << setw(25) << names[i]
             << "$" << fixed << setprecision(2) << prices[i] << endl;
             
    }
    cout << "--------------------------------------------------" << endl;
}

//return valid index if the item is found, return -1 if not
int findItem(string inputCode) {
    for (int i = 0; i < numProducts; i++) {
        if (codes[i] == inputCode) {
            return i;
        }
    }
    return -1;
}

// read order string like "A1 A2 E1 E2 S1" and generate the restaurant bill.
// Output the item name and price in each line, total in the final line.
void process() {
    string order;
    double total = 0.0;
    
    cout << "Enter item codes (separated by spaces): ";
    getline(cin, order);
    
    istringstream iss(order);
    string itemCode;
    
    cout << "\nOrder Summary:\n";
    while (iss >> itemCode) { //checks if the itemCode exist in the first parallel array
        int index = findItem(itemCode);
        if (index != -1) {
            cout << names[index] << ": $" << fixed << setprecision(2) << prices[index] << endl;
            total += prices[index];
        } else {
            cout << itemCode << " is invalid. Skipping it." << endl;
        }
    }
    
    cout << "Total: $" << fixed << setprecision(2) << total << endl; //prints the total after each order is placed
}


