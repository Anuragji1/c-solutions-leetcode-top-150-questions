**Jump Game**

Problem Statement 9) You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = bool canJump(int* nums, int numsSize) {
    int reachable = 0;  // Tracks the farthest reachable index

    for (int i = 0; i < numsSize; i++) {
        if (i > reachable) {  // If we can't reach the current index, we can't reach any further
            return false;
        }
        reachable = fmax(reachable, i + nums[i]);  // Update reachable index based on current jump capability
    }

    return true;  // If we reached the end of the loop, we can reach the last index
}

--------------------------Explanation :-
Purpose:

The code implements a function named canJump() that determines whether it's possible to reach the last index of an array nums by making jumps based on the values in the array. Each element represents the maximum jump length from that position.
Key Steps:

Initialization:

reachable is initialized to 0, representing the farthest reachable index so far (initially, only index 0 is reachable).
Iteration and Reachable Index Check:

The code iterates through each index of the array:
It checks if the current index i is greater than the reachable index. If so, it means there's no way to reach the current index, and the function immediately returns false.
Otherwise, it means the current index is reachable, so the function updates reachable to the maximum of its current value and i + nums[i]. This calculates the farthest potentially reachable index from the current position.
Return True If Last Index Reachable:

If the loop completes without encountering an unreachable index, it means the last index is reachable, and the function returns true.
Logic:

The key idea is to keep track of the farthest reachable index as you iterate through the array. If you ever encounter an index that's farther than your current reach, it means you can't progress any further, and the goal is unreachable.
Time and Space Complexity:

Time Complexity: O(n), where n is the size of the array. The algorithm performs a single linear pass through the array.
Space Complexity: O(1), as it uses only a constant amount of extra space for variables, regardless of the input size.
