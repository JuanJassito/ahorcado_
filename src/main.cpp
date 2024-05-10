#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <fstream>
#include <string> 
#include <dibujo.hpp>
#include <palabra.hpp>

using namespace std;
using namespace ftxui;

int main(){
    dibujo principal("./assets/images/arbol.txt");
    dibujo eldos("./assets/images/65pix.txt");
    Palabra incognita("./assets/palabras.txt");
    int fotograma = 0;

    while(true){
        fotograma++;
        std::string palabraAleatoria = incognita.getPalabra();
        int longitud = incognita.getLongitudPalabra(palabraAleatoria);
        std::string cadena = std::to_string(longitud);
        this_thread::sleep_for(0.5s);

        Element personaje = spinner(21,fotograma) | bold | color(Color::Red3) | bgcolor(Color::White);
        Element juego = hbox({text(palabraAleatoria)|border|flex ,text(cadena)|border|flex});
        Element dibujo = vbox({eldos.getElement()|border,juego}) | color(Color::Red3Bis);
        

        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla,dibujo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();
    }

    return EXIT_SUCCESS;
}