**Find Medium from Data Stream**

Problem Statement 116) The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.

-------------------------------------------------------------------------------------------------------------------------------
SOLUTION = 
#define MAX_HEAP (2*100010) 

typedef struct { 
    int *root; 
    int size; 
    short (*comparator)(int a, int b);
    int end; /*always points to first open spot*/
} Heap;  

typedef struct {
    Heap *l; 
    Heap *r;
} MedianFinder;

Heap *heap_create(int mode); 
short min_comparator(int val1, int val2); 
short max_comparator(int val1, int val2); 
short insert(Heap *h, int val, short (*comp)(int a, int b)); 
int deletion(Heap *h, short (*comp)(int a, int b)); 
short push(Heap *heap, int val); 
int poll(Heap *heap);

MedianFinder* medianFinderCreate() {
    MedianFinder *med = malloc(sizeof(MedianFinder)); 
    med->l = heap_create(1); 
    med->r = heap_create(0); 
    return med;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if(!obj) 
        return; 
    Heap *l = obj->l; 
    Heap *r = obj->r; 
    
    push(l,num); 
    push(r,poll(l)); 
    if(l->size < r->size) 
        push(l,poll(r)); 
    
}

double medianFinderFindMedian(MedianFinder* obj) {
    if(!obj) 
        return 0.0;  
    
    Heap *l = obj->l; 
    Heap *r = obj->r;
    double med = 0.0; 
    
    if(l->size == r->size) 
        med = ((double) peek(l) + (double) peek(r))/2; 
    else 
        med = peek(l);
    
    return med;
}

void medianFinderFree(MedianFinder* obj) {
    if(!obj) 
        return;  
    
    free(obj->l->root); 
    free(obj->r->root); 
    free(obj->l); 
    free(obj->r); 
    
} 

Heap *heap_create(int mode) { 
    Heap *heap = malloc(sizeof(Heap)); 
    heap->root = calloc(sizeof(int), MAX_HEAP); 
    heap->size = 0; 
    heap->end = 0;  
    heap->comparator = !mode ? min_comparator : max_comparator;
    return heap;
}  

short min_comparator(int val1, int val2) { /*ret -1 if val1 less than val2, 1 greater, 0 if equal*/
    return val1 == val2 ? 0 : (val1>val2 ? 1 : -1);
} 

short max_comparator(int val1, int val2) { /*ret 1 if val1 less than val2, -1 greater, 0 if equal*/
    return -1*(val1 == val2 ? 0 : (val1>val2 ? 1 : -1));
} 

short insert(Heap *h, int val, short (*comp)(int a, int b)) { 
    if(h->size >= MAX_HEAP)
        return 0; 
    
    int *heap = h->root;  
    int curr = (h->end)++; 
    int par = (curr-1)/2;
    heap[curr] = val; 
    
    while(par>=0 && comp(heap[curr],heap[par]) == -1) {  
        int tmp = heap[par]; 
        heap[par] = heap[curr]; 
        heap[curr] = tmp;  
        
        curr = par;
        par = (curr-1)/2;
    } 
    
    (h->size)++;
    return 1;
} 

int deletion(Heap *h, short (*comp)(int a, int b)) { 
    
    int *heap = h->root; 
    int last = (h->end)-1; 
    int curr = 0;   
    int left = 2*curr+1; 
    int right = 2*curr+2; 
    int head = heap[0]; 
    
    heap[curr] = heap[last]; 
    
    while(right <= last && (comp(heap[curr],heap[left]) == 1 ||  
           comp(heap[curr],heap[right]) == 1)) {  
        
        int swap = 0;  
        
        if(comp(heap[curr],heap[left]) == 1 && comp(heap[curr],heap[right]) == 1)   
            swap = comp(heap[left],heap[right]) == -1 ? left : right; 
        
        else if(comp(heap[curr],heap[left]) == 1)  
            swap = left;  
        
        else  
            swap = right;   
        
        int tmp = heap[swap]; 
        heap[swap] = heap[curr]; 
        heap[curr] = tmp;
        
        curr = swap;
        left = 2*curr+1; 
        right = 2*curr+2;
    } 
    
    (h->end)--; 
    (h->size)--;
    return head;
} 

short push(Heap *heap, int val) { /*0 for min, 1 for max*/
    if(!heap) 
        return 0; 
    return insert(heap,val,heap->comparator);
}

int poll(Heap *heap) {  /*0 for min, 1 for max */ 
    assert(heap != NULL); 
    return deletion(heap,heap->comparator);  
} 

int peek(Heap *heap) { 
    return (heap->root)[0];
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/

----Explanation:- 
Key Components:

Heaps: The code utilizes two heaps to maintain partial order among the elements:

A max-heap (r) to store the smaller half of the numbers.
A min-heap (l) to store the larger half of the numbers.
MedianFinder Structure: It acts as a container for these heaps:

l: The min-heap.
r: The max-heap.
Main Functions:

medianFinderCreate():

Initializes a MedianFinder object.
Creates a min-heap (l) and a max-heap (r) to store the numbers.
medianFinderAddNum(obj, num):

Adds a new number num to the data structure.
Maintains the size balance between the heaps to ensure efficient median calculation:
Inserts num into the max-heap (r).
Pushes the largest element from r (now the median) into the min-heap (l).
Rebalances the heaps if l becomes larger than r by pushing the smallest element from l back to r.
medianFinderFindMedian(obj):

Calculates and returns the current median:
If both heaps have the same size, the median is the average of the top elements of both heaps.
If the heaps have different sizes, the median is the top element of the larger heap.
medianFinderFree(obj):

Frees the memory used by the MedianFinder object, including both heaps.
Key Advantages:

Efficient Median Calculation: O(log N) time complexity for adding numbers and finding the median, making it suitable for continuous data streams.
Balanced Heaps: The balancing logic ensures that both heaps remain roughly equal in size, leading to optimal performance.
