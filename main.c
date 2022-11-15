#include <stdio.h>
#include <stdlib.h>

#define WALL 0
#define EMPTY 1
#define VISITED 2
#define DRAGON 3
#define N 4
#define IMPOSSIBLE (N*N+1)

int solveMaze(int maze[N][N], int i, int j, int dragonsCounter)
{
    int up,down,left,right,currentHighestAmount = IMPOSSIBLE;

    if ((maze[i][j] == WALL) || (maze[i][j] == VISITED)){ return 0; }
    if (maze[i][j] == VISITED) { return 0; }
    if (maze[i][j] == DRAGON) { dragonsCounter++; }
    if (i==N-1 && j==N-1) { return dragonsCounter; }
    maze[i][j] = VISITED; // Mark curren t spot with (2).

   if (i>0) {
       up = solveMaze(maze,i-1,j,dragonsCounter);
       if (up != 0 && up < currentHighestAmount) {
           currentHighestAmount = up;
       }
   }
    if (i<N-1) {
        down = solveMaze(maze,i+1,j,dragonsCounter);
        if (down != 0 && down < currentHighestAmount) {
            currentHighestAmount = down;
        }
    }
    if (j>0) {
        left = solveMaze(maze,i,j-1,dragonsCounter);
        if (left != 0 && left < currentHighestAmount) {
            currentHighestAmount = left;
        }
    }
    if (j<N-1) {
        right = solveMaze(maze,i,j+1,dragonsCounter);
        if (right != 0 && right < currentHighestAmount) {
            currentHighestAmount = right;
        }
    }

    if ( (currentHighestAmount == IMPOSSIBLE) && (i != 0) && (j != 0)) {
        return 0;
    }

    return currentHighestAmount;
}

int main() {
    int res,maze[N][N] = { {1,1,3,3},
                       {3,0,1,1},
                       {3,0,0,1},
                       {1,3,3,1} };

    res = solveMaze(maze, 0, 0,0);

    printf("Amount of dragons passed through in the maze: %d\n",res);


}
