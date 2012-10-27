#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "maquina.h"

using namespace std;

int main(){

  maquina *m=new maquina();
  int salida=0;
  string file;
  string pap;
  string reco;
  string temp;
  string opc;
  char eps;
  
  while(salida==0){
    cout << "MAQUINA DE TURING" << endl << endl;
    cout << "Ingrese el archivo de la configuracion: ";
    cin >> file;
    cout << "Ingrese su caracter para la variable epsilon: ";
    cin >> eps;
    cout << endl << "Desea ver paso a paso o solo el resultado??" << endl;
    cout << "1) paso a paso" << endl << "2) solo resultado" << endl;
    cout << "seleccione la opcion: ";
    cin >> pap;
    cout << endl << "Desea reconocer o computar??" << endl;
    cout << "1) reconocer" << endl << "2) computar" << endl;
    cout << "seleccione la opcion: ";
    cin >> reco;
    cout << endl;
    maquina *m=new maquina();
    m->leerdatos(file);
    m->computar(pap,reco,eps);
    cout << "Desea configurar otra maquina???" << endl << "1) si" << endl << "2) no" << endl;
    cin >> opc;
    if(opc=="2"){
      salida=1;
    }else{
      m->~maquina();
    }
  }
  return 0;
}
  
