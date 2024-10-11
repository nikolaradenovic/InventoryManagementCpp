#include "phone.h"
#include <iostream>
#include "..\validations.h"
#include <limits>

Phone::Phone(const std::string& name, const std::string& desc, double price, const std::string &dateAcquired, const double &powerConsumption, const double &warrantyPeriod, const double &batteryLife, const std::string &brand)
    : Electronics(name, desc, price, dateAcquired, powerConsumption, warrantyPeriod), batteryLife(batteryLife), brand(brand){
        count++;
    }

Phone::~Phone(){
    count --;
}

void Phone::setPowerConsumption(double newPowerConsumption){
    powerConsumption = newPowerConsumption;
}

void Phone::setWarrantyPeriod(double newWarrantyPeriod){
    warrantyPeriod = newWarrantyPeriod;
}

void Phone::setBatteryLife(double newBatteryLife){
    batteryLife = newBatteryLife;
}

void Phone::setBrand(std::string newBrand){
    brand = newBrand;
}

double Phone::getPowerConsumption(){
    return powerConsumption;
}

double Phone::getWarrantyPeriod(){
    return warrantyPeriod;
}

double Phone::getBatteryLife(){
    return batteryLife;
}

std::string Phone::getBrand(){
    return brand;
}

void Phone::displayItem() const{
    std::cout<<"Item ID:  "<<itemID<<"\nItem name:  "<<name<<"\nItem price:  "<<price<<"\nDate acquired:  "<<dateAcquired<<"\nPower consumption:  "<<powerConsumption<<"\nWarranty period:  "<<warrantyPeriod<<"\nBattery life: "<<batteryLife<<"\nBrand:   "<<brand<<"\n\nDescription:  "<<description<<"\n\n";
}

void Phone::updateItem(Item &item){
    std::string name, desc, dateAcquired, brand;
    double price, powerConsumption, warrantyPeriod, batteryLife;

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

            std::cout << "Enter warranty period: ";
            std::cin, warrantyPeriod;
            item.setWarrantyPeriod(warrantyPeriod);

            std::cout << "Enter battery life: ";
            std::cin, batteryLife;
            item.setBatteryLife(batteryLife);

            std::cout << "Enter brand: ";
            getline(std::cin,  brand);
            item.setBrand(brand);

            std::cout << "Item updated.\n";
            return;
        

    return;
}

std::string Phone::toCSV() const{
    return std::to_string(itemID) + "," + name + "," + description +  "," + std::to_string(price) + "," + dateAcquired + "," + std::to_string(powerConsumption) + "," + std::to_string(warrantyPeriod) + "," + std::to_string(batteryLife) +  "," + brand;
}

void Phone::saveToCSV(const std::vector<Item*>& item_array) const{
    std::ofstream file("csvs/phone.csv");
    
    if(file.is_open()){
        for (Item* item : item_array) {
            Phone* phoneItem = dynamic_cast<Phone*>(item);
            if (phoneItem) {
                file << phoneItem->toCSV() << "\n"; 
            }
        }
        //file << toCSV() << "\n";
        file.close();
        std::cout << "Data saved to database.\n\n" << std::endl;
    }else{
        std::cerr << "Unable to save file.\n\n" << std::endl;
    }
}

