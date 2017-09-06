@echo off

gnuplot -p -e "set pal gray; plot 'stm.txt'matrix with image"