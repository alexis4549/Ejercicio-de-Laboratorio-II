#ifndef MENUINTERPRETES_H_INCLUDED
#define MENUINTERPRETES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
#include"ClassInterpretes.h"
////////////////////////////////////////
///BUSCA UNA ID QUE SE DA COMO PARAMETRO Y DEVUELVE SU POSICION; SI NO SE ENCUENTRA DEVUELCE -1
int BuscarIDInterprete(int ID){
    int pos=0;
    Interprete obj;
    FILE *p;
    p=fopen("Interpretes.dat","rb");
    while(fread(&obj,sizeof obj,1,p)==1){
            if(obj.getIDInterprete()==ID){
            fclose(p);
            return pos;}
            pos++;}
    fclose(p);
    return -1;
}
///LEE UN REGISTRO DADA UNA POSICION Y LO DEVUELVE ,SI NO EXISTE DEVUELVE UN REGISTRO CON ID IGUAL A 0
Interprete LeerRegistroInterprete(int pos){
    Interprete obj;
    FILE *p;
    p=fopen("Interpretes.dat","rb");
    fseek(p,pos*sizeof obj,0);
    if(fread(&obj,sizeof obj,1,p)==1){
            fclose(p);
            return obj;}
    else{
        obj.setIDInterprete(0);
        fclose(p);
        return obj;}
}
///GRABAR UN REGISTRO
void GrabarRegistroInterprete(Interprete obj){
    FILE *p;
    p=fopen("Interpretes.dat","ab");
    fwrite(&obj,sizeof obj,1,p);
    fclose(p);
}
///GRABAR REGISTRO DADA UNA POSICION
void GrabarRegistroInterpretePosicion(Interprete obj,int pos){
    FILE *p;
    p=fopen("Interpretes.dat","rb+");
    fseek(p,pos*sizeof obj,0);
    fwrite(&obj,sizeof obj,1,p);
    fclose(p);
}
///////////////////////////////////////////
///AGREGAR INTERPRETE
void AgregarInterprete(){
    Interprete obj;
    obj.Cargar();
    GrabarRegistroInterprete(obj);}
///LISTAR INTERPRETE POR ID
void ListarPorIDInterprete(){
    Interprete obj;
    int ID,pos;
    cout<<"INGRESE LA ID QUE DESEA BUSCAR: ";
    cin>>ID;
    pos=BuscarIDInterprete(ID);
    if(pos!=-1){
    obj=LeerRegistroInterprete(pos);
    if(obj.getEstado()==true){
    obj.Mostrar();}
    else{cout<<"ID INEXISTENTE!"<<endl;}}
    else{cout<<"ID INEXISTENTE!"<<endl;}
    system("pause");
}
///LISTAR TODOS LOS INTERPRETES
void ListarTodoInterprete(){
    Interprete obj;
    int pos=0;
    while(true){
    obj=LeerRegistroInterprete(pos);
    if(obj.getIDInterprete()>0){
        if(obj.getEstado()==true){
                obj.Mostrar();
                cout<<"----------------------"<<endl;}}
    else{
        system("pause");
        return;}
        pos++;}
}
///MODIFICAR FECHA DE ESTRENO
void ModificarTipoMusica(){
    int NuevoTipo;
    Interprete obj;
    int ID,pos;
    cout<<"INGRESE LA ID QUE DESEA MODIFICAR: ";
    cin>>ID;
    pos=BuscarIDInterprete(ID);
    if(pos==-1){cout<<"ID INEXISTENTE!"<<endl;
    system("pause");}
    else{
    obj=LeerRegistroInterprete(pos);
    cout<<"INGRESE EL NUEVO TIPO DE MUSICA: ";
    cin>>NuevoTipo;
    if(NuevoTipo>0&&NuevoTipo<11){
    obj.setTipoMusica(NuevoTipo);
    GrabarRegistroInterpretePosicion(obj,pos);}
    else{cout<<"VALOR DE TIPO DE MUSICA INVALIDO!"<<endl;
    system("pause");}}
}
///BAJA LOGICA
void BajaLogicaInterprete(){
    Interprete obj;
    int ID,pos;
    cout<<"INGRESE LA ID QUE DESEA DAR DE BAJA: ";
    cin>>ID;
    pos=BuscarIDInterprete(ID);
    if(pos==-1){cout<<"ID INEXISTENTE!"<<endl;
    system("pause");}
    else{
    obj=LeerRegistroInterprete(pos);
    obj.setEstado(false);
    GrabarRegistroInterpretePosicion(obj,pos);}
}
///MENU
void MenuInterpretes(){
    cout<<"MENU INTERPRETES\n"
    "---------------------------------\n"
    "1)AGREGAR INTERPRETE\n"
    "2)LISTAR INTERPRETE POR ID\n"
    "3)LISTAR TODOS LOS INTERPRETES\n"
    "4)MODIFICAR TIPO DE MUSICA\n"
    "5)ELIMINAR INTERPRETE\n"
    "---------------------------------\n"
    "0)VOLVER AL MENU PRINCIPAL\n"
    "\n"
    "SELECCIONE UNA OPCION: ";
}
///FUNCION PRINCIPAL
void FuncionPrincipalInterpretes(){
int opcion;
    while(true){
    system("cls");
    MenuInterpretes();
    cin>>opcion;
    system("cls");
    switch(opcion){
    case 1:AgregarInterprete();
    break;
    case 2:ListarPorIDInterprete();
    break;
    case 3:ListarTodoInterprete();
    break;
    case 4:ModificarTipoMusica();
    break;
    case 5:BajaLogicaInterprete();
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

#endif // MENUINTERPRETES_H_INCLUDED
