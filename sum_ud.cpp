//this code compares floating point operations when computing a sum going forward and backwords. It can be
//seen from the plot that there is a difference between the two techniques. The backwards summation is more accurate
//because small numbers are being added to larger numbers. Going forward, large numbers are being added to smaller number,
// due to the roundoff error, the sums are less accurate. This shows when you are adding you want to add from smallest numbers to biggest.
// for small N it looks like a power law, for larger values of N the errors begin to oscillate.

#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>      // library to output to a file
#include <cmath>

int main()
{
    float N;
    float sum_up = 0;
    float sum_down = 0;
    float n=1;
    float error;


    ofstream myfile; //creates file
    myfile.open("sums.dat"); // opens file and names it sums.dat

while(n< 10000){
  N=n;
  sum_up=0;   //initializes sums to zero in loop
  sum_down=0;
  for (float i = 1; i <= N; i+=1) {          //computes forward sum
          sum_up += 1.0/i;
      }
  for(float i = N; i >= 1; i-=1){          // computes downwards sum
          sum_down += 1.0/i;
        }

        error=(abs(sum_up-sum_down))/1/2*(abs(sum_up)+abs(sum_down));  //computes error
        myfile<< setprecision(18)<<" "<<N << " " <<sum_up << " "<<sum_down <<" "<< error<<endl;
        n+=1;
        }




  //  cout << "Sum_up = " <<setprecision(12)<<sum_up << endl<<"Sum_down = "<<sum_down<<endl;
    return 0;
}
