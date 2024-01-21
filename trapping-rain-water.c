**Trapping Rain Water**

Problem Statement 16) Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int trap(int* height, int heightSize) {
    if (heightSize <= 2) return 0;  // Handle edge cases

    int left = 0, right = heightSize - 1, water = 0;
    int leftMax = 0, rightMax = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }

    return water;
}


-------------------------------Explanation :-
  Purpose:

The code implements a function named trap() that calculates the total amount of rainwater that can be trapped within an elevation map represented by an array height.
Key Steps:

Edge Case Handling:

If the array has less than or equal to 2 elements, no water can be trapped, so it returns 0.
Initialization:

It sets up two pointers, left and right, starting at the beginning and end of the array, respectively.
It initializes water to 0 to keep track of the trapped water.
It initializes leftMax and rightMax to 0 to track the maximum heights seen from the left and right sides.
Two-Pointer Approach:

The code uses a two-pointer approach to iterate through the array:
It compares the heights at left and right indices:
If height[left] is less than or equal to height[right]:
It checks if height[left] is greater than or equal to leftMax. If so, it updates leftMax as a new potential boundary for trapping water.
Otherwise, it calculates the trapped water at the current left index as leftMax - height[left] and adds it to the water total.
It moves the left pointer to the next index.
Similarly, if height[right] is less than height[left], it processes the right pointer in a similar manner.
Returning the Trapped Water:

After the iteration, the water variable holds the total amount of trapped rainwater, which is returned as the result.
Logic:

The code effectively uses the two-pointer approach to efficiently scan the array from both ends.
It leverages the concept of tracking maximum heights from both sides to determine the potential water that can be trapped at each position.
It calculates the trapped water at each position based on the difference between the current height and the maximum height seen so far from the appropriate side.
Time and Space Complexity:

Time Complexity: O(n), where n is the size of the array. The algorithm performs a single linear pass through the array using the two pointers.
Space Complexity: O(1), as it uses only a constant amount of extra space for variables.
