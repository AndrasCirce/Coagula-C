#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const char DIR_ARCHIVO []= "contactos.dat";

struct Contacto{
char nombre [30];
char apellido [45];
int edad;
char correo [45];
};
//FUNCIONES del programa
void agregarContacto(Contacto c);
Contacto leerContactto();
bool existeContacto(char nombre[],char apellido[]);
Contacto buscarContacto(char nombre[],char apellido[]);
void mostraContacto(Contacto c);
void listarContactos();
void eliminarContacto(char nombre[], char apellido[]);
void actualizarContacto(char nombre[], char apellido[]);

//Funciones del menu
void menuIngresar();
void menuBuscar();
void menuListrar();
void menuEliminar();
void menuActualizar();

int main (){
    /*Agenda
    agregar contactos
    buscar un contacto
    ver contactos
    eliminar contacto
    actualizar contacto
    */
    int op;
    do{
        cout<<"\t\t\t\tAgenda Shida"<<endl;
        cout<<"\t\t\tIngresar contacto........[1]"<<endl;
        cout<<"\t\t\tBuscar contacto..........[2]"<<endl;
        cout<<"\t\t\tVer contactos............[3]"<<endl;
        cout<<"\t\t\tEliminar contacto........[4]"<<endl;
        cout<<"\t\t\tActualizar contacto......[5]"<<endl;
        cout<<"\t\t\tSalir....................[6]"<<endl;
        cout<<"\t\t\tIngresa una opcion: ";
        cin>>op;
        cin.ignore();
        switch(op){
            case 1: menuIngresar();
            break;
            case 2: menuBuscar();
            break;
            case 3: menuListrar();
            break;
            case 4: menuEliminar();
            break;
            case 5: menuActualizar();
            break;
            case 6: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }
    }while(op!=6);

    return 0;
}


void agregarContacto(Contacto c){
    ofstream salida;
    salida.open(DIR_ARCHIVO,ios::binary | ios::app);
    salida.write((char*)&c,sizeof(Contacto));
    salida.close();
}

Contacto leerContactto(){
Contacto c;
cout<<"\t\t\t  Nombre: ";
cin.getline(c.nombre,30);
cout<<"\t\t\tApellido: ";
cin.getline(c.apellido,45);
cout<<"\t\t\t    Edad: ";
cin>>c.edad;
cin.ignore();
cout<<"\t\t\t  Correo: ";
cin.getline(c.correo,45);
return c;
}

bool existeContacto(char nombre[],char apellido[]){
    Contacto c;
    ifstream entrada;
    entrada.open(DIR_ARCHIVO,ios::binary);
    if(entrada.good()){
        while(entrada.read((char*)&c,sizeof(Contacto))){
            /**strcm = string compariction**/
            if(strcmp(nombre,c.nombre)==0 && strcmp(apellido,c.apellido)==0){
                entrada.close();
                return true;
            }
        }
        entrada.close();
        return false;
    }
    else{
    entrada.close();
    return false;
    }
}
Contacto buscarContacto(char nombre[],char apellido[]){
    Contacto c;
    ifstream entrada;
    entrada.open(DIR_ARCHIVO,ios::binary);
    if(entrada.good()){
        while(entrada.read((char*)&c,sizeof(Contacto))){
            /**strcm = string compariction**/
            if(strcmp(nombre,c.nombre)==0 && strcmp(apellido,c.apellido)==0){
                entrada.close();
                return c;
            }
        }
    }
}
void mostraContacto(Contacto c){
    cout<<endl;
    cout<<"\t\t\t   Nombre: "<<c.nombre<<endl;
    cout<<"\t\t\t Apellido: "<<c.apellido<<endl;
    cout<<"\t\t\t     Edad: "<<c.edad<<endl;
    cout<<"\t\t\t   Correo: "<<c.correo<<endl;
    cout<<endl;
}

void listarContactos(){
    ifstream entrada;
    entrada.open(DIR_ARCHIVO,ios::binary);
    Contacto c;
    if(entrada.good()){
        while(entrada.read((char*)&c,sizeof (Contacto))){
            mostraContacto(c);
        }
    }
    else{
        cout<<"No puede leer archivo"<<endl;
    }
     entrada.close();
}

