#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string phoneNumber;
    std::string address;

public:
    Customer(const std::string& name, const std::string& phoneNumber, const std::string& address);
    std::string getName() const;
    void setName(const std::string& newName);
    std::string getPhoneNumber() const;
    void setPhoneNumber(const std::string& newPhoneNumber);
    void displayInfo() const;
};

#endif // CUSTOMER_H