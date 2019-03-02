#include <iostream>
#include <fstream>
using namespace std;

int main(){
ifstream entrada;
char linea [80];
entrada.open("EstadoDeFlujoEntreProgramaYArchivo.cpp");
while (!entrada.eof()){
    entrada.getline(linea,80);
    cout<<linea<<endl;
}
entrada.close();
return 0;
}
