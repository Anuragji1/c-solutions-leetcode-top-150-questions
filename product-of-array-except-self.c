**Product of Array Except Self**

Problem Statement 13) Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    // Calculate prefix products from left to right
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Calculate suffix products from right to left and combine with prefixes
    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}


------------------------------Explanation :-
Purpose:

The code implements a function named productExceptSelf() that efficiently calculates the product of all elements in an array nums, except for each element itself. It does this without using division.
Key Steps:

Initialization:

An array answer of size numsSize is allocated to store the resulting products.
*returnSize is set to numsSize to indicate the size of the returned array.
Prefix Product Calculation:

The code iterates through the array from left to right, starting with the second element:
It calculates the prefix product for each index i by multiplying the previous prefix product answer[i - 1] with the element at index i - 1.
This effectively stores the product of all elements to the left of each index in the answer array.
Suffix Product Calculation and Combination:

The code iterates through the array from right to left, starting with the second last element:
It maintains a suffix variable, initialized to 1, which stores the product of all elements to the right of the current index.
It combines the prefix product at each index i with the suffix by multiplying them and storing the result back in answer[i].
The suffix is then updated by multiplying it with the current element nums[i] for the next iteration.
Return the Result:

The final answer array contains the product of all elements except for each element itself, and it's returned as the result.
Logic:

The code leverages the concept of prefix and suffix products to efficiently calculate the desired result without using division. It avoids division by cleverly combining partial products from both ends of the array.
Time and Space Complexity:

Time Complexity: O(n), where n is the size of the array. The algorithm performs two linear passes through the array.
Space Complexity: O(n), as it uses an additional array of size numsSize to store the results.
