@echo off

gcc -o Ex5_4 Ex5_4.c
Ex5_4 > output
gnuplot -p -e "plot 'output' u 1:2 w lines,'output' u 1:3 w lines,'output' u 1:4 w lines"
