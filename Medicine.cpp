#include "Medicine.h"
#include <stdexcept>
#include <iostream>

Medicine::Medicine(const std::string& name, const std::string& manufacturer, double price, int stockQuantity, const std::string& expirationDate, bool prescriptionRequired)
    : name(name), manufacturer(manufacturer), price(price), stockQuantity(stockQuantity), expirationDate(expirationDate), prescriptionRequired(prescriptionRequired) {
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
    if (newPrice < 0) throw std::invalid_argument("���� �� ����� ���� �������������.");
    price = newPrice;
}

int Medicine::getStockQuantity() const {
    return stockQuantity;
}

void Medicine::updateStock(int amount) {
    if (stockQuantity + amount < 0) throw std::out_of_range("������������� ���������� �� ������.");
    stockQuantity += amount;
}

bool Medicine::isExpired() const {
    return expirationDate < "2025-01-01"; // ���������� ��������
}

bool Medicine::isPrescriptionRequired() const {
    return prescriptionRequired;
}

void Medicine::setPrescriptionRequired(bool required) {
    prescriptionRequired = required;
}

void Medicine::displayInfo() const {
    std::cout << "���������: " << name << "\n�������������: " << manufacturer
        << "\n����: $" << price << "\n���������� �� ������: " << stockQuantity
        << "\n���� ��������: " << expirationDate
        << "\n��������� ������: " << (prescriptionRequired ? "��" : "���") << "\n";
}

std::string Medicine::getManufacturer() const {
    return manufacturer;
}

std::string Medicine::getExpirationDate() const {
    return expirationDate;
}