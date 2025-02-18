#ifndef ANALYSIS_FUNCTIONS_H
#define ANALYSIS_FUNCTIONS_H

// Function Prototypes
/***************************************************
*   int load_data(int numRows, int numCol, int teamData[][numCol], char* fileName);
* 
*   This function reads data from a file and stores it in a 2D array
*
* Input:
*   int numRows - number of rows in the 2D array
*   int numCol - number of columns in the 2D array
*   int teamData[][numCol] - 2D array to store the data
*   char* fileName - name of the file to read from
*
* Return:
*  int - the year read from the file
************************************************/
int load_data(int numRows, int numCol, int teamData[][numCol], char* fileName);
/***************************************************
*   void findTotals(int numTeams, int totals[], int dataRows, int dataCol, int team_data[][dataCol]);
* 
*   This function calculates the total points scored by each team
*
* Input:
*   int numTeams - number of teams
*   int totals[] - array to store the total points scored by each team
*   int dataRows - number of rows in the 2D array
*   int dataCol - number of columns in the 2D array
*   int team_data[][dataCol] - 2D array containing the game data
*
* Return:
*  void
************************************************/
void findTotals(int numTeams, int totals[], int dataRows, int dataCol, int team_data[][dataCol]);
/***************************************************
*   void findWins(int numTeams, int wins[], int dataRows, int dataCol, int team_data[][dataCol]);
* 
*   This function calculates the number of wins for each team
*
* Input:
*   int numTeams - number of teams
*   int totals[] - array to store the total points scored by each team
*   int dataRows - number of rows in the 2D array
*   int dataCol - number of columns in the 2D array
*   int team_data[][dataCol] - 2D array containing the game data
*
* Return:
*  void
************************************************/
void findWins(int numTeams, int wins[], int dataRows, int dataCol, int team_data[][dataCol]);
/***************************************************
*   int findTop(int numRows, int wins[], int totals[], int is_top[]);
* 
*   This function determines the top team/s based on the number of wins and total points scored
*
* Input:
*   int numRows - number of teams
*   int wins[] - array containing the number of wins for each team
*   int totals[] - array containing the total points scored by each team
*   int is_top[] - array to store the top team/s
*
* Return:
*  int - 1 if there is a tie, 0 otherwise
************************************************/
int findTop(int numRows, int wins[], int totals[], int is_top[]);

#endif