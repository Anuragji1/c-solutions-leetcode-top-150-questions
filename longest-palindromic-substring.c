**Longest Palindromic Substring**

Problem-Solving 145) Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

-------------------------------------------------------------------------------
SOLUTION = 
typedef struct word {
    char *s;
    int len;
} word;

char * longestPalindrome(char * s)
{
    int n = strlen(s);
    int i, j, d;
    word longest;
    longest.s = s;
    longest.len = 0;
    
    for (i = 0; i < n; i++) {
        for (d = 0; i - d >= 0 && i + d < n; d++) {
            if (s[i - d] != s[i + d])
                break;
            if (longest.len < 1 + d * 2) {
                longest.s = &s[i - d];
                longest.len = 1 + d * 2;
            }
        }

        for (d = 1; i - d + 1 >= 0 && i + d < n; d++) {
            if (s[i - d + 1] != s[i + d])
                break;
            if (longest.len < d * 2) {
                longest.s = &s[i - d + 1];
                longest.len = d * 2;
            }
        }
    }
    
    if (longest.len < n)
        longest.s[longest.len] = '\0';
    return longest.s;
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
