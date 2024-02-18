**Surreounded Regions**

Problem Statement 90) Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.

------------------------------------------------------------------------------------------------------
SOLUTION = void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0 || *boardColSize == 0) return;  // Empty board

    int rows = boardSize, cols = *boardColSize;

    // Mark 'O's on the borders as safe
    for (int i = 0; i < rows; i++) {
        if (board[i][0] == 'O') dfs(board, rows, cols, i, 0);
        if (board[i][cols - 1] == 'O') dfs(board, rows, cols, i, cols - 1);
    }
    for (int j = 0; j < cols; j++) {
        if (board[0][j] == 'O') dfs(board, rows, cols, 0, j);
        if (board[rows - 1][j] == 'O') dfs(board, rows, cols, rows - 1, j);
    }

    // Flip remaining 'O's to 'X'
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == '#') board[i][j] = 'O';  // Restore safe 'O's
        }
    }
}

void dfs(char** board, int rows, int cols, int i, int j) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O') return;

    board[i][j] = '#';  // Mark as safe

    dfs(board, rows, cols, i + 1, j);
    dfs(board, rows, cols, i - 1, j);
    dfs(board, rows, cols, i, j + 1);
    dfs(board, rows, cols, i, j - 1);
}


-------------Exlanation :-
Functionality:

This code implements a function solve that solves the "Surrounded Regions" problem on a 2D board. It identifies regions of 'O's that are not connected to any 'O's on the board's borders and flips them to 'X's.

Breakdown:

solve Function:

Base Case: Handles empty boards by returning immediately.
Marking Safe 'O's:
Iterates through the board's borders (top, bottom, left, right edges):
If an 'O' is found, calls dfs to explore and mark connected 'O's as safe using a temporary '#' symbol.
Flipping Remaining 'O's:
Iterates through the entire board:
If a cell is 'O' (not marked safe), it's surrounded, so change it to 'X'.
If a cell is '#' (previously marked safe), restore it to 'O'.
dfs Function (Recursive Depth-First Search):

Base Cases:
If the cell is out of bounds or not 'O' (not part of the connected region), return.
Marking and Exploration:
Mark the current cell as safe (board[i][j] = '#').
Recursively call dfs on its four adjacent neighbors (up, down, left, right) to explore connected 'O's.
Key Points:

The code effectively uses DFS to mark connected regions of 'O's that reach the borders as safe.
Safe 'O's are temporarily marked with '#' to distinguish them from surrounded 'O's.
The final traversal flips any remaining 'O's (surrounded regions) to 'X' and restores safe 'O's to their original 'O' value.
Time complexity: O(m * n), where m and n are the board dimensions, as each cell is visited at most once.
Space complexity: O(h), where h is the maximum depth of the recursion stack, which depends on the size of connected regions.
Example:

Consider a board initially:

X X X X
X O O X
X X O X
X O X X
After calling solve, it becomes:

X X X X
X X X X
X X X X
X O X X
