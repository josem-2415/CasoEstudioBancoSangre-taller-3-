/*
Clase: Report

Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
UNIVERSIDAD DEL VALLE

Información CRC:

Clase: Report

Responsabilidades:
    - Ofrecer La cantidad de personas a procesar total, y separada de acuerdo con su tipo de 
    sangre, procedencia y edad.
    - Ofrece datos estadísticos sobre el número de chocoanos con tipo de sangre A+, el número 
    de araucanos con tipo de sangre O- y el número de caucanos con tipo de sangre B+
    - ofrece datos estadísticos sobre la edad promedio de los donantes del Choco, Arauca y Valle del Cauca.
    - ofrece datos estadísticos sobre la cantidad de vallecaucanos con tipo de sangre B+ y mayores de edad.
    - Hallar y muestra el número de unidades de sangre que dona una persona y la fecha de donación. 
    - Entrega un reporte de cierre de año, en el cual se presente el porcentaje de donantes por 
    tipos de sangre y para cada una de las zonas del país.
      
Colaboradores:
    - Usa la clase BloodDatabase importando su vector de donantes para calcular los datos estadísticos 
    de sus responsabilidades.


Autores:
    - Jose Manuel Cardona Gil 2521653
    - Nerie Vásquez Diaz      2519638
    - Juan Sebastian Valencia 2439803
    - Andrés Felipe Rodríguez 2539555
*/

#ifndef REPORTS_H
#define REPORTS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"

class Reports {
private:
    std::vector<Donor> auxDonor;

public:
    Reports();
    void loadDataBase(const std::vector<Donor>& adonor);

    int donorTotal() const;
    int donorTotal(const int& district, const int& age, const int& bloodType) const;
    int donorTotal(const int& district, const int& bloodType) const;  
    double donorMeanAge(const int& district) const;
    int donorAdult(const int& district, const int& bloodType) const;
    int bloodDonorUnits(const int donorId) const;
    void yearAndReport() const;

     // Nuevos métodos
    void meanBloodData()const; //Es una funcion que saca el porcentaje por cada tipo de sangre
    void predominantBlood()const; //funcion que muestra la sangre que predomina
};

#endif // REPORTS_H
