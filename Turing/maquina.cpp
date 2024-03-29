#include "maquina.h"

maquina::maquina(){}
maquina::~maquina(){}

inline vector<char> extsiggam(string s){

  vector<char> r;

  for(int i=0;i<s.size();i++){
    if(s[i]==','){}
    else{
      r.push_back(s[i]);
    }
  }

  return r;

}

inline vector<int> extest(string s){

  vector<int> e;

  for(int i=0;i<s.size();i++){
    if(s[i]==','){}
    else{
      e.push_back(atoi(&s[i]));
    }
  }

  return e;

}

inline vector<char> creacinta(){

  vector<char> p;
  string s;

  cout << "Ingrese la Cinta a computar: ";
  cin >> s;

  for(int i=0;i<s.size();i++){
    p.push_back(s[i]);
  }

  return p;
}
string maquina::saltos(int s){
  string temp;
  for(int i=0;i<s;i++){
    conf >> temp;
  }
  return temp;
}

inline trans* exttrans(string f,string n){

  trans *t=new trans(atoi(&f[0]),f[2],atoi(&n[0]),n[2],n[4]);

  return t;
} 

void maquina::leerdatos(string file){

  string temp,temp2;

  conf.open(file.c_str());

  cinta=creacinta();
  cabeza=0;

  sigma=extsiggam(saltos(4));
  sigma.push_back('&');
  gamma=extsiggam(saltos(4));
  gamma.push_back('&');
  temp=saltos(4);
  conf >> nestados;
  temp=saltos(3);
  conf >> estini;
  actual=estini;
  esacep=extest(saltos(5));
  esrech=extest(saltos(5));
  temp=saltos(3);
  temp2=saltos(2);
  while(!conf.eof()){
    tra.push_back(exttrans(temp,temp2));
    conf >> temp;
    temp2=saltos(2);
  }
}

void maquina::computar(string pap,string reco,char eps){

  int pass=0;

  if(pap=="1")
    cout << endl << "Los pasos de las transiciones son los siguentes:  " << endl; 

  for(int i=0;i<tra.size();i++){

    if(tra[i]->getestact() == actual and (tra[i]->getcarent() == cinta[cabeza])or(tra[i]->getcarent()== '&')){

      if(pap=="1"){
	tra[i]->printtrans();
      }
      pass=1;
      actual=tra[i]->getestsig();
      if(tra[i]->getesc()!=eps){
	cinta[cabeza]=tra[i]->getesc();
      }
      if(tra[i]->getmov() == 'R'){
	cabeza++;
	if(cinta.size()==cabeza){
	  cinta.push_back('_');
	}
      }else{	
	cabeza--;
	if(cabeza<0){
	  cinta.insert(cinta.begin(),'_');
	  cabeza++;
	}
      }
      if(pap=="1"){
	cout << "     " ;
	for(int h=0; h<cinta.size();h++){
	  cout << cinta[h] ;
	}	
	cout << "     cabeza en " << cinta[cabeza] << endl;
      }
      i=0; 
    }
  }
  
  if(pap!="1"){
    cout << "El resultado es:  " ;
    for(int h=0; h<cinta.size();h++){
      cout << cinta[h] ;
    }	
  }
  cout << endl << endl;

  if(reco=="1"){
    for(int i=0; i<esacep.size();i++){
      if(actual==esacep[i]){
	cout << "La cadena llego a un estado de  ACEPTACION!!" << endl << endl;
	i=esacep.size()+1;
	pass=1;
      }
    }
    for(int j=0; j<esrech.size();j++){
      if(actual==esrech[j]){
	cout << "La cadena llego a un estado de RECHAZO!!" << endl << endl;
	j=esacep.size()+1;
	pass=1;
      }
    }	 
    cout << endl; 
    if(pass==0){
      cout << "la cadena a sido ???" << endl;
    }
  }else{
    cout << "La cinta a quedado asi:  " ;
    for(int h=0; h<cinta.size();h++){
      cout << cinta[h] ;
    }	
    cout << endl << endl;
  }
}

