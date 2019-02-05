#gnu plot file

set terminal xterm
set title ' error distribution  '
set xlabel 'i'
set ylabel 'error'
plot "ramdomr.dat" using 1:4
