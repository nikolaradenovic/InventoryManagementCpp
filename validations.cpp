#include <iostream>
#include <limits>
#include "validations.h"

#ifndef VALIDATIONS_H
#define VALIDATIONS_H

bool isNumeric(const std::string& str) {
    if (str.empty()) return false;

    bool hasDecimalPoint = false;
    
    for (size_t i = 0; i < str.size(); ++i) { // da li su u stringu sve cifre i/ili tacno jedna . za decimale
        if (str[i] == '.') {
            if (hasDecimalPoint) {
                return false;
            }
            hasDecimalPoint = true;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }

    int inputNum = std::stoi(str);
    if(inputNum <= 0){ //cijena mora biti veca od nule
        return false;
    }
    
    return true;
}

bool isValidDate(const std::string &date){ //format: YYYY-MM-DD

    if(!(date.length() == 10 && //provjera osnovnog formata
       date[0] == '2' && 
       date[1] == '0' && 
       std::isdigit(date[2]) && 
       std::isdigit(date[3]) &&
       date[4] == '-' &&
       std::isdigit(date[5]) && 
       std::isdigit(date[6]) &&
       date[7] == '-' &&
       std::isdigit(date[8]) && 
       std::isdigit(date[9])
       )){
        return false;
       }

    std::string YYYYstr = date.substr(0, 4); //YYY
    std::string MMstr = date.substr(5, 2); // MM
    std::string DDstr = date.substr(8, 2); // DD
    int YYYY = std::stoi(YYYYstr);
    int MM = std::stoi(MMstr);
    int DD = std::stoi(DDstr);

    if(!(MM >= 1 && MM <= 12)){ //probjera vrijednosti mjeseca
        return false;
    }
    
    switch(MM){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(!(DD >= 1 && DD <= 31)){
                return false;
            }
            break;
        
        case 4:
        case 6:
        case 9:
        case 11:
            if(!(DD >= 1 && DD <= 30)){
                return false;
            }
            break;

        case 2:
            if (YYYY % 4 == 0 && (YYYY % 100 != 0 || YYYY % 400 == 0)){ //ako je godina prestupna
                if(!(DD >= 1 && DD <= 29)){
                    return false;
                }
            }else{
                if(!(DD >= 1 && DD <= 28)){
                    return false;
                }
            }
            break;
        default: return false;
    }
    return true;
}



#endif