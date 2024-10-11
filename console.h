#include <vector>

void deleteItem(std::vector<Item*> &item_array);
void viewItems(std::vector<Item*> &item_array);
void showMenu();
void showItemMenu();
void showFoodMenu();
void showClothingMenu();
void showElectronicsMenu();
void saveChanges(std::vector<Item*> &item_array);
bool loadFromCSV(std::vector<Item*> &item_array);