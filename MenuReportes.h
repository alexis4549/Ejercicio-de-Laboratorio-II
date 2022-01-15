#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
#include"ClassCanciones.h"
#include"ClassInterpretes.h"
#include"MenuCanciones.h"
#include"MenuInterpretes.h"
#include"Parcial_Franco.h"
void Reportes1(){
Cancion objCancion;
Interprete objInterprete;
int posCancion=0,posInterprete=0,cantidad,i,ii;
posCancion=ContarCanciones();
posInterprete=ContarInterpretes();
for(i=0;i<posInterprete;i++){
    objInterprete=LeerRegistroInterprete(i);
    if(objInterprete.getEstado()==true&&objInterprete.getIDInterprete()!=0){
    cout<<"ID DE INTERPRETE: "<<objInterprete.getIDInterprete()<<endl;
    cout<<"NOMBRE DEL INTERPRETE: "<<objInterprete.getNombre()<<endl;
    cantidad=0;
    for(ii=0;ii<posCancion;ii++){
        objCancion=LeerRegistroCancion(ii);
        if(objCancion.getIDCancion()!=0){
        if(objInterprete.getIDInterprete()==objCancion.getIDInterprete()&&objCancion.getEstado()==true){
            cantidad++;}}}
    cout<<"CANTIDAD DE CANCIONES:" <<cantidad<<endl;
    cout<<"--------------------------"<<endl;}}
system("pause");
}
///MENU
void MenuReportes(){
    cout<<"MENU REPORTES\n"
    "---------------------------------\n"
    "1)MOSTRAR POR CADA INTERPRETE LA CANTIDAD DE CANCIONES REGISTRADAS\n"
    "2)PARCIAL PUNTO 1\n"
    "3)PARCIAL PUNTO 2\n"
    "4)PARCIAL PUNTO 3\n"
    "---------------------------------\n"
    "0)VOLVER AL MENU PRINCIPAL\n"
    "\n"
    "SELECCIONE UNA OPCION: ";
}
void FuncionPrincipalReportes(){
int opcion;
    while(true){
    system("cls");
    MenuReportes();
    cin>>opcion;
    system("cls");
    switch(opcion){
    case 1:Reportes1();
    break;
    case 2:ParcialPunto1();
    break;
    case 3:ParcialPunto2();
    break;
    case 4:ParcialPunto3();
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
#endif // MENUREPORTES_H_INCLUDED