void eliminarContacto(char nombre[], char apellido[]){
/**Se creará un archivo donde se copiarán todos
    los registros menos el que se desea borrar
    y despues se renombrará para que trabaje el programa
    con la constante**/
ifstream entrada;
ofstream retornable;
entrada.open(DIR_ARCHIVO,ios::binary);
retornable.open("temp.dat",ios::binary);
Contacto c;
    if(entrada.good()){
        while(entrada.read((char*)&c,sizeof (Contacto))){
          if(strcmp(nombre,c.nombre)!=0 || strcmp(apellido,c.apellido)!=0){
                retornable.write((char*)&c,sizeof(Contacto));
            }
        }
    }

entrada.close();
retornable.close();
remove(DIR_ARCHIVO);
rename("temp.dat",DIR_ARCHIVO);
}

void actualizarContacto(char nombre[], char apellido[]){
    /**Se creará un nuevo archivo en el que se creará un nuevo registro para poder
        "actualizzar" el contacto**/
 ifstream entrada;
ofstream retornable;
entrada.open(DIR_ARCHIVO,ios::binary);
retornable.open("temp.dat",ios::binary);
Contacto c;
    if(entrada.good()){
        while(entrada.read((char*)&c,sizeof (Contacto))){
          if(strcmp(nombre,c.nombre)==0 && strcmp(apellido,c.apellido)==0){
                Contacto nuevesito = leerContactto();
                retornable.write((char*)&nuevesito,sizeof(Contacto));
            }
            else{
                retornable.write((char*)&c,sizeof(Contacto));
            }
        }
    }

entrada.close();
retornable.close();
remove(DIR_ARCHIVO);
rename("temp.dat",DIR_ARCHIVO);
}

/**/
void menuIngresar(){
    cout<<"\t\t\t\tIngreso de nuevo contacto"<<endl;
    Contacto nuevo= leerContactto();
    agregarContacto(nuevo);
    cout<<"\t\t\t\tContacto agregado"<<endl;
}
void menuBuscar(){
    cout<<"\t\t\t\tBuscar contacto"<<endl;
    char nombre[30],apellido[45];
    cout<<"\t\tIngreso los datos de busqueda"<<endl;
    cout<<"\t\t\tNombre: ";
    cin.getline(nombre,30);
    cout<<"\t\t\tApellido: ";
    cin.getline(apellido,45);
    if (existeContacto(nombre,apellido)){
        Contacto buscado = buscarContacto(nombre,apellido);
        mostraContacto(buscado);
    }
    else{
       cout<<"\t\t\t\tNo encontramos contacto"<<endl;
    }
}

void menuListrar(){
    cout<<"\t\t\tLista de contacto"<<endl;
 listarContactos();
}
void menuEliminar(){
    cout<<"\t\t\t\tEliminar contacto"<<endl;
    char nombre[30],apellido[45];
    cout<<"\t\tIngreso los datos a eliminar"<<endl;
    cout<<"\t\t\tNombre: ";
    cin.getline(nombre,30);
    cout<<"\t\t\tApellido: ";
    cin.getline(apellido,45);
    if(existeContacto(nombre,apellido)){
        Contacto eliminar = buscarContacto(nombre,apellido);
        int opcion;
        cout<<"\t\t¿Seguro que borraras a sta/ste shaba/men?"<<endl;
        mostraContacto(eliminar);
        do{
          cout<<"\t\t\tSi[1]....No[2] "<<endl;
            cin>>opcion;
            switch(opcion){
                case 1:eliminarContacto(nombre,apellido);
                cout<<"\t\t\tContacto eliminado"<<endl;
                break;
                case 2: break;
                default: cout<<"\t\t\tOpcion incorrecta"<<endl;
            }
        }while(opcion!=1 && opcion!=2);

    }
    else {
        cout<<"\t\tNo existe el contacto"<<endl;
    }
}
void menuActualizar(){
cout<<"\t\t\t\tActualizar contacto"<<endl;
    char nombre[30],apellido[45];
    cout<<"\t\tIngreso los datos a actualizar"<<endl;
    cout<<"\t\t\tNombre: ";
    cin.getline(nombre,30);
    cout<<"\t\t\tApellido: ";
    cin.getline(apellido,45);
    if(existeContacto(nombre,apellido)){
        Contacto buscado = buscarContacto(nombre,apellido);
        cout<<"\t\t\tRegistro a modificar"<<endl;
        mostraContacto(buscado);
        actualizarContacto(nombre,apellido);
        cout<<"\t\t\tSe actualizo el contacto"<<endl;
        }
    else {
        cout<<"\t\tNo existe el contacto"<<endl;
    }
}
