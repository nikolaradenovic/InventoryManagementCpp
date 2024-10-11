#include "food.h"
#pragma once
class PerishableFood : public Food{
    
    public:
        PerishableFood(const std::string& name, const std::string& desc, double price,const std::string dateAcquired, const std::string &dateOfExpiry, const std::string &dateProduced, const std::string &category, const bool expired);
        ~PerishableFood() override;

        void displayItem() const override;

        void setDateOfExpiry(std::string newDateOfExpiry) override;
        void setDateProduced(std::string newDateProduced) override;
        void setCategory(std::string newCategory) override;
        void setExpired(bool newExpired);

        std::string getDateOfExpiry() const;
        std::string getDateProduced() const;
        std::string getCategory() const override;
        bool getExpired() const;

        void updateItem(Item &item) override;
        void saveToCSV(const std::vector<Item*>& item_array) const override;
        std::string toCSV() const override; 

    protected:
        bool expired;
        static int count;
        std::string dateOfExpiry;
    
};