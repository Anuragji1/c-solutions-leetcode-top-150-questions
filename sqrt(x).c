**Sqrt(x)**

Problem Statement 126) Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

--------------------------------------------------------------
SOLUTION = int mySqrt(int x) {
    if(x<2){return x;}
    int first=1;
    int end=x;
    int mid=0;
    while(first<=end){
        mid=first+(end-first)/2;
        if(mid==x/mid){return mid;}
        if(mid<x/mid){
            first=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return end;
}
/*int mySqrt(int x) {
    int i=1;
    for(;i<=x/i;i++){}
    return i-1;
}*/

----Explanation :-
Base Cases:

The code first checks for base cases:
If x is less than 2, it returns x itself as the square root of 0 is 0 and the square root of 1 is 1.
Binary Search Initialization:

It initializes three integer variables:
first starting at 1 (lower bound of the search range).
end starting at x (upper bound of the search range).
mid to store the middle element during the search process.
Iterative Search:

It enters a while loop that continues as long as first is less than or equal to end. This ensures the search space keeps getting refined until the target square root is found.
In each iteration:
Calculating the Midpoint: It calculates the mid point by taking the average of first and end using the formula mid = first + (end - first) / 2. This integer division ensures mid doesn't overflow.
Perfect Square Found: If mid multiplied by itself (mid * mid) is equal to x, it means the perfect square root has been found, and the function returns mid.
Search Right Half: If mid multiplied by itself is less than x, it implies the square root lies somewhere between mid and end. So, the search continues in the right half by updating first to mid + 1.
Search Left Half: If mid multiplied by itself is greater than x, it signifies the square root is between first and mid. So, the search proceeds in the left half by updating end to mid - 1.
No Perfect Square Found:

If the loop completes without finding a perfect square (all possible values from first to end have been checked), it means x is not a perfect square. In this case, the function returns end (which will hold the closest integer less than the actual square root).
Alternative Approach (Looping):

The commented section of the code (/*int mySqrt(int x) { ... }*/) provides an alternative approach that might be slightly less efficient for larger x values. Here's how it works:

Iterative Loop:

It starts a loop with a variable i initialized to 1.
The loop keeps iterating as long as i is less than or equal to x divided by i (i <= x / i). This condition ensures i * i doesn't overflow.
Inside the loop, it doesn't explicitly perform any calculations. It simply increments i in each iteration.
Returning the Square Root:

Once the loop terminates (when i becomes greater than the square root of x), i - 1 will hold the largest integer less than or equal to the square root of x. The function returns this value.
Key Points:

The binary search approach is generally more efficient for larger x values as it reduces the search space by half in each iteration.
The looping approach might be simpler to understand but can have more iterations for larger inputs.
