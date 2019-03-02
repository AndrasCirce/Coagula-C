#include <iostream>
#include <fstream>
using namespace std;

int main(){
/*Pasos para trabajar con archivos de texto*/
/*
1. Abre el archivo
2. Opera el archivo
3. Cierra el archivo
*/

ofstream salida;
salida.open("archivo.txt");
salida<<"Hola men"<<endl;
salida.close();

return 0;
}
