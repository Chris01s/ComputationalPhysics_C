@echo off

gcc -o Ex5_10 Ex5_10.c
echo 100 | "C:\Users\CHRIS\Documents\Pelles C Projects\Computational_Physics\Gaussxw\Gaussxw" > input
Ex5_10 < input > output
gnuplot -p -e "plot 'output' u 1:2 w lines"
