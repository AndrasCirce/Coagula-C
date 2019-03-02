#include <iostream>
#include <fstream>
using namespace std;

struct Persona{
int edad;
char nombre [80];
};

/**El proceso de escritura es
desde memoria -> al archivo
1. Desde que punto de la memormia iniciara el traspaso
2. cuantos bytes se van a pasar**/

/**
1. Un puntero que indique la posición desde donde se va a escribir
2. Cuantos bytes se van a pasar**/

int main (){
    ofstream salida;
    salida.open("data.bin",ios::binary);
    Persona p ={19,"Andres"};
    salida.write((char*)&p,sizeof(Persona));
    salida.close();
    return 0;
}
