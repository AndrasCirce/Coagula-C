#include <iostream>
#include <fstream>
using namespace std;

int main(){

    /**Renombrar
    if(rename("archivo.txt","Nuevo Nombre.txt")==0){
        cout<<"El archivo se cambio de nombre"<<endl;
    }else{cout<<"Houston, hay un problema"<<endl;}**/

    //Eliminar
    if(remove("Nuevo Nombre.txt")==0){
        cout<<"la impureza se elimino"<<endl;
    }else{cout<<"Houston, hay un problema"<<endl;}
   return 0;
}

