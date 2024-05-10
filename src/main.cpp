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
    float fotograma = 0;

    while(true){
        fotograma = fotograma + 0.1 ;
        std::string palabraAleatoria = incognita.getPalabra();
        int longitud = incognita.getLongitudPalabra(palabraAleatoria);
        std::string cadena = std::to_string(longitud);
        this_thread::sleep_for(0.5s);

        //Element personaje = spinner(21,fotograma) | bold | color(Color::Red3) | bgcolor(Color::White);
        Element salida1 =hbox({filler(),text(palabraAleatoria),filler()})|border|flex;
        Element salida2 =hbox({filler(),text(cadena),filler()})|border|flex;
        Element salida3 =hbox({eldos.getElement()})|color(Color::LightGoldenrod2Bis);
        Element datos = hbox({salida1,salida2})|bold;
        Element juego = vbox({datos|color(Color::Cyan1),gauge(fotograma)|borderHeavy|color(Color::Red3Bis)});
        Element titulo = hbox({filler(),text("EL AHORCADO"),filler()})|borderDouble|flex|bold|color(Color::Red3Bis);
        Element dibujo = vbox({titulo,hbox({salida3|border,juego|border|flex}) });

        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla,dibujo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();
    }
    
    return EXIT_SUCCESS;
}