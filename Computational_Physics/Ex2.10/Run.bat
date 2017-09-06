@echo off

gcc -o Ex2_10 Ex2_10.c
Ex2_10
gnuplot -p -e "plot 'BE_Nucleon.txt' using 2:1 with lines, 'MAXBE_Nucleon.txt' using 2:1 with points"
gnuplot -p -e "plot 'BE_NucleonCurve.txt' using 2:1 with lines"
