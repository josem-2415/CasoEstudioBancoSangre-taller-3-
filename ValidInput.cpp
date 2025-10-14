#include "ValidInput.h"
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <regex>  // Para validar el formato de fecha
#include <stdexcept>

int ValidInput::getInt(const std::string& prompt, int min, int max) {
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);

        if (line.empty()) {
            std::cout << "Entrada vacía. Por favor ingrese un número.\n";
            continue;
        }

        
        auto start = line.find_first_not_of(' ');
        auto end = line.find_last_not_of(' ');
        if (start == std::string::npos) { std::cout << "Entrada inválida.\n"; continue; }
        std::string trimmed = line.substr(start, end - start + 1);

        bool ok = true;
        size_t i = 0;
        if (trimmed[0] == '-' || trimmed[0] == '+') i = 1;
        for (; i < trimmed.size(); ++i) {
            if (!std::isdigit(static_cast<unsigned char>(trimmed[i]))) { ok = false; break; }
        }

        if (!ok) {
            std::cout << "Entrada no numérica. Intente de nuevo.\n";
            continue;
        }

        try {
            long long val = std::stoll(trimmed);
            if (val < min || val > max) {
                std::cout << "Número fuera de rango.";
                if (min != INT_MIN || max != INT_MAX) std::cout << " Rango permitido: [" << min << " - " << max << "].";
                std::cout << "\n";
                continue;
            }
            return static_cast<int>(val);
        } catch (...) {
            std::cout << "Error al convertir el número. Intente de nuevo.\n";
        }
    }
}

long long ValidInput::getLongLong(const std::string& prompt, long long min, long long max) {
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) { std::cout << "Entrada vacía. Intente de nuevo.\n"; continue; }

       
        auto start = line.find_first_not_of(' ');
        auto end = line.find_last_not_of(' ');
        if (start == std::string::npos) { std::cout << "Entrada inválida.\n"; continue; }
        std::string trimmed = line.substr(start, end - start + 1);

        bool ok = true;
        size_t i = 0;
        if (trimmed[0] == '-' || trimmed[0] == '+') i = 1;
        for (; i < trimmed.size(); ++i) {
            if (!std::isdigit(static_cast<unsigned char>(trimmed[i]))) { ok = false; break; }
        }
        if (!ok) { std::cout << "Entrada no numérica. Intente de nuevo.\n"; continue; }

        try {
            long long val = std::stoll(trimmed);
            if (val < min || val > max) {
                std::cout << "Número fuera de rango.\n";
                continue;
            }
            return val;
        } catch (...) {
            std::cout << "Error al convertir el número. Intente de nuevo.\n";
        }
    }
}

std::string ValidInput::getLine(const std::string& prompt, bool allowEmpty) {
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        
        auto start = line.find_first_not_of(' ');
        if (start == std::string::npos) {
            if (allowEmpty) return "";
            std::cout << "La entrada no puede estar vacía. Intente de nuevo.\n";
            continue;
        }
        auto end = line.find_last_not_of(' ');
        std::string trimmed = line.substr(start, end - start + 1);
        if (trimmed.empty() && !allowEmpty) {
            std::cout << "La entrada no puede estar vacía. Intente de nuevo.\n";
            continue;
        }
        return trimmed;
    }
}

long long ValidInput::getPhoneNumber(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        // eliminar espacios y guiones comunes, paréntesis y puntos
        line.erase(std::remove_if(line.begin(), line.end(), [](char c){
            return std::isspace(static_cast<unsigned char>(c)) || c=='-' || c=='.' || c=='(' || c==')';
        }), line.end());

        if (line.size() != 10) {
            std::cout << "El número debe tener exactamente 10 dígitos. Intente de nuevo.\n";
            continue;
        }
        if (!std::all_of(line.begin(), line.end(), [](char c){ return std::isdigit(static_cast<unsigned char>(c)); })) {
            std::cout << "El número debe contener sólo dígitos. Intente de nuevo.\n";
            continue;
        }
        try {
            return std::stoll(line);
        } catch (...) {
            std::cout << "Error al leer el número. Intente de nuevo.\n";
        }
    }
}

std::string ValidInput::getDate(const std::string& prompt) {
    // formato esperado DD/MM/AAAA
    const std::regex re(R"(^\s*(\d{2})/(\d{2})/(\d{4})\s*$)");
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        std::smatch m;
        if (!std::regex_match(line, m, re)) {
            std::cout << "Formato inválido. Use DD/MM/AAAA. Intente de nuevo.\n";
            continue;
        }
        int d = std::stoi(m[1].str());
        int mo = std::stoi(m[2].str());
        int y = std::stoi(m[3].str());
        if (mo < 1 || mo > 12) { std::cout << "Mes inválido. Intente de nuevo.\n"; continue; }
        if (y < 1900) { std::cout << "Año inválido. Intente de nuevo.\n"; continue; }
        int mdays = 31;
        if (mo == 4 || mo == 6 || mo == 9 || mo == 11) mdays = 30;
        else if (mo == 2) {
            bool leap = ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
            mdays = leap ? 29 : 28;
        }
        if (d < 1 || d > mdays) { std::cout << "Día inválido para ese mes. Intente de nuevo.\n"; continue; }
        // devolver fecha en el mismo formato 
        auto start = line.find_first_not_of(' ');
        auto end = line.find_last_not_of(' ');
        return line.substr(start, end - start + 1);
    }
}

bool ValidInput::getYesNo(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        // transformar a minúsculas y quitar espacios
        std::string s;
        for (char c : line) {
            if (!std::isspace(static_cast<unsigned char>(c))) s.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
        }
        if (s == "s" || s == "si" || s == "y" || s == "yes") return true;
        if (s == "n" || s == "no") return false;
        std::cout << "Respuesta inválida. Responda 's'/'si' o 'n'/'no'.\n";
    }
}
