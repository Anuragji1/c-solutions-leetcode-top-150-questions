**Longest Increasing Subsequence**

Problem Statement 133) Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

-------------------------------------------------------------------------------------------------
SOLUTION = int lengthOfLIS(int* nums, int numsSize) {
    if(numsSize==0){
        return 0;
    }
    int* dp=(int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        dp[i]=1;
    }
    for(int i=1;i<numsSize;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=dp[i]>1+dp[j]?dp[i]:1+dp[j];
            }
        }
        
    }
    for(int j=0;j<numsSize;j++){
        dp[numsSize-1]=dp[numsSize-1]>dp[j]?dp[numsSize-1]:dp[j];
    }
    return dp[numsSize-1];
}

-----Explanation :-
Base Case:

The code first checks for a base case. If numsSize (number of elements in the array) is 0, it means there's no sequence, so it returns 0.
dp Array Initialization:

It allocates memory for a dynamic programming array dp of size numsSize using malloc. This array will store the length of the LIS ending at each index in the nums array.
It initializes all elements in dp to 1. This is because an increasing subsequence of length 1 can always be formed by considering a single element itself.
Iterative Length Updates:

It uses nested for loops to iteratively build the LIS lengths in the dp array:
The outer loop (i) iterates from 1 to numsSize - 1 (excluding the first element as it's already considered in the initialization).
The inner loop (j) iterates from 0 to i - 1 (checking all elements before the current element i).
Inside the inner loop, it checks if the current element nums[i] is greater than the element at index j (nums[j]).
If nums[i] is greater:
It calculates the potential LIS length ending at index i by considering the LIS length at index j (which is the longest increasing subsequence up to element j that can be extended by nums[i]) and adding 1 (to include nums[i]).
It compares the calculated length with the current value in dp[i] (which might have a different LIS length ending at i from previous comparisons in the inner loop).
The larger of the two lengths is stored in dp[i]. This ensures that dp[i] always holds the maximum LIS length ending at index i.
Incorrect Loop (Commented Out):

The code includes an additional loop (commented out) that iterates through dp again and seems to have an error. It compares dp[numsSize - 1] (LIS length at the last element) with all other elements in dp and updates dp[numsSize - 1] if a larger value is found. This loop is not necessary for finding the LIS length and can be safely removed.
Return the Result:

After the loops complete, the dp array will contain the LIS lengths for all subsequences ending at each index. The LIS length for the entire sequence is stored in dp[numsSize - 1]. So, the function returns the value stored in dp[numsSize - 1], which represents the length of the longest increasing subsequence in the nums array.
