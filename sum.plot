#gnu plot file

set terminal xterm
set title '1/n summation'
set xlabel 'log(n)'
set ylabel 'log(error)'

set timestamp
set logscale
plot "sums.dat" using 1:4
