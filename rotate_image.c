**Rotate Image**

Problem Statement 36) You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

------------------------------------------------------------------------------------------
SOLUTION = void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int n = matrixSize;
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - layer - 1;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            // Save top element
            int top = matrix[first][i];

            // Move left element to top
            matrix[first][i] = matrix[last - offset][first];

            // Move bottom element to left
            matrix[last - offset][first] = matrix[last][last - offset];

            // Move right element to bottom
            matrix[last][last - offset] = matrix[i][last];

            // Move saved top element to right
            matrix[i][last] = top;
        }
    }
}

----------------------------Explanation :-
Function Overview:

rotate rotates a given square matrix in-place by 90 degrees clockwise.
Key Elements:

matrix: The input 2D matrix to be rotated.
matrixSize: The size of the matrix (assumed to be square).
matrixColSize: Array of column sizes (not used in this implementation).
Algorithm:

Layer-by-Layer Rotation:
Iterate through "layers" of the matrix (from outer to inner):
Calculate first and last indices for the current layer.
Iterate through elements in the current layer:
Perform a 4-way element swap:
Save the top element in a temporary variable.
Move the left element to the top position.
Move the bottom element to the left position.
Move the right element to the bottom position.
Move the saved top element to the right position.
Key Points:

Layer-Based Approach: The code efficiently rotates layers of elements, ensuring a complete 90-degree rotation.
In-Place Modification: It modifies the matrix directly, avoiding additional memory usage.
Time Complexity: O(n^2) due to nested loops that iterate through all elements.
Space Complexity: O(1), as it uses a fixed amount of extra space for variables.
Additional Insights:

Generalizability: The code assumes a square matrix; extensions could handle rectangular matrices.
Alternative Approaches:
Consider using temporary arrays for element storage, potentially simplifying logic.
Explore matrix transposition and reversal for alternative rotation methods.
Visualization: Drawing a visual diagram of the layer-by-layer rotation can aid understanding.
Error Handling: The code doesn't explicitly handle invalid inputs like non-square matrices.

