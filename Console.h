/*
Clase: Console
Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
UNIVERSIDAD EL VALLE

Información CRC:

Clase: Console

Responsabilidades:
    - Proporcionar una interfaz de interacción en consola para el usuario, facilitando la visualización 
      y selección de opciones dentro del sistema.
    - Mostrar listas predefinidas como provincias y tipos de sangre para asistir en el ingreso de datos.
    - Limpiar la pantalla de la consola para mantener una visualización ordenada y clara.
    - Pausar la ejecución hasta que el usuario presione una tecla, permitiendo una navegación controlada.
    - Validar y obtener entradas numéricas del usuario, garantizando que las respuestas sean válidas y seguras.

Colaboradores:
    - Colabora con la clase Donor, al mostrar información relacionada con los datos de los donantes.
    - Utiliza las librerías estándar <iostream> para la entrada y salida por consola.
    - Emplea <string> para manejar textos mostrados al usuario.
    - Usa <vector> para posibles listas de opciones en pantalla.
    - Se apoya en <fstream> en conjunto con otras clases para operaciones relacionadas con archivos.

Autores:
    - Jose Manuel Cardona Gil   2521653
    - Nerie Vásquez Diaz        2519638
    - Juan Sebastian Valencia   2439803
    - Andrés Felipe Rodríguez   2539555
*/

#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"

class Console {
public:
    static void displayProvinces();
    static void displayBloodType();
    static void clearConsole();
    static void waitForKeyPress();


};

#endif // CONSOLE_H
