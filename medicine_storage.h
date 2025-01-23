#ifndef MEDICINE_STORAGE_H
#define MEDICINE_STORAGE_H

#include <vector>
#include <string>
#include "Medicine.h"
#include "Employee.h"

class MedicineStorage {
private:
    std::vector<Medicine> medicines;
    std::vector<Employee> employees;

public:
    MedicineStorage();
    void addMedicine(const Medicine& medicine);
    void removeMedicine(const std::string& name);
    void displayAllMedicines() const;
    std::vector<Medicine>& getMedicines();
    void saveToFile();
    std::vector<Employee>& getEmployees();
    void loadEmployees();
    void removeEmployee(const std::string& username);
};

#endif // MEDICINE_STORAGE_H