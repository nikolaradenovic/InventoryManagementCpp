#include "clothing.h"

Clothing::Clothing(const std::string &name, const std::string &desc, double price, const std::string &dateAcquired, const std::string &size, const std::string &type) :
    Item::Item(name, desc, price, dateAcquired), size(size), type(type){
        count ++;
    };

Clothing::~Clothing(){
    count --;
};

//setteri
/*
void Clothing::setSize(std::string newSize){
    size = newSize;
}

void Clothing::setType(std::string newType){
    type = newType;
}

//getteri

std::string Clothing::getSize(){
    return size;
}

std::string Clothing::getType(){
    return type;
}
*/