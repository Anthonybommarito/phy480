
#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <cmath>


int
main ()
{
float x_f = 0. ; // define float variable of x
double x_d = 0.; // define double of x
double error // define error between double and float

ofstream myfile; //creates file
myfile.open("ramdomr.dat"); // opens file and names it ramdomr.dat


for (int i = 1; i < 20000;i+=1){
  x_d=sqrt(double(i)); //computes sqrt of x as a double
  x_f=sqrt(float(i)); //computes sqrt of x as float

   error= (x_d - x_f)/x_d;  //relative error, no absolute value to show random distribution
   myfile<< " "<<i<<" "<< x_d << " "<< x_f << " "<<error<<endl;
}

myfile.close();
return 0;


}
