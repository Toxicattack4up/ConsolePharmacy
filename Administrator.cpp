#include "Administrator.h"
#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"

Administrator::Administrator(const std::string& username, const std::string& password)
    : User(username, password, "admin") {
}

void Administrator::addMedicine() {
    std::string name, manufacturer, expirationDate;
    double price;
    int stockQuantity;
    bool prescriptionRequired;
    std::cout << "¬ведите название лекарства: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "¬ведите производител€: ";
    std::getline(std::cin, manufacturer);
    std::cout << "¬ведите цену: ";
    std::cin >> price;
    std::cout << "¬ведите количество на складе: ";
    std::cin >> stockQuantity;
    std::cout << "¬ведите срок годности (YYYY-MM-DD): ";
    std::cin >> expirationDate;
    std::cout << "“ребуетс€ рецепт (y/n): ";
    char prescReq;
    std::cin >> prescReq;
    prescriptionRequired = (prescReq == 'y');

    Medicine medicine(name, manufacturer, price, stockQuantity, expirationDate, prescriptionRequired);
    medicineStorage.addMedicine(medicine);
    std::cout << "Ћекарство успешно добавлено.\n";
}

void Administrator::removeMedicine() {
    std::string name;
    std::cout << "¬ведите название лекарства дл€ удалени€: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    medicineStorage.removeMedicine(name);
    std::cout << "Ћекарство успешно удалено.\n";
}

void Administrator::displayAllMedicines() {
    medicineStorage.displayAllMedicines();
}

void Administrator::addEmployee() {
    std::string username, password, position;
    double salary;
    std::cout << "¬ведите им€ пользовател€: ";
    std::cin.ignore();
    std::getline(std::cin, username);
    std::cout << "¬ведите пароль: ";
    std::getline(std::cin, password);
    std::cout << "¬ведите должность: ";
    std::getline(std::cin, position);
    std::cout << "¬ведите зарплату: ";
    std::cin >> salary;
    medicineStorage.getEmployees().emplace_back(username, hashPassword(password), position, salary);
    std::cout << "—отрудник успешно добавлен.\n";
    medicineStorage.saveToFile();
}

void Administrator::removeEmployee() {
    std::string username;
    std::cout << "¬ведите им€ пользовател€ дл€ удалени€: ";
    std::cin.ignore();
    std::getline(std::cin, username);
    medicineStorage.removeEmployee(username);
}

void Administrator::displayAllEmployees() {
    for (const auto& employee : medicineStorage.getEmployees()) {
        employee.displayInfo();
    }
}

MedicineStorage& Administrator::getMedicineStorage() {
    return medicineStorage;
}

void Administrator::displayInfo() const {
    std::cout << "јдминистратор: " << getUsername() << "\n“ип: " << getType() << "\n";
}