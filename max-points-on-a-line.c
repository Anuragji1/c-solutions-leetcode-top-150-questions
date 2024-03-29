**Max Points on a Line**

Problem Statement 128) Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:


Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

------------------------------------------------------------------------------------------------
SOLUTION = #define max(a,b)(a>b?a:b)
int maxPoints(int** points, int pointsSize, int* pointsColSize){

    if(pointsSize == 1) return 1;
    int retVal = 2;
    
    for(int i = 0; i < pointsSize; ++i)
    {
        for(int j = i+1; j < pointsSize; ++j)
        {
            int cnt = 2;
            for(int k = 0; k < pointsSize; ++k)
            {
                if(k != i && k != j && 
                   (*(*(points+i) + 1) - *(*(points + j) + 1)) * (*(*(points + i)) - *(*(points + k))) 
                   == (*(*(points+i) + 1) - *(*(points + k) + 1)) * (*(*(points + i)) - *(*(points + j))))
                {
                    cnt++;
                }
            }
            retVal = max(retVal, cnt);
        }
    }
    return retVal;
    
}

-----Explanation :-
Base Case:

The code first checks for a base case. If pointsSize (number of points) is 1, it means there's only one point, and by definition, a single point is always collinear with itself. So, it returns 1 in this case.
Initialization:

It initializes a variable retVal to 2, assuming the maximum number of collinear points to be at least 2 (for the first two points encountered).
Nested Loops:

It uses two nested for loops to iterate through all pairs of points in the points array:
The outer loop (i) iterates from 0 to pointsSize - 1.
The inner loop (j) iterates from i + 1 to pointsSize - 1. This ensures that only unique pairs of points are considered (avoiding duplicates).
Collinearity Check:

Inside the inner loop, a variable cnt is initialized to 2, representing the two points being compared (i and j).
Another nested loop (k) iterates through all remaining points (k = 0 to pointsSize - 1).
It checks if the current point (k) is different from both i and j (to avoid considering the points being compared themselves).

The core condition for collinearity involves a slope calculation using the following expression:

((*(*(points+i) + 1) - *(*(points + j) + 1)) * (*(*(points + i)) - *(*(points + k)))) == 
((*(*(points+i) + 1) - *(*(points + k) + 1)) * (*(*(points + i)) - *(*(points + j))))
Let's break down this expression:
points[i] and points[j] represent the coordinates of the two points being compared.
*(*(points+i) + 1) and *(*(points+j) + 1) access the y-coordinates of points i and j, respectively.
*(*(points+i)) and *(*(points+j)) access the x-coordinates of points i and j, respectively.
The entire expression essentially calculates the cross product of the vectors formed by points i and j and points i and k. If the cross product is 0, it indicates that all three points are collinear.
If the collinearity condition holds true for the current point (k), the cnt variable is incremented to include that point in the count of collinear points.

Update Maximum:

After checking all points in the inner loop (k), the value of cnt represents the number of points collinear with the initial pair (i and j). The function uses the max macro (defined as max(a, b)) to compare cnt with the current retVal (maximum points found so far) and update retVal if cnt is larger.
Return the Result:

After iterating through all pairs of points, the function returns the final value of retVal, which represents the maximum number of points found to be collinear in the given set of points.
