#include "Console.h"
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

void Console::displayProvinces() {
    std::cout << "Elige el departamento:\n";
    std::cout << "1. Putumayo\n";
    std::cout << "2. Cauca\n";
    std::cout << "3. Valle del Cauca\n";
    std::cout << "4. Amazonas\n";
    std::cout << "5. Risaralda\n";
    std::cout << "6. Antioquia\n";
    std::cout << "7. Norte de Santander\n";
    std::cout << "8. Chocó\n";
    std::cout << "9. Arauca\n";
    std::cout << "10. Guainía\n";
}

void Console::displayBloodType() {
    std::cout << "Elige el tipo de sangre:\n";
    std::cout << "1. A+\n";
    std::cout << "2. A-\n";
    std::cout << "3. B+\n";
    std::cout << "4. B-\n";
    std::cout << "5. AB+\n";
    std::cout << "6. AB-\n";
    std::cout << "7. O+\n";
    std::cout << "8. O-\n";
}

void Console::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    // system("clear");
#endif
}

void Console::waitForKeyPress() {
    std::cout << "Presiona cualquier tecla para continuar...";
    std::cin.ignore();
    std::cin.get();
}

int Console::getValidatedInput(const std::string& prompt) {
    int value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        try {
            if (!std::all_of(input.begin(), input.end(), ::isdigit)) {
                throw std::invalid_argument("La entrada contiene caracteres no numéricos");
            }
            value = std::stoi(input);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Entrada no válida: " << e.what() << ". Por favor ingrese un número válido." << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Entrada fuera de rango. Por favor ingrese un número válido." << std::endl;
        }
    }
    return value;
}
