//from our fit, we can conclude that simpsons rule goes like 1/N^4 on the interval 0 to 1.
//This interval was chosen because it was before the error began to oscillate. The Milne rule goes like 1/N^6.
//The interval was also chosen for reasons similar to the simpsons rule. According to wikipedia, this is what we would expect.
// The optimum N is roughly 4, this is because the error begins to oscillate for values larger than 4. If we then realize That
//the error is bound by the sixth derivative which takes a minimum value of 45, Et=-8/45f^(6)h^7. We get an N value roughly 4.035 or 4.
//This agrees with what we would predict with the graph.


 //The fit paramaters can be seen in the terminal once integ_plot.h is executed.

// include files
#include <cmath>
#include "routines.h"   // integration routine prototypes
#include <gsl/gsl_integration.h>

// Integration using Simpson's rule

double my_gsl_integrand (double x, void *params_ptr);

double simpsons_rule ( int num_pts, float x_min, float x_max,
                      float (*integrand) (float x) )
{
   double interval = ((x_max - x_min)/float(num_pts - 1));  // called h in notes
   double sum=  0.;  // initialize integration sum to zero

   for (int n=2; n<num_pts; n+=2)                // loop for odd points
   {
     double x = x_min + interval * float(n-1);
     sum += (4./3.)*interval * integrand(x);
   }
   for (int n=3; n<num_pts; n+=2)                // loop for even points
   {
     double x = x_min + interval * float(n-1);
     sum += (2./3.)*interval * integrand(x);
   }
   // add in the endpoint contributions
   sum +=  (interval/3.) * (integrand(x_min) + integrand(x_max));

   return (sum);
}

double milne_rule ( int num_pts, float x_min, float x_max,
                      float (*integrand) (float x) ) //milne integration routine
{
double interval = ((x_max - x_min)/float(num_pts - 1));
double sum=  0.;
  for (int n=2; n<num_pts; n+=2)                // loop for even points
  {
  double x = x_min + interval * float(n-1);
  sum += (64./45.)*interval * integrand(x);
                        }
for (int n=3; n<num_pts; n+=4)                // loop for odd points
  {
    double x = x_min + interval * float(n-1);
    sum += (24./45.)*interval * integrand(x);
    }

    for (int n=5; n<num_pts; n+=4)                // loop for odd points
      {
        double x = x_min + interval * float(n-1);
        sum += (28./45.)*interval * integrand(x);
        }
sum +=  (interval*14./45.) * (integrand(x_min) + integrand(x_max));
return(sum);
    }
//gsl routine
    double my_gsl_rule(int i)
    {
      gsl_integration_workspace * w = gsl_integration_workspace_alloc (i);

      double result1, error; //returns error and result of gsl
      double lower_limit = 0.;  //integration bounds
      double upper_limit = 1.;
      double alpha = 1.; //void paramater necessary for gsl to work
      void *params_ptr;
      params_ptr = &alpha;
      gsl_function F;
      F.params = params_ptr;
      F.function = &my_gsl_integrand;


      gsl_integration_qags (&F, lower_limit, upper_limit, 0, 1e-2, i,w, &result1, &error);
      gsl_integration_workspace_free (w);
      return(result1);

    }

//function we want to integrate using gsl. Format i do not understand but it works.
    double
   my_gsl_integrand (double x, void *params_ptr)
   {
     double alpha;
     alpha = *(double *) params_ptr;

    return (sqrt(1+(x*x)));
    }

//************************************************************************
