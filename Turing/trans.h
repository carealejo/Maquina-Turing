#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class trans{
  
 private:
  int estact;
  char carent;
  int estsig;
  char escritura;
  char mov;
 public:
  trans(int estact,char carent,int estsig,char escritura,char mov);
  virtual ~trans();
  int getestact();
  char getcarent();
  int getestsig();
  char getesc();
  char getmov();

  void printtrans();
};
