@echo off

gcc -o Ex5_15 Ex5_15.c
Ex5_15
Ex5_15 > output
gnuplot -p -e "plot 'output' u 1:2 w points, 'output' u 1:3 w lines"
