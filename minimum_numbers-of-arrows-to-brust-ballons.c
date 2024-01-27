**Minimum Numbers of Arrows to Brust Ballons**

Problem Statement 52) There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 

Constraints:

1 <= points.length <= 105
points[i].length == 2
-231 <= xstart < xend <= 231 - 1

------------------------------------------------------------------------------------------------
SOLUTION = // sort end
int cmpfunc( const void** p1,  const void** p2){
   int* arr1 = *(int**)p1;
   int* arr2 = *(int**)p2;
  if(arr1[1] == arr2[1]){
      if(arr1[0] == arr2[0])
          return 0;
      else if(arr1[0] > arr2[0])
          return 1;
      else 
          return -1;      
  } 
  else{
      if(arr1[1] == arr2[1])
          return 0;
      else if(arr1[1] > arr2[1])
          return 1;
      else 
          return -1;
  }  
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    int i;
    qsort(points, pointsSize, sizeof(int*), cmpfunc);
    int k = points[0][1];
    int cn = 1;
    for(i = 1; i < pointsSize; i++){
        if(points[i][0] > k){
            cn++;
            k = points[i][1];
        }    
    }
    
    return cn;
}

------------------------------------Explanation :-
Purpose:

This code finds the minimum number of arrows needed to burst all balloons in a 2D array of points (points), where each point represents a balloon's start and end coordinates.
Function Breakdown:

cmpfunc Function:

Compares two intervals (arr1 and arr2) for sorting:
Prioritizes sorting by end values (arr1[1] and arr2[1]) in ascending order.
If end values are equal, sorts by start values (arr1[0] and arr2[0]) in ascending order.
findMinArrowShots Function:

Sorting Intervals:

Sorts points in ascending order of end values using qsort and cmpfunc.
Iterating and Counting Arrows:

Initializes k to the end value of the first interval and cn (arrow count) to 1.
Iterates through points from the second interval onwards:
If the start value of the current interval (points[i][0]) is greater than k:
Increments cn (a new arrow is needed).
Updates k to the end value of the current interval.
Return Arrow Count:

Returns cn, representing the minimum number of arrows needed.
Key Points:

Greedy Approach: Uses a greedy approach by shooting arrows at the earliest ending balloons first.
Sorting for Efficiency: Sorting enables efficient identification of non-overlapping balloons.
Arrow Count Logic: Increments the arrow count only when a new arrow is needed (no overlap with previous balloons).
Time Complexity: O(n log n) due to sorting, where n is the number of points.
Space Complexity: O(1) for additional variables.
