**Maximum Subarray**

Problem Statement 104) Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

--------------------------------------------------------------------------------
SOLUTION :- #define MAX(a, b) ((a)>(b)?(a):(b))

int maxSubArray(int* nums, int numsSize)
{
    int i;
    int best = INT_MIN;
    int currsum = 0;

    for (i = 0; i < numsSize; i++) {
        currsum = MAX(currsum + nums[i], nums[i]);
        best = MAX(best, currsum);
    }

    return best;
}
---------Explanation :-
Initialization:

Declare an integer i for loop iteration.
Initialize best to INT_MIN to store the maximum subarray sum found so far (negative infinity essentially).
Initialize currsum to 0 to store the current subarray sum.
Iterate through the array:

Use a for loop to iterate through each element (nums[i]) in the nums array.
Update current subarray sum:

Calculate the maximum between the current subarray sum (currsum) and the current element (nums[i]) using the MAX macro. This ensures that the current subarray sum only increases if including the current element makes it larger.
Update currsum with the calculated maximum value.
Update maximum subarray sum:

Compare the current subarray sum (currsum) with the current best sum (best) using the MAX macro.
If currsum is greater than best, update best as it represents the new maximum subarray sum found so far.
Return the result:

After iterating through the entire array, the best variable will hold the maximum subarray sum found.
Return the best value.
Key Points:

The MAX macro ensures that the currsum is only updated if the current element contributes positively to the subarray sum.
This approach iterates through the array only once, making it efficient for finding the maximum subarray sum.
