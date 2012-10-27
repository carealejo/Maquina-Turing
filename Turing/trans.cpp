#include "trans.h"

trans::trans(int es,char ca,int est,char esc,char m){
  estact=es;
  carent=ca;
  estsig=est;
  escritura=esc;
  mov=m;
}

int trans::getestact(){
  return estact;
}

char trans::getcarent(){
  return carent;
}

int trans::getestsig(){
  return estsig;
}

char trans::getesc(){
  return escritura;
}

char trans::getmov(){
  return mov;
}

void trans::printtrans(){
  cout << estact << ',' << carent << "->" << estsig << ',' << escritura << ',' << mov ;

}
trans::~trans(){}
