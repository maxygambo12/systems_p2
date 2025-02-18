#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analysis_functions.h"

#define NUM_TEAMS 10
#define NUM_YEARS 4
#define NUM_GAMES 45

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Run the program with a list of input file, followed by the output file\n\n");
        printf("./runScores file_name.txt ... results.txt\n\n");
        printf("where file_name.txt ... is a list of files to process\n");
        printf("and results.txt is the name of the output file to produce.\n");
        return 1;
    }

    // Initialize the arrays
    int numYears = argc - 2;
    int wins[NUM_TEAMS][numYears];
    int totals[NUM_TEAMS][numYears];
    int topTeams[NUM_TEAMS][numYears];
    int years[numYears];

    // Initialize the arrays
    for (int i = 0; i < NUM_TEAMS; i++) {
        for (int j = 0; j < numYears; j++) {
            wins[i][j] = 0;
            totals[i][j] = 0;
            topTeams[i][j] = 0;
        }
    }

    for (int i = 0; i < numYears; i++) {
        int teamData[NUM_GAMES][4];
        years[i] = load_data(NUM_GAMES, 4, teamData, argv[i + 1]);

        // Initialize the arrays
        int yearWins[NUM_TEAMS];
        int yearTotals[NUM_TEAMS];
        int is_top[NUM_TEAMS];

        findWins(NUM_TEAMS, yearWins, NUM_GAMES, 4, teamData); // Calculate the wins
        findTotals(NUM_TEAMS, yearTotals, NUM_GAMES, 4, teamData); // Calculate the totals
        int tie = findTop(NUM_TEAMS, yearWins, yearTotals, is_top); // Find the top team

        for (int j = 0; j < NUM_TEAMS; j++) { // Store the data
            wins[j][i] = yearWins[j];
            totals[j][i] = yearTotals[j];
            topTeams[j][i] = is_top[j];
        }

        if (tie == 1) {
            for (int j = 0; j < NUM_TEAMS; j++) {
                if (is_top[j]) {
                    printf("The top team of %d was Team %d.\n", years[i], j + 1); // Print the top team
                }
            }
        } else {
            printf("The top team of %d was ", years[i]);
            int first = 1;
            for (int j = 0; j < NUM_TEAMS; j++) {
                if (is_top[j]) {
                    if (!first) {
                        printf(" and ");
                    }
                    printf("Team %d", j + 1);
                    first = 0;
                }
            }
            printf(".\n");
        }
    }

    FILE *outputFile = fopen(argv[argc - 1], "w"); // Open the output file
    if (outputFile == NULL) {
        printf("Error opening output file %s\n", argv[argc - 1]);
        return 1;
    }

    // Print the header
    fprintf(outputFile, "Team");
    for (int i = 0; i < numYears; i++) {
        fprintf(outputFile, " %4d", years[i]); // Years for wins
    }
    for (int i = 0; i < numYears; i++) {
        fprintf(outputFile, " %4d", years[i]); // Years for totals
    }
    fprintf(outputFile, "\n");

    // Print the data for each team
    for (int i = 0; i < NUM_TEAMS; i++) {
        fprintf(outputFile, "%4d", i + 1); // Team number
        for (int j = 0; j < numYears; j++) {
            fprintf(outputFile, " %4d", wins[i][j]); // Wins
        }
        for (int j = 0; j < numYears; j++) {
            fprintf(outputFile, " %4d", totals[i][j]); // Totals
        }
        fprintf(outputFile, "\n"); // New line after each team
    }

    fclose(outputFile);
    return 0;
}