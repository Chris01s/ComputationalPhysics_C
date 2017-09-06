@echo off

gcc -o Ex3_2 Ex3_2.c
echo D | Ex3_2.exe > Spiral1.txt
echo G | Ex3_2.exe > Spiral2.txt
echo F | Ex3_2.exe > Spiral3.txt
gnuplot -p -e "plot 'Spiral1.txt' using 2:1 with lines

