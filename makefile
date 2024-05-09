bin/ahorcado : src/main.cpp
	g++ -o bin/ahorcado src/main.cpp -Iinclude -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

run : bin/ahorcado
	./bin/ahorcado