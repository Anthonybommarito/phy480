
#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>      // library to output to a file
#include <cmath>


int
main ()
{
float x_f = 0. ;
double x_d = 0.;
double error;

ofstream myfile; //creates file
myfile.open("ramdomr.dat"); // opens file and names it area.dat


for (int i = 1; i < 20000;i+=1){
  x_d=sqrt(double(i));
  x_f=sqrt(float(i));

   error= (x_d - x_f)/x_d;
   myfile<< " "<<i<<" "<< x_d << " "<< x_f << " "<<error<<endl;
}

myfile.close();
return 0;


}
