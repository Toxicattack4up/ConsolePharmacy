#ifndef SALE_H
#define SALE_H

#include <vector>
#include <utility>
#include "Medicine.h"
#include "Customer.h"

class Sale {
private:
    std::vector<std::pair<Medicine, int>> itemsSold;
    Customer customer;
    double totalPrice;

public:
    Sale(const Customer& customer);
    void addItem(Medicine& medicine, int quantity);
    double calculateTotalPrice() const;
    void displayReceipt() const;
};

#endif // SALE_H