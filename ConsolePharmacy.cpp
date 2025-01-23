#include <iostream>
#include <vector>
#include "Medicine.h"
#include "Customer.h"
#include "Prescription.h"
#include "Employee.h"
#include "Sale.h"

void displayMainMenu();
void handleAddSale(std::vector<Medicine>& medicines, Customer& customer);
void handleDisplayPrescription(const Prescription& prescription);
void handleAddEmployee(std::vector<Employee>& employees);
void handleDisplayAllMedicines(const std::vector<Medicine>& medicines);

int main() {

    setlocale(LC_ALL, "Russian");
    std::vector<Medicine> medicines = {
        Medicine("Аспирин", "Рохфахам", 5.99, 100, "2026-01-01"),
        Medicine("Парацетамол", "Генеральфарма", 3.49, 150, "2027-01-01")
    };

    Customer customer("Иван Иванов", "+79001234567", "Москва, ул. Ленина, д. 1");

    Prescription prescription("PR001", customer, medicines, "Доктор Петров", "2023-10-01");

    std::vector<Employee> employees;

    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            handleAddSale(medicines, customer);
            break;
        case 2:
            handleDisplayPrescription(prescription);
            break;
        case 3:
            handleAddEmployee(employees);
            break;
        case 4:
            handleDisplayAllMedicines(medicines);
            break;
        case 5:
            std::cout << "Выход из системы.\n";
            break;
        default:
            std::cerr << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);

    return 0;
}

void displayMainMenu() {
    std::cout << "\n--- Система управления аптекой ---\n";
    std::cout << "1. Добавить продажу\n";
    std::cout << "2. Просмотреть рецепт\n";
    std::cout << "3. Добавить сотрудника\n";
    std::cout << "4. Показать все лекарства\n";
    std::cout << "5. Выйти\n";
    std::cout << "Выберите вариант: ";
}

void handleAddSale(std::vector<Medicine>& medicines, Customer& customer) {
    Sale sale(customer);
    int choice;
    while (true) {
        std::cout << "\nДоступные лекарства:\n";
        for (size_t i = 0; i < medicines.size(); ++i) {
            std::cout << i + 1 << ". ";
            medicines[i].displayInfo();
        }
        std::cout << "Введите номер лекарства для добавления в продажу (0 для завершения): ";
        std::cin >> choice;
        if (choice == 0) break;
        if (choice < 1 || choice > medicines.size()) {
            std::cerr << "Неверный выбор. Попробуйте снова.\n";
            continue;
        }
        int quantity;
        std::cout << "Введите количество: ";
        std::cin >> quantity;
        try {
            sale.addItem(medicines[choice - 1], quantity);
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << "\n";
        }
    }
    sale.displayReceipt();
}

void handleDisplayPrescription(const Prescription& prescription) {
    prescription.displayPrescription();
}

void handleAddEmployee(std::vector<Employee>& employees) {
    std::string name, position;
    double salary;
    std::cin.ignore(); // Clear input buffer
    std::cout << "Введите имя сотрудника: ";
    std::getline(std::cin, name);
    std::cout << "Введите должность: ";
    std::getline(std::cin, position);
    std::cout << "Введите зарплату: ";
    std::cin >> salary;
    employees.emplace_back(name, position, salary);
    std::cout << "Сотрудник успешно добавлен.\n";
}

void handleDisplayAllMedicines(const std::vector<Medicine>& medicines) {
    for (const auto& medicine : medicines) {
        medicine.displayInfo();
    }
}