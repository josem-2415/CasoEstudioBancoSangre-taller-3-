/*
Clase: PhoneValidator
Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
UNIVERSIDAD EL VALLE

Información CRC:

Clase: PhoneValidator

Responsabilidades:
    - Validar números telefónicos ingresados por el usuario, garantizando que cumplan con el formato 
      y longitud adecuados antes de ser almacenados o procesados.
    - Implementar la verificación de números mediante la API NumVerify para asegurar su autenticidad.
    - Proporcionar una interfaz sencilla para validar datos sin necesidad de instanciar objetos.
    - Facilitar la detección de errores en la entrada de números telefónicos.

Colaboradores:
    - Utiliza la biblioteca estándar <string> para el manejo de datos de texto.
    - Puede colaborar con clases como Donor o BloodDatabase para verificar y asegurar que los números 
      telefónicos registrados sean válidos antes de su almacenamiento.

Autores:
    - Jose Manuel Cardona Gil   2521653
    - Nerie Vásquez Diaz        2519638
    - Juan Sebastian Valencia   2439803
    - Andrés Felipe Rodríguez   2539555
*/

#ifndef VALIDACIONTELEFONOS_H
#define VALIDACIONTELEFONOS_H

#include <string>

class PhoneValidator {
public:
    // Valida un número telefónico usando la API NumVerify
    static bool validate(long long phone);
};

#endif // PHONEVALIDATOR_H
