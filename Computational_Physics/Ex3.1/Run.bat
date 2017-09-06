@echo off

gcc -o Ex3_1 Ex3_1.c
Ex3_1 > MovingAverage.txt
gnuplot -p -e "plot 'sunspots.txt' every ::0::1000 using 1:2 with lines, 'MovingAverage.txt' using 2:1 with lines"
pause