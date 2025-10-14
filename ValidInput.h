/*
    Clase: ValidInput
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:
    
    Clase: ValidInput

    Responsabilidades:
        - Encapsula y centraliza toda la logica de validaciones de las 
          entradas por consola del programa.
        - Evita duplicación decodigo en la logica de validaciones de entradas
          por consola
        - Leer y validar un entero de consola, con opcional rango mínimo/máximo.
        - Leer y validar una fecha en formato DD/MM/AAAA.
        - Muestrar mensajes de error y reintentos hasta que la entrada sea valida
    
    Colaboradores:
        - BloodDatabase usa a ValidInput para todas las lecturas de información como
          Id, edad, teléfono, fecha, unidades, departamento, tipo de sangre y 
          confirmaciones para borrar.
*/


#ifndef VALIDINPUT_H
#define VALIDINPUT_H

#include <string>
#include <climits>

class ValidInput {
public:
    // Lee un entero con validación de dígitos y rango opcional
    static int getInt(const std::string& prompt, int min = INT_MIN, int max = INT_MAX);

    // Lee un long long 
    static long long getLongLong(const std::string& prompt, long long min = LLONG_MIN, long long max = LLONG_MAX);

    // Lee una línea de texto por defecto no se permite vacía
    static std::string getLine(const std::string& prompt, bool allowEmpty = false);

    // Lee y valida un número de teléfono de exactamente 10 dígitos
    static long long getPhoneNumber(const std::string& prompt);

    // Lee y valida una fecha en formato DD/MM/AAAA (Dia / Mes / Año)
    static std::string getDate(const std::string& prompt);

    // Pregunta de confirmación sí/no retorna true si es sí
    static bool getYesNo(const std::string& prompt);
};

#endif // VALIDINPUT_H



