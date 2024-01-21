**Jump Game II**

Problem Statement 10) You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int jump(int* nums, int numsSize) {
	if (numsSize == 0) return -1;
	int* min_jumps_array = (int*)calloc(numsSize, sizeof(int));
	min_jumps_array[numsSize - 1] = 0;
	for (int i = numsSize - 2; i >= 0; i--) {
		int min = numsSize+1;
		for (int j = 1; j <= nums[i] && j + i < numsSize; j++) {
			min = min_jumps_array[i + j] < min ? min_jumps_array[i + j] : min;
		}
		min_jumps_array[i] = min + 1;
	}
	return min_jumps_array[0];
}


-----------------------------Explanation :-
Purpose:

The code implements a function named jump() that efficiently calculates the minimum number of jumps required to reach the last index of an array nums. Each element in nums represents the maximum jump length from that position.
Key Steps:

Edge Case Handling:

If numsSize is 0 (empty array), the function returns -1, indicating no jumps are possible.
Initialization of Jump Count Array:

An array min_jumps_array of size numsSize is allocated and initialized to 0 using calloc. This array will store the minimum number of jumps required to reach each index from the beginning of the array.
The last index is set to 0, as you're already there and need no jumps.
Dynamic Programming Iteration:

The code iterates through the array from the second last index to the first index:
For each index i, it iterates through potential reachable indices within the jump range nums[i]:
It finds the minimum number of jumps required to reach any of these reachable indices from i.
The minimum jump count for index i is then calculated by adding 1 to the minimum jump count of the reachable index with the smallest jump count.
Return Minimum Jumps:

After the iteration, the first element of min_jumps_array holds the minimum number of jumps required to reach the last index from the beginning, which is returned as the result.
Logic:

The code employs dynamic programming to build the solution incrementally. It leverages the fact that the minimum jumps to reach any index depend on the minimum jumps required to reach its reachable indices.
Time and Space Complexity:

Time Complexity: O(n^2), due to the nested loops iterating through the array and potential reachable indices.
Space Complexity: O(n), as it uses an array of size numsSize to store the minimum jump counts for each index.
