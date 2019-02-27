


extern double simpsons_rule ( int num_pts, float x_min, float x_max,
                       float (*integrand) (float x) );    // Simpson's rule

extern double milne_rule ( int num_pts, float x_min, float x_max,
        float (*integrand) (float x) );    // milne rule



extern double my_gsl_rule(int i);  // gsl rule
