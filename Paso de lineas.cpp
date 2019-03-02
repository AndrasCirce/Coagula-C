#include <iostream>
#include <fstream>
using namespace std;
/**Escribe un programa que lea el archivo "archivo.txt"
escribe otro archivo "arcivo2.TXT con el contenido del primero
todo en mayusculas **/

void pasarAMayusculas(char cadeba[]);
void pasarLineas(char origen[],char destino[]);
int main(){
    pasarLineas("archivo.txt","archivo2.txt");

    return 0;
}

void pasarAMayusculas(char cadena[]){
int i=0;
while(cadena[i]){
    cadena[i]= toupper(cadena[i]);
    i++;
}
}

void pasarLineas(char origen[], char destino[]){
    ifstream entrada;
    ofstream salida;
    char linea [256];
    entrada.open(origen);
    salida.open(destino);
    if(entrada.good()){
       while(!entrada.eof()){
        entrada.getline(linea,256);
        pasarAMayusculas(linea);
        salida << linea<<endl;

       }
    }else{
        cout<<"Houston, hay un problema"<<endl;
    }
    entrada.close();
    salida.close();
}
