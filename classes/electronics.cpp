#include "electronics.h"

Electronics::Electronics(const std::string& name, const std::string& desc, double price, const std::string &dateAcquired, const double &powerConsumption, const double &warrantyPeriod)
    : Item(name, desc, price, dateAcquired), powerConsumption(powerConsumption), warrantyPeriod(warrantyPeriod){
        count ++;
    }
Electronics::~Electronics(){
    count --;
}
/*
void Electronics::setPowerConsumption(double newPowerConsumption){
    powerConsumption = newPowerConsumption;
}
void Electronics::setWarrantyPeriod(double newWarrantyPeriod){
    warrantyPeriod = newWarrantyPeriod;
}

double Electronics::getPowerConsumption(){
    return powerConsumption;
}
double Electronics::getWarrantyPeriod(){
    return warrantyPeriod;
}

*/