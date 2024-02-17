**Number of Islands**

Problem Statement 89) Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

------------------------------------------------------------------------------------------------------------
SOLUTION = #include <stdio.h>

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '1') {
                count++;  // Found a new island
                dfs(grid, gridSize, gridColSize, i, j);  // Sink the island
            }
        }
    }

    return count;
}

void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || i >= gridSize || j < 0 || j >= *gridColSize || grid[i][j] == '0') {
        return;  // Outside grid or water
    }

    grid[i][j] = '0';  // Mark as visited

    dfs(grid, gridSize, gridColSize, i + 1, j);
    dfs(grid, gridSize, gridColSize, i - 1, j);
    dfs(grid, gridSize, gridColSize, i, j + 1);
    dfs(grid, gridSize, gridColSize, i, j - 1);
}


--------------Explanation :-
Explanation:

numIslands Function:

Initialization:
count to 0, accumulating the island count.
Grid Traversal:
Nested loops iterate through each cell in the grid (grid[i][j]).
If the cell contains land (grid[i][j] == '1'), it's part of an unvisited island:
Increment count for a new island.
Call dfs to explore and mark visited cells on this island.
Return:
Return the final count, representing the total number of islands found.
dfs Function (Recursive Depth-First Search):

Base Cases:
If the cell is outside the grid boundaries, water (grid[i][j] == '0'), or already visited, return (don't explore further).
Marking and Exploration:
Mark the current cell as visited by changing grid[i][j] to '0'.
Recursively call dfs on its four adjacent neighbors (up, down, left, right) to explore connected land cells, effectively sinking the entire island.
Key Points:

The algorithm efficiently counts islands using DFS to avoid revisiting explored cells.
Time complexity: O(m * n), where m and n are the grid dimensions, as each cell is visited at most once in the worst case.
Space complexity: O(h), where h is the depth of the recursion stack, which depends on the grid's largest island size and recursion depth.
Example:

Consider a grid represented by:

11000
11000
00100
00011
This grid has 3 islands: the top-left 2x2 block, the middle 1x2 block, and the bottom-right 2x2 block. The numIslands function would return 3.
