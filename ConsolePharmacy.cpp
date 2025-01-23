#include <iostream>
#include <vector>
#include <windows.h>
#include "Administrator.h"
#include "Employee.h"
#include "Medicine.h"
#include "Prescription.h"
#include "Sale.h"
#include "utils.h"
#include "logger.h"

void setConsoleCP1251() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

void displayMainMenu();
void handleAdminMenu(Administrator& admin);
void handleEmployeeMenu(Employee& employee, MedicineStorage& medicineStorage);
void handleAddSale(MedicineStorage& medicineStorage, Customer& customer, Logger& logger);
void handleDisplayPrescription(const Prescription& prescription);
void handleAddEmployee(Administrator& admin);
void handleRemoveEmployee(Administrator& admin);
void handleDisplayAllMedicines(MedicineStorage& medicineStorage);
void handleLogin(Administrator& admin, MedicineStorage& medicineStorage, Logger& logger);

int main() {
    setConsoleCP1251();

    Administrator admin("admin", hashPassword("adminpass"));

    MedicineStorage medicineStorage;

    Customer customer("Иван Иванов", "+79001234567", "Москва, ул. Ленина, д. 1");

    Prescription prescription("PR001", customer, medicineStorage.getMedicines(), "Доктор Петров", "2023-10-01");

    Logger logger("log.txt");

    while (true) {
        handleLogin(admin, medicineStorage, logger);
    }

    return 0;
}

void displayMainMenu() {
    std::cout << "\n--- Система управления аптекой ---\n";
    std::cout << "1. Войти как администратор\n";
    std::cout << "2. Войти как сотрудник\n";
    std::cout << "3. Выйти\n";
    std::cout << "Выберите вариант: ";
}

void handleLogin(Administrator& admin, MedicineStorage& medicineStorage, Logger& logger) {
    int choice;
    std::string username, password;
    std::vector<Employee>& employees = medicineStorage.getEmployees();
    bool found = false;

    displayMainMenu();
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
    case 1:
        std::cout << "Введите имя пользователя (администратор): ";
        std::getline(std::cin, username);
        std::cout << "Введите пароль: ";
        std::getline(std::cin, password);
        if (username == admin.getUsername() && admin.checkPassword(password)) {
            handleAdminMenu(admin);
            logger.log("Администратор вошел в систему.");
        }
        else {
            std::cerr << "Неверное имя пользователя или пароль.\n";
        }
        break;
    case 2:
        std::cout << "Введите имя пользователя (сотрудник): ";
        std::getline(std::cin, username);
        std::cout << "Введите пароль: ";
        std::getline(std::cin, password);
        for (auto& employee : employees) {
            if (employee.getUsername() == username && employee.checkPassword(password)) {
                handleEmployeeMenu(employee, medicineStorage);
                logger.log("Сотрудник вошел в систему.");
                found = true;
                break;
            }
        }
        if (!found) {
            std::cerr << "Неверное имя пользователя или пароль.\n";
        }
        break;
    case 3:
        exit(0);
    default:
        std::cerr << "Неверный выбор. Попробуйте снова.\n";
        break;
    }
}

void handleAdminMenu(Administrator& admin) {
    int choice;
    do {
        std::cout << "\n--- Меню администратора ---\n";
        std::cout << "1. Добавить лекарство\n";
        std::cout << "2. Удалить лекарство\n";
        std::cout << "3. Показать все лекарства\n";
        std::cout << "4. Добавить сотрудника\n";
        std::cout << "5. Удалить сотрудника\n";
        std::cout << "6. Показать всех сотрудников\n";
        std::cout << "7. Выход\n";
        std::cout << "Выберите вариант: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            admin.addMedicine();
            break;
        case 2:
            admin.removeMedicine();
            break;
        case 3:
            admin.displayAllMedicines();
            break;
        case 4:
            admin.addEmployee();
            break;
        case 5:
            admin.removeEmployee();
            break;
        case 6:
            admin.displayAllEmployees();
            break;
        case 7:
            std::cout << "Выход из меню администратора.\n";
            return;
        default:
            std::cerr << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (true);
}

void handleEmployeeMenu(Employee& employee, MedicineStorage& medicineStorage) {
    int choice;
    Customer customer("Иван Иванов", "+79001234567", "Москва, ул. Ленина, д. 1");
    Prescription prescription("PR001", customer, medicineStorage.getMedicines(), "Доктор Петров", "2023-10-01");
    Logger logger("log.txt");

    do {
        std::cout << "\n--- Меню сотрудника ---\n";
        std::cout << "1. Добавить продажу\n";
        std::cout << "2. Просмотреть рецепт\n";
        std::cout << "3. Показать все лекарства\n";
        std::cout << "4. Выход\n";
        std::cout << "Выберите вариант: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            handleAddSale(medicineStorage, customer, logger);
            break;
        case 2:
            handleDisplayPrescription(prescription);
            break;
        case 3:
            handleDisplayAllMedicines(medicineStorage);
            break;
        case 4:
            std::cout << "Выход из меню сотрудника.\n";
            return;
        default:
            std::cerr << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (true);
}

void handleAddSale(MedicineStorage& medicineStorage, Customer& customer, Logger& logger) {
    Sale sale(customer, logger);
    int choice;
    bool prescriptionShown = false;
    while (true) {
        std::cout << "\nДоступные лекарства:\n";
        for (size_t i = 0; i < medicineStorage.getMedicines().size(); ++i) {
            std::cout << i + 1 << ". ";
            medicineStorage.getMedicines()[i].displayInfo();
        }
        std::cout << "Введите номер лекарства для добавления в продажу (0 для завершения): ";
        std::cin >> choice;
        if (choice == 0) break;
        if (choice < 1 || static_cast<size_t>(choice) > medicineStorage.getMedicines().size()) { // Преобразование типа
            std::cerr << "Неверный выбор. Попробуйте снова.\n";
            continue;
        }
        if (medicineStorage.getMedicines()[choice - 1].isPrescriptionRequired() && !prescriptionShown) {
            std::cout << "Для этого лекарства требуется рецепт. Просмотрите рецепт перед покупкой (y/n): ";
            char confirm;
            std::cin >> confirm;
            if (confirm != 'y') {
                std::cerr << "Продажа отменена.\n";
                return;
            }
            prescriptionShown = true;
        }
        int quantity;
        std::cout << "Введите количество: ";
        std::cin >> quantity;
        try {
            sale.addItem(medicineStorage.getMedicines()[choice - 1], quantity);
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << "\n";
        }
    }
    sale.displayReceipt();
    std::cout << "Продажа завершена.\n";
}

void handleDisplayPrescription(const Prescription& prescription) {
    prescription.displayPrescription();
}

void handleAddEmployee(Administrator& admin) {
    admin.addEmployee();
}

void handleRemoveEmployee(Administrator& admin) {
    admin.removeEmployee();
}

void handleDisplayAllMedicines(MedicineStorage& medicineStorage) {
    medicineStorage.displayAllMedicines();
}