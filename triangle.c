**Trainagle**

Problem Statement 134) Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104

----------------------------------------------------------------------------------------
SOLUTION = 
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    int last_row_sz = triangleColSize[triangleSize - 1];
    
    int memo[last_row_sz];
    for (int idx = 0; idx < last_row_sz; ++idx)
        memo[idx] = triangle[triangleSize - 1][idx];
    
    for (int r = triangleSize -2; r >= 0; --r) {
        for (int c = 0 ; c < triangleColSize[r]; ++c) {
            memo[c] = triangle[r][c] + MIN(memo[c], memo[c + 1]);
        }
    }
    return memo[0];
}

----Explanation :-
Base Case (Bottom Row):

The code first retrieves the size of the last row in the triangle using triangleColSize[triangleSize - 1].
It creates a memoization array memo of size last_row_sz to store the minimum sum at each element in the bottom row (last row).
It iterates through the elements in the bottom row and directly copies their values from the triangle array into the memo array. This is because the minimum sum to reach any element in the bottom row is simply the value of that element itself.
Iterative Bottom-up Approach:

The code uses nested for loops to iteratively calculate the minimum sum for elements in rows above the bottom row:
The outer loop (r) iterates in reverse order from the second-last row (triangleSize - 2) up to the first row (r >= 0).
The inner loop (c) iterates through the elements in the current row (r), considering valid column indices within the range 0 to triangleColSize[r] - 1.
Minimum Sum Calculation with Memoization:

Inside the inner loop, for each element triangle[r][c] in the current row r, the code calculates the minimum sum to reach that element. It leverages the memoization table to achieve this efficiently.
It calculates the sum of the current element's value (triangle[r][c]) and the minimum sum stored for the element below it in the next row (memo[c]).
It uses the MIN macro (defined as MIN(X, Y)) to compare this calculated sum with the minimum sum stored for the element to the right below it in the next row (memo[c + 1]).
The smaller of these two sums is then stored in the corresponding element (memo[c]) of the memoization array for the current row r. This ensures that memo[c] always holds the minimum total sum to reach that element in the triangle considering all possible paths from the bottom row up to that point.
Return the Minimum Total:

After iterating through all rows and elements, the memo array will contain the minimum total sum to reach each element in the triangle. The minimum total path from the top to the bottom will always start from the first element (index 0) in the top row.
Therefore, the function returns the value stored in memo[0], which represents the minimum total sum for the entire path from the top to the bottom element in the triangle.
