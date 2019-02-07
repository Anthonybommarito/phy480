#gnu plot file
# plot y label not showing for some reason

set terminal xterm
set title ' log bessel error '
set xlabel 'x'
set ylabel "error"
show ylabel
set logscale
plot "bessel.dat" using 1:4
set output 'bessel.ps'
set terminal postscript
replot
