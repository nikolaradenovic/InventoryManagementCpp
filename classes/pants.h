#include "clothing.h"
#include <string>

class Pants : public Clothing{
protected:
std::string pantsFitType;
std::string pantsMaterial;

public:
Pants(const std::string &name, const std::string &desc, double price, const std::string &dateAcquired, const std::string &size, const std::string &type, const std::string &pantsFitType, const std::string &pantsMaterial);
~Pants() override;

void setPantsFitType(std::string newPantsFitType) override;
void setPantsMaterial(std::string newPantsMaterial) override;

std::string getPantsFitType() override;
std::string getPantsMaterial() override;

void updateItem(Item &item) override;

void displayItem() const override;

std::string toCSV() const override;
void saveToCSV(const std::vector<Item*>& item_array) const override;

};