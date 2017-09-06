@echo off

gnuplot -p -e "plot 'temperature.dat' u 2:1:3 w image"