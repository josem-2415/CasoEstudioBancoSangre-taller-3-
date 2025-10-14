#include "BloodDatabase.h"
#include "Donor.h"
#include "Reports.h"
#include "Console.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

void limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int donorId;
    std::string donorName;
    BloodDatabase database;
    Reports reporte;
    int d=3;
    int a=43;
    int b=3;
    int choice;

    while (true) {
        reporte.loadDataBase(database.getDonors());
        Console::clearConsole();
        std::cout <<
             " ░█████╗░██████╗░██╗░░░██╗███████╗  ██████╗░░█████╗░░░░░░██╗░█████╗░\n"
             " ██╔══██╗██╔══██╗██║░░░██║╚════██║  ██╔══██╗██╔══██╗░░░░░██║██╔══██╗\n"
             " ██║░░╚═╝██████╔╝██║░░░██║░░███╔═╝  ██████╔╝██║░░██║░░░░░██║███████║\n"
             " ██║░░██╗██╔══██╗██║░░░██║██╔══╝░░  ██╔══██╗██║░░██║██╗░░██║██╔══██║\n"
             " ╚█████╔╝██║░░██║╚██████╔╝███████╗  ██║░░██║╚█████╔╝╚█████╔╝██║░░██║\n"
             " ░╚════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝  ╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░╚═╝\n";
        std::cout << "1. Registrar donante\n";
        std::cout << "2. Buscar donante\n";
        std::cout << "3. Eliminar donante\n";
        std::cout << "4. Reportes\n";
        std::cout << "5. Unidades donadas\n";
        std::cout << "6. Reporte por año/departamento\n";
        std::cout << "7. Porcentaje por tipo de sangre\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese su elección: ";
        std::cin >> choice;
        limpiarBuffer();

        switch (choice) {
        case 1:
            database.getDonorDetails();
            database.writeDataToFile();
            break;

        case 2:
            database.searchAndDisplay();
            break;

        case 3:
            std::cout << "Ingrese el nombre del donante a eliminar: ";
            limpiarBuffer();
            std::getline(std::cin, donorName);
            database.deleteDonor(donorName);
            Console::waitForKeyPress();
            break;

        case 4:
            std::cout << "Total registros: " << reporte.donorTotal() << endl;
        
            //Reporte del total de registros del Valle del Cauca, 43 años y B+
            std::cout<< "El total de registros del Valle del Cauca, 43 años y B+ es: "<< reporte.donorTotal(d, a, b) << endl;

            //Reporte del total de registros de Chocoanos A+
            d = 8;b = 1;std::cout << "El total de registros de Chocoanos A+ es: "<< reporte.donorTotal(d, b) << endl;

            //Reporte del total de registros de Aracaunos O-
            d = 9;b = 8;std::cout << "El total de registros de Aracaunos O- es: "<< reporte.donorTotal(d, b) << endl;

            //Reporte del total de registros de vallecaucanos B+
            d = 3;b = 3;std::cout << "El total de registros de Valle Caucanos B+ es: "<< reporte.donorTotal(d, b) << endl;
        
            //Reporte del promedio de edad de los individuos de Choco, Arauca y Valle de Cauca
            double auxedad;
            d = 8;auxedad = reporte.donorMeanAge(d);
            d = 9;auxedad = (auxedad + reporte.donorMeanAge(d)) / 2;
            d = 3;auxedad = (auxedad + reporte.donorMeanAge(d)) / 2;
            std::cout << "El promedio de edad los individuos de Choco, Arauca y Valle de Cauca: "<< auxedad << endl;
        
            //Reporte de donantes mayores de edad vallecaucanos B+
            d = 3;b = 3;std::cout << "El total de registros mayores de edad vallecaucanos B+: "<< reporte.donorAdult(d, b) << endl;
            Console::waitForKeyPress();
            break;

        case 5:
            // Asegura que el reporte tenga los datos cargados
            reporte.loadDataBase(database.getDonors());
            std::cout << "Ingrese el ID del donante para ver unidades donadas: ";
    
            // Limpia el buffer por si quedó algo pendiente
            std::cin >> donorId;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Console::waitForKeyPress();

            // Ejecuta la función
            reporte.bloodDonorUnits(donorId);

            // Pausa antes de volver al menú
            Console::waitForKeyPress();
            break;
        
        case 6:
            //Funcion que muestra el reporte por año y departamento
            reporte.yearAndReport();
            Console::waitForKeyPress();
            break;
        
        case 7:
            std::cout << "El porcentaje de registros de tipo de sangre de todos los donantes: "<< reporte.donorAdult(d, b) << endl;
            //Funcion que muestra el porcentaje por tipo de sangre en la poblacion
            reporte.meanBloodData();
            //Funcion que muestra la sangre que predomina
            reporte.predominantBlood();
            Console::waitForKeyPress();
            break;

        case 8:
            std::cout << "Saliendo del programa...\n";
            return 0;
        
        default:
            std::cout << "Opción no válida.\n";
            Console::waitForKeyPress();
            break;
        }
    }
}
