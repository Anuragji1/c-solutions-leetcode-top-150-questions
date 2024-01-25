**Spiral Matrix**

Problem Statement 35) Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

-----------------------------------------------------------------------------------------------
SOLUTION = int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int rows = matrixSize, cols = matrixColSize[0];
    int* result = (int*)malloc(rows * cols * sizeof(int));
    *returnSize = rows * cols;

    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int index = 0;

    while (top <= bottom && left <= right) {
        // Traverse right
        for (int i = left; i <= right; i++) {
            result[index++] = matrix[top][i];
        }
        top++;

        // Traverse down
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;

        // Traverse left (if any elements remaining)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[index++] = matrix[bottom][i];
            }
            bottom--;
        }

        // Traverse up (if any elements remaining)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}

---------------------------Explanation :-
Function Overview:

spiralOrder takes a 2D matrix as input and returns an array containing its elements in spiral order (clockwise, starting from the top-left corner).
Key Elements:

matrix: The input 2D matrix.
matrixSize: Number of rows in the matrix.
matrixColSize: Array of column sizes (not fully utilized in this implementation).
returnSize: Pointer to store the size of the output array.
result: Array to store the elements in spiral order.
top, bottom, left, right: Variables to track boundaries of the spiral.
index: Index for filling the result array.
Algorithm:

Initialization:

Allocate memory for the result array.
Set boundary variables based on matrix dimensions.
Initialize index to 0.
Spiral Traversal:

Iterate while there are elements within the spiral boundaries:
Traverse Right:
Move from left to right, adding elements to result.
Traverse Down:
Move from top to bottom, adding elements to result.
Traverse Left (if remaining):
Move from right to left, adding elements to result.
Traverse Up (if remaining):
Move from bottom to top, adding elements to result.
Update boundary variables to shrink the spiral.
Return Result:

Return the result array containing elements in spiral order.
Key Points:

Concise Traversal Logic: The code effectively uses nested loops and boundary updates to achieve spiral traversal.
Space Optimization: It avoids unnecessary element access and memory usage.
Time Complexity: O(m * n), where m and n are the matrix dimensions, due to single traversal through all elements.
Space Complexity: O(m * n) for the result array, but additional space is used for variables and pointers.
