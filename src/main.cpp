#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <fstream>
#include <string> 

using namespace std;
using namespace ftxui;

int main(){
    int fotograma = 0;

    while(true){
        this_thread::sleep_for(0.1s);
        Element personaje = spinner(21,fotograma) | bold | color(Color::Red3) | bgcolor(Color::White);
        Screen pantalla = Screen::Create(Dimension::Full());
        pantalla.Print();
        cout<<pantalla.ResetPosition();
        fotograma++;
    }

    return EXIT_SUCCESS;
}