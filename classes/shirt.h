#include "clothing.h"
#include <string>

class Shirt : public Clothing{
protected:
std::string shirtColor;
std::string sleeveLength;

public:
Shirt(const std::string &name, const std::string &desc, double price, const std::string &dateAcquired, const std::string &size, const std::string &type, const std::string &shirtColor, const std::string &sleeveLength);
~Shirt() override;

void setShirtColor(std::string newColor) override;
void setSleeveLength(std::string newSleeveLength) override;

std::string getShirtColor() override;
std::string getSleeveLength() override;

void updateItem(Item &item) override;

void displayItem() const override;

std::string toCSV() const override;
void saveToCSV(const std::vector<Item*>& item_array) const override;

};