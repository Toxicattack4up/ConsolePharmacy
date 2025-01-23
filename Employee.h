#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "User.h"

class Employee : public User {
private:
    std::string position;
    double salary;

public:
    Employee(const std::string& username, const std::string& password, const std::string& position, double salary);
    std::string getPosition() const;
    void setPosition(const std::string& newPosition);
    double getSalary() const;
    void setSalary(double newSalary);
    void displayInfo() const override; // Переопределение чисто виртуальной функции
};

#endif // EMPLOYEE_H