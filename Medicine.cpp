#include "Medicine.h"
#include <stdexcept>
#include <iostream>

Medicine::Medicine(const std::string& name, const std::string& manufacturer, double price, int stockQuantity, const std::string& expirationDate)
    : name(name), manufacturer(manufacturer), price(price), stockQuantity(stockQuantity), expirationDate(expirationDate) {
}

std::string Medicine::getName() const {
    return name;
}

void Medicine::setName(const std::string& newName) {
    name = newName;
}

double Medicine::getPrice() const {
    return price;
}

void Medicine::setPrice(double newPrice) {
    if (newPrice < 0) throw std::invalid_argument("Цена не может быть отрицательной.");
    price = newPrice;
}

int Medicine::getStockQuantity() const {
    return stockQuantity;
}

void Medicine::updateStock(int amount) {
    if (stockQuantity + amount < 0) throw std::out_of_range("Недостаточное количество на складе.");
    stockQuantity += amount;
}

bool Medicine::isExpired() const {
    return expirationDate < "2025-01-01"; // Упрощённая проверка
}

void Medicine::displayInfo() const {
    std::cout << "Лекарство: " << name << "\nПроизводитель: " << manufacturer
        << "\nЦена: $" << price << "\nКоличество на складе: " << stockQuantity
        << "\nСрок годности: " << expirationDate << "\n";
}