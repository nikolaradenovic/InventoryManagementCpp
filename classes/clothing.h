#include "item.h"
#include "item.h"
#ifndef CLOTHING_H
#define CLOTHING_H

class Clothing : public Item{

    protected:
    std::string size; //xs,s,m,l,xl,xxl
    std::string type; //majice, pantalone, jakne

    public:
    Clothing(const std::string &name, const std::string &desc, double price, const std::string &dateAcquired, const std::string &size, const std::string &type);
    ~Clothing() override;
    /*
    void setSize(std::string newSize);
    void setType(std::string newType);

    std::string getSize();
    std::string getType();
    */
};

#endif