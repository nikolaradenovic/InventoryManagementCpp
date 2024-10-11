#include "pants.h"
#include <string>
#include <iostream>
#include "..\validations.h"
#include <limits>

Pants::Pants(const std::string &name, const std::string &desc, double price, const std::string &dateAcquired, const std::string &size, const std::string &type, const std::string &pantsFitType, const std::string &pantsMaterial):
    Clothing(name, desc, price, dateAcquired, size, type), pantsFitType(pantsFitType), pantsMaterial(pantsMaterial){
        count ++;
    };
Pants::~Pants(){
    count --;
};


//setters

void Pants::setPantsFitType(std::string newPantsFitType){
    pantsFitType = newPantsFitType;
}

void Pants::setPantsMaterial(std::string newPantsMaterial){
    pantsMaterial = newPantsMaterial;
}

//getters

std::string Pants::getPantsFitType(){
    return pantsFitType;
}

std::string Pants::getPantsMaterial(){
    return pantsMaterial;
}

void Pants::displayItem() const{
    std::cout<<"Item ID:  "<<itemID<<"\nItem name:  "<<name<<"\nItem price:  "<<price<<"\nDate acquired:  "<<dateAcquired<<"\nSize:  "<<size<<"\nType (shirts, pants, jackets...):  "<<type<<"\nPants fit type: "<<pantsFitType<<"\nPants material:   "<<pantsMaterial<<"\n\nDescription:  "<<description<<"\n\n";
}

void Pants::updateItem(Item &item){
    std::string name, desc, dateAcquired, size, type, pantsFitType,  pantsMaterial;
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

            std::cout << "Enter pants fit type: ";
            getline(std::cin, pantsFitType);
            item.setPantsFitType(pantsFitType);

            std::cout << "Enter pants material: ";
            std::cin >> pantsMaterial;
            item.setPantsMaterial(pantsMaterial);

            std::cout << "Item updated.\n";
            return;
        

    return;
}

std::string Pants::toCSV() const{
    return std::to_string(itemID) + "," + name + "," + description +  "," + std::to_string(price) + "," + dateAcquired + "," + size + "," + type + "," + pantsFitType +  "," + pantsMaterial;
}

void Pants::saveToCSV(const std::vector<Item*>& item_array) const{
    std::ofstream file("csvs/pants.csv");
    
    if(file.is_open()){
        for (Item* item : item_array) {
            Pants* pantsItem = dynamic_cast<Pants*>(item);
            if (pantsItem) {
                file << pantsItem->toCSV() << "\n"; 
            }
        }
        //file << toCSV() << "\n";
        file.close();
        std::cout << "Data saved to database.\n\n" << std::endl;
    }else{
        std::cerr << "Unable to save file.\n\n" << std::endl;
    }
}

