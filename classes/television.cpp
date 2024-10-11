#include "television.h"
#include <iostream>
#include "..\validations.h"
#include <limits>

Television::Television(const std::string& name, const std::string& desc, double price, const std::string &dateAcquired, const double &powerConsumption, const double &warrantyPeriod, const double &screenSize, const bool &isSmart)
    : Electronics(name, desc, price, dateAcquired, powerConsumption, warrantyPeriod), screenSize(screenSize), isSmart(isSmart){
        count++;
    }

Television::~Television(){
    count --;
}

void Television::setPowerConsumption(double newPowerConsumption){
    powerConsumption = newPowerConsumption;
}

void Television::setWarrantyPeriod(double newWarrantyPeriod){
    warrantyPeriod = newWarrantyPeriod;
}

void Television::setScreenSize(double newScreenSize){
    screenSize = newScreenSize;
}

void Television::setIsSmart(bool newIsSmart){
    isSmart = newIsSmart;
}

double Television::getPowerConsumption(){
    return powerConsumption;
}

double Television::getWarrantyPeriod(){
    return warrantyPeriod;
}

double Television::getScreenSize(){
    return screenSize;
}

bool Television::getIsSmart(){
    return isSmart;
}

void Television::displayItem() const{
    std::cout<<"Item ID:  "<<itemID<<"\nItem name:  "<<name<<"\nItem price:  "<<price<<"\nDate acquired:  "<<dateAcquired<<"\nPower consumption:  "<<powerConsumption<<"\nWarranty period:  "<<warrantyPeriod<<"\nScreen size: "<<screenSize<<"\nIs Smart TV? (1-yes, 0-no):   "<<isSmart<<"\n\nDescription:  "<<description<<"\n\n";
}

void Television::updateItem(Item &item){
    std::string name, desc, dateAcquired, brand;
    double price, powerConsumption, warrantyPeriod, screenSize;
    bool isSmart;

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

            std::cout << "Enter power consumption: ";
            std::cin, powerConsumption;
            item.setPowerConsumption(powerConsumption);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter warranty period: ";
            std::cin, warrantyPeriod;
            item.setWarrantyPeriod(warrantyPeriod);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter screen size: ";
            std::cin, screenSize;
            item.setScreenSize(screenSize);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Is this a Smart TV? (1-yes, 0-no)? ";
            std::cin >> isSmart;
            item.setIsSmart(isSmart);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Item updated.\n";
            return;
        

    return;
}

std::string Television::toCSV() const{
    return std::to_string(itemID) + "," + name + "," + description +  "," + std::to_string(price) + "," + dateAcquired + "," + std::to_string(powerConsumption) + "," + std::to_string(warrantyPeriod) + "," + std::to_string(screenSize) +  "," + std::to_string(isSmart);
}

void Television::saveToCSV(const std::vector<Item*>& item_array) const{
    std::ofstream file("csvs/television.csv");
    
    if(file.is_open()){
        for (Item* item : item_array) {
            Television* televisionItem = dynamic_cast<Television*>(item);
            if (televisionItem) {
                file << televisionItem->toCSV() << "\n"; 
            }
        }
        //file << toCSV() << "\n";
        file.close();
        std::cout << "Data saved to database.\n\n" << std::endl;
    }else{
        std::cerr << "Unable to save file.\n\n" << std::endl;
    }
}

