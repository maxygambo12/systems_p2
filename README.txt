Sports Analysis
Max Gambino

This program analyzes the results of sports events over multiple years. 
It reads data from input files, calculates the number of events won and total points scored by each team each year, and determines the top team/s for each year. 
The program outputs the results to both the terminal and a specified output file.



To compile:
Move to the folder containing the program and type:

make

To run:

./runScores scores20.txt scores21.txt ... results.txt

You will be prompted to enter the name of the input file and select a calculation.

File Format:
The first line specifies the year: Year: YYYY
Subsequent lines contain the event data in columns:
Column 0: Away team (1-10)
Column 1: Home team (1-10)
Column 2: Away team score
Column 3: Home team score

References:
I worked alone and didn't use anything that needs to be sourced.