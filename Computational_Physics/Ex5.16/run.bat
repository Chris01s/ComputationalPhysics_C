@echo off

gcc -o Ex5_16 Ex5_16.c
Ex5_16
Ex5_16 > output
gnuplot -p -e "plot 'output' u 1:2 w points, 'output' u 1:3 w lines"
