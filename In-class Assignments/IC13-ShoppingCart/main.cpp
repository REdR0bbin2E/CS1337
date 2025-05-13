// main.cpp
#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
    ItemToPurchase item1, item2;
    string name;
    int price, quantity;

    // Input for first item
    cout << "Item 1" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, name);
    item1.SetName(name);
    
    cout << "Enter the item price:" << endl;
    cin >> price;
    item1.SetPrice(price);
    
    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    item1.SetQuantity(quantity);
    
    cin.ignore(); // Ignore newline before taking next string input

    // Input for second item
    cout << "\nItem 2" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, name);
    item2.SetName(name);
    
    cout << "Enter the item price:" << endl;
    cin >> price;
    item2.SetPrice(price);
    
    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    item2.SetQuantity(quantity);
    
    // Compute and display total cost
    int totalCost1 = item1.GetPrice() * item1.GetQuantity();
    int totalCost2 = item2.GetPrice() * item2.GetQuantity();
    int totalCost = totalCost1 + totalCost2;
    
    cout << "\nTOTAL COST" << endl;
    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << totalCost1 << endl;
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << totalCost2 << endl;
    cout << "\nTotal: $" << totalCost << endl;
    
    return 0;
}
