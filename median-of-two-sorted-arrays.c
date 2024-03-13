**Median of Two Sorted Arrays**

Problem Statement 111) Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

----------------------------------------------------------------------------------------------------------------------
SOLUTION = int *merge(int *arr1, int l1, int *arr2, int l2, int *arr3) {
    int i, j, k;
    i = 0; j = 0; k = 0;
    while (i < l1 && j < l2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < l1) {
        arr3[k++] = arr1[i++];
    }
    while (j < l2) {
        arr3[k++] = arr2[j++];
    }
    return arr3;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *nums, numsSize; 
    double returnValue;
    numsSize = nums1Size + nums2Size;
    nums = malloc(numsSize * sizeof(int));
    nums = merge(nums1, nums1Size, nums2, nums2Size, nums);
    if (numsSize & 1) {
        returnValue = (double) nums[numsSize/2];
    } else {
        returnValue = (double) (nums[numsSize/2-1] + nums[numsSize/2]) / 2.0;
    }
    free(nums);
    return returnValue;
}

----Explanation:- This code implements two functions:

merge function:

This function merges two sorted arrays (arr1 and arr2) of lengths l1 and l2 respectively, into a third array (arr3).
It uses three integer variables (i, j, and k) as indices for arr1, arr2, and arr3, respectively.
The function iterates through both arr1 and arr2 using a while loop, comparing elements and copying the smaller element to arr3.
After exhausting one of the arrays, the remaining elements from the other array are copied to arr3.
The function returns the arr3 array (assuming it's already allocated elsewhere).
findMedianSortedArrays function:

This function finds the median of two sorted arrays (nums1 and nums2) of lengths nums1Size and nums2Size respectively.
It allocates memory for a new array (nums) to hold the merged elements using malloc.
It calls the merge function to merge nums1 and nums2 into the nums array.
The function calculates the median based on the total size (numsSize):
If numsSize is odd, the median is the element at the middle index (numsSize / 2).
If numsSize is even, the median is the average of the two middle elements ((nums[numsSize/2-1] + nums[numsSize/2]) / 2.0).
The function then frees the allocated memory for nums using free.
Finally, it returns the calculated median value (returnValue).
