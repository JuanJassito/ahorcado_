#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <fstream>
#include <string> 
#include <dibujo.hpp>

using namespace std;
using namespace ftxui;

int main(){
    dibujo principal("./assets/images/arbol.txt");
    int fotograma = 0;

    while(true){
        fotograma++;
        this_thread::sleep_for(0.1s);

        Element personaje = spinner(21,fotograma) | bold | color(Color::Red3) | bgcolor(Color::White);
        Element dibujo = hbox({personaje,principal.getElement()});

        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla,dibujo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();
    }

    return EXIT_SUCCESS;
}