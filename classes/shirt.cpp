#include "shirt.h"
#include <string>
#include <iostream>
#include "..\validations.h"
#include <limits>

Shirt::Shirt(const std::string &name, const std::string &desc, double price, const std::string &dateAcquired, const std::string &size, const std::string &type, const std::string &shirtColor, const std::string &sleeveLength):
    Clothing(name, desc, price, dateAcquired, size, type), shirtColor(shirtColor), sleeveLength(sleeveLength){
        count ++;
    };
Shirt::~Shirt(){
    count --;
};


//setters

void Shirt::setShirtColor(std::string newShirtColor){
    shirtColor = newShirtColor;
}

void Shirt::setSleeveLength(std::string newSleeveLength){
    sleeveLength = newSleeveLength;
}

//getters

std::string Shirt::getShirtColor(){
    return shirtColor;
}

std::string Shirt::getSleeveLength(){
    return sleeveLength;
}

void Shirt::displayItem() const{
    std::cout<<"Item ID:  "<<itemID<<"\nItem name:  "<<name<<"\nItem price:  "<<price<<"\nDate acquired:  "<<dateAcquired<<"\nSize:  "<<size<<"\nType (shirts, pants, jackets...):  "<<type<<"\nShirt color:  "<<shirtColor<<"\nSleeve length:   "<<sleeveLength<<"\n\nDescription:  "<<description<<"\n\n";
}

void Shirt::updateItem(Item &item){
    std::string name, desc, dateAcquired, size, type, shirtColor, sleeveLength;
    double price;

            std::cout<<"Your item has been found. Enter new parameters for this item: \n\n";

            std::cout << "Enter Name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.sync();  //praznjenje buffer-a
            getline(std::cin, name);
            item.setName(name);

            std::cout << "Enter Description: ";
            getline(std::cin, desc);
            item.setDescription(desc);

            std::cout << "Enter Price: ";
            std::cin >> price;
            std::cin.ignore();
            item.setPrice(price);

            std::cout << "Enter Date Acquired (YYYY-MM-DD): ";
            getline(std::cin, dateAcquired);
            if(isValidDate(dateAcquired)){ 
                item.setDateAcquired(dateAcquired);
            }else{
                std::cout<<"Date is not valid, try again\n";
                return;
            }

            std::cout << "Enter size: ";
            getline(std::cin, size);
            item.setSize(size);

            std::cout << "Enter type: ";
            getline(std::cin, type);
            item.setType(type);

            std::cout << "Enter shirt color: ";
            getline(std::cin, shirtColor);
            item.setShirtColor(shirtColor);

            std::cout << "Enter sleeve length: ";
            std::cin >> sleeveLength;
            item.setSleeveLength(sleeveLength);

            std::cout << "Item updated.\n";
            return;
        

    return;
}

std::string Shirt::toCSV() const{
    return std::to_string(itemID) + "," + name + "," + description +  "," + std::to_string(price) + "," + dateAcquired + "," + size + "," + type + "," + shirtColor +  "," + sleeveLength;
}

void Shirt::saveToCSV(const std::vector<Item*>& item_array) const{
    std::ofstream file("csvs/shirt.csv");
    
    if(file.is_open()){
        for (Item* item : item_array) {
            Shirt* shirtItem = dynamic_cast<Shirt*>(item);
            if (shirtItem) {
                file << shirtItem->toCSV() << "\n"; 
            }
        }
        //file << toCSV() << "\n";
        file.close();
        std::cout << "Data saved to database.\n\n" << std::endl;
    }else{
        std::cerr << "Unable to save file.\n\n" << std::endl;
    }
}

