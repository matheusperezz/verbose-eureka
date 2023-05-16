#include <iostream>
#include <vector>

using namespace std;

// Set the size of the maze
const int N = 5;

// Set the maze (0 is free space, 1 represents a wall)
int maze[N][N] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
};

const int startRow = 0, startCol = 0;
const int endRow = 4, endCol = 4;

bool visited[N][N];

// Function to print the maze
void printMaze(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isValid(int row, int col){
    return (row >= 0 && row < N && col >= 0 && col < N && maze[row][col] == 0 && !visited[row][col]);
}

bool solveMaze(int row, int col){

    // verify if we in the final point
    if (row == endRow && col == endCol){
        return true;
    }

    visited[row][col] = true;

    // Verify the neighbor cell
    if (isValid(row + 1, col)){ // Down
        if (solveMaze(row + 1, col)){
            return true;
        }
    }

    if (isValid(row, col + 1)){ // Right
        if (solveMaze(row, col + 1)){
            return true;
        }
    }

    if (isValid(row - 1, col)){ // Up
        if (solveMaze(row - 1, col)){
            return true;
        }
    }

    if (isValid(row, col - 1)){ // Left
        if (solveMaze(row, col - 1)){
            return true;
        }
    }

    // If we find't the way, we desmaerk the cell as visited, and return false
    visited[row][col] = false;
    return false;

}

int main(){
    
    cout << "Start maze: " << endl;
    printMaze();

    // Try to solve the maze
    if (solveMaze(startRow, startCol)){
        cout << "Path founded: " << endl;

        // Mark the path in maze
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (visited[i][j]){
                    maze[i][j] = 2;
                }
            }
        }

        printMaze();
    } else {
        cout << "Path not found :(" << endl;
    }

    return 0;
}