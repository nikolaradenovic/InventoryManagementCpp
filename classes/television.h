#include "electronics.h"

class Television : public  Electronics{
    protected:
    double screenSize;
    bool isSmart;

    public:
    void setPowerConsumption(double newPowerConsumption) override;
    void setWarrantyPeriod(double newWarrantyPeriod) override;
    void setScreenSize(double newScreenSize) override;
    void setIsSmart(bool newIsSmart) override;

    double getPowerConsumption() override;
    double getWarrantyPeriod() override;
    double getScreenSize() override;
    bool getIsSmart() override;

    Television(const std::string& name, const std::string& desc, double price, const std::string &dateAcquired, const double &powerConsumption, const double &warrantyPeriod, const double &screenSize, const bool &isSmart);
    ~Television();

    void updateItem(Item &item) override;

    void displayItem() const override;

    std::string toCSV() const;
    void saveToCSV(const std::vector<Item*>& item_array) const;
};