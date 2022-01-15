#ifndef PARCIAL_FRANCO_H_INCLUDED
#define PARCIAL_FRANCO_H_INCLUDED
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
///
class Interpretes2021{
    private:
    int IDInterprete;
    char Nombre[40],Nacionalidad[20];
public:
    ///SETS
    void setIDInterprete(int i){IDInterprete=i;}
    void setNombre(char* n){strcpy(Nombre,n);}
    void setNacionalidad(char* na){strcpy(Nacionalidad,na);;}
    ///GETS
    int getIDInterprete(){return IDInterprete;}
    char* getNombre(){return Nombre;}
    char* getNacionalidad(){return Nacionalidad;}
};
void ParcialPunto1(){
int Tipo;
cout<<"INGRESE EL TIPO DE MUSICA QUE DESA BUSCAR: ";
cin>>Tipo;
if(Tipo>0&&Tipo<11){
FILE *p;
Interprete reg;
p=fopen("Interpretes.dat","rb");
while(fread(&reg,sizeof reg,1,p)==1){
    if(reg.getTipoMusica()==Tipo){
            reg.Mostrar();
            cout<<"----------------------"<<endl;}}
fclose(p);}
else{cout<<"VALOR INCORRECTO(1 AL 10)"<<endl;}
system("pause");
}
///
void VectorCero(int v[]){
int i;
for(i=0;i<10;i++){
    v[i]=0;}
}
void ParcialPunto2(){
Interprete obj;
int t[10],cant,i,ii;
VectorCero(t);
cant=ContarInterpretes();
for(i=0;i<10;i++){
    for(ii=0;ii<cant;ii++){
        obj=LeerRegistroInterprete(ii);
        if(obj.getTipoMusica()==(i+1)){
        if(obj.getTipoInterprete()==1){
            t[i]++;
        }}}
}
int valormax,nummax;
for(i=0;i<10;i++){
    if(i==0){
            nummax=i+1;
            valormax=t[i];}
    else{if(t[i]>valormax){
        nummax=i+1;
        valormax=t[i];}}
}
cout<<"EL TIPO DE MUSICA NUMERO "<<nummax<<" ES EL QUE TIENE MAS CANTIDAD DE INTERPRETES SOLISTAS"<<endl;
cout<<"EL TOTAL ES IGUAL A "<<valormax<<" INTERPRETES"<<endl;
system("pause");
}
void ParcialPunto3(){
FILE *p;
p=fopen("Interpretes2021.dat","wb");
Interpretes2021 objI2021;
Interprete objI;
Cancion objC;
int cantI,cantC,i,ii;
cantI=ContarInterpretes();
cantC=ContarCanciones();
for(i=0;i<cantI;i++){
    objI=LeerRegistroInterprete(i);
    for(ii=0;ii<cantC;ii++){
        objC=LeerRegistroCancion(ii);
        if(objC.getIDInterprete()==objI.getIDInterprete()){
            if(objC.getFechaEstreno().getAnio()==2021){
                objI2021.setIDInterprete(objI.getIDInterprete());
                objI2021.setNombre(objI.getNombre());
                objI2021.setNacionalidad(objI.getNacionalidad());
                fwrite(&objI2021,sizeof objI2021,1,p);}}
}
}
}
#endif // PARCIAL_FRANCO_H_INCLUDED
