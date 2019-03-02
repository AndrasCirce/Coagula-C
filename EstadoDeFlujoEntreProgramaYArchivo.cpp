#include <iostream>
#include <fstream>
using namespace std;

/**Estado del archivo

bad()  Cuando no hay permiso de leer, no hay espacio, no existe archivo
fail() Error de formato
eof() Fin del archivo
good()   **/

int main(){
ifstream entrada;
entrada.open("archivo.txt");
if(entrada.good()){
    cout<<"Todo chido"<<endl;
}else{
cout<<"wasted :v"<<endl;}
return 0;
}
