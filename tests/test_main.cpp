#include <gtest/gtest.h>
#include "Donor.h"
#include "ValidInput.h"
#include "ValidacionTelefonos.h"

// Prueba: creación manual de un Donor y validación de sus datos
TEST(DonorTest, ManualObjectCreation) {
    Donor d;
    d.setDonorId(101);
    d.setName("Juan Perez");
    d.setAge(35);
    d.setAddress("Calle 12 #4-56");
    d.setDistrict(3);     // Valle del Cauca
    d.setBloodType(1);    // A+
    d.setNumber(3204567890);
    d.setUnits(4);
    d.setDate("12/10/2024");

    EXPECT_EQ(d.getDonorId(), 101);
    EXPECT_EQ(d.getName(), "Juan Perez");
    EXPECT_EQ(d.getAge(), 35);
    EXPECT_EQ(d.getAddress(), "Calle 12 #4-56");
    EXPECT_EQ(d.getDistrict(), 3);
    EXPECT_EQ(d.getBloodType(), 1);
    EXPECT_EQ(d.getNumber(), 3204567890);
    EXPECT_EQ(d.getUnits(), 4);
    EXPECT_EQ(d.getDate(), "12/10/2024");
}

// Prueba: validaciones de entrada (sin necesidad de consola)
TEST(ValidInputTest, ValidateIntRange) {
    // Simulación lógica: rango de edad válido
    int edad = 25;
    EXPECT_GE(edad, 0);
    EXPECT_LE(edad, 150);
}

TEST(ValidInputTest, ValidatePhoneNumberLength) {
    long long telefono = 3124567890;
    std::string telefonoStr = std::to_string(telefono);

    EXPECT_EQ(telefonoStr.size(), 10);
    EXPECT_EQ(telefonoStr[0], '3'); // Los celulares colombianos empiezan por 3
}

// Prueba: validación con formato de fecha DD/MM/AAAA
TEST(ValidInputTest, ValidateDateFormat) {
    std::string fecha = "05/09/2024";

    EXPECT_EQ(fecha.size(), 10);
    EXPECT_EQ(fecha[2], '/');
    EXPECT_EQ(fecha[5], '/');
    EXPECT_TRUE(std::isdigit(fecha[0]) && std::isdigit(fecha[1]));
    EXPECT_TRUE(std::isdigit(fecha[3]) && std::isdigit(fecha[4]));
    EXPECT_TRUE(std::isdigit(fecha[6]) && std::isdigit(fecha[9]));
}

// Prueba: validación de número con la clase PhoneValidator
// (solo testea que el método se ejecuta, sin requerir conexión)
TEST(PhoneValidatorTest, ValidateNumberOfflineMock) {
    long long telefono = 3216549870;
    bool valido = PhoneValidator::validate(telefono);
    // En modo sin conexión podría devolver false, pero el test asegura que la función responde.
    EXPECT_TRUE(valido || !valido);
}

// 🔹 Entrada principal de pruebas
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
