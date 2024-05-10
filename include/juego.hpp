#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <string>

class Juego {
private:
    Palabra palabraSecreta;
    std::string palabraAdivinada;
    std::string letrasUtilizadas;
    int intentosRestantes;

public:
    Juego(const std::string& filename) : palabraSecreta(filename) {}

    void inicializarJuego() {
        // Inicializar la palabra a adivinar con guiones bajos
        palabraAdivinada = std::string(palabraSecreta.getLongitudPalabra(palabraSecreta.getPalabra()), '_');
        letrasUtilizadas = "";
        intentosRestantes = 6; // Número de intentos permitidos
    }

    void Juego::jugar() {
    // Inicializar el juego
    inicializarJuego();

    // Crear una cadena para mantener el estado de las letras adivinadas
    std::string letrasAdivinadas(palabraSecreta.getLongitudPalabra(palabraSecreta.getPalabra()), '_');

    while (intentosRestantes > 0 && palabraAdivinada != palabraSecreta.getPalabra()) {
        // Mostrar estado del juego
        std::cout << "Palabra: " << palabraAdivinada << std::endl;
        std::cout << "Intentos restantes: " << intentosRestantes << std::endl;
        std::cout << "Letras utilizadas: " << letrasUtilizadas << std::endl;

        // Obtener la entrada del jugador
        char letra;
        std::cout << "Ingrese una letra: ";
        std::cin >> letra;

        // Verificar si la letra ya fue utilizada
        if (letrasUtilizadas.find(letra) != std::string::npos) {
            std::cout << "¡Ya has utilizado esa letra! Por favor, elige otra." << std::endl;
            continue;
        }

        // Marcar la letra como utilizada
        letrasUtilizadas += letra;

        // Verificar si la letra está en la palabra secreta
        bool letraAdivinada = false;
        std::string palabra = palabraSecreta.getPalabra();
        for (size_t i = 0; i < palabra.length(); ++i) {
            if (palabra[i] == letra) {
                // Actualizar la cadena de letras adivinadas
                letrasAdivinadas[i] = letra;
                letraAdivinada = true;
            }
        }

        // Actualizar la palabra adivinada con las letras adivinadas hasta ahora
        for (size_t i = 0; i < palabra.length(); ++i) {
            if (letrasAdivinadas[i] != '_') {
                palabraAdivinada[i] = letrasAdivinadas[i];
            }
        }

        // Decrementar los intentos si la letra no fue adivinada
        if (!letraAdivinada) {
            --intentosRestantes;
        }
    }

    // Mostrar el resultado del juego
    if (intentosRestantes == 0) {
        std::cout << "La palabra era: " << palabraSecreta.getPalabra() << std::endl;
        std::cout << "¡Has perdido!" << std::endl;
    } else {
        std::cout << "¡Felicidades! ¡Has adivinado la palabra: " << palabraSecreta.getPalabra() << "!" << std::endl;
    }
}

};

int main() {
    Juego juego("./assets/palabras.txt");
    juego.jugar();
    return 0;
}
