**H-Index**

Problem Statement 11) Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
Example 2:

Input: citations = [1,3,1]
Output: 1
 

Constraints:

n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int hIndex(int* citations, int citationsSize) {
    int bucket[1001] = {0};  // Bucket to count papers with each citation count

    // Count papers in each citation bucket
    for (int i = 0; i < citationsSize; i++) {
        bucket[citations[i]]++;
    }

    // Find the h-index using cumulative sum from the highest bucket
    int papers = 0, h = 0;
    for (int i = 1000; i >= 0; i--) {
        papers += bucket[i];
        if (papers >= i) {  // Check if h-index condition is met
            h = i;
            break;
        }
    }

    return h;
}


------------------------------------------Explanation :-
Purpose:

The code implements a function named hIndex() that efficiently calculates the h-index of a researcher given an array of their citation counts.
Key Concepts:

h-index: A metric that measures both the productivity and impact of a researcher's publications. A researcher has an h-index of h if they have at least h publications that have each been cited at least h times.
Key Steps:

Bucket Initialization:

An array bucket of size 1001 is created and initialized to 0. This array will be used to count the number of papers with each citation count (assuming a maximum of 1000 citations).
Citation Counting into Buckets:

The code iterates through the citations array and increments the corresponding bucket for each citation count. This creates a histogram of citation counts.
Finding the h-index Using Cumulative Sum:

The code iterates through the bucket array from the highest citation count (1000) to the lowest:
It keeps a running count of papers papers by cumulatively summing the values in the buckets.
For each citation count i, it checks if papers is greater than or equal to i. If so, it means the condition for the h-index is met (at least i papers have at least i citations), so h is set to i, and the loop breaks.
Return h-index:

After the iteration, the h value holds the calculated h-index, which is returned as the result.
Time and Space Complexity:

Time Complexity: O(n), where n is the number of citations. The algorithm performs two linear passes through the data: once to count citations and once to find the h-index.
Space Complexity: O(1001) or O(1), depending on the perspective. It uses a fixed-size array of 1001 elements, which can be considered constant in some contexts.
