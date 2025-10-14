#include "BloodDatabase.h"
#include "ValidInput.h"   
#include "ValidacionTelefonos.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <algorithm>

using namespace std;

void BloodDatabase::getDonorDetails() {
    Console::clearConsole();
    std::cout << "Ingrese los detalles del donante\n";

    Donor newDonor;

    newDonor.setDonorId( ValidInput::getInt("Id: ", 1) );

    std::string name = ValidInput::getLine("Nombre: ", false);
    newDonor.setName(name);

    int age = ValidInput::getInt("Edad: ", 0, 150);
    newDonor.setAge(age);

    std::string address = ValidInput::getLine("Dirección: ", false);
    newDonor.setAddress(address);

    Console::displayProvinces();
    int district = ValidInput::getInt("Departamento (ingrese el número correspondiente): ", 1, 10);
    newDonor.setDistrict(district);

    Console::displayBloodType();
    int bloodType = ValidInput::getInt("Tipo de Sangre (ingrese el número correspondiente): ", 1, 8);
    newDonor.setBloodType(bloodType);

   long long phone = ValidInput::getPhoneNumber("Número de móvil (10 dígitos): ");

    // Validación con la API NumVerify
    if (PhoneValidator::validate(phone)) {
        newDonor.setNumber(phone);
    } else {
        std::cout << "El número no pasó la validación de NumVerify. Intente con otro número.\n";
        return; // Detiene el registro si el número no es válido
    }


    int units = ValidInput::getInt("Unidades de sangre donadas: ", 0);
    newDonor.setUnits(units);

    std::string date = ValidInput::getDate("Fecha de donación (DD/MM/AAAA): ");
    newDonor.setDate(date);

    donors.push_back(newDonor);
}

void BloodDatabase::writeDataToFile() {
    std::ofstream outfile(fileName, std::ios::app);
    if (!outfile) {
        std::cout << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }

    Donor d = donors.back();
    outfile << d.getDonorId() << ",    "
            << d.getName() << ",    "
            << d.getAge() << ",    "
            << d.getAddress() << ",    "
            << d.getDistrict() << ",    "
            << d.getBloodType() << ",    "
            << d.getNumber() << ",    "
            << d.getUnits() << ",    "
            << d.getDate() << std::endl;
    outfile.close();
}

void BloodDatabase::searchAndDisplay() const {
    Console::clearConsole();
    Console::displayProvinces();
    int provinceName = ValidInput::getInt("Ingrese el número del departamento: ", 1, 10);

    std::cout << "Ingrese la dirección (dejar en blanco para omitir): ";
    std::string addressFilter;
    std::getline(std::cin, addressFilter);

    std::ifstream inFile(fileName);
    if (!inFile) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    std::vector<Donor> result;
    std::string line;
    bool found = false;

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        bool match = d.getDistrict() == provinceName &&
            (addressFilter.empty() || d.getAddress().find(addressFilter) != std::string::npos);
        if (match) {
            result.push_back(d);
            found = true;
        }
    }

    if (!found) {
        std::cout << "No se encontraron personas del departamento " << provinceName;
        if (!addressFilter.empty()) {
            std::cout << " con dirección que contiene '" << addressFilter << "'";
        }
        std::cout << "." << std::endl;
    } else {
        for (const auto& d : result) {
            std::cout << "Nombre: " << d.getName() << std::endl;
            std::cout << "Edad: " << d.getAge() << std::endl;
            std::cout << "Dirección: " << d.getAddress() << std::endl;
            std::cout << "Departamento: " << d.getDistrict() << std::endl;
            std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl;
            std::cout << "Número de móvil: " << d.getNumber() << std::endl;
            std::cout << "Unidades donadas: " << d.getUnits() << std::endl;
            std::cout << "Fecha: " << d.getDate() << std::endl;
            std::cout << std::endl;
        }
    }

    inFile.close();
    Console::waitForKeyPress();
}

void BloodDatabase::deleteDonor(const std::string& donorName) {
    std::ifstream inFile(fileName);
    std::ofstream tempFile("temp.txt");
    if (!inFile || !tempFile) return;

    std::string line;
    bool found = false;
    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        if (d.getName() == donorName) {
            found = true;
            // usar ValidInpud para confirmar
            bool confirm = ValidInput::getYesNo(std::string("Eliminar a ") + d.getName() + "? [s/n]: ");
            if (confirm) {
                // omitir (no escribir en temp)
                continue;
            }
        }
        tempFile << d.getDonorId() << ",    "
                 << d.getName() << ",    "
                 << d.getAge() << ",    "
                 << d.getAddress() << ",    "
                 << d.getDistrict() << ",    "
                 << d.getBloodType() << ",    "
                 << d.getNumber() << ",    "
                 << d.getUnits() << ",    "
                 << d.getDate() << std::endl;
    }
    inFile.close(); tempFile.close();
    remove(fileName.c_str());
    rename("temp.txt", fileName.c_str());
    if (!found) std::cout << "No se encontró " << donorName << std::endl;
}

std::vector<Donor> BloodDatabase::getDonors(){
    std::ifstream inFile(fileName);
    std::vector<Donor> donors;
    std::string line;
    while (std::getline(inFile, line)) {
        donors.push_back(Donor::parseLine(line));
    }
    inFile.close();
    return donors;
}
