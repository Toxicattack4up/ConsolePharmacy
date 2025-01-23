#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include <string>
#include <vector>
#include "Medicine.h"
#include "Customer.h"

class Prescription {
private:
    std::string prescriptionID;
    Customer customer;
    std::vector<Medicine> medicines;
    std::string doctorName;
    std::string issueDate;

public:
    Prescription(const std::string& prescriptionID, const Customer& customer, const std::vector<Medicine>& medicines, const std::string& doctorName, const std::string& issueDate);
    void addMedicine(const Medicine& medicine);
    void removeMedicine(const std::string& medicineName);
    void displayPrescription() const;
};

#endif // PRESCRIPTION_H