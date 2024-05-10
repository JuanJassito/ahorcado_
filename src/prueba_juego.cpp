#include <iostream>
#include <string>
#include <juego.hpp>

int main() {
    Juego juego("./assets/palabras.txt");
    juego.inicializarJuego();
    juego.jugar();

    return 0;
}