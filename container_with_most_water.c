**Container With Most Water**

Problem Statement 28) You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int maxArea(int* height, int heightSize){
    int l=0, r=heightSize-1;
    int max = 0;
    while(l < r)
    {
        int area = (r-l)*(height[l] < height[r]? height[l++] : height[r--]);
        max = max > area? max : area;
    }
    return max;
}

--------------------------------Explanation :-
Key elements:

height: Pointer to an array of integers representing the heights of containers.
heightSize: Integer representing the size of the height array.
l: Integer index pointing to the leftmost container in the search window.
r: Integer index pointing to the rightmost container in the search window.
max: Integer variable keeping track of the maximum area found so far.
Algorithm:

Initializing pointers:

Initialize l to point to the first container (index 0) and r to point to the last container (index heightSize - 1).
Two-pointer loop:

Enter a loop while l is less than r. This ensures both pointers remain within the valid range of the height array.
Within the loop:
Calculate the potential area of a container formed by the current left and right container heights:
The area is computed as the product of the difference between r and l (representing the container width) and the smaller of the two heights at l and r (representing the container height).
Compare the calculated area with the current max:
If the area is greater than max, update max to store the newly found larger area.
Move the pointers based on the container heights:
If the height at l is smaller than the height at r, increment l to potentially find a taller container on the left that can contribute to a larger area.
Otherwise, decrement r to potentially find a taller container on the right that can contribute to a larger area.
Returning maximum area:

After the loop finishes iterating through all container pairs, max will hold the maximum area found among all possible container combinations.
Therefore, the function returns the value of max.
Key points:

The two-pointer approach efficiently explores all possible container pairings without redundant calculations.
It cleverly utilizes the smaller height of the two pointers as the container height to ensure the container doesn't overflow the lower border.
Updating max only when a larger area is found efficiently identifies the optimal container combination.
This implementation offers a well-structured and efficient solution for finding the maximum area of a container formed by two lines connecting the given heights, demonstrating the use of the two-pointer technique and efficient area calculation strategies.
