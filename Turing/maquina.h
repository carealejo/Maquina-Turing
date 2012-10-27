#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream> 
#include "trans.h"

using namespace std;

class maquina{
  
 private:
  //Cinta
  vector<char> cinta;
  int actual;
  int cabeza;

  //Configuracion
  fstream conf;
  vector<char> sigma;
  vector<char> gamma;
  int nestados;
  int estini;
  vector<int> esacep;
  vector<int> esrech;
  vector<trans*> tra;

  string saltos(int s);

 public:
  maquina();
  void leerdatos(string file);
  void computar(string pap,string reco,char eps);
  virtual ~maquina();

};
