@echo off

gcc -o Ex5_1 Ex5_1.c
Ex5_1 < velocities.txt > output
gnuplot -p -e "plot 'velocities.txt' u 1:2 w lines, 'output' w lines"
