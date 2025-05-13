// ItemToPurchase.h
#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    // Constructor
    ItemToPurchase();
    
    // Mutators
    void SetName(string name);
    void SetPrice(int price);
    void SetQuantity(int quantity);
    
    // Accessors
    string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;
    
private:
    string itemName;
    int itemPrice;
    int itemQuantity;
};

#endif
