#include <iostream>
#include <string>
#include <cctype> // Para la función std::tolower
#include <palabra.hpp> // Asegúrate de incluir correctamente el archivo de encabezado de la clase Palabra

class Juego {
private:
    Palabra palabraSecreta;
    std::string palabraAdivinada;
    std::string letrasUtilizadas;
    int intentosRestantes;

public:
    Juego(const std::string& filename);
    void inicializarJuego();
    void jugar();
    bool juegoTerminado();
};

Juego::Juego(const std::string& filename) : palabraSecreta(filename) {}

void Juego::inicializarJuego() {
    // Almacenar la palabra secreta en una variable local para mejorar la eficiencia
    std::string palabra = palabraSecreta.getPalabra();

    // Inicializar la palabra a adivinar con guiones bajos
    palabraAdivinada = std::string(palabra.length(), '_');
    letrasUtilizadas = "";
    intentosRestantes = 6; // Número de intentos permitidos
}

void Juego::jugar() {
    // Inicializar el juego
    inicializarJuego();

    while (!juegoTerminado()) {
        // Mostrar estado del juego
        std::cout << "Palabra: " << palabraAdivinada << std::endl;
        std::cout << "Intentos restantes: " << intentosRestantes << std::endl;
        std::cout << "Letras utilizadas: " << letrasUtilizadas << std::endl;

        // Obtener la entrada del jugador
        char letra;
        std::cout << "Ingrese una letra: ";
        std::cin >> letra;

        // Convertir la letra a minúsculas
        letra = std::tolower(letra);

        // Verificar si la entrada es una letra
        if (!std::isalpha(letra)) {
            std::cout << "Entrada inválida. Por favor, ingrese solo letras." << std::endl;
            continue;
        }

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
        std::vector<size_t> posiciones;
        for (size_t i = 0; i < palabra.length(); ++i) {
            if (palabra[i] == letra) {
                // Almacenar la posición de la letra adivinada
                posiciones.push_back(i);
                letraAdivinada = true;
            }
        }

        // Actualizar la palabra adivinada según las posiciones
        for (size_t pos : posiciones) {
            palabraAdivinada[pos] = letra;
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
        std::cout << "La palabra era: " << palabraSecreta.getPalabra() << std::endl;
        std::cout << "¡Felicidades! ¡Has adivinado la palabra!" << std::endl;
    }
}


bool Juego::juegoTerminado() {
    return palabraAdivinada == palabraSecreta.getPalabra() || intentosRestantes == 0;
}

int main() {
    Juego juego("./assets/palabras.txt");
    juego.jugar();
    return 0;
}
