#include "item.h"
#include <iostream>
#include <string>

int Item::count = 0;
int Item::current_id = 1;

Item::Item(const std::string &name, const std::string &desc, double price, const std::string &dateAcquired)
    : name(name), description(desc),  price(price), dateAcquired(dateAcquired){
        itemID = current_id;
        current_id++;
        count++;
    }
    
Item::~Item(){
    count--; //Item je apstraktna klasa, tako da njegov destruktor se svodi na dekrementaciju count
}

//setters

void Item::setName(std::string newName){
    name = newName;
}

void Item::setDescription(std::string newDesc){
    description = newDesc;
}

void Item::setPrice(double newPrice){
    price = newPrice;
}

void Item::setDateAcquired(std::string newDateAcquired){
    dateAcquired = newDateAcquired;
}

void Item::setPreservationMethod(std::string newPreservationMethod){
    return;
}

void Item::setExpired(bool newExpired){
    return;
}

void Item::setDateOfExpiry(std::string newDateOfExpiry){
    return;
}

void Item::setDateProduced(std::string newDateProduced){
    return;
}

void Item::setCategory(std::string newCategory){
    return;
}

void Item::setSize(std::string newSize){
    return;
}

void Item::setType(std::string newType){
    return;
}

void Item::setShirtColor(std::string newColor){
    return;
}

void Item::setSleeveLength(std::string newSleeveLength){
    return;
}

void Item::setPantsFitType(std::string newPantsFitType){
    return;
}
void Item::setPantsMaterial(std::string newPantsMaterial){
    return;
}

void Item::setPowerConsumption(double newPowerConsumption){
    return;
}

void Item::setWarrantyPeriod(double newWarrantyPeriod){
    return;
}

void Item::setBatteryLife(double newBatteryLife){
    return;
}

void Item::setBrand(std::string brand){
    return;
}

void Item::setScreenSize(double newScreenSize){
    return;
}
void Item::setIsSmart(bool newIsSmart){
    return;
}

//getters

int Item::getId() const{
    return itemID;
}

std::string Item::getName() const{
    return name;
}

std::string Item::getDescription() const{
    return description;
}

double Item::getPrice() const{
    return price;
}

std::string Item::getDateAcquired() const{
    return dateAcquired;
}

int Item::getCurrent_Id() const{
    return current_id;
}

std::string Item::getDateOfExpiry() const{
    return "";
}

bool Item::getExpired(){
    return false;
}

std::string Item::getPreservationMethod() const{
    return "";
}

std::string Item::getDateProduced() const{
    return "";
}

std::string Item::getCategory() const{
    return "";
}

std::string Item::getSize(){
    return "";
}

std::string Item::getType(){
    return "";
}

std::string Item::getShirtColor(){
    return "";
}

std::string Item::getSleeveLength(){
    return "";
}

std::string Item::getPantsFitType(){
    return "";
}

std::string Item::getPantsMaterial(){
    return "";
}

double Item::getPowerConsumption(){
    return 0;
}

double Item::getWarrantyPeriod(){
    return 0;
}

double Item::getBatteryLife(){
    return 0;
}

std::string Item::getBrand(){
    return "";
}

double Item::getScreenSize(){
    return 0;
}

bool Item::getIsSmart(){
    return 0;
}