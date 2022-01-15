#ifndef MENUCANCIONES_H_INCLUDED
#define MENUCANCIONES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
#include"ClassCanciones.h"
////////////////////////////////////////
///BUSCA UNA ID QUE SE DA COMO PARAMETRO Y DEVUELVE SU POSICION; SI NO SE ENCUENTRA DEVUELVE -1
int BuscarIDCancion(int ID){
    int pos=0;
    Cancion obj;
    FILE *p;
    p=fopen("Canciones.dat","rb");
    while(fread(&obj,sizeof obj,1,p)==1){
            if(obj.getIDCancion()==ID){
            fclose(p);
            return pos;}
            pos++;}
    fclose(p);
    return -1;
}
///LEE UN REGISTRO DADA UNA POSICION SI NO EXISTE DEVUELVE UN REGISTRO CON ID IGUAL A 0
Cancion LeerRegistroCancion(int pos){
    Cancion obj;
    FILE *p;
    p=fopen("Canciones.dat","rb");
    fseek(p,pos*sizeof obj,0);
    if(fread(&obj,sizeof obj,1,p)==1){
            fclose(p);
            return obj;}
    else{
        obj.setIDCancion(0);
        fclose(p);
        return obj;}
}
///GRABAR UN REGISTRO
void GrabarRegistroCancion(Cancion obj){
    FILE *p;
    p=fopen("Canciones.dat","ab");
    fwrite(&obj,sizeof obj,1,p);
    fclose(p);
}
///GRABAR REGISTRO DADA UNA POSICION
void GrabarRegistroCancionPosicion(Cancion obj,int pos){
    FILE *p;
    p=fopen("Canciones.dat","rb+");
    fseek(p,pos*sizeof obj,0);
    fwrite(&obj,sizeof obj,1,p);
    fclose(p);
}
///////////////////////////////////////////
///AGREGAR CANCION
void AgregarCancion(){
    Cancion obj;
    obj.Cargar();
    GrabarRegistroCancion(obj);}
///LISTAR CANCION POR ID
void ListarPorIDCancion(){
    Cancion obj;
    int ID,pos;
    cout<<"INGRESE LA ID QUE DESEA BUSCAR: ";
    cin>>ID;
    pos=BuscarIDCancion(ID);
    if(pos!=-1){
    obj=LeerRegistroCancion(pos);
    if(obj.getEstado()==true){
    obj.Mostrar();}
    else{cout<<"ID INEXISTENTE!"<<endl;}}
    else{cout<<"ID INEXISTENTE!"<<endl;}
    system("pause");
}
///LISTAR TODAS LAS CANCIONES
void ListarTodoCancion(){
    Cancion obj;
    int pos=0;
    while(true){
    obj=LeerRegistroCancion(pos);
    if(obj.getIDCancion()>0){
        if(obj.getEstado()==true){
                obj.Mostrar();
                cout<<"----------------------"<<endl;}}
    else{
        system("pause");
        return;}
        pos++;}
}
///MODIFICAR FECHA DE ESTRENO
void ModificarFechaEstreno(){
    Fecha NuevaFecha;
    Cancion obj;
    int ID,pos;
    cout<<"INGRESE LA ID QUE DESEA MODIFICAR: ";
    cin>>ID;
    pos=BuscarIDCancion(ID);
    if(pos==-1){cout<<"ID INEXISTENTE!"<<endl;
    system("pause");}
    else{
    obj=LeerRegistroCancion(pos);
    cout<<"INGRESE LA NUEVA FECHA: "<<endl;
    NuevaFecha.Cargar();
    obj.setFechaEstreno(NuevaFecha);
    GrabarRegistroCancionPosicion(obj,pos);}
}
///BAJA LOGICA
void BajaLogicaCancion(){
    Cancion obj;
    int ID,pos;
    cout<<"INGRESE LA ID QUE DESEA DAR DE BAJA: ";
    cin>>ID;
    pos=BuscarIDCancion(ID);
    if(pos==-1){cout<<"ID INEXISTENTE!"<<endl;
    system("pause");}
    else{
    obj=LeerRegistroCancion(pos);
    obj.setEstado(false);
    GrabarRegistroCancionPosicion(obj,pos);}
}
///MENU
void MenuCanciones(){
    cout<<"MENU CANCIONES\n"
    "---------------------------------\n"
    "1)AGREGAR CANCION\n"
    "2)LISTAR CANCION POR ID\n"
    "3)LISTAR TODAS LAS CANCIONES\n"
    "4)MODIFICAR FECHA DE ESTRENO\n"
    "5)ELIMINAR CANCION\n"
    "---------------------------------\n"
    "0)VOLVER AL MENU PRINCIPAL\n"
    "\n"
    "SELECCIONE UNA OPCION: ";
}
///FUNCION PRINCIPAL
void FuncionPrincipalCanciones(){
int opcion;
    while(true){
    system("cls");
    MenuCanciones();
    cin>>opcion;
    system("cls");
    switch(opcion){
    case 1:AgregarCancion();
    break;
    case 2:ListarPorIDCancion();
    break;
    case 3:ListarTodoCancion();
    break;
    case 4:ModificarFechaEstreno();
    break;
    case 5:BajaLogicaCancion();
    break;
    case 0:
        return;
    break;
    default:
    system("cls");
    cout<<"OPCION INCORRECTA!"<<endl;
    system("pause");
    break;}
}
}
#endif // MENUCANCIONES_H_INCLUDED
