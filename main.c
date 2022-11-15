#include <stdio.h>

#define WALL 0
#define VISITED 2
#define DRAGON 3
#define N 4
#define IMPOSSIBLE (N*N+1)

int solveMaze(int maze[N][N], int i, int j, int dragonsCounter)
{
    int up,down,left,right,currentHighestAmount = IMPOSSIBLE;

    if (maze[i][j] == WALL){ return 0; } //Check if wall
    if (maze[i][j] == VISITED) { return 0; } //Check if it's marked with a '2'
    if (maze[i][j] == DRAGON) { dragonsCounter++; } //Check if a dragon, if it is > ++.
    if (i==N-1 && j==N-1) { return dragonsCounter; } //Whenever I'm at the end, return the counter.

    maze[i][j] = VISITED; // Mark current spot with (2).

   if (i>0) { //Check borders
       up = solveMaze(maze,i-1,j,dragonsCounter);
       if (up != 0 && up < currentHighestAmount) { //check if theres more dragons up
           currentHighestAmount = up;
       }
   }
    if (i<N-1) { //check borders
        down = solveMaze(maze,i+1,j,dragonsCounter);
        if (down != 0 && down < currentHighestAmount) { //check dragons down
            currentHighestAmount = down;
        }
    }
    if (j>0) { //check borders, left col
        left = solveMaze(maze,i,j-1,dragonsCounter);
        if (left != 0 && left < currentHighestAmount) {
            currentHighestAmount = left;
        }
    }
    if (j<N-1) { //check borders, right col
        right = solveMaze(maze,i,j+1,dragonsCounter);
        if (right != 0 && right < currentHighestAmount) {
            currentHighestAmount = right;
        }
    }
    if ( (currentHighestAmount == IMPOSSIBLE) && (i != 0) && (j != 0)) { //Will literally never get here.
        return 0;
    }
    return currentHighestAmount; //will return the least amount of dragons on the way
}

int main() {
    int res,maze[N][N] = { {1,1,3,3},
                       {3,0,1,1},
                       {3,0,0,1},
                       {1,3,3,1} };

    res = solveMaze(maze, 0, 0,0);
    printf("Amount of dragons passed through in the maze: %d\n",res);


}
