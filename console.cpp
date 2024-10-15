#include <iostream>
#include <limits>
#include <vector>
#include "classes/item.h"
#include "classes/perishableFood.h"
#include "classes/nonPerishableFood.h"
#include "classes/pants.h"
#include "classes/shirt.h"
#include "classes/television.h"
#include "classes/phone.h"
#include "console.h"

bool loadFromCSV(std::vector<Item*> &item_array){ // za parsovanje CSV-ova i popunjavanje item_array
    std::ifstream perishableFoodFile("csvs/perishableFood.csv");
    if (!perishableFoodFile.is_open()) {
        std::cerr << "Could not open perishable food CSV file!" << std::endl;
        return false;
    }

    // PERISHABLE FOOD
    std::string perishableFoodLine;
    while (getline(perishableFoodFile, perishableFoodLine)) {
        std::stringstream ss(perishableFoodLine);
        std::string token;

        int itemID;
        std::string name, desc, dateAcquired, dateOfExpiry, dateProduced, category;
        double price;
        bool expired;

        getline(ss, token, ','); itemID = stoi(token);  
        getline(ss, name, ',');                         
        getline(ss, desc, ',');                         
        getline(ss, token, ','); price = stod(token);   
        getline(ss, dateAcquired, ',');                 
        getline(ss, dateOfExpiry, ',');                 
        getline(ss, dateProduced, ',');                 
        getline(ss, category, ',');                     
        getline(ss, token, ','); expired = (token == "1"); 

        Item* item = new PerishableFood(name, desc, price, dateAcquired, dateOfExpiry, dateProduced, category, expired);

        item_array.push_back(item);
    }
    perishableFoodFile.close();

    // NON PERISHABLE FOOD
    std::ifstream nonPerishableFoodFile("csvs/nonPerishableFood.csv");
    if (!nonPerishableFoodFile.is_open()) {
        std::cerr << "Could not open non-perishable food CSV file!" << std::endl;
        return false;
    }

    std::string nonPerishableFoodLine;
    while (getline(nonPerishableFoodFile, nonPerishableFoodLine)) {
        std::stringstream ss(nonPerishableFoodLine);
        std::string token;

        int itemID;
        std::string name, desc, dateAcquired, dateProduced, category, preservationMethod;
        double price;

        getline(ss, token, ','); itemID = stoi(token); 
        getline(ss, name, ',');                         
        getline(ss, desc, ',');                         
        getline(ss, token, ','); price = stod(token);   
        getline(ss, dateAcquired, ',');                 
        getline(ss, dateProduced, ',');                 
        getline(ss, category, ',');                     
        getline(ss, preservationMethod, ',');           

        Item* item = new NonPerishableFood(name, desc, price, dateAcquired, dateProduced, category, preservationMethod);

        item_array.push_back(item);
    }

    nonPerishableFoodFile.close();

    //PANTS

    std::ifstream pantsFile("csvs/pants.csv");
    if (!pantsFile.is_open()) {
        std::cerr << "Could not open pants CSV file!" << std::endl;
        return false;
    }

    std::string pantsLine;
    while (getline(pantsFile, pantsLine)) {
        std::stringstream ss(pantsLine);
        std::string token;

        int itemID;
        std::string name, desc, dateAcquired, size, type, pantsFitType, pantsMaterial;
        double price;

        getline(ss, token, ','); itemID = stoi(token); 
        getline(ss, name, ',');                         
        getline(ss, desc, ',');                         
        getline(ss, token, ','); price = stod(token);   
        getline(ss, dateAcquired, ',');                 
        getline(ss, size, ',');                 
        getline(ss, type, ',');                     
        getline(ss, pantsFitType, ',');         
        getline(ss, pantsMaterial, ',');     

        Item* item = new Pants(name, desc, price, dateAcquired, size, type, pantsFitType, pantsMaterial);

        item_array.push_back(item);
    }

    pantsFile.close();

    //SHIRT

    std::ifstream shirtFile("csvs/shirt.csv");
    if (!shirtFile.is_open()) {
        std::cerr << "Could not open shirt CSV file!" << std::endl;
        return false;
    }

    std::string shirtLine;
    while (getline(shirtFile, shirtLine)) {
        
        std::stringstream ss(shirtLine);
        std::string token;

        int itemID;
        std::string name, desc, dateAcquired, type, size, shirtColor, sleeveLength;
        double price;

        getline(ss, token, ','); itemID = stoi(token); 
        getline(ss, name, ',');                         
        getline(ss, desc, ',');                         
        getline(ss, token, ','); price = stod(token);   
        getline(ss, dateAcquired, ',');                 
        getline(ss, size, ',');                 
        getline(ss, type, ',');                     
        getline(ss, shirtColor, ',');         
        getline(ss, sleeveLength, ',');     

        Item* item = new Shirt(name, desc, price, dateAcquired, size, type, shirtColor, sleeveLength);

        item_array.push_back(item);
    }

    shirtFile.close();

    //TELEVISION

    std::ifstream televisionFile("csvs/television.csv");
    if (!televisionFile.is_open()){
        std::cerr << "Could not open television CSV file!" << std::endl;
        return false;
    }

    std::string televisionLine;
    while (getline(televisionFile, televisionLine)) {
        std::stringstream ss(televisionLine);
        std::string token;

        int itemID;
        std::string name, desc, dateAcquired;
        double price, powerConsumption, warrantyPeriod, screenSize, isSmart;

        getline(ss, token, ','); itemID = stoi(token); 
        getline(ss, name, ',');                         
        getline(ss, desc, ',');                         
        getline(ss, token, ','); price = stod(token);   
        getline(ss, dateAcquired, ',');                 
        getline(ss, token, ','); powerConsumption = stod(token);                 
        getline(ss, token, ','); warrantyPeriod = stod(token);                  
        getline(ss, token, ','); screenSize = stod(token);         
        getline(ss, token, ','); isSmart = (token == "1");   

        Item* item = new Television(name, desc, price, dateAcquired, powerConsumption, warrantyPeriod, screenSize, isSmart);

        item_array.push_back(item);
    }

    televisionFile.close();

    //PHONE

    std::ifstream phoneFile("csvs/phone.csv");
    if (!phoneFile.is_open()){
        std::cerr << "Could not open phone CSV file!" << std::endl;
        return false;
    }

    std::string phoneLine;
    while (getline(phoneFile, phoneLine)) {
        std::stringstream ss(phoneLine);
        std::string token;

        int itemID;
        std::string name, desc, dateAcquired, brand;
        double price, powerConsumption, warrantyPeriod, batteryLife;

        getline(ss, token, ','); itemID = stoi(token); 
        getline(ss, name, ',');                         
        getline(ss, desc, ',');                         
        getline(ss, token, ','); price = stod(token);   
        getline(ss, dateAcquired, ',');                 
        getline(ss, token, ','); powerConsumption = stod(token);                 
        getline(ss, token, ','); warrantyPeriod = stod(token);                  
        getline(ss, token, ','); batteryLife = stod(token);         
        getline(ss, brand, ',');  

        Item* item = new Phone(name, desc, price, dateAcquired, powerConsumption, warrantyPeriod, batteryLife, brand);

        item_array.push_back(item);
    }

    phoneFile.close();
    return true;

}





