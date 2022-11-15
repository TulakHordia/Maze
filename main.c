#include <stdio.h>

#define IMPOSSIBLE (N*N+1)

enum {WALL,EMPTY,VISITED,DRAGON,N};

int number_of_dragons=0,currentMostDragons=0;

int printMaze(int maze[N][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}

int solveMaze(int maze[N][N], int i, int j, int sol[N][N])
{
    if (maze[i][j] == WALL){ return 0; }
    if (maze[i][j] == VISITED) { return 0; }
    if (maze[i][j] == DRAGON) {
        number_of_dragons++;
        if (currentMostDragons != 0 && number_of_dragons > currentMostDragons) {
            maze[i][j] = VISITED;
            return 0;
        }
        sol[i][j] = DRAGON;
    }
    maze[i][j] = VISITED; // Mark current spot with (2).
    if (i==N-1 && j==N-1) {
        if (currentMostDragons != 0 && currentMostDragons >= number_of_dragons) {
            return 1;
        } else {
            currentMostDragons = number_of_dragons;
            number_of_dragons = 0;
        }
    } //reached the end (N-1,N-1) - (3,3) incase N is 4.
    if (   ((i < N-1) && solveMaze(maze,i+1,j,sol))
    || ((i > 0) && solveMaze(maze,i-1,j,sol))
    || ((j < N-1) && solveMaze(maze,i,j+1,sol))
    || ((j > 0) && solveMaze(maze,i,j-1,sol)) ) { // checking index-out-bounds + recursively going around the maze
        return 1;
    }
    maze[i][j] = EMPTY;
    return 0;
}

int main() {
    int maze[N][N] = { {1,1,3,3},
                       {3,0,1,1},
                       {3,0,0,1},
                       {1,3,3,1} };
    int sol[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };

    int solved = solveMaze(maze, 0, 0, sol);
    if (solved)
    {
        printMaze(maze);
        printf("Amount of dragons passed through in the maze: %d\n",number_of_dragons);
    }
    else
    {
        printf("No solution, %d\n",IMPOSSIBLE);
    }
}
