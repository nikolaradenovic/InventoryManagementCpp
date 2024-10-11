#include "nonPerishableFood.h"
#include "..\validations.h"
#include <iostream>
#include <limits>

int NonPerishableFood::count = 0;

NonPerishableFood::NonPerishableFood(const std::string& name, const std::string& desc, double price, const std::string dateAcquired, const std::string &dateProduced, const std::string &category, std::string preservationMethod)
    : Food(name, desc, price, dateAcquired, dateProduced, category), preservationMethod(preservationMethod){
        count++;
    };

NonPerishableFood::~NonPerishableFood(){
    count--;
}

void NonPerishableFood::setDateProduced(std::string newDateProduced){
    dateProduced = newDateProduced;
}

void NonPerishableFood::setCategory(std::string  newCategory){
    category = newCategory;
}

void NonPerishableFood::setPreservationMethod(std::string newPreservationMethod){
    preservationMethod = newPreservationMethod;
}

std::string NonPerishableFood::getDateProduced() const{
    return dateProduced;
}

std::string NonPerishableFood::getCategory() const{
    return category;
}

std::string NonPerishableFood::getPreservationMethod() const{
    return preservationMethod;
}


void NonPerishableFood::displayItem() const{
    std::cout<<"Item ID:  "<<itemID<<"\nItem name:  "<<name<<"\nItem price:  "<<price<<"\nDate acquired:  "<<dateAcquired<<"\nDate of expiry:  "<<dateProduced<<"\nCategory:  "<<category<<"\nPreservation methid:   "<<preservationMethod<<"\n\nDescription:  "<<description<<"\n\n";
}

void NonPerishableFood::updateItem(Item &item){
    std::string name, desc, dateAcquired, dateProduced, category, preservationMethod;
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

            std::cout << "Enter Date Produced (YYYY-MM-DD): ";
            getline(std::cin, dateProduced);
            if(isValidDate(dateProduced)){
                item.setDateProduced(dateProduced);
             }else{
                std::cout<<"Date is not valid, try again\n";
                return;
            }

            std::cout << "Enter Category: ";
            getline(std::cin, category);
            item.setCategory(category);

            
            std::cout << "Enter preservation method: ";
            getline(std::cin, preservationMethod);
            item.setPreservationMethod(preservationMethod);

            std::cout << "Item updated.\n";
            return;
        

    return;
}

std::string NonPerishableFood::toCSV() const{
    return std::to_string(itemID) + "," + name + "," + description +  "," + std::to_string(price) + "," + dateAcquired + "," + dateProduced + "," + category + "," + preservationMethod;
}

void NonPerishableFood::saveToCSV(const std::vector<Item*>& item_array) const{
    std::ofstream file("csvs/nonPerishableFood.csv");
    
    if(file.is_open()){
        for (Item* item : item_array) {
            NonPerishableFood* nonPerishableItem = dynamic_cast<NonPerishableFood*>(item);
            if (nonPerishableItem) {
                file << nonPerishableItem->toCSV() << "\n"; 
            }
        }
        //file << toCSV() << "\n";
        file.close();
        std::cout << "Data saved to database.\n\n" << std::endl;
    }else{
        std::cerr << "Unable to save file.\n\n" << std::endl;
    }
}


