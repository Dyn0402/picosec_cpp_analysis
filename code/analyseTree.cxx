#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>

#include "MyFunctions.h"

using namespace std;

int main(int argc, char **argv)
{
  int detid=0;
  int runid=0;
  if (argc>2)  {
    int tst=sscanf(argv[1],"%d", &detid);
    int tst2=sscanf(argv[2],"%d", &runid);
    if (tst<=0||tst2<=0) {
      cout<<"syntax: makeTree <detector number> <run number>"<<endl; 
      return -1;
    }
  }
  else {
    cout<<"syntax: makeTree <detector number> <run number>"<<endl; 
    return -2;
  }
    
  if (runid<MINRUN || runid>MAXRUN){
    cout<<"run "<<runid<<" out of bounts ("<<MINRUN<<"-"<<MAXRUN<<")"<<endl;
    return -3;
  }
  
  char fname[100];
  sprintf(fname,"%s/logs/analysis/logS%03d-%02d.txt",WORKDIR,detid,runid);
  FILE *ftmp = fopen(fname,"w");
  fclose(ftmp);
  char command[2000];
  sprintf(command,"root -b -x '%s/AnalyseTreeProduction.C+(%d,%d)' -q >> %s &\n",WORKDIR,detid,runid,fname);
  cout<<"executing:\n"<<command<<endl;
  system(command);

  return (1);
}