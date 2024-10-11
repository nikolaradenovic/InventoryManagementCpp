#include "food.h"
#include <iostream>

int Food::count = 0;
Food::Food(const std::string& name, const std::string& desc, double price, const std::string &dateAcquired, const std::string &dateProduced, const std::string &category)
    : Item(name, desc, price, dateAcquired), dateProduced(dateProduced), category(category){
        count++;
    };

Food::~Food(){
    count--;
}
