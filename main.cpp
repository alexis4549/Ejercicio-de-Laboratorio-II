#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include"ClassFecha.h"
#include"ClassCanciones.h"
#include"ClassInterpretes.h"
#include"MenuCanciones.h"
#include"MenuInterpretes.h"
#include"MenuReportes.h"
#include"MenuConfiguracion.h"
using namespace std;
void MenuPrincipal(){
    cout<<"MENU PRINCIPAL\n"
    "-----------------------\n"
    "1)MENU CANCIONES\n"
    "2)MENU INTERPRETES\n"
    "3)MENU REPORTES\n"
    "4)CONFIGURACION\n"
    "-----------------------\n"
    "0)FINALIZAR PROGRAMA\n"
    "\n"
    "SELECCIONE UNA OPCION: ";
}
int main()
{
    int opcion;
    while(true){
    system("cls");
    MenuPrincipal();
    cin>>opcion;
    switch(opcion){
    case 1:FuncionPrincipalCanciones();
    break;
    case 2:FuncionPrincipalInterpretes();
    break;
    case 3:FuncionPrincipalReportes();
    break;
    case 4:MenuConfiguraciones();
    break;
    case 0:
        return 0;
    break;
    default:
    system("cls");
    cout<<"OPCION INCORRECTA!"<<endl;
    system("pause");
    break;}
}
}
