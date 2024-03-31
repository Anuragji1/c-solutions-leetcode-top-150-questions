**House Robber**

Problem Statement 130) You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400

---------------------------------------------------------------------------------------------------
SOLUTION = 
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize)
{
    int i;
    int *dp = malloc(sizeof(int) * numsSize);
    
    if (numsSize == 0)
        return 0;
    
    for (i = 0; i < numsSize; i++) {
        switch(i) {
            case 0:
                dp[i] = nums[0];
                break;
            case 1:
                dp[i] = MAX(nums[i], dp[i - 1]);
                break;
            default:
                dp[i] = MAX(nums[i] + dp[i - 2], dp[i - 1]);
        }
    }
    
    return dp[numsSize - 1];
}

----Explanation :-
Memory Allocation:

The code starts by allocating memory for a dynamic programming array dp of size numsSize using malloc. This array will store the maximum amount of money obtainable at each house index.
Base Cases:

It checks for an empty array (numsSize == 0) and returns 0 in that case (no houses to rob from).
Dynamic Programming with Memoization:

It uses a for loop to iterate through each house index (i) in the nums array.
Inside the loop, a switch statement handles different scenarios based on the house index:
First House (i = 0):
The maximum amount obtainable at the first house is simply the value present in nums[0]. So, dp[0] is assigned nums[0].
Second House (i = 1):
The thief can either rob the first house (dp[0]) or the second house (nums[1]). The better option is stored in dp[1] using the MAX macro (defined as MAX(a, b) to return the larger of a and b).
Other Houses (i > 1):
The thief cannot rob two adjacent houses. So, the maximum obtainable amount at the current house (i) depends on two possibilities:
Rob the current house (nums[i]) and add the maximum obtainable amount from the house two positions before (dp[i-2]) (since the thief cannot rob the previous house).
Skip the current house and consider the maximum obtainable amount from the previous house (dp[i-1]).
The MAX macro is again used to choose the larger of these two options and store it in dp[i].
Return the Maximum:

After iterating through all houses, the dp array will hold the maximum obtainable amount at each house index. The function returns the value stored in dp[numsSize - 1], which represents the maximum amount possible for the last house, considering the constraints.
