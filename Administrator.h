#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include <vector>
#include "User.h"
#include "Medicine.h"
#include "Employee.h"
#include "medicine_storage.h"

class Administrator : public User {
private:
    MedicineStorage medicineStorage;

public:
    Administrator(const std::string& username, const std::string& password);
    void addMedicine();
    void removeMedicine();
    void displayAllMedicines();
    void addEmployee();
    void removeEmployee();
    void displayAllEmployees();
    MedicineStorage& getMedicineStorage();
    void displayInfo() const override; // Переопределение чисто виртуальной функции
};

#endif // ADMINISTRATOR_H