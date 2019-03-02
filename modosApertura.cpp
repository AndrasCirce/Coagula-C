#include <iostream>
#include <fstream>
using namespace std;

/**Modos de apertura

ios:: in modo de lectura
ios:: out modo de escritura
ios:: ate te posiciona al final del docto para hacer cambios deonde quieras
ios:: app todo lo que escribas en este modo se pondrá al final del docto, respetando lo anteriormente escrito
ios:: trunc reescribe todo el docto**/


int main(){
ofstream salida;
salida.open("archivo.txt",ios::app);
salida<<"Linea 1"<<endl;
salida<<"Linea 2"<<endl;
salida<<"Linea 3"<<endl;
salida.close();
return 0;
}
