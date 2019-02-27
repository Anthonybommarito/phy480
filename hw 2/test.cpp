

// include files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <gsl/gsl_integration.h>
using namespace std;

#include "routines.h"	// prototypes for integration routines

float my_integrand (float x);


//************************************************************************

int
main ()
{
  // set up the integration specifiction
  const int max_intervals = 1000;	// maximum number of intervals
  const double lower = 0;	// lower limit of integration
  const double upper = 1.0;	// upper limit of integration

  const double answer = 1.1477935746963;
	// the "exact" answer for the test from wolfram
  double result = 0.;  // approximate answer

  // open the output file stream
  ofstream integ_out ("integ.dat"); //save simpson data in integ.dat
  ofstream integ_out1 ("integ1.dat");	// save milne and gsl data in integ1.dat
  integ_out << "#  N        Simpsons " << endl;
  integ_out << "#-------------------" << endl;
  integ_out1<< "#  N     Milne         gsl"<<endl;
  integ_out1<<"#-------------------------"<<endl;

  // Simpson's rule requires an odd number of intervals
  for (int i = 3; i <= max_intervals; i += 2)
  {
    integ_out << setw(4) << log10(i);



    result = simpsons_rule (i, lower, upper, &my_integrand);
    integ_out << "  " << setprecision(12) <<log10(fabs(result-answer)/answer);
    integ_out<<endl;}
    //milne starts with n=5 and iterates by 4
for (int i = 5; i <= max_intervals; i += 4){
    integ_out1 << setw(4) << log10(i);

    result = milne_rule (i, lower, upper, &my_integrand);
    integ_out1 << "  " << setprecision(12) <<log10(fabs(result-answer)/(answer));

    result=my_gsl_rule(i);

    integ_out1 << "  " << setprecision(12) <<log10(fabs(result-answer)/answer);
    integ_out1<<endl;
}







  cout << "data stored in integ.dat\n";
  integ_out.close ();
  integ_out1.close();

  return (0);
}

//************************************************************************

// the function we want to integrate
float
my_integrand (float x)
{
  return (sqrt(1+(x*x)));
}
