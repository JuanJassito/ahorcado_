#include <iostream>
#include <palabra.hpp> // O "#include "Palabra.h" si usas una extensión .h para el archivo de declaración de la clase.

int main() {
    // Crear un objeto de la clase Palabra, proporcionando el nombre del archivo que contiene las palabras.
    Palabra palabra("./assets/palabras.txt"); // Reemplaza "archivo.txt" con el nombre de tu archivo de palabras.
    int longitud;
    // Obtener una palabra aleatoria utilizando el método getPalabra().
    std::string palabraAleatoria = palabra.getPalabra();
    if (!palabraAleatoria.empty()) {
        std::cout << "Palabra aleatoria seleccionada: " << palabraAleatoria << std::endl;
        longitud = palabra.getLongitudPalabra(palabraAleatoria);
        std::cout << "Longitud de la palabra: " << longitud << std::endl;
    }

    return 0;
}