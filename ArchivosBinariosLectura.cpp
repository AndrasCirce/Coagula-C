#include <iostream>
#include <fstream>
using namespace std;

struct Persona{
int edad;
char nombre [80];
};

/**El proceso de lectura es
desde archivo -> a la memoria
1. Desde que punto de la memormia voy a pasar los bytes
2. cuantos bytes se van a pasar**/

/**
1. Un puntero que indique la posición desde donde se va a escribir
2. Cuantos bytes se van a pasar**/

int main (){
    Persona p;
    ifstream entrada;
    entrada.open("data.bin",ios::binary);
    entrada.read((char*)&p,sizeof(Persona));
    cout<<p.nombre<<endl;
    cout<<p.edad<<endl;
    entrada.close();
    return 0;
}

