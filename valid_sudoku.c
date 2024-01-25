**Valid Sudoku**

Problem Statement 34) Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    // Check rows
    for (int i = 0; i < 9; i++) {
        int seen[9] = {0};
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1';
                if (seen[num]) {
                    return false; // Duplicate in row
                }
                seen[num] = 1;
            }
        }
    }

    // Check columns
    for (int j = 0; j < 9; j++) {
        int seen[9] = {0};
        for (int i = 0; i < 9; i++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1';
                if (seen[num]) {
                    return false; // Duplicate in column
                }
                seen[num] = 1;
            }
        }
    }

    // Check 3x3 sub-boxes
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int seen[9] = {0};
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (board[i + k][j + l] != '.') {
                        int num = board[i + k][j + l] - '1';
                        if (seen[num]) {
                            return false; // Duplicate in sub-box
                        }
                        seen[num] = 1;
                    }
                }
            }
        }
    }

    return true; // No duplicates found, Sudoku is valid
}

---------------------------------------------Explanation :-
Function Overview:

isValidSudoku determines whether a given 9x9 Sudoku board is valid, meaning each row, column, and 3x3 sub-box contains the digits 1-9 without duplicates.
Key Elements:

board: Two-dimensional character array representing the Sudoku board.
boardSize: Size of the board (always 9 in this case).
boardColSize: Array of column sizes (not used in this implementation).
seen: Array of size 9 used to track the presence of digits within a row, column, or sub-box.
Algorithm:

Check Rows:

Iterate through each row:
Create a new seen array to track digits in the current row.
Iterate through each cell in the row:
If the cell is not empty:
Convert the digit character to its numerical value (0-8).
If the digit has already been seen in this row, return false (invalid Sudoku).
Mark the digit as seen in the seen array.
Check Columns:

Iterate through each column analogously, using a seen array to track digits within each column.
Check 3x3 Sub-Boxes:

Iterate through each 3x3 sub-box:
Create a new seen array for the sub-box.
Iterate through each cell in the sub-box:
If the cell is not empty:
Check for duplicates in the seen array and return false if found.
Mark the digit as seen.
Return Result:

If no duplicates were found in any row, column, or sub-box, return true (valid Sudoku).
Key Points:

Clear Structure: The code is well-structured, with separate blocks for checking rows, columns, and sub-boxes.
Efficient Duplicate Tracking: The seen array efficiently tracks digit occurrences within each unit.
Time Complexity: O(n^2), where n is the board size (9), due to nested loops.
Space Complexity: O(1), as it uses fixed-size arrays regardless of input.
