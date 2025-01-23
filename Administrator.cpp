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
    std::cout << "������� �������� ���������: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "������� �������������: ";
    std::getline(std::cin, manufacturer);
    std::cout << "������� ����: ";
    std::cin >> price;
    std::cout << "������� ���������� �� ������: ";
    std::cin >> stockQuantity;
    std::cout << "������� ���� �������� (YYYY-MM-DD): ";
    std::cin >> expirationDate;
    std::cout << "��������� ������ (y/n): ";
    char prescReq;
    std::cin >> prescReq;
    prescriptionRequired = (prescReq == 'y');

    Medicine medicine(name, manufacturer, price, stockQuantity, expirationDate, prescriptionRequired);
    medicineStorage.addMedicine(medicine);
    std::cout << "��������� ������� ���������.\n";
}

void Administrator::removeMedicine() {
    std::string name;
    std::cout << "������� �������� ��������� ��� ��������: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    medicineStorage.removeMedicine(name);
    std::cout << "��������� ������� �������.\n";
}

void Administrator::displayAllMedicines() {
    medicineStorage.displayAllMedicines();
}

void Administrator::addEmployee() {
    std::string username, password, position;
    double salary;
    std::cout << "������� ��� ������������: ";
    std::cin.ignore();
    std::getline(std::cin, username);
    std::cout << "������� ������: ";
    std::getline(std::cin, password);
    std::cout << "������� ���������: ";
    std::getline(std::cin, position);
    std::cout << "������� ��������: ";
    std::cin >> salary;
    medicineStorage.getEmployees().emplace_back(username, hashPassword(password), position, salary);
    std::cout << "��������� ������� ��������.\n";
    medicineStorage.saveToFile();
}

void Administrator::removeEmployee() {
    std::string username;
    std::cout << "������� ��� ������������ ��� ��������: ";
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
    std::cout << "�������������: " << getUsername() << "\n���: " << getType() << "\n";
}