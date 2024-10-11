#include "electronics.h"

class Phone : public  Electronics{
    protected:
    double batteryLife;
    std::string brand;

    public:
    void setPowerConsumption(double newPowerConsumption) override;
    void setWarrantyPeriod(double newWarrantyPeriod) override;
    void setBatteryLife(double newBatteryLife) override;
    void setBrand(std::string brand) override;

    double getPowerConsumption() override;
    double getWarrantyPeriod() override;
    double getBatteryLife() override;
    std::string getBrand() override;

    Phone(const std::string& name, const std::string& desc, double price, const std::string &dateAcquired, const double &powerConsumption, const double &warrantyPeriod, const double &batteryLife, const std::string &brand);
    ~Phone();

    void updateItem(Item &item) override;

    void displayItem() const override;
    std::string toCSV() const;
    void saveToCSV(const std::vector<Item*>& item_array) const;
};