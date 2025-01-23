#include "medicine_storage.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include "utils.h"

MedicineStorage::MedicineStorage() {
    loadEmployees();

    std::ifstream file("medicines.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> parts = splitString(line, ';');
            if (parts.size() == 6) {
                Medicine medicine(parts[0], parts[1], std::stod(parts[2]), std::stoi(parts[3]), parts[4], parts[5] == "true");
                medicines.push_back(medicine);
            }
        }
        file.close();
    }
}

void MedicineStorage::addMedicine(const Medicine& medicine) {
    medicines.push_back(medicine);
    saveToFile();
}

void MedicineStorage::removeMedicine(const std::string& name) {
    medicines.erase(std::remove_if(medicines.begin(), medicines.end(),
        [&name](const Medicine& m) { return m.getName() == name; }),
        medicines.end());
    saveToFile();
}

void MedicineStorage::displayAllMedicines() const {
    for (const auto& medicine : medicines) {
        medicine.displayInfo();
    }
}

std::vector<Medicine>& MedicineStorage::getMedicines() {
    return medicines;
}

void MedicineStorage::saveToFile() {
    std::ofstream file("medicines.txt");
    if (file.is_open()) {
        for (const auto& medicine : medicines) {
            file << medicine.getName() << ";"
                << medicine.getManufacturer() << ";"
                << medicine.getPrice() << ";"
                << medicine.getStockQuantity() << ";"
                << medicine.getExpirationDate() << ";"
                << (medicine.isPrescriptionRequired() ? "true" : "false") << "\n";
        }
        file.close();
    }

    std::ofstream empFile("employees.txt");
    if (empFile.is_open()) {
        for (const auto& employee : employees) {
            empFile << employee.getUsername() << ";"
                << employee.getPassword() << ";"
                << employee.getPosition() << ";"
                << employee.getSalary() << "\n";
        }
        empFile.close();
    }
}

std::vector<Employee>& MedicineStorage::getEmployees() {
    return employees;
}

void MedicineStorage::loadEmployees() {
    std::ifstream empFile("employees.txt");
    if (empFile.is_open()) {
        std::string line;
        while (std::getline(empFile, line)) {
            std::vector<std::string> parts = splitString(line, ';');
            if (parts.size() == 4) {
                Employee employee(parts[0], parts[1], parts[2], std::stod(parts[3]));
                employees.push_back(employee);
            }
        }
        empFile.close();
    }
}

void MedicineStorage::removeEmployee(const std::string& username) {
    employees.erase(std::remove_if(employees.begin(), employees.end(),
        [&username](const Employee& e) { return e.getUsername() == username; }),
        employees.end());
    saveToFile();
    std::cout << "Сотрудник успешно удален.\n";
}