# Ahorcado

## Objetivo
El objetivo de este proyecto es hacer una animacion con arte ascii basada en el juego del ***ahorcado***

### Exploracion
El proyecto se ha estructurado de manera simple y clara para facilitar tanto el inicio como la comprensión de la idea general. Se ha puesto especial énfasis en organizar los archivos de manera intuitiva, lo que permite a los desarrolladores sumergirse rápidamente en el código y comprender la estructura del proyecto.

Entre los archivos más importantes para la ejecución del proyecto se encuentra el archivo principal (`main.cpp`), que actúa como punto de entrada del programa. Además, se han creado tres bibliotecas fundamentales hasta el momento: Dibujo, Juego y Palabra. Estas bibliotecas encapsulan la lógica esencial del juego y proporcionan una interfaz clara para interactuar con él.

Además de estas bibliotecas principales, se han diseñado otras clases necesarias para complementar y ampliar la funcionalidad del proyecto. Estas clases están estructuradas de manera coherente y están diseñadas para ser fácilmente extensibles en el futuro.

En cuanto al Makefile, se ha configurado de manera que permita ejecutar pruebas separadas para las bibliotecas de Juego y Palabra. Esto facilita el proceso de depuración y garantiza la calidad del código en cada etapa del desarrollo.

Por último, se ha agregado un comando especial al Makefile: `make run`. Este comando permite ejecutar la animación del juego de manera rápida y sencilla, lo que facilita la visualización y prueba del proyecto en su estado actual.


### Carpetas
- bin/ - Contiene los ejecutables del proyecto
- src/ - Contiene el codigo fuente
- include/ - Los archivos de cabecera
- assets/ - Contiene los recuros del proyecto
- docs/ - Contiene la documentacion del proyecto

# Descripcion
El propósito de este proyecto es simular las primeras versiones de un videojuego del tipo ahorcado. Por el momento, las funcionalidades incluyen una animación que representa cómo se vería el juego. Sin embargo, se tiene la intención de completar el desarrollo del juego en su totalidad.

El estado actual del proyecto consiste en establecer las bases fundamentales para la creación del videojuego. Para elaborar y presentar la idea, se emplearon bibliotecas especializadas en el desarrollo de entornos gráficos, como FTXUI, así como técnicas de arte ASCII.

Para utilizar el código, únicamente se requiere contar con todas las dependencias instaladas y luego ejecutarlo.

# Dependencias

## FTXUI
`git clone https://github.com/ArthurSonzogni/FTXUI.git`
`sudo apt install cmake`
`cd FTXUI`
`mkdir build`
`cd build`
`cmake ..`
`make`
`sudo make install`


## Plugins VSCode
- material icon
- plant uml
- c/c++

## Graphviz
`sudo apt update`
`sudo apt install graphviz`
