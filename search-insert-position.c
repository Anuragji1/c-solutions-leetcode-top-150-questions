**Search Insert Position**

Problem Statement 106) Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

----------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Found the target
            } else if (nums[mid] < target) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }

        // Target not found, return the insertion point
        return left;
    }
};

----------Explanation :-
Initialization:

Declare two integer variables:
left: Initialized to 0, representing the index of the first element in the search range.
right: Initialized to nums.size() - 1, representing the index of the last element in the search range.
Binary Search Loop:

Use a while loop to continue searching as long as left is less than or equal to right:
Calculate the middle index mid as the average of left and right.
Comparison and Update:

Check if the target is found at the middle index:
If nums[mid] == target, return mid as the target is found at the correct position.
If the target is greater than the middle element:
Update left to mid + 1 to search the right half of the remaining search range.
Otherwise (target is less than the middle element):
Update right to mid - 1 to search the left half of the remaining search range.
Target Not Found:

If the loop completes without finding the target, it means the target is not present in the vector.
In this case, left will point to the index where the target should be inserted to maintain the sorted order.
Return the value of left as the insertion point.
