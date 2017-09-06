@echo off

gcc -o Ex5_3 Ex5_3.c
Ex5_3 > output
gnuplot -p -e "plot 'output' u 1:2 w lines"
