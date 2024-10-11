#include "perishableFood.h"
#include "..\validations.h"
#include <iostream>
#include <limits>


int PerishableFood::count = 0;

PerishableFood::PerishableFood(const std::string& name, const std::string& desc, double price, const std::string dateAcquired, const std::string &dateOfExpiry, const std::string &dateProduced, const std::string &category, const bool expired)
    : Food(name, desc, price, dateAcquired, dateProduced, category), expired(expired), dateOfExpiry(dateOfExpiry){
        count++;
    };

PerishableFood::~PerishableFood(){
    count--;
}

void PerishableFood::setDateOfExpiry(std::string newDateOfExpiry){
    dateOfExpiry = newDateOfExpiry;
}

void PerishableFood::setDateProduced(std::string newDateProduced){
    dateOfExpiry = newDateProduced;
}

void PerishableFood::setCategory(std::string  newCategory){
    category = newCategory;
}

void PerishableFood::setExpired(bool newExpired){
    expired = newExpired;
}

std::string PerishableFood::getDateOfExpiry() const{
    return dateOfExpiry;
}

std::string PerishableFood::getDateProduced() const{
    return dateProduced;
}

std::string PerishableFood::getCategory() const{
    return category;
}


bool PerishableFood::getExpired() const{
    return expired;
}


void PerishableFood::displayItem() const{
    std::cout<<"Item ID:  "<<itemID<<"\nItem name:  "<<name<<"\nItem price:  "<<price<<"\nDate acquired:  "<<dateAcquired<<"\nDate of expiry:  "<<dateOfExpiry<<"\nDate produced:  "<<dateProduced<<"\nCategory:  "<<category<<"\nIs expired?:   "<<expired<<"\n\nDescription:  "<<description<<"\n\n";
}

void PerishableFood::updateItem(Item &item){
    std::string name, desc, dateAcquired, dateOfExpiry, dateProduced, category;
    double price;
    bool expired;

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

            std::cout << "Enter Date of Expiry (YYYY-MM-DD): ";
            getline(std::cin, dateOfExpiry);
            if(isValidDate(dateOfExpiry)){
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

            std::cout << "Is it expired? (1 for Yes, 0 for No): ";
            std::cin >> expired;
            item.setExpired(expired);

            std::cout << "Item updated.\n";
            return;
        

    return;
}

std::string PerishableFood::toCSV() const{
    return std::to_string(itemID) + "," + name + "," + description +  "," + std::to_string(price) + "," + dateAcquired + "," + dateOfExpiry + "," + dateProduced + "," + category + "," + std::to_string(expired);
}

void PerishableFood::saveToCSV(const std::vector<Item*>& item_array) const{
    std::ofstream file("csvs/perishableFood.csv");
    
    if(file.is_open()){
        if (file.is_open()) {
        for (Item* item : item_array) {
            PerishableFood* perishableItem = dynamic_cast<PerishableFood*>(item);
            if (perishableItem) {
                file << perishableItem->toCSV() << "\n"; 
            }
        }
        //file << toCSV() << "\n";
        file.close();
        std::cout << "Data saved to database.\n\n" << std::endl;
    }else{
        std::cerr << "Unable to save file.\n\n" << std::endl;
    }
    }
}
