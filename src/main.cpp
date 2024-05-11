#include <iostream>
#include <cstdlib>
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

    std::string palabraAleatoria = incognita.getPalabra();
    int longitud = incognita.getLongitudPalabra(palabraAleatoria);
    std::string cadena = std::to_string(longitud);
    Element salida1 =hbox({filler(),text(palabraAleatoria),filler()})|border|flex;
    Element titulo = hbox({filler(),text("EL AHORCADO"),filler()})|borderDouble|flex|bold|color(Color::Red3Bis);
    Element witch = vbox({
        hbox({text("ACUSADA")})|bold,
        hbox({text("Nombre: "),text("Eloisa")}),
        hbox({text("Razon: "),text("tiene un gato negro")}),
    })|border;
    while(fotograma<=1){
        fotograma = fotograma + 0.1 ;
        
        this_thread::sleep_for(0.5s);
        //Element personaje = spinner(21,fotograma) | bold | color(Color::Red3) | bgcolor(Color::White);
        
        Element salida2 =hbox({filler(),text(cadena),filler()})|border|flex;
        Element salida3 =hbox({principal.getElement()})|color(Color::LightGoldenrod2Bis);
        Element salida4 =vbox({text("Ingrese una letra: a"),text("Letras incorretas: w"),text("¿Es una bruja?")|borderHeavy|bold});
        Element datos = hbox({salida1,salida2})|bold;
        Element juego = vbox({datos|color(Color::Cyan1),gauge(fotograma)|borderHeavy|color(Color::Red3Bis),witch,salida4});
        
        Element dibujo = vbox({titulo,hbox({salida3|border,juego|border|flex}) });

        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla,dibujo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();
    }
    system("clear");

    while (true) {
        this_thread::sleep_for(0.5s);
        fotograma = 1;

        Element sf1 =hbox({text("LA PALABRA CORRECTA ERA: "),text(palabraAleatoria)})|color(Color::Cyan1)|flex;
        Element sf2 =hbox({eldos.getElement()})|color(Color::LightGoldenrod2Bis);

        Element salida2 =hbox({filler(),sf1,filler()})|borderHeavy|flex;
        Element salida3 =hbox({eldos.getElement()})|color(Color::LightGoldenrod2Bis);
        Element datos = hbox({text("PERDISTE")|borderHeavy|bold,salida2})|bold;
        Element juego = vbox({datos|color(Color::Cyan1),gauge(fotograma)|borderHeavy|color(Color::Red3Bis),witch,text("¿VOLVER A JUGAR?")|bold|borderHeavy|color(Color::LightGoldenrod2Bis)});
        
        Element dibujo2 = vbox({titulo,hbox({salida3|border,juego|border|flex}) });

        Screen pantalla2 = Screen::Create(Dimension::Full());
        Render(pantalla2,dibujo2);
        pantalla2.Print();
        cout<<pantalla2.ResetPosition();
    }

    return EXIT_SUCCESS;
}