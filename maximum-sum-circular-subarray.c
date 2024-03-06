**Maximum Sum Circular Subarray**

Problem Statement 105) Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104

--------------------------------------------------------------------------------------------------------
SOLUTION :-
int maxSubarraySumCircular(int* nums, int numsSize){
    short sNumsSize = numsSize;
    int nTotal = 0, nMax = INT_MIN, nMaxTmp = 0, nMin = INT_MAX, nMinTmp = 0;
    while(numsSize-- > 0)
    {
        nTotal += *nums;

        // check max
        if(nMaxTmp > 0)
        {
            nMaxTmp += *nums;
        }
        else
        {
            nMaxTmp = *nums;
        }
        if(nMaxTmp > nMax) nMax = nMaxTmp;

        // check min
        if(nMinTmp < 0)
        {
            nMinTmp += *nums;
        }
        else
        {
            nMinTmp = *nums;
        }
        if(nMinTmp < nMin) nMin = nMinTmp;



        nums++;
    }

    // get result from nTotal - nMin
    nTotal -= nMin;

    return nMax < 0? nMax: (nTotal > nMax? nTotal: nMax);
}

---------Explanation :-
This code implements the maxSubarraySumCircular function, which finds the maximum subarray sum in a circular array of integers (nums). A circular array can be thought of as an array where the last element connects back to the first element, forming a loop.

Steps:

Variable Declaration:

Declare sNumsSize as a short to store the numsSize for type safety.
Initialize variables:
nTotal: To store the sum of all elements in the array.
nMax: To store the maximum subarray sum found so far.
nMaxTmp: To store the temporary maximum subarray sum.
nMin: To store the minimum subarray sum found so far.
nMinTmp: To store the temporary minimum subarray sum.
Iterate through the array:

Use a while loop to iterate until numsSize becomes negative (condition numsSize-- > 0). This effectively iterates through the array once, considering its circular nature (the last element leads back to the first).
Update nTotal:

Add the current element (*nums) to nTotal.
Update nMax (maximum subarray sum):

Check if nMaxTmp is positive (previous maximum could contribute):
If yes, add the current element (*nums) to nMaxTmp.
Otherwise, set nMaxTmp to the current element (*nums).
Update nMax to the maximum of its current value and nMaxTmp.
Update nMin (minimum subarray sum):

Check if nMinTmp is negative (previous minimum could contribute):
If yes, add the current element (*nums) to nMinTmp.
Otherwise, set nMinTmp to the current element (*nums).
Update nMin to the minimum of its current value and nMinTmp.
Move to the next element:

Increment the pointer nums to move to the next element in the array.
Handle circular nature (optional):

Since it's a circular array, the minimum subarray sum might represent the entire circular sum if all elements are negative.
Subtract nMin from nTotal to remove the negative contribution of the minimum subarray sum, potentially leading to a larger overall sum.
Return the result:

If nMax is negative, meaning all elements are negative, return nMax as it's the largest negative sum.
Otherwise, compare nTotal and nMax:
If nTotal is greater than nMax, return nTotal as the overall circular sum is larger than the maximum subarray sum.
Otherwise, return nMax as the maximum subarray sum is the largest.
