@echo off

gcc -o Ex3_8 Ex3_8.c
Ex3_8 < millikan.txt > bestFit
gnuplot -p -e "plot 'bestFit' u 1:2 w lines, 'millikan.txt' u 1:2 w points"