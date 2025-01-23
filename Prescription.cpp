#include "Prescription.h"
#include <algorithm>
#include <iostream>

Prescription::Prescription(const std::string& prescriptionID, const Customer& customer, const std::vector<Medicine>& medicines, const std::string& doctorName, const std::string& issueDate)
    : prescriptionID(prescriptionID), customer(customer), medicines(medicines), doctorName(doctorName), issueDate(issueDate) {
}

void Prescription::addMedicine(const Medicine& medicine) {
    medicines.push_back(medicine);
}

void Prescription::removeMedicine(const std::string& medicineName) {
    medicines.erase(std::remove_if(medicines.begin(), medicines.end(),
        [&medicineName](const Medicine& m) { return m.getName() == medicineName; }),
        medicines.end());
}

void Prescription::displayPrescription() const {
    std::cout << "\n--- Рецепт ---\n";
    customer.displayInfo();
    std::cout << "Врач: " << doctorName << "\nДата выдачи: " << issueDate << "\nЛекарства:\n";
    for (const auto& medicine : medicines) {
        medicine.displayInfo();
    }
}