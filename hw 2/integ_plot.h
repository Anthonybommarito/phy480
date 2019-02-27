set terminal xterm
set title 'integral error plots'
set xlabel ' log(N)'
set ylabel 'log(error)'
set pointsize 1.5
set key top right
set timestamp
f(x)=m*x+b
fit [0:1] f(x) 'integ.dat' using 1:2 via m,b
plot 'integ.dat' using 1:2  title 'simpsons' ,'integ1.dat' using 1:2 title 'milne'
g(x)=l*x+k
fit [0:1.2] g(x) 'integ1.dat' using 1:2 via l,k
set term png
set output "error.png"

replot
