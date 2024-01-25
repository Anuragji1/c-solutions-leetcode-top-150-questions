**Set Matrix Zeroes**

Problem Statement 37) Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

-------------------------------------------------------------------------------------------------------------------
SOLUTION = void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int m = matrixSize, n = matrixColSize[0];
    bool firstRowZero = false, firstColZero = false;

    // Check for zeros in the first row and column
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Use the first row and column to mark zeros
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark the corresponding row
                matrix[0][j] = 0; // Mark the corresponding column
            }
        }
    }

    // Set zeros based on the markings
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set zeros in the first row and column if needed
    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

----------------------------------Explanation :-
Function Overview:

setZeroes modifies a given 2D matrix in-place, setting all elements in a row or column to 0 if any element in that row or column is 0.
Key Elements:

matrix: The input 2D matrix to be modified.
matrixSize: Number of rows in the matrix.
matrixColSize: Array of column sizes (not fully utilized here).
firstRowZero, firstColZero: Flags to track if the first row or column needs to be set to 0.
Algorithm:

Check First Row and Column:

Iterate through the first row and column to check for zeros and set flags accordingly.
Mark Zeros:

Iterate through the matrix (excluding first row and column):
If an element is 0:
Mark the corresponding row and column by setting matrix[i][0] and matrix[0][j] to 0.
Set Zeros Based on Markings:

Iterate through the matrix (excluding first row and column):
If either matrix[i][0] or matrix[0][j] is 0, set matrix[i][j] to 0.
Set Zeros in First Row and Column (if needed):

If firstRowZero is true, set all elements in the first row to 0.
If firstColZero is true, set all elements in the first column to 0.
Key Points:

In-Place Modification: Efficiently modifies the matrix without extra memory.
Space Optimization: Uses the first row and column as markers, reducing memory usage.
Handles Edge Cases: Explicitly checks and sets zeros in the first row and column.
Time Complexity: O(m * n) due to nested loops iterating through all elements.
Space Complexity: O(1), using only a few extra variables.
