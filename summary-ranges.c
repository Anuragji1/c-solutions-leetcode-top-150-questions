**Summary Ranges**

Problem Statement 49) You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
 

Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.

-------------------------------------------------------------------------------------
SOLUTION = char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	*returnSize=0;
	if(0==numsSize){
		return 0;
	}
	char **ret=malloc(sizeof(char*)*numsSize);
	char buff[265];
	int p1=0;
	int p2=1;
	while(p1<numsSize){
		while(p2<numsSize && nums[p2-1]==nums[p2]-1) ++p2;

		if(p1 < p2-1){
			int isp=sprintf(buff,"%d->%d",nums[p1],nums[p2-1]);
			char *m=malloc(sizeof(char)*(isp+1));
			ret[*returnSize]=strcpy(m,buff);
			++(*returnSize);
		}else{
			int isp=sprintf(buff,"%d",nums[p1]);
			printf("n:%d,isp:%d\n",nums[p1],isp);
			char *m=malloc(sizeof(char)*(isp+1));
			ret[*returnSize]=strcpy(m,buff);
			++(*returnSize);
		}
		p1=p2;
		++p2;
	}
	return ret;
}

---------------------Explanation :-
Purpose:

This code summarizes a sorted array nums of integers into ranges, representing consecutive numbers as "start->end" or single numbers as "number".
Function Breakdown:

Initialization:

Sets *returnSize to 0 for tracking the number of ranges.
Handles the empty array case: returns 0.
Allocates memory for an array of char* pointers (ret) to store the range strings.
Creates a temporary buffer buff for string formatting.
Initializes pointers p1 and p2 for range detection.
Iterating and Identifying Ranges:

Iterates through nums using p1 and p2:
Inner while loop: Extends the current range as long as consecutive elements are found:
Increments p2 until a gap is found or the end of the array is reached.
If a range is found (p1 < p2-1):
Formats the range string using sprintf.
Allocates memory for the range string.
Copies the formatted string into the allocated memory and stores it in ret.
Increments *returnSize.
If a single number is found:
Formats the number string using sprintf.
Allocates memory for the number string.
Copies the formatted string into the allocated memory and stores it in ret.
Increments *returnSize.
Updates p1 and p2 for the next range.
Return Range Summary:

Returns the array ret containing the range strings.
Key Points:

Two Pointer Approach: Uses two pointers to efficiently detect ranges in a single pass.
Dynamic Memory Allocation: Allocates memory dynamically for range strings based on their lengths.
String Formatting: Uses sprintf to format range and number strings.
Time Complexity: O(n), where n is the array size.
Space Complexity: O(n) for the output array and temporary strings.
