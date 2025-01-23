#ifndef MEDICINE_H
#define MEDICINE_H

#include <string>

class Medicine {
private:
    std::string name;
    std::string manufacturer;
    double price;
    int stockQuantity;
    std::string expirationDate;

public:
    Medicine(const std::string& name, const std::string& manufacturer, double price, int stockQuantity, const std::string& expirationDate);
    std::string getName() const;
    void setName(const std::string& newName);
    double getPrice() const;
    void setPrice(double newPrice);
    int getStockQuantity() const;
    void updateStock(int amount);
    bool isExpired() const;
    void displayInfo() const;
};

#endif // MEDICINE_H