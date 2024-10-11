#include <iostream>
#include "./classes/perishableFood.h"
#include "./classes/nonPerishableFood.h"
#include "./classes/shirt.h"
#include "./classes/pants.h"
#include "./classes/phone.h"
#include "./classes/television.h"
#include "./validations.h"
#include <limits>
#include "addItem.h"

class ItemData{
    public:

    std::string name;
    std::string desc;
    double price;
    std::string dateAcquired;
};

bool collectItemData(ItemData &data){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //obavezno ocistiti buffer zbog presotalih \n sa main

    std::cout << "Enter Name: ";
    getline(std::cin, data.name);

    std::cout << "Enter Description: ";
    getline(std::cin, data.desc);

    std::cout << "Enter Price: ";
    std::cin >> data.price;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cerr << "Invalid input. Please enter a numeric value." << std::endl;
        return 0; 
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Date Acquired (YYYY-MM-DD): ";
    getline(std::cin, data.dateAcquired);
    if(isValidDate(data.dateAcquired) == 0){
        std::cout<<"Date is not valid, try again\n";
        return 0;
    }
    return 1;
};

void addPerishableFood(std::vector<Item*> &item_array) {
    std::string dateOfExpiry, dateProduced, category;
    bool expired;

    ItemData *newItemData = new ItemData;
    if(collectItemData(*newItemData) == 0){
        return;
    }

    std::cout << "Enter Date of Expiry (YYYY-MM-DD): ";
    getline(std::cin, dateOfExpiry);
    if(isValidDate(dateOfExpiry) == 0){
        std::cout<<"Date is not valid, try again\n";
        return;
    }

    std::cout << "Enter Date Produced (YYYY-MM-DD): ";
    getline(std::cin, dateProduced);
    if(isValidDate(dateProduced) == 0){
        std::cout<<"Date is not valid, try again\n";
        return;
    }

    std::cout << "Enter Category: ";
    getline(std::cin, category);

    std::cout << "Is it expired? (1 for Yes, 0 for No): ";
    std::cin >> expired;
    if(std::cin.fail() || !(expired == 0 || expired == 1)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid input for expiry, please use 0 or 1. \n\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Item *current_item = new PerishableFood((*newItemData).name, (*newItemData).desc, (*newItemData).price, (*newItemData).dateAcquired, dateOfExpiry, dateProduced, category, expired);
    std::cout << "Perishable food item added successfully.\n\n";
    item_array.push_back(current_item);  
}


void addNonPerishableFood(std::vector<Item*> &item_array) {
    std::string dateProduced, category, preservationMethod;
    
    ItemData *newItemData = new ItemData;
    if(collectItemData(*newItemData) == 0){
        return;
    }

    std::cout << "Enter Date Produced (YYYY-MM-DD): ";
    getline(std::cin, dateProduced);
    if(isValidDate(dateProduced) == 0){
        std::cout<<"Date is not valid, try again\n";
        return;
    }

    std::cout << "Enter Category: ";
    getline(std::cin, category);

    std::cout << "Enter preservation method: ";
    getline(std::cin, preservationMethod);

    Item *current_item = new NonPerishableFood((*newItemData).name, (*newItemData).desc, (*newItemData).price, (*newItemData).dateAcquired, dateProduced, category, preservationMethod);
    std::cout << "Non perishable food item added successfully.\n\n";
    item_array.push_back(current_item);
}

void addShirt(std::vector<Item*> &item_array) {
std::string size, type, shirtColor, sleeveLenght;
    
    ItemData *newItemData = new ItemData;
    if(collectItemData(*newItemData) == 0){
        return;
    }

    std::cout << "Enter size: ";
    getline(std::cin, size);

    std::cout << "Enter type (shirts or pants): ";
    getline(std::cin, type);

    std::cout << "Enter shirt color: ";
    getline(std::cin, shirtColor);

    std::cout << "Enter sleeve length: ";
    getline(std::cin, sleeveLenght);

    Item *current_item = new Shirt((*newItemData).name, (*newItemData).desc, (*newItemData).price, (*newItemData).dateAcquired, size, type, shirtColor, sleeveLenght);
    std::cout << "Shirt item added successfully.\n\n";
    item_array.push_back(current_item);

}

void addPants(std::vector<Item*> &item_array) {
std::string size, type, pantsFitType, pantsMaterial;
    
    ItemData *newItemData = new ItemData;
    if(collectItemData(*newItemData) == 0){
        return;
    }

    std::cout << "Enter size: ";
    getline(std::cin, size);

    std::cout << "Enter type (shirts or pants): ";
    getline(std::cin, type);

    std::cout << "Enter pants fit type: ";
    getline(std::cin, pantsFitType);

    std::cout << "Enter pants material: ";
    getline(std::cin, pantsMaterial);

    Item *current_item = new Pants((*newItemData).name, (*newItemData).desc, (*newItemData).price, (*newItemData).dateAcquired, size, type, pantsFitType, pantsMaterial);
    std::cout << "Pants item added successfully.\n\n";
    item_array.push_back(current_item);

}

void addPhone(std::vector<Item*> &item_array) {
std::string brand;
double powerConsumption, warrantyPeriod, batteryLife;
    
    ItemData *newItemData = new ItemData;
    if(collectItemData(*newItemData) == 0){
        return;
    }

    std::cout << "Enter power consumption: ";
    std::cin >> powerConsumption;

    std::cout << "Enter warranty period: ";
    std::cin >> warrantyPeriod;

    std::cout << "Enter battery life: ";
    std::cin >> batteryLife;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter brand: ";
    getline(std::cin, brand);

    Item *current_item = new Phone((*newItemData).name, (*newItemData).desc, (*newItemData).price, (*newItemData).dateAcquired, powerConsumption, warrantyPeriod, batteryLife, brand);
    std::cout << "Phone item added successfully.\n\n";
    item_array.push_back(current_item);

}

void addTelevision(std::vector<Item*> &item_array) {
bool isSmart;
double powerConsumption, warrantyPeriod, screenSize;
    
    ItemData *newItemData = new ItemData;
    if(collectItemData(*newItemData) == 0){
        return;
    }

    std::cout << "Enter power consumption: ";
    std::cin >> powerConsumption;

    std::cout << "Enter warranty period: ";
    std::cin >> warrantyPeriod;

    std::cout << "Enter screen size: ";
    std::cin >> screenSize;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Is this a Smart TV? (1-yes, 0-no)? ";
    std::cin, isSmart;
    if(std::cin.fail() || !(isSmart == 0 || isSmart == 1)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid input for expiry, please use 0 or 1. \n\n";
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Item *current_item = new Television((*newItemData).name, (*newItemData).desc, (*newItemData).price, (*newItemData).dateAcquired, powerConsumption, warrantyPeriod, screenSize, isSmart);
    std::cout << "Television item added successfully.\n\n";
    item_array.push_back(current_item);

}