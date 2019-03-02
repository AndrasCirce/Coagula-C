#include <iostream>
using namespace std;

struct Fecha{
int dia;
int mes;
int anio;
};

struct Persona{
char nombre[30];
char apellido[30];
char sexo;
int edad;
Fecha fechaNacimiento;
};

void llenarPersonas(Persona[],int);
void mostrarVerones(Persona[],int,Fecha,Fecha);
Persona leerPersona();
Fecha leerFecha();
bool leTocaServicio(Persona,Fecha,Fecha);
int numDias(Fecha);

int main() {
Persona personas[30];
int N=4;
Fecha ini, f;
llenarPersonas(personas,N);
cout<<"Fecha de inicio";
ini=leerFecha();
cout<<"Fecha de fin";
f = leerFecha();
cout<<endl;
mostrarVerones(personas,N,ini,f);
return 0;
}

void llenarPersonas(Persona P[],int N){
for (int i=0; i<N; i++){
    cout<<"PERSONA"<<i+1<<endl;
    P[i] = leerPersona();
    cout <<endl;
    }
}

void mostrarVerones(Persona P[],int N,Fecha ini,Fecha f){
for (int i=0; i<N; i++){
    if((P[i].sexo == 'M') && (leTocaServicio(P[i],ini,f))){
        cout<<" Nombre :"<<P[i].nombre<<endl;
        cout<<"Apellido:"<<P[i].apellido<<endl;
        cout<<"    Edad:"<<P[i].edad<<endl;
        cout<<endl;
    }
    }
}

Persona leerPersona(){
    Persona p;
    cout<<"  Nombre: ";
    cin.getline(p.nombre,30);
    cout<<"Apellido: ";
    cin.getline(p.apellido,30);
    cout<<"    Edad: ";
    cin>>p.edad;
    cout<<"    Sexo: ";
    cin>>p.sexo;
    cout<<"Ingresa la fecha de nacimiento: ";
    p.fechaNacimiento = leerFecha();
    cin.ignore();
    return p;
    }

Fecha leerFecha() {
 Fecha f;
 cin>>f.dia>>f.mes>>f.anio;
 return f;
 }

bool leTocaServicio(Persona P,Fecha ini,Fecha f){
    int diasIni = numDias(ini);
    int diasFin = numDias(f);
    int diasNacimiento = numDias(P.fechaNacimiento);
    if(diasIni<= diasNacimiento && diasNacimiento<= diasFin){
        return true;
       }else{
       return false;}
    }


int numDias(Fecha f){
return f.dia + f.mes*30+f.anio*365;
}
