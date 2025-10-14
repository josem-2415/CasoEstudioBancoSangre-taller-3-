/*
Clase: Donor
Curso: Fundamentos de programación orientada a objetos (FPOO)
UNIVERSIDAD DEL VALLE

Información CRC:

Clase: Donor

Responsabilidades:
    - Representar la entidad básica del sistema: un donante de sangre.
    - Almacenar los datos personales y médicos relevantes del donante, tales como:
        • Identificación
        • Nombre
        • Edad
        • Dirección
        • Departamento (distrito)
        • Tipo de sangre
        • Número telefónico (validado con 10 dígitos y comenzando en 3)
        • Unidades de sangre donadas
        • Fecha de la última donación
    - Proporcionar métodos de acceso (getters) y modificación (setters) para garantizar el 
      encapsulamiento de los atributos.
    - Validar y convertir correctamente los datos provenientes de archivos o entradas de usuario 
      (por ejemplo, parseo de líneas desde `data.txt`).
    - Servir como estructura de datos principal para los reportes y las operaciones de la base de datos.

Colaboradores:
    - Colabora con la clase BloodDatabase, que administra el almacenamiento, búsqueda y eliminación de donantes.
    - Colabora con la clase Reports, que utiliza objetos Donor para generar estadísticas y reportes.
    - Utiliza clases de la STL (como `std::string`) para el manejo de cadenas y datos.
    - Se apoya en funciones de validación de entrada de C++ (como `std::all_of`, `std::stoll`) 
      para garantizar consistencia en los datos.

Autores:
    - Jose Manuel Cardona Gil 2521653
    - Nerie Vásquez Diaz      2519638
    - Juan Sebastian Valencia 2439803
    - Andrés Felipe Rodríguez 2539555
*/

#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor {
private:
    int donorId, district, bloodType, age;
    std::string name, address;
    long long number;   // teléfono validado (10 dígitos)
    int units;          // unidades de sangre donadas
    std::string date;   // fecha de última donación

    static std::string trim(const std::string& str);

public:
    Donor() = default;

    // Getters
    int getDonorId() const;
    std::string getName() const;
    int getAge() const;
    std::string getAddress() const;
    int getDistrict() const;
    int getBloodType() const;
    long long getNumber() const;
    int getUnits() const;
    std::string getDate() const;

    // Setters
    void setDonorId(int id);
    void setName(const std::string& n);
    void setAge(int a);
    void setAddress(const std::string& addr);
    void setDistrict(int d);
    void setBloodType(int bt);
    void setNumber(long long num);
    void setUnits(int u);
    void setDate(const std::string& d);

    // Métodos
    void donorDetails() const;
    static Donor parseLine(const std::string& line);
};

#endif // DONOR_H
