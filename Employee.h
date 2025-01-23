#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string name;
    std::string position;
    double salary;

public:
    Employee(const std::string& name, const std::string& position, double salary);
    std::string getName() const;
    void setName(const std::string& newName);
    std::string getPosition() const;
    void setPosition(const std::string& newPosition);
    double getSalary() const;
    void setSalary(double newSalary);
    void displayInfo() const;
};

#endif // EMPLOYEE_H