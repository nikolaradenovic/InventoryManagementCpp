#include "food.h"
#pragma once
class NonPerishableFood : public Food{
    protected:
        static int count;
        std::string preservationMethod;
        
    public:
        void displayItem() const override;
        void saveToCSV(const std::vector<Item*>& item_array) const override;
        std::string toCSV() const override; 

        void setDateProduced(std::string newDateProduced) override;
        void setCategory(std::string newCategory) override;
        void setPreservationMethod(std::string newPreservationMethod);

        std::string getDateProduced() const;
        std::string getCategory() const override;
        std::string getPreservationMethod() const;

        void updateItem(Item &item) override;
        NonPerishableFood(const std::string& name, const std::string& desc, double price,const std::string dateAcquired, const std::string &dateProduced, const std::string &category, std::string preservationMethod);
        ~NonPerishableFood() override;


};