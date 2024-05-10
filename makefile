bin/ahorcado : src/main.cpp
	g++ -o bin/ahorcado src/main.cpp -Iinclude -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

run : bin/ahorcado
	./bin/ahorcado

bin/prueba_palabra : src/prueba_palabra.cpp
	g++ -o bin/prueba_palabra src/prueba_palabra.cpp -Iinclude -std=c++2a
runPal : bin/prueba_palabra
	./bin/prueba_palabra

bin/prueba_juego : src/prueba_juego.cpp
	g++ -o bin/prueba_juego src/prueba_juego.cpp -Iinclude -std=c++2a

runJuego : bin/prueba_juego
	./bin/prueba_juego