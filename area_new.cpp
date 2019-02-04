//  file: area.cpp
//
//  This program calculates the area of a circle, given the radius.
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02-Jan-2004  original version, for 780.20 Computational Physics
//      01-Jan-2010  updates to "To do" wishlist
//      12-Jan-2016  comment out "using namespace std;"
//
//  Notes:
//   * compile with:  "g++ -o area.x area.cpp"
//
//  To do:
//   1. output the answer with higher precision (more digits)
//   2. use a "predefined" value of pi or generate it with atan
//   3. define an inline square function
//   4. split the calculation off into a function (subroutine)
//   5. output to a file (and/or input from a file)
//   6. add checks of the input (e.g., for non-positive radii)
//   7. rewrite using a Circle class
//
//*********************************************************************//

// include files
#include <iostream>	     // this has the cout, cin definitions
using namespace std;     // if omitted, then need std::cout, std::cin
#include <iomanip>      // std::setprecision
#include <math.h>       // library that includes pi
#include <fstream>      // library to output to a file

//*********************************************************************//

//const double pi = 3.1415926535897932385;   // define pi as a constant

inline double square(double r) //function that calculates the radius squared
{
  return (r*r);
}

inline double area(double z) //function that calculates the area
{
  return(M_PI*z);
}

int main ()
{
  ofstream myfile; //creates file
  myfile.open("area.dat"); // opens file and names it area.dat

  double radius;    // every variable is declared as int or double or ...

  cout << "Enter the radius of a circle: ";	// ask for radius
  cin >> radius;
    // statement that checks if radius is greater than zero to continue program
  if (radius < 0){
    cout<< "radius must be greater than zero";
    return 0;
  }

  double k= square(radius);  // dummy variable that stores the radius squared


  //double area = M_PI * square(radius);	// standard area formula

  cout << "radius = " << radius << ",  area = " << setprecision(10)<<area(k);
  myfile<< "radius = " << radius << ",  area = " << setprecision(10)<<area(k);//writes area and radius to file
  myfile.close(); //closes file

  return 0;			// "0" for successful completion
}

//*********************************************************************//
