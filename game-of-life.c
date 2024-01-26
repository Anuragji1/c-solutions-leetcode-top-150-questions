**Game of Life

Problem Statement 38) According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.

--------------------------------------------------------------------------------------------------------------------------------
SOLUTION = void gameOfLife(int** board, int boardSize, int* boardColSize){
    int m = boardSize, n = boardColSize[0];

    // Directions for neighbor checking
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && abs(board[x][y]) == 1) {
                    liveNeighbors++;
                }
            }

            // Apply the Game of Life rules
            if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                board[i][j] = -1; // Mark as dead for the next state
            } else if (board[i][j] == 0 && liveNeighbors == 3) {
                board[i][j] = 2; // Mark as live for the next state
            }
        }
    }

    // Update the board to the next state
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == -1) {
                board[i][j] = 0; // Dead in the next state
            } else if (board[i][j] == 2) {
                board[i][j] = 1; // Live in the next state
            }
        }
    }
}

-----------------------------------------Explanation :-
Purpose:

This code implements a single step of Conway's Game of Life, a cellular automaton that simulates the evolution of cells based on simple rules.
Function Breakdown:

Initialization:

m and n store the dimensions of the board.
dx and dy arrays define the directions to check for neighboring cells.
Iterating over Cells:

The outer loops iterate through each cell on the board.
For each cell:
liveNeighbors is initialized to 0.
The inner loop checks the neighboring cells using dx and dy.
If a neighbor is alive (value of 1 or -1), liveNeighbors is incremented.
Applying Rules:

Underpopulation: If a live cell has fewer than 2 or more than 3 live neighbors, it dies in the next state (marked as -1).
Survival: If a live cell has 2 or 3 live neighbors, it stays alive in the next state.
Reproduction: If a dead cell has exactly 3 live neighbors, it becomes alive in the next state (marked as 2).
Updating Board:

The final loops update the board to the next state:
Cells marked as -1 become dead (0).
Cells marked as 2 become alive (1).
Key Points:

In-Place Modification: The code modifies the board in-place, avoiding extra memory usage.
Temporizing for Clarity: It uses -1 and 2 as temporary markers to distinguish between cells that will die or become alive in the next state, making the logic clearer.
Time and Space Complexity: O(m * n) time due to nested loops, O(1) space as it uses a constant amount of extra variables.
