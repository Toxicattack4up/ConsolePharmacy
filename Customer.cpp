#include "Customer.h"
#include <stdexcept>
#include <iostream>

Customer::Customer(const std::string& name, const std::string& phoneNumber, const std::string& address)
    : name(name), phoneNumber(phoneNumber), address(address) {
}

std::string Customer::getName() const {
    return name;
}

void Customer::setName(const std::string& newName) {
    name = newName;
}

std::string Customer::getPhoneNumber() const {
    return phoneNumber;
}

void Customer::setPhoneNumber(const std::string& newPhoneNumber) {
    if (newPhoneNumber.empty()) throw std::invalid_argument("Номер телефона не может быть пустым.");
    phoneNumber = newPhoneNumber;
}

void Customer::displayInfo() const {
    std::cout << "Клиент: " << name << "\nТелефон: " << phoneNumber << "\nАдрес: " << address << "\n";
}