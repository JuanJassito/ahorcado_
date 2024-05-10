#include <iostream>
#include <palabra.hpp> // O "#include "Palabra.h" si usas una extensión .h para el archivo de declaración de la clase.
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>

using namespace std;
using namespace ftxui;


int main() {
    // Crear un objeto de la clase Palabra, proporcionando el nombre del archivo que contiene las palabras.
    float value = 0.5;
    Palabra palabra("./assets/palabras.txt"); // Reemplaza "archivo.txt" con el nombre de tu archivo de palabras.
    int longitud;
    // Obtener una palabra aleatoria utilizando el método getPalabra().
    std::string palabraAleatoria = palabra.getPalabra();
    if (!palabraAleatoria.empty()) {
        std::cout << "Palabra aleatoria seleccionada: " << palabraAleatoria << std::endl;
        longitud = palabra.getLongitudPalabra(palabraAleatoria);
        std::cout << "Longitud de la palabra: " << longitud << std::endl;
    }
    
    Element document =
    hbox({
      text(palabraAleatoria)   | border | flex | bold | color(Color::Red3) | bgcolor(Color::LightGoldenrod2Bis) ,
      text(palabraAleatoria) | borderDashed | flex | blink | color(Color::MistyRose3) | bgcolor(Color::Black) ,
      text(palabraAleatoria)  | borderHeavy | flex | inverted | color(Color::MistyRose3) | bgcolor(Color::Black),
      separator(),
      gauge(value) | borderDouble | color(Color::MistyRose3),
    });

    auto screen = Screen::Create(
    Dimension::Full(),       // Width
    Dimension::Fit(document) // Height
    );
    Render(screen, document);
    screen.Print();

    return 0;
}