void deleteItem(std::vector<Item*> &item_array){
    int targetId;
    std::cout << "Enter ID of the item you wish to delete: ";
    std::cin >> targetId;
    std::cin.ignore();

    bool found = false; 
    for (auto it = item_array.begin(); it != item_array.end(); ++it) {
        if ((*it)->getId() == targetId) {
            delete *it;          
            item_array.erase(it); 
            std::cout << "Item with ID " << targetId << " has been deleted." << std::endl;
            found = true;       
            break;              
        }
    }
}

void viewItems(std::vector<Item*> &item_array){
    if (item_array.empty()) {
        std::cout << "No items in inventory.\n";
        return;
    }
    std::cout<<"---------------------\n"<<"Printing all items: \n\n";
    for(Item* item : item_array){
        item->displayItem();
    }
    std::cout<<"---------------------\n\n";
    return;
}

void saveChanges(std::vector<Item*> &item_array){
    for(Item *item : item_array){
        item->saveToCSV(item_array);
    }
}

void searchByItemID(const std::vector<Item*> &item_array){
    int targetID;
    std::cout << "Enter ID of the item you wish to find: ";
    std::cin >> targetID;
    std::cin.ignore();
    for(Item *item : item_array){
        if(item->getId() == targetID){
            item->displayItem();
            std::cout<<"---------------------\n\n";
            return;
        }
    }
    std::cout << "Item with item ID " << targetID << " couldn't be found.\n";
    return;
}


