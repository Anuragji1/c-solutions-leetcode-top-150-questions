**MAximum Square**

Problem Statement 150) Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.

-------------------------------------------------------------------------------------------------------------
SOLUTION = #include <stdio.h>
#include <limits.h>

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0];
    int dp[m + 1][n + 1];
    int maxSide = 0;

    // Initialize dp array with 0s for base cases
    memset(dp, 0, sizeof(dp));

    // Iterate through the matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = 1 + fmin(fmin(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                maxSide = fmax(maxSide, dp[i][j]);
            }
        }
    }

    return maxSide * maxSide; // Area of the largest square
}

----Explanation :-
Dynamic Programming for Largest Square Submatrix:

Initialization:

The code includes necessary header files (stdio.h for input/output and limits.h for integer constant definitions).
It takes the input matrix (matrix), its size (matrixSize), and an array containing the column size (matrixColSize) (assuming the matrix might have non-uniform column sizes).
It retrieves the actual number of rows (m) from matrixSize and the number of columns (n) from the first element of matrixColSize.
It declares a 2D integer array dp of size (m + 1) x (n + 1) to store the side length of the maximum square submatrix ending at each cell in the original matrix.
It initializes the dp array with all zeros using memset. This represents that there's no square submatrix of size greater than 0 ending at any cell initially.
Base Cases (Implicit):

Since the dp array is initialized with zeros, it implicitly handles the base cases:
If a cell in the original matrix has a value '0', the corresponding dp[i][j] will remain 0, indicating no square submatrix exists ending at that cell.
The first row (dp[0]) and the first column (dp[i][0]) will also have zeros by initialization, considering there can't be squares extending beyond the matrix boundaries.
Iterative DP Calculations:

The code uses nested for loops to iterate through the dp array (excluding the first row and column as they represent base cases):

The outer loop (i) iterates from 1 to m (actual rows in the matrix).
The inner loop (j) iterates from 1 to n (actual columns in the matrix).
Inside the loops, for each cell dp[i][j], it checks if the corresponding character in the original matrix (matrix[i-1][j-1]) is '1' (represents a valid starting point for a square).

If it's '1':
The size of the current square submatrix is calculated by considering the minimum side length of the squares ending at the top (dp[i-1][j]), left (dp[i][j-1]), and top-left (dp[i-1][j-1]) cells. The fmin function is used to find the minimum among these three values.
Since the current cell is valid ('1'), we can add 1 to the minimum side length from the previous squares to get the size of the square ending at the current cell.
This calculated value is stored in dp[i][j].
The code also updates maxSide to keep track of the largest side length encountered so far. This is done using fmax(maxSide, dp[i][j]).
Return Maximum Square Area:

After iterating through all cells, the dp array will contain the side lengths of the maximum square submatrix ending at each cell in the original matrix.
The final result is the area of the largest square, which is calculated by squaring the maxSide value.
The function returns this area (maxSide * maxSide).
