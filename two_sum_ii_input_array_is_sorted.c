**Two Sum II - Input Array Is Sorted**

Problem Statement 27) Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.

-----------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left = 0, right = numbersSize - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            *returnSize = 2;
            int *result = malloc(sizeof(int) * 2);
            result[0] = left + 1;  // Add 1 for 1-indexing
            result[1] = right + 1;
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    *returnSize = 0;  // No solution found
    return NULL;
}

-------------------------------------Explanation :-
Key elements:

numbers: Pointer to the array of integers (assumed to be sorted in ascending order).
numbersSize: Integer representing the size of the numbers array.
target: Integer representing the desired sum.
returnSize: Pointer to an integer variable to store the size of the result array.
left: Integer index pointing to the beginning of the search window.
right: Integer index pointing to the end of the search window.
Algorithm:

Initializing pointers:

Initialize left and right to point to the first and last element of the numbers array, respectively.
Two-pointer loop:

Enter a loop while left is less than right. This ensures both indexes remain within the array bounds.
Within the loop:
Calculate the sum of the elements pointed to by left and right.
Compare the sum with the target:
Target found:
If the sum matches the target, set *returnSize to 2 and dynamically allocate memory for a result array of size 2.
Store the 1-indexed positions of left and right in the result array and return it.
Sum less than target:
If the sum is less than the target, the desired pair must be located further towards the right side of the sorted array. Therefore, increment left to move the search window closer to potentially larger values.
Sum greater than target:
If the sum is greater than the target, the desired pair must be located towards the left side of the sorted array. Therefore, decrement right to move the search window closer to potentially smaller values.
No solution:

If the loop finishes without finding a match, set *returnSize to 0 and return NULL to indicate no solution exists.
Key points:

The two-pointer approach efficiently utilizes the sorted nature of the array to eliminate unnecessary comparisons.
It avoids duplicate comparisons by always moving the pointer pointing to the element exceeding the desired sum.
Dynamic memory allocation ensures efficient creation of the result array only when a solution is found.
