#include "Employee.h"
#include <stdexcept>
#include <iostream>

Employee::Employee(const std::string& username, const std::string& password, const std::string& position, double salary)
    : User(username, password, "employee"), position(position), salary(salary) {
}

std::string Employee::getPosition() const {
    return position;
}

void Employee::setPosition(const std::string& newPosition) {
    position = newPosition;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(double newSalary) {
    if (newSalary < 0) throw std::invalid_argument("Зарплата не может быть отрицательной.");
    salary = newSalary;
}

void Employee::displayInfo() const {
    std::cout << "Сотрудник: " << getUsername() << "\nДолжность: " << position << "\nЗарплата: $" << salary << "\n";
}