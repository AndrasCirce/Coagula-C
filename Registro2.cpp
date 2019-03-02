#include <iostream>

using namespace std;

 struct Alumno{
 char nombre[30];
 float cali1;
 float cali2;
 float cali3;
 float promedio;
 };

 void llenarAlumnos(Alumno[],int);
 void mostrarAlumnos(Alumno[],int);
 void ordenarpromedio(Alumno[],int);

 int main(){
Alumno alumnos[30];
int N=4;
llenarAlumnos(alumnos,N);
ordenarpromedio(alumnos, N);
mostrarAlumnos(alumnos, N);


 return 0;
 }

 void llenarAlumnos(Alumno A[],int N){
 for(int i=0;i<N;i++){
    cout<<"ALUMNO"<<i+1<<endl;
    cout<<"Nombre : ";
    cin.getline(A[i].nombre,30);
    cout <<"Nota 1: ";
    cin>>A[i].cali1;
    cin.ignore();
    cout <<"Nota 2: ";
    cin>>A[i].cali2;
    cin.ignore();
    cout <<"Nota 3: ";
    cin>>A[i].cali3;
    cin.ignore();
    cout<<endl;
    A[i].promedio= (A[i].cali1+A[i].cali2+A[i].cali3)/3;
    }
 }

 void mostrarAlumnos(Alumno A[],int N){
for(int i=0;i<N;i++){
    cout<<"  Nombre: "<<A[i].nombre<<endl;
    cout<<"Promedio: "<<A[i].promedio<<endl;
    cout<<endl;

}
 }

 void ordenarpromedio(Alumno A[],int N){
 for(int i=0;i<N;i++){
    for(int j=0;j<N-1;j++){
        if(A[j].promedio<A[j+1].promedio){
            Alumno aux = A[j];
            A[j]=A[j+1];
            A[j+1]=aux;
        }
    }
}
 }
