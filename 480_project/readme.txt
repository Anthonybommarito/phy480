  Double Pendulum
  Anthony Bommarito


  This project sets out to solve the equations of motion for the double pendulum using odeint. The equations of motion were
  written using the Lagrangian method. Also a GUI was built to enable more user interaction with the source code.
  The GUI allows the user to change the physical parameters of the pendulum such as the mass and lengths and then easily plot them.
  Pyvie was used to take snap shots of the plots at each time and stitched them together to make a movie. I got rid of the feature
  because it created too many files and became annoying when one wants to play around with the paramaters.

  In order to run the code the user must have:
  Jupyter notebook
  python 3 (ipython)
  numpy   -used to store arrays
  matplotlib - used to make plots
  ffmpeg -used with pyvie to make movie/animation
  #pyvie
  scipy -odeint

  Analysis: We can see from some of the included graphs that changing the parameters of the system has a large effect on the overall dynamics.
  Making Mass one extremely large relative to Mass 2 causes theta 1 to swing at a large negative angle, while mass 2 oscillates
  around a small positive angle, slowly increasing its amplitude. Conversely, if we make mass 2 very large and mass 1 negligible,
  pendulum 1 will swing in phase with pendulum 2, sweeping out the same angles at the same time.Ive also included a few example graphs
  of how exaggerated lengths change the dynamics of the system. The most interesting aspect of the double pendulum system is its dependency
  on initial conditions. I included an example of this. I let pendulum 1 have an initial angle of pi and pendulum 2 have an intial angle of pi/4,
  I then perturbed pendulum 2 by .001 degrees and the resulting phase portrait was quite different. This is what we would expect from a chaotic system,
  and it is nice that python is able to display this phenomena so well.

  The energy is also calculated each time the odes are solved. Plotting the energy is a great way to see how accurate our solutions are.
  In doing so one will notice that the energy is not conserved, and either grows/decays.  This is due to ode int using the Adams Bashforth method.
  This method takes three initial points calculated via the runge kutta method. The method then uses the four prior points to calculate the newest point.
  The error of this algorithm is on the order of h^4, which is fairly accurate but unfortunately it does not conserve energy. Typically, in order to conserve
  energy in physics, one must use a Verlet algorithm.

  Finally, there may be a small bug with the clear figure commands in my code. The result is that two curves will appear on the same plot if one changes
  a parameter with the GUI (plots the last parameters as well as the newest one). The GUI can be bypassed completely by just changing the parameters hardcoded
  in and making a plot in another cell as seen in the notebook.
