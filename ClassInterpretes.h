#ifndef CLASSINTERPRETES_H_INCLUDED
#define CLASSINTERPRETES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;

class Interprete{
private:
    int IDInterprete,TipoInterprete,TipoMusica;
    char Nombre[40],Nacionalidad[20];
    bool Estado=true;
public:
    ///SETS
    void setIDInterprete(int i){IDInterprete=i;}
    void setTipoInterprete(int t){TipoInterprete=t;}
    void setTipoMusica(int m){TipoMusica=m;}
    void setNombre(char* n){strcpy(Nombre,n);}
    void setNacionalidad(char* na){strcpy(Nacionalidad,na);;}
    void setEstado(bool e){Estado=e;}
    ///GETS
    int getIDInterprete(){return IDInterprete;}
    int getTipoInterprete(){return TipoInterprete;}
    int getTipoMusica(){return TipoMusica;}
    char* getNombre(){return Nombre;}
    char* getNacionalidad(){return Nacionalidad;}
    bool getEstado(){return Estado;}
    ///METODOS
    void Cargar();
    void Mostrar();
};
////////////////////////////////////////
///CONTAR TOTAL DE REGISTROS DE INTERPRETE
int ContarInterpretes(){
    int cantidad=0;
    Interprete obj;
    FILE *p;
    p=fopen("Interpretes.dat","rb");
    while(fread(&obj,sizeof obj,1,p)==1){
        cantidad++;}
        fclose(p);
        return cantidad;
}
////////////////////////////////////////
///CARGAR
void Interprete::Cargar(){
    bool continuar=true;
    IDInterprete=ContarInterpretes()+1;
    while(continuar==true){
    cout<<"INGRESE UN VALOR CORRESPONDIENTE AL TIPO DE INTERPRETE: ";
    cin>>TipoInterprete;
    if(TipoInterprete>0&&TipoInterprete<6){continuar=false;}
    else{cout<<"VALOR INVALIDO!(DEBE SER DEL 1 AL 5)"<<endl;}}
    continuar=true;
    while(continuar==true){
    cout<<"INGRESE UN VALOR CORRESPONDIENTE AL TIPO DE MUSICA: ";
    cin>>TipoMusica;
    if(TipoMusica>0&&TipoMusica<11){continuar=false;}
    else{cout<<"VALOR INVALIDO!(DEBE SER DEL 1 AL 10)"<<endl;}}
    cout<<"INGRESE EL NOMBRE DEL INTERPRETE: ";
    cin.ignore();
    cin.getline(Nombre,40);
    cout<<"INGRESE LA NACIONALIDAD DEL INTERPRETE: ";
    cin.ignore(0);
    cin.getline(Nacionalidad,20);

}
///MOSTRAR
void Interprete::Mostrar(){
    cout<<"ID DEL INTERPRETE: "<<IDInterprete<<endl;
    cout<<"TIPO DE INTERPRETE NUMERO: "<<TipoInterprete<<endl;
    cout<<"TIPO DE MUSICA NUMERO: "<<TipoMusica<<endl;
    cout<<"NOMBRE: "<<Nombre<<endl;
    cout<<"NACIONALIDAD: "<<Nacionalidad<<endl;
}
#endif // CLASSINTERPRETES_H_INCLUDED
