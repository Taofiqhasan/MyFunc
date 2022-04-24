#include <stdio.h>
#include <math.h>
#include "numlib.h"

double f(double);
double df(double);
//double NewtonRaphson(double,double,int);

//double x,f,df;
int main(){
    fprintf(stdout,"Print the NR approximation\n");

  //  NewtonRaphson(&f,&df,0.05,0.0001,20);
  //  SecantMethod(&f,0.02,0.05,0.0001,20);
  BisectionMethod(&f,0,0.11,0.0001,20);


}

double f(double x){
    return pow(x,3)-0.165*pow(x,2)+0.0003993;
}

double df(double x){
    return 3*pow(x,2)-0.33*x;
}
