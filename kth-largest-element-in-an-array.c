**

Problem Statement 113) Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104


--------------------------------------------------------------------------------------------------------------------
SOLUTION = int findKthLargest(int* nums, int numsSize, int k) {
    // Use a min-heap to efficiently track the k largest elements seen so far
    int heap[k];
    for (int i = 0; i < k; i++) {
        heap[i] = nums[i];
    }
    build_min_heap(heap, k);  // Build the initial min-heap

    // Iterate through the remaining elements
    for (int i = k; i < numsSize; i++) {
        if (nums[i] > heap[0]) {  // If the current element is larger than the top of the heap
            heap[0] = nums[i];    // Replace the top with the current element
            min_heapify(heap, k, 0);  // Maintain the min-heap property
        }
    }

    // The root of the min-heap now holds the kth largest element
    return heap[0];
}

// Helper functions for min-heap operations
void build_min_heap(int heap[], int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        min_heapify(heap, heap_size, i);
    }
}

void min_heapify(int heap[], int heap_size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < heap_size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap, i, smallest);
        min_heapify(heap, heap_size, smallest);
    }
}

void swap(int heap[], int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

-------Explanation :-
Mentioned code implements the findKthLargest function to find the kth largest element in an array (nums) of size numsSize. It achieves this efficiently using a min-heap data structure and the following steps:

Min-Heap Initialization:

Declare an integer array heap of size k to store the k largest elements encountered so far.
Use a loop to fill the heap array with the first k elements from the input array nums.
Build Min-Heap:

Call the build_min_heap function (not shown in detail here) to convert the initial heap array into a min-heap. In a min-heap, the smallest element is always at the root (heap[0]).
Iterate Through Remaining Elements:

Use a loop to iterate through the remaining elements of the nums array starting from index k.
For each element nums[i]:
If nums[i] is greater than the current root element (heap[0]), it means it has the potential to be among the k largest elements.
Replace the root element (heap[0]) with nums[i].
Call the min_heapify function (not shown in detail here) to restore the min-heap property. This ensures the smallest element remains at the root after the replacement.
Kth Largest Element:

After iterating through all elements, the heap array will now contain the k largest elements encountered in the nums array.
The root of the min-heap (heap[0]) will hold the kth largest element as it's the smallest element among the k largest.
Helper Functions (not shown in detail):

The code includes comments mentioning helper functions for min-heap operations:
build_min_heap: This function converts an array into a min-heap by performing a bottom-up heapification process.
min_heapify: This function maintains the min-heap property at a particular node by comparing it with its child nodes and swapping elements if necessary.
swap: This function swaps the values of two elements in the heap array.
