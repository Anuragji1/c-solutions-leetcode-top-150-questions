**Minimum Size Subarray Sum**

Problem Statement 30) Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

--------------------------------------------------------------------------------------------------------------------------
SOLUTION = int minSubArrayLen(int target, int* nums, int numsSize){
    int left = 0, sum = 0, minLen = INT_MAX;

    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];

        while (sum >= target) {
            minLen = fmin(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}


-------------------Explanation:-
Function Overview:

minSubArrayLen finds the minimum length of a contiguous subarray within a given array of integers that has a sum greater than or equal to a specified target.
It employs a sliding window technique to efficiently scan the array.
Key Elements:

**target: The minimum required sum for the subarray.
**nums: Pointer to the array of integers.
**numsSize: Size of the nums array.
**left: Index marking the left end of the current subarray window.
**right: Index marking the right end of the current subarray window.
**sum: Variable holding the sum of elements within the current window.
**minLen: Variable storing the minimum subarray length found so far.
Algorithm:

Initialization:

Set left, sum, and minLen to 0, 0, and INT_MAX, respectively.
Sliding Window:

Iterate through the array using right pointer:
Add the current element to sum.
While sum is greater than or equal to target:
Update minLen if the current window size is smaller than the current minLen.
Subtract the element at left from sum and move left forward to shrink the window.
Return Result:

If minLen remains INT_MAX, it implies no subarray with the required sum was found. Return 0.
Otherwise, return minLen, representing the minimum subarray length.
