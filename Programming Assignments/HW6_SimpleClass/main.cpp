#include <iostream>
#include "Product.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Structure to hold transaction details
struct Transaction {
    int transactionNumber;
    string PLU;
    int type; // 1 for add, 2 for subtract
    int amount;
};

// Function prototypes
void displayMenu(); // Displays the menu options
void displayProducts(Product *products, int size); // Displays product details
void addInventory(Product *products, int size, Transaction history[], int &transactionCount); // Adds to inventory
void subtractInventory(Product *products, int size, Transaction history[], int &transactionCount); // Subtracts from inventory

int main() {
    // Prompt user for input file name
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    // Open file and validate
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Count number of records in the file
    int size = 0;
    string line;
    while (getline(file, line)) {
        size++;
    }
    
    // Reset file pointer to the beginning
    file.clear();
    file.seekg(0, ios::beg);

    // Create a dynamic array of products
    Product *products = new Product[size];

    string PLU, name;
    int type, inventory;
    double price;
    
    // Read file and set product attributes
    for (int i = 0; i < size; i++) {
        file >> PLU >> name >> type >> price >> inventory;
        products[i].setProductAttributes(PLU, name, type, price, inventory);
    }
    
    file.close(); // Close the file

    // Display number of records and product details
    cout << "There are " << size << " records in the file" << endl;
    cout << "\nContent of object array" << endl;
    cout << "-----------------------" << endl;
    displayProducts(products, size);

    // Initialize transaction history
    Transaction history[5];
    int transactionCount = 0;

    int choice;
    
    // Display menu and handle user choices
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addInventory(products, size, history, transactionCount);
                break;
            case 2:
                subtractInventory(products, size, history, transactionCount);
                break;
            case 3:
                cout << "Current inventory" << endl;
                cout << "-----------------" << endl;
                displayProducts(products, size);
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 4);

    // Display transaction history (last 5 transactions)
    cout << "\nHistory of transactions" << endl;
    cout << "-----------------------" << endl;
    if (transactionCount > 5) {
        transactionCount = 5;
    }
    
    for (int i = transactionCount - 1; i >= 0; i--) {
        cout << "Transaction #: " << history[i].transactionNumber << ", PLU: " << history[i].PLU << ", type: ";
        cout << (history[i].type == 1 ? "Add to inventory, " : "Subtract from inventory, ");
        cout << "amount: " << history[i].amount << endl;
    }

    // Free allocated memory
    delete[] products; 
    return 0;
}

// Displays the menu options
void displayMenu() {
    cout << "\nMenu" << endl;
    cout << "----" << endl;
    cout << "1->Add to inventory           , 2->Subtract from inventory" << endl;
    cout << "3->Print info for all products, 4->Exit" << endl;
}

// Displays product details
void displayProducts(Product *products, int size) {
    for (int i = 0; i < size; i++) {
        cout << left << "PLU: " << products[i].getPLU() << ", " << setw(17) << products[i].getName() << ", "
             << "type: " << products[i].getType() << ", " << "unit price: " << right << setw(5) << products[i].getPrice() << ", "
             << "inventory: " << products[i].getInventory() << endl;
    }
}

// Adds items to inventory and records transaction history
void addInventory(Product *products, int size, Transaction history[], int &transactionCount) {
    string PLU;
    int amount = 0;
    cout << "Enter the PLU: ";
    cin >> PLU;
    
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (products[i].getPLU() == PLU) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "PLU not found" << endl;
        return;
    }
    
    cout << "Enter amount to add: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Amount must be > 0" << endl;
        return;
    }
    
    for (int i = 0; i < size; i++) {
        if (products[i].getPLU() == PLU) {
            products[i].setInventory(products[i].getInventory() + amount);
            
            // Log transaction
            if (transactionCount < 5) {
                history[transactionCount] = {transactionCount + 1, PLU, 1, amount};
                transactionCount++;
            } else {
                for (int j = 0; j < 4; j++) {
                    history[j] = history[j + 1];
                }
                history[4] = {transactionCount + 1, PLU, 1, amount};
                transactionCount++;
            }
        }
    }
}

// Subtracts items from inventory and records transaction history
void subtractInventory(Product *products, int size, Transaction history[], int &transactionCount) {
    string PLU;
    int amount = 0;
    cout << "Enter the PLU: ";
    cin >> PLU;
    
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (products[i].getPLU() == PLU) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "PLU not found" << endl;
        return;
    }
    
    cout << "Enter amount to subtract: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Amount must be > 0" << endl;
        return;
    }
    
    for (int i = 0; i < size; i++) {
        if (products[i].getPLU() == PLU) {
            int actualSubtracted = min(amount, products[i].getInventory());
            products[i].setInventory(products[i].getInventory() - actualSubtracted);
            
            // Log transaction
            if (transactionCount < 5) {
                history[transactionCount] = {transactionCount + 1, PLU, 2, actualSubtracted};
                transactionCount++;
            } else {
                for (int j = 0; j < 4; j++) {
                    history[j] = history[j + 1];
                }
                history[4] = {transactionCount + 1, PLU, 2, actualSubtracted};
                transactionCount++;
            }
        }
    }
}
