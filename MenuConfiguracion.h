#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
///
///
///
///ESTAS FUNCIONES AUN NO FUERON TESTEADAS
///
///
///
///CREAR BACKUP CANCIONES
void BackupCanciones(){
FILE *p,*pBackup;
Cancion reg;
p=fopen("Canciones.dat","rb");
pBackup=fopen("Canciones.bkp","wb");
while(fread(&reg,sizeof reg,1,p)==1){
    fwrite(&reg,sizeof reg,1,pBackup);}
fclose(p);
fclose(pBackup);
}
///CREAR BACKUP INTERPRETES
void BackupInterpretes(){
FILE *p,*pBackup;
Interprete reg;
p=fopen("Interpretes.dat","rb");
pBackup=fopen("Interpretes.bkp","wb");
while(fread(&reg,sizeof reg,1,p)==1){
    fwrite(&reg,sizeof reg,1,pBackup);}
fclose(p);
fclose(pBackup);
}
///RESTAURAR CANCIONES
void RestaurarCanciones(){
FILE *p,*pBackup;
Cancion reg;
p=fopen("Canciones.dat","wb");
pBackup=fopen("Canciones.bkp","rb");
while(fread(&reg,sizeof reg,1,pBackup)==1){
    fwrite(&reg,sizeof reg,1,p);}
fclose(p);
fclose(pBackup);
}
///RESTAURAR INTERPRETES
void RestaurarInterpretes(){
FILE *p,*pBackup;
Interprete reg;
p=fopen("Interpretes.dat","wb");
pBackup=fopen("Interpretes.bkp","rb");
while(fread(&reg,sizeof reg,1,pBackup)==1){
    fwrite(&reg,sizeof reg,1,p);}
fclose(p);
fclose(pBackup);
}
///ESTABLECER DATOS DE INICIO
void DatosInicio(){
FILE *p1,*pBackup1,*p2,*pBackup2;
Cancion reg1;
Interprete reg2;
p1=fopen("Canciones.dat","wb");
pBackup1=fopen("CancionesInicial.dat","rb");
p2=fopen("Interpretes.dat","wb");
pBackup2=fopen("InterpretesInicial.dat","rb");
while(fread(&reg1,sizeof reg1,1,pBackup1)==1){
    fwrite(&reg1,sizeof reg1,1,p1);}
while(fread(&reg2,sizeof reg2,1,pBackup2)==1){
    fwrite(&reg2,sizeof reg2,1,p2);}
fclose(p1);
fclose(pBackup1);
fclose(p2);
fclose(pBackup2);
}
using namespace std;
void MenuConfiguraciones(){
int opcion;
bool continuar=true;
while(continuar==true){
system("cls");
cout<<"MENU CONFIGURACION\n"
"------------------\n"
"1) HACER COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES\n"
"2) HACER COPIA DE SEGURIDAD DEL ARCHIVO DE INTERPRETES\n"
"3) RESTAURAR EL ARCHIVO DE CANCIONES\n"
"4) RESTAURAR EL ARCHIVO DE INTERPRETES\n"
"5) ESTABLECER DATOS DE INICIO\n"
"--------------------------------\n"
"0) VOLVER AL MENU PRINCIPAL\n"
"INGRESE UNA OPCION:";
cin>>opcion;
system("cls");
switch (opcion){
case 1:BackupCanciones();
    break;
case 2:BackupInterpretes();
    break;
case 3:RestaurarCanciones();
    break;
case 4:RestaurarInterpretes();
    break;
case 5:DatosInicio();
case 0:
    continuar=false;
    break;
default:
    cout<<"OPCION INCORRECTA!"<<endl;
    break;
}}
}


#endif // MENUCONFIGURACION_H_INCLUDED
