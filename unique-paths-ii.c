**Unique Paths II**

Problem Statement 136) You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

---------------------------------------------------------------------------------------------------------------------
SOLUTION = int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize, n = obstacleGridColSize[0];
    int dp[m][n];

    // Initialize the first row and column, handling obstacles
    dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    for (int i = 1; i < m; i++) {
        dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i - 1][0] : 0;
    }
    for (int j = 1; j < n; j++) {
        dp[0][j] = obstacleGrid[0][j] == 0 ? dp[0][j - 1] : 0;
    }

    // Fill the remaining cells using dynamic programming
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            } else {
                dp[i][j] = 0; // Obstacle blocks the path
            }
        }
    }

    return dp[m - 1][n - 1]; // Number of unique paths to the bottom-right corner
}

-----Explanation :-
Grid Dimensions and DP Array:

The code starts by retrieving the number of rows (m) from obstacleGridSize and the number of columns (n) from the first element of obstacleGridColSize.
It declares a 2D integer array dp of size m x n to store the number of unique paths to reach each cell in the grid considering obstacles.
Base Case Initialization (Handling Obstacles):

It uses for loops to initialize the first row (i = 0) and the first column (j = 0) of the dp array.
The initial cell (dp[0][0]) is checked for an obstacle (obstacleGrid[0][0]). If there's no obstacle (value is 0), it sets dp[0][0] to 1, indicating one possible path (the starting point itself). Otherwise, it sets dp[0][0] to 0 as there are no paths if the starting point is blocked.
For the remaining cells in the first row (i > 0) and the first column (j > 0), it follows a similar approach. If the corresponding grid cell (obstacleGrid[i][0] or obstacleGrid[0][j]) does not contain an obstacle (value is 0), it considers the number of unique paths to reach the cell above it in the same column (for the first row) or the cell to the left in the same row (for the first column) and stores that value in dp[i][0] or dp[0][j]. This is because if the previous cell is not blocked, the current cell can be reached from there. If the grid cell contains an obstacle, the number of paths to the current cell becomes 0 (represented by setting dp[i][0] or dp[i][j] to 0).
Dynamic Programming with Obstacle Handling:

The core logic utilizes nested for loops to iteratively fill the remaining cells in the dp array:
The outer loop (i) iterates from row 1 (i = 1) to the last row (i < m).
The inner loop (j) iterates from column 1 (j = 1) to the last column (j < n).
Inside the loops, for each cell dp[i][j], the code checks if there's an obstacle in the current grid cell (obstacleGrid[i][j]).
If there's no obstacle (value is 0):
It calculates the number of unique paths to reach the current cell by considering two possibilities:
The number of unique paths to reach the cell above it (dp[i-1][j]).
The number of unique paths to reach the cell to the left (dp[i][j-1]).
The total number of unique paths to reach the current cell dp[i][j] is the sum of these two possibilities, considering that both paths are now valid since the current cell is not blocked.
If there's an obstacle (obstacleGrid[i][j] is not 0), the number of unique paths to reach the current cell becomes 0, as the obstacle blocks any movement from previous cells. This is reflected by setting dp[i][j] to 0.
Return the Number of Unique Paths:

After iterating through all cells, the dp array will contain the number of unique paths to reach each cell in the grid considering obstacles. The number of unique paths for the entire path from the top-left corner to the bottom-right corner will be stored in dp[m - 1][n - 1]. So, the function returns this value.
