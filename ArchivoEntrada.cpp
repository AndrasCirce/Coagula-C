#include <iostream>
#include <fstream>
using namespace std;

int main(){
ifstream entrada;
entrada.open("archivo.txt");
char linea[80];
entrada.getline(linea,80);
cout<<linea<<endl;
entrada.close();
return 0;
}
