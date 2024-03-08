**Search a 2D Matrix**

Problem Statement 107) You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

----------------------------------------------------------------------------------------------------------------
SOLUTIOn = bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize, n = matrixColSize[0];
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int row = mid / n, col = mid % n;

        if (matrix[row][col] == target) {
            return true; // Target found
        } else if (matrix[row][col] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return false; // Target not found
}


-----------Explanation :-
Initialization:

Extract the number of rows (m) from matrixSize.
Extract the number of columns (n) from the first element of matrixColSize (assuming all rows have the same number of columns).
Declare two integer variables:
left: Initialized to 0, representing the index of the first element in the search range (considering the matrix as a one-dimensional array).
right: Initialized to m * n - 1, representing the index of the last element in the search range (considering the matrix as a one-dimensional array).
Binary Search Loop:

Use a while loop to continue searching as long as left is less than or equal to right:
Calculate the middle index mid as the average of left and right.
Calculate Row and Column from Index:

Derive the row (row) and column (col) indices corresponding to the middle index mid using integer division (mid / n) and modulo (mid % n) operations.
Comparison and Update:

Check if the target is found at the calculated position in the matrix:
If matrix[row][col] == target, return true as the target is found.
If the target is greater than the element at the middle position:
Update left to mid + 1 to search the right half of the remaining search range.
Otherwise (target is less than the element at the middle position):
Update right to mid - 1 to search the left half of the remaining search range.
Target Not Found:

If the loop completes without finding the target, it means the target is not present in the matrix.
Return false to indicate the target was not found.