void searchByName(const std::vector<Item*> &item_array){
    std::vector<Item*> exactMatches;
    std::vector<Item*> partialMatches;
    std::string targetName;
    std::cout << "Enter the name of the item you wish to find: ";
    std::cin >> targetName;
    std::cin.ignore();

    for(Item *item : item_array){
        if(item->getName() == targetName){
            exactMatches.push_back(item);
        }
        if(item->getName().find(targetName) != std::string::npos){ //npos je no position, .find() vraca indeks prvog pojavljivalja podstrigna u arg. ako find() vrati npos, znaci da podstring nije nadjen
            partialMatches.push_back(item);
        }
    }
    std::cout << "\nExact matches: \n";
    for(Item *item : exactMatches){
        item->displayItem();
        std::cout<<"---------------------\n\n";
    }
    std::cout << "\nPartial matches: \n";
    for(Item *item : partialMatches){
        item->displayItem();
        std::cout<<"---------------------\n\n";
    }
}

void searchByDescription(const std::vector<Item*> &item_array){
    std::vector<Item*> exactMatches;
    std::vector<Item*> partialMatches;
    std::string targetDescription;
    std::cout << "Enter the description of the item you wish to find: ";
    std::cin >> targetDescription;
    std::cin.ignore();

    for(Item *item : item_array){
        if(item->getName() == targetDescription){
            exactMatches.push_back(item);
        }
        if(item->getName().find(targetDescription) != std::string::npos){
            partialMatches.push_back(item);
        }
    }
    std::cout << "\nExact matches: \n";
    for(Item *item : exactMatches){
        item->displayItem();
        std::cout<<"---------------------\n\n";
    }
    std::cout << "\nPartial matches: \n";
    for(Item *item : partialMatches){
        item->displayItem();
        std::cout<<"---------------------\n\n";
    }
}

void searchByPrice(const std::vector<Item*> &item_array){
    
}

void showMenu(){
    std::cout << "Inventory Management System\n";
    std::cout << "1. Add Item\n";
    std::cout << "2. View Items\n";
    std::cout << "3. Update Item\n";
    std::cout << "4. Delete Item\n";
    std::cout << "5. Save changes\n";
    std::cout << "6. Search and filter\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

void showItemMenu(){
    std::cout<<"What kind of item do you want to add?\n\n";
    std::cout << "1. Add Food\n";
    std::cout << "2. Add clothes\n";
    std::cout << "3. Add electronics\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void showFoodMenu(){
    std::cout<<"What kind of food do you want to add?\n\n";
    std::cout << "1. Add perishable food\n";
    std::cout << "2. Add non perishable food\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

void showClothingMenu(){
    std::cout<<"What kind of clothes do you want to add?\n\n";
    std::cout << "1. Add shirts\n";
    std::cout << "2. Add pants\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

void showElectronicsMenu(){
    std::cout<<"What kind of electronics item do you want to add?\n\n";
    std::cout << "1. Add phones\n";
    std::cout << "2. Add televisions\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

void searchAndFilterMenu(){
    std::cout<<"What kwould you like to search or filter?\n\n";
    std::cout << "1. Search\n";
    std::cout << "2. Filter\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

void searchMenu(){
    std::cout<<"Which attribute would you like to filter by?\n\n";
    std::cout << "1. Item ID\n";
    std::cout << "2. Name\n";
    std::cout << "3. Description\n";
    std::cout << "4. Price\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}