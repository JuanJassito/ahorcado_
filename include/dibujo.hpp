#include <ftxui/dom/elements.hpp>
#include <fstream>
#include <string> 

using namespace std;
using namespace ftxui;

class dibujo
{
private:
    ifstream archivo;
    Element contenido;
public:
    dibujo(string path)
    {
        archivo.open(path);
        Elements elementos1;
        string linea;
        while (getline(archivo, linea))
        {
            elementos1.emplace_back(text(linea));
        }
        contenido = vbox(elementos1);
        archivo.close();
    }
    
    
    Element getElement(){
        return this -> contenido;
    }


    ~dibujo()
    {

    }
};