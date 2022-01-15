#ifndef CLASSCANCIONES_H_INCLUDED
#define CLASSCANCIONES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include"ClassInterpretes.h"
using namespace std;
class Cancion{
private:
    int IDCancion,IDInterprete;
    char Nombre[30],NombreAutor[30];
    Fecha FechaEstreno;
    bool Estado=true;
public:
    ///SETS
    void setIDCancion(int c){IDCancion=c;}
    void setIDInterprete(int i){IDInterprete=i;}
    void setNombre(char* n){strcpy(Nombre,n);}
    void setNombreAutor(char* n){strcpy(NombreAutor,n);}
    void setFechaEstreno(Fecha f){FechaEstreno=f;}
    void setEstado(bool e){Estado=e;}
    ///GETS
    int getIDCancion(){return IDCancion;}
    int getIDInterprete(){return IDInterprete;}
    char* getNombre(){return Nombre;}
    char* getNombreAutor(){return NombreAutor;}
    Fecha getFechaEstreno(){return FechaEstreno;}
    bool getEstado(){return Estado;}
    ///METODOS
    void Cargar();
    void Mostrar();
};
//////////////////////////////////////////
///CONTAR TOTAL DE REGISTROS DE CANCIONES
int ContarCanciones(){
    int cantidad=0;
    Cancion obj;
    FILE *p;
    p=fopen("Canciones.dat","rb");
    while(fread(&obj,sizeof obj,1,p)==1){
        cantidad++;}
        fclose(p);
        return cantidad;
}
///VALIDAR SI EL INTERPRETE INGRESADO EXISTE
bool BuscarInterprete(int ID){
    Interprete obj;
    FILE *p;
    p=fopen("Interpretes.dat","rb");
    while(fread(&obj,sizeof obj,1,p)==1){
        if(ID==obj.getIDInterprete()){
                if(obj.getEstado()==true){
                fclose(p);
                return true;}}}
    fclose(p);
    return false;
}
///VALIDAR SI LA FECHA INGRESADA ES MENOR O IGUAL A LA FECHA ACTUAL
bool ValidarFecha(Fecha obj1){
    Fecha obj2;
    obj2.FechaActual();
    if(obj1<=obj2){return true;}
    else{return false;}
}
////////////////////////////////////////////
///CARGAR
void Cancion::Cargar(){
bool continuar=false;
IDCancion=ContarCanciones()+1;
while(continuar==false){
cout<<"INGRESE ID DE INTERPRETE:";
cin>>IDInterprete;
continuar=BuscarInterprete(IDInterprete);
if(continuar==false){cout<<"ID INEXISTENTE!"<<endl;}}
cout<<"INGRESE EL NOMBRE DE LA CANCION: ";
cin.ignore();
cin.getline(Nombre,30);
cout<<"INGRESE EL NOMBRE DEL AUTOR: ";
cin.ignore(0);
cin.getline(NombreAutor,30);
while(continuar==true){
cout<<"INGRESE LA FECHA DE ESTRENO:"<<endl;
FechaEstreno.Cargar();
if(ValidarFecha(FechaEstreno)==true){continuar=false;}
else{cout<<"FECHA INVALIDA!"<<endl;};}
}
///MOSTRAR
void Cancion::Mostrar(){
cout<<"ID DE LA CANCION: "<<IDCancion<<endl;
cout<<"ID DEL INTERPRETE: "<<IDInterprete<<endl;
cout<<"NOMBRE DE LA CANCION: "<<Nombre<<endl;
cout<<"NOMBRE DE EL AUTOR: "<<NombreAutor<<endl;
cout<<"FECHA DE ESTRENO: ";
FechaEstreno.Mostrar();
cout<<endl;
}

#endif // CLASSCANCIONES_H_INCLUDED
