@echo off

gcc -o Ex5_11 Ex5_11.c
echo 50 | "C:\Users\CHRIS\Documents\Pelles C Projects\Computational_Physics\Gaussxw\Gaussxw" > input
Ex5_11 < input > output
gnuplot -p -e "plot 'output' u 1:2 w lines"
type output