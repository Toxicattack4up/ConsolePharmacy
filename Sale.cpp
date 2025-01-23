#include "Sale.h"
#include <stdexcept>
#include <iostream>

Sale::Sale(const Customer& customer) : customer(customer), totalPrice(0.0) {}

void Sale::addItem(Medicine& medicine, int quantity) {
    if (quantity <= 0) throw std::invalid_argument("���������� ������ ���� �������������.");
    medicine.updateStock(-quantity);
    itemsSold.push_back({ medicine, quantity });
    totalPrice += medicine.getPrice() * quantity;
}

double Sale::calculateTotalPrice() const {
    return totalPrice;
}

void Sale::displayReceipt() const {
    std::cout << "\n--- ��������� � ������� ---\n";
    customer.displayInfo();
    for (const auto& item : itemsSold) {
        std::cout << item.first.getName() << " x" << item.second << " @ $" << item.first.getPrice() << " �� �����\n";
    }
    std::cout << "����� �����: $" << totalPrice << "\n";
}