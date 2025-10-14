#include "Reports.h"
#include <iostream>
using namespace std;

Reports::Reports() {}

void Reports::loadDataBase(const std::vector<Donor> &auxdonor) {
  this->auxDonor = auxdonor;
}

int Reports::donorTotal() const { return auxDonor.size(); }

int Reports::donorTotal(const int &district, const int &age,
                        const int &bloodType) const {
  int total = 0;
  for (const auto &d : auxDonor) {
    if (d.getDistrict() == district && d.getAge() == age &&
        d.getBloodType() == bloodType)
      total++;
  }
  return total;
}

int Reports::donorTotal(const int &district, const int &bloodType) const {
  int total = 0;
  for (const auto &d : auxDonor) {
    if (d.getDistrict() == district && d.getBloodType() == bloodType)
      total++;
  }
  return total;
}

double Reports::donorMeanAge(const int &district) const {
  int total = 0, ages = 0;
  for (const auto &d : auxDonor) {
    if (d.getDistrict() == district) {
      ages += d.getAge();
      total++;
    }
  }
  return (total > 0) ? (double)ages / total : 0;
}

int Reports::donorAdult(const int &district, const int &bloodType) const {
  int total = 0;
  for (const auto &d : auxDonor) {
    if (d.getDistrict() == district && d.getAge() >= 18 &&
        d.getBloodType() == bloodType)
      total++;
  }
  return total;
}

int Reports::bloodDonorUnits(const int donorId) const {
    for (const auto &d : auxDonor) {
        if (d.getDonorId() == donorId) {
            std::cout << "-------------------------------------\n";
            std::cout << "ID del donante: " << d.getDonorId() << "\n";
            std::cout << "Nombre: " << d.getName() << "\n";
            std::cout << "Unidades donadas: " << d.getUnits() << "\n";
            std::cout << "Fecha última donación: " << d.getDate() << "\n";
            std::cout << "-------------------------------------\n";
            return d.getUnits();
        }
    }
    std::cout << "Donante con ID " << donorId << " no encontrado.\n";
    return 0;
}


void Reports::yearAndReport() const {
  static const std::string departamentos[] = {
      "Putumayo",  "Cauca",     "Valle del Cauca",    "Amazonas",
      "Risaralda", "Antioquia", "Norte de Santander", "Chocó",
      "Arauca",    "Guainía"};

  static const std::string tiposSangre[] = {"A+",  "A-",  "B+", "B-",
                                            "AB+", "AB-", "O+", "O-"};

  std::cout << "Reporte de donantes por Departamento y Tipo de Sangre:\n\n";

  for (int dep = 1; dep <= 10; dep++) {
    std::cout << "Departamento " << dep << " (" << departamentos[dep - 1]
              << "):\n";

    int totalDep = 0;
    std::vector<int> conteo(8, 0);

    // 🔹 Contar donantes del departamento por tip
    for (const auto &d : auxDonor) {
      if (d.getDistrict() == dep) {
        conteo[d.getBloodType() - 1]++;
        totalDep++;
      }
    }

    if (totalDep == 0) {
      std::cout << "No hay donantes registrados\n\n";
      continue;
    }

    // 🔹 Mostrar resultados con porcentaj
    for (int bt = 0; bt < 8; bt++) {
      if (conteo[bt] > 0) {
        double porcentaje =
            (static_cast<double>(conteo[bt]) / totalDep) * 100.0;
        std::cout << "   Tipo de sangre " << tiposSangre[bt] << ": "
                  << conteo[bt] << " donante(s) "
                  << "(" << porcentaje << "%)\n";
      }
    }

    std::cout << "   Total en este departamento: " << totalDep
              << " donante(s)\n\n";
  }
}

//Funcion que muestra el porcentaje por tipo de sangre en la poblacion
void Reports::meanBloodData() const {
    static const std::string tiposSangre[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
    int total = auxDonor.size();
    if (total == 0) return;

    for (int bt = 1; bt <= 8; bt++) {
        int count = 0;
        for (const auto& d : auxDonor) {
            if (d.getBloodType() == bt) count++;
        }
        double mean = (count * 100.0) / total;
        std::cout << "Porcentaje de tipo de sangre " << tiposSangre[bt - 1] << ": " << mean << "%\n";
    }
}

//Funcion que muestra la sangre que predomina
void Reports::predominantBlood() const {
    static const std::string tiposSangre[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
    int counts[8] = {0};
    for (const auto& d : auxDonor) counts[d.getBloodType() - 1]++;

    int maxCount = 0, predominantType = 0;
    for (int i = 0; i < 8; i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            predominantType = i + 1;
        }
    }

    std::cout << "La sangre que predomina es: " << tiposSangre[predominantType - 1]
              << " con " << maxCount << " donantes.\n";
}
