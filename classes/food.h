#include "item.h"
#ifndef FOOD_H
#define FOOD_H

class Food : public Item{
    protected:
        std::string dateProduced;
        std::string category; //voce, povrce, meso...
        bool perishable;

        static int count;

    public:
        Food(const std::string& name, const std::string& desc, double price, const std::string &dateAcquired, const std::string &dateProduced, const std::string &category);
        ~Food() override;
        

};
#endif