#include <iostream>
#include <string>
#include <palabra.hpp>

class Juego {
private:
    Palabra palabraSecreta;
    std::string palabraAdivinada;
    int intentosRestantes;
    std::string letrasIncorrectas;

public:
    Juego(const std::string& filename);
    void inicializarJuego();
    void jugar();
    bool juegoTerminado();
};

Juego::Juego(const std::string& filename) : palabraSecreta(filename) {}

void Juego::inicializarJuego() {
    // Obtener la palabra secreta
    std::string palabra = palabraSecreta.getPalabra();
    // Inicializar palabraAdivinada con espacios en blanco para indicar letras no adivinadas
    palabraAdivinada = std::string(palabra.length(), ' ');
    intentosRestantes = 6; // Número de intentos permitidos
    letrasIncorrectas = "";
}

void Juego::jugar() {
    while (!juegoTerminado()) {
        // Mostrar estado del juego
        std::cout << "Palabra: " << palabraAdivinada << std::endl;
        std::cout << "Intentos restantes: " << intentosRestantes << std::endl;
        std::cout << "Letras incorrectas: " << letrasIncorrectas << std::endl;

        // Obtener la entrada del jugador
        char letra;
        std::cout << "Ingrese una letra: ";
        std::cin >> letra;

        // Actualizar el estado del juego
        bool letraAdivinada = false;
        for (int i = 0; i < palabraSecreta.getPalabra().length(); ++i) {
            if (palabraSecreta.getPalabra()[i] == letra) {
                palabraAdivinada[i] = letra;
                letraAdivinada = true;
            }
        }

        if (!letraAdivinada) {
            --intentosRestantes;
            letrasIncorrectas += letra;
        }
    }

    if (intentosRestantes == 0) {
        std::cout << "¡Has perdido! La palabra era: " << palabraSecreta.getPalabra() << std::endl;
    } else {
        std::cout << "¡Felicidades! ¡Has adivinado la palabra!" << std::endl;
    }
}

bool Juego::juegoTerminado() {
    return palabraAdivinada == palabraSecreta.getPalabra() || intentosRestantes == 0;
}
