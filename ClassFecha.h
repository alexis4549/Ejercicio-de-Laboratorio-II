#ifndef CLASSFECHA_H_INCLUDED
#define CLASSFECHA_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
///CLASE FECHA
class Fecha{
private:
    int Dia,Mes,Anio;
public:
    ///SETS
    void setDia(int d){Dia=d;}
    void setMes(int m){Mes=m;}
    void setAnio(int a){Anio=a;}
    ///GETS
    int getDia(){return Dia;}
    int getMes(){return Mes;}
    int getAnio(){return Anio;}
    ///METODOS
    void Cargar();
    void Mostrar();
    void FechaActual();
    bool operator<=(Fecha obj);
};
///CARGAR
void Fecha::Cargar(){
while(true){
cout<<"INGRESE EL DIA: ";
cin>>Dia;
cout<<"INGRESE EL MES: ";
cin>>Mes;
cout<<"INGRESE EL ANIO: ";
cin>>Anio;
if(Anio>1900&&(Mes>0&&Mes<13)&&(Dia>0&&Dia<31)){return;}
else{cout<<"FECHA INVALIDA INTENTE NUEVAMENTE!"<<endl;}
    }
}
///MOSTRAR
void Fecha::Mostrar(){
cout<<Dia<<"/"<<Mes<<"/"<<Anio;
}
//////////////////////////////////////////////////
///CARGAR FECHA ACTUAL
void Fecha::FechaActual(){
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	Dia=timePtr->tm_mday;
    Mes=timePtr->tm_mon+1;
    Anio=timePtr->tm_year+1900;
}
///FECHA MENOR O IGUAL (SOBRECARGA DE OPERADOR)
bool Fecha:: operator<=(Fecha obj){
    if(Anio>obj.Anio){return false;}
    else{if(Anio<obj.Anio){return true;}
    else{if(Mes>obj.Mes){return false;}
    else{if(Mes<obj.Mes){return true;}
    else{if(Dia<=obj.Dia){return true;}
    else{return false;}
    }}}}
}
#endif // CLASSFECHA_H_INCLUDED
