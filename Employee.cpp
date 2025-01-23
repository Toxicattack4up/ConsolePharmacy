#include "Employee.h"
#include <stdexcept>
#include <iostream>

Employee::Employee(const std::string& name, const std::string& position, double salary)
    : name(name), position(position), salary(salary) {
}

std::string Employee::getName() const {
    return name;
}

void Employee::setName(const std::string& newName) {
    name = newName;
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
    std::cout << "Сотрудник: " << name << "\nДолжность: " << position << "\nЗарплата: $" << salary << "\n";
}