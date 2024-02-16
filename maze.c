#include <stdio.h>

#define SIZE 5 // Adjust the size of the maze accordingly

void printMaze(int maze[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int maze[][SIZE], int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && maze[x][y] == 0);
}

int solveMazeUtil(int maze[][SIZE], int x, int y) {
    if (x == SIZE - 1 && y == SIZE - 1) {
        maze[x][y] = 2; // Mark the exit point
        return 1; // Maze is solved
    }

    if (isSafe(maze, x, y)) {
        maze[x][y] = 2; // Mark the current cell as visited

        // Move forward
        if (solveMazeUtil(maze, x + 1, y) || solveMazeUtil(maze, x, y + 1)) {
            return 1; // Maze is solved
        }

        // If moving forward does not lead to a solution, backtrack
        maze[x][y] = 0; // Mark the current cell as unvisited
        return 0;
    }

    return 0;
}

void solveMaze(int maze[][SIZE]) {
    if (solveMazeUtil(maze, 0, 0)) {
        printf("The rat has found a path to the exit:\n");
        printMaze(maze);
    } else {
        printf("No path found for the rat.\n");
    }
}

int main() {
    int maze[SIZE][SIZE];

    printf("Enter the maze configuration (0 for open path, 1 for obstacle):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    printf("Initial maze configuration:\n");
    printMaze(maze);

    solveMaze(maze);

    return 0;
}
