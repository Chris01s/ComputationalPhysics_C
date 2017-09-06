@echo off

gcc -o Ex5_9 Ex5_9.c
echo 50 | "C:\Users\CHRIS\Documents\Pelles C Projects\Computational_Physics\Gaussxw\Gaussxw" > input
Ex5_9 < input > output
type output
gnuplot -p -e "plot 'output' u 1:2 w lines"


