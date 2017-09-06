@echo off

gcc -o Ex5_12 Ex5_12.c
echo 1000 | "C:\Users\CHRIS\Documents\Pelles C Projects\Computational_Physics\Gaussxw\Gaussxw" > input
Ex5_12 < input > output
gnuplot -p -e "plot 'output' u 1:2 w lines"
