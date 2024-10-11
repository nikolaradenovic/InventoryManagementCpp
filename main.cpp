#include <iostream>
#include <limits>
#include "classes/shirt.h"
#include "classes/perishableFood.h"
#include "classes/nonPerishableFood.h"
#include "classes/food.h"
#include "classes/item.h"
#include "addItem.h"
#include "console.h"
#include "addItem.h"

int main() {
    std::vector<Item*> item_array; //vektor koji sadrzi sve item-e
    //bool loadFromCSV(std::vector<Item*> &item_array);
    loadFromCSV(item_array);
    int choice, itemChoice, foodChoice, clothesChoice, electronicsChoice, success;

    while (true) {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "Invalid input. Please enter a number." << std::endl;
            continue; 
        }
        
    switch (choice) {
    case 1: 
        showItemMenu();
        if (!(std::cin >> itemChoice)) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "Invalid input. Please enter a number." << std::endl;
            continue; 
        }
        switch(itemChoice) {
            case 1:
                showFoodMenu();
                if (!(std::cin >> foodChoice)) {
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cerr << "Invalid input. Please enter a number." << std::endl;
                    continue; 
                }
                switch(foodChoice) {
                    case 1:
                        addPerishableFood(item_array);
                        break;
                    case 2:
                        addNonPerishableFood(item_array);
                        break;
                    default:
                        std::cerr << "Invalid food choice." << std::endl;
                        continue;       
                }
                break;
            case 2:
                showClothingMenu();
                if (!(std::cin >> clothesChoice)) {
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cerr << "Invalid input. Please enter a number." << std::endl;
                    continue; 
                }
                switch(clothesChoice){
                    case 1:
                        addShirt(item_array);
                        break;
                    case 2:
                        addPants(item_array);
                        break;
                }
                break;
            case 3:
                showElectronicsMenu();
                if (!(std::cin >> electronicsChoice)) {
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cerr << "Invalid input. Please enter a number." << std::endl;
                    continue; 
                }
                switch(electronicsChoice){
                    case 1:
                        addPhone(item_array);
                        break;
                    case 2:
                        addTelevision(item_array);
                        break;
                break;

            default:
                std::cerr << "Invalid item choice." << std::endl;
                continue; 
        }
    }

        break;
            case 2:
                viewItems(item_array);
                break;
            case 3:
                int targetId;
                std::cout<<"Which item would you like to edit? Enter its ID:  ";
                std::cin>> targetId ;
                for(Item* item : item_array){
                    if (item->getId() == targetId){
                        item->updateItem(*item);
                    }
                }
                break;
            case 4:
                deleteItem(item_array);
                break;
            case 5:
                saveChanges(item_array);
                break;
            case 6:
                std::cout << "Exiting program.\n";
                return 0;  
            default:
            std::cerr << "Invalid choice." << std::endl;
            continue;
        }
    }

}

