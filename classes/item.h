#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#ifndef ITEM_H
#define ITEM_H
#pragma once
class Item{
    protected:
    int itemID;
    int static current_id;
    std::string name;
    std::string description;
    double price;
    std::string dateAcquired; //datum nabavke

    static int count;

    public:
        Item(const std::string &name, const std::string &desc, double price, const std::string &dateAcquired);
        virtual ~Item(); 
        static std::vector<Item*> item_array;
        
        virtual void setName(std::string newName); 
        virtual void setDescription(std::string newDesc);
        virtual void setPrice(double newPrice);
        virtual void setDateAcquired(std::string newDateAcquired);

        virtual void setDateOfExpiry(std::string newDateOfExpiry);
        virtual void setDateProduced(std::string newDateProduced);
        virtual void setCategory(std::string newCategory); 
        virtual void setExpired(bool newExpired);
        virtual void setPreservationMethod(std::string newPreservationMethod);

        virtual void setSize(std::string newSize);
        virtual void setType(std::string newType);
        virtual void setShirtColor(std::string newColor);
        virtual void setSleeveLength(std::string newSleeveLength);
        virtual void setPantsFitType(std::string newPantsFitType);
        virtual void setPantsMaterial(std::string newPantsMaterial);

        virtual void setPowerConsumption(double newPowerConsumption);
        virtual void setWarrantyPeriod(double newWarrantyPeriod);
        virtual void setBatteryLife(double newBatteryLife);
        virtual void setBrand(std::string brand);
        virtual void setScreenSize(double newScreenSize);
        virtual void setIsSmart(bool newIsSmart);

        virtual int getId() const;
        virtual std::string getName() const;
        virtual std::string getDescription() const;
        virtual double getPrice() const;
        virtual std::string getDateAcquired() const;

        virtual std::string getDateOfExpiry() const;
        virtual std::string getDateProduced() const;
        virtual std::string getCategory() const ; 
        virtual bool getExpired();
        virtual std::string getPreservationMethod() const;

        virtual std::string getSize();
        virtual std::string getType();
        virtual std::string getShirtColor();
        virtual std::string getSleeveLength();
        virtual std::string getPantsFitType();
        virtual std::string getPantsMaterial();

        virtual double getPowerConsumption();
        virtual double getWarrantyPeriod();
        virtual double getBatteryLife();
        virtual std::string getBrand();
        virtual double getScreenSize();
        virtual bool getIsSmart();


        int getCurrent_Id() const;
        
        virtual void updateItem(Item &item) = 0;


        virtual void displayItem() const = 0;
        virtual void saveToCSV(const std::vector<Item*>& item_array) const = 0;
        virtual std::string toCSV() const = 0;



};
#endif