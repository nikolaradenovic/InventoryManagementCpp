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
    int choice, itemChoice, foodChoice, clothesChoice, electronicsChoice, searchAndFilterChoice, searchCHoice, success;

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
                searchAndFilterMenu(); 
                if (!(std::cin >> searchAndFilterChoice)) {
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cerr << "Invalid input. Please enter a number." << std::endl;
                    continue; 
                }
                switch (searchAndFilterChoice){
                    case 1:
                        searchMenu();
                        if (!(std::cin >> searchCHoice)) {
                            std::cin.clear(); 
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                            std::cerr << "Invalid input. Please enter a number." << std::endl;
                            continue; 
                        }
                        switch(searchCHoice){
                            case 1:
                                searchByItemID(item_array);
                                break;
                            case 2:
                                searchByName(item_array);
                                break;
                            case 3:
                                searchByDescription(item_array);
                                break;
                            case 4:
                                searchByPrice(item_array);
                                break;
                            }

                        break;
                        
                    case 2:

                        break;
                }
                break;
            case 7:
                std::cout << "Exiting program.\n";
                return 0;  
            default:
            std::cerr << "Invalid choice." << std::endl;
            continue;
        }
    }
system("pause");
}

/*
1. Search and Filter Functionality
Implement search and filtering capabilities that allow the user to:

Search for items by name, category, or other attributes.
Filter items by date range (e.g., show items acquired between two dates) or price range.
Sort items by attributes (e.g., by price, date acquired, or expiration date).
How it enhances your project: This demonstrates data manipulation skills and makes your inventory system more useful in real-world scenarios.

Sample interface:

markdown
Copy code
1. Search items
2. Filter items by date
3. Filter items by price
4. Sort items
2. Backup and Restore
Implement a feature to backup CSV files (either manually or automatically) to a separate directory.
Add a restore feature that allows the user to load a previous backup of their inventory in case of errors or accidental deletions.
How it enhances your project: Shows you understand the importance of data integrity and handling unexpected user errors.

Sample interface:

kotlin
Copy code
1. Backup data
2. Restore data from backup
3. Reports and Analytics
Add a reporting feature that can generate summaries, such as:
Total number of items in the inventory.
Total value of all items.
Count of items per category.
For perishable items: how many are about to expire in the next X days.
How it enhances your project: This adds a data analysis aspect, showing you can provide insights from raw data, which is valuable in real-world applications.

Sample interface:

markdown
Copy code
1. View total items
2. View total inventory value
3. View items by category
4. View expiring items
4. User Authentication and Role Management
Add basic user authentication and roles:

Different users (e.g., admin vs viewer) can have different levels of access to the system.
For example, admins can add/edit/delete items, while viewers can only view or search the inventory.
How it enhances your project: It demonstrates an understanding of access control, which is important in any application dealing with data modification.

Sample interface:

csharp
Copy code
1. Log in as Admin
2. Log in as Viewer
5. Automated Expiry Check
Add a feature that automatically checks for any perishable items that are past their expiration date or will expire soon.
Provide a notification or warning when the user logs in if any items need attention.
How it enhances your project: Adds real-world utility and demonstrates automation logic.

Sample interface:

csharp
Copy code
[Warning] 2 items are expiring in the next 3 days.
6. Customizable Settings
Allow the user to change certain settings such as default file paths, backup frequency, or the time interval for automatic expiry checks.
Store these settings in a simple configuration file (e.g., JSON or XML).
How it enhances your project: Shows that your system is flexible and customizable, giving the user control over the environment.

Sample interface:

javascript
Copy code
1. Set backup frequency
2. Set default CSV file path
7. Command-Line Arguments
Enable the program to take command-line arguments for things like specifying the CSV file, automatically running a report, or loading a specific backup without opening the full menu.
How it enhances your project: Adds flexibility for power users and shows your ability to work with command-line interfaces.

Example:

bash
Copy code
./inventory_management --report total_items
./inventory_management --load backup.csv
8. Improved Error Handling
Implement better error handling and logging so that any issues (like failing to read/write files, invalid data formats, or failed operations) get logged to a file with a timestamp for debugging purposes.
How it enhances your project: Shows you understand the importance of robust error handling in production-level software.

9. Unit Testing
Write unit tests for your core functions, particularly the validation, CSV parsing, and object creation functions.
Use a testing framework like Google Test for C++.
How it enhances your project: Shows a commitment to code quality and reliability, which is highly valued in the industry.

Bonus: You can also integrate Continuous Integration (CI) with a platform like GitHub Actions to automatically run tests whenever new code is pushed.
*/