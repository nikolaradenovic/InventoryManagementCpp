#include "item.h"
#ifndef ELECTRONICS_H
#define ELECTRONICS_H

class Electronics : public Item{
    protected:
    double powerConsumption;
    double warrantyPeriod;

    public:
    /*
    void setPowerConsumption(double newPowerConsumption) override;
    void setWarrantyPeriod(double newWarrantyPeriod) override;

    double getPowerConsumption() override;
    double getWarrantyPeriod() override;
    */

    Electronics(const std::string& name, const std::string& desc, double price, const std::string &dateAcquired, const double &powerConsumption, const double &warrantyPeriod);
    ~Electronics();
};

#endif