#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analysis_functions.h"

int load_data(int numRows, int numCol, int teamData[][numCol], char* fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName); // Print error message
        exit(1);
    }

    int year;
    fscanf(file, "Year: %d", &year);

    for (int i = 0; i < numRows; i++) {
        fscanf(file, "%d %d %d %d", &teamData[i][0], &teamData[i][1], &teamData[i][2], &teamData[i][3]); // Read the data
    }

    fclose(file);
    return year;
}

void findTotals(int numTeams, int totals[], int dataRows, int dataCol, int team_data[][dataCol]) {
    for (int i = 0; i < numTeams; i++) {
        totals[i] = 0;
    }

    for (int i = 0; i < dataRows; i++) { // Calculate the totals
        int awayTeam = team_data[i][0] - 1;
        int homeTeam = team_data[i][1] - 1;
        int awayScore = team_data[i][2];
        int homeScore = team_data[i][3];

        totals[awayTeam] += awayScore;
        totals[homeTeam] += homeScore;
    }
}

void findWins(int numTeams, int wins[], int dataRows, int dataCol, int team_data[][dataCol]) {
    for (int i = 0; i < numTeams; i++) {
        wins[i] = 0;
    }

    for (int i = 0; i < dataRows; i++) { // Calculate the wins
        int awayTeam = team_data[i][0] - 1;
        int homeTeam = team_data[i][1] - 1;
        int awayScore = team_data[i][2];
        int homeScore = team_data[i][3];

        if (awayScore > homeScore) {
            wins[awayTeam]++;
        } else if (homeScore > awayScore) {
            wins[homeTeam]++;
        } else {
            wins[awayTeam]++;
            wins[homeTeam]++;
        }
    }
}

int findTop(int numRows, int wins[], int totals[], int is_top[]) {
    int maxWins = 0;
    for (int i = 0; i < numRows; i++) { // Find the maximum number of wins
        if (wins[i] > maxWins) {
            maxWins = wins[i];
        }
    }

    int count = 0;
    for (int i = 0; i < numRows; i++) { // Find the top team/s
        if (wins[i] == maxWins) {
            is_top[i] = 1;
            count++;
        } else {
            is_top[i] = 0;
        }
    }

    if (count > 1) {
        int maxPoints = 0;
        for (int i = 0; i < numRows; i++) {
            if (is_top[i] && totals[i] > maxPoints) { // Find the maximum number of points
                maxPoints = totals[i];
            }
        }

        for (int i = 0; i < numRows; i++) {
            if (is_top[i] && totals[i] < maxPoints) { // Remove the team/s with fewer points
                is_top[i] = 0;
            }
        }
    }

    return count;
}