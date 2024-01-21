**Insert Delete GetRandom O(1)**

Problem Statement 12) Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

 

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
 

Constraints:

-231 <= val <= 231 - 1
At most 2 * 105 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = #include <stdlib.h>
#include <time.h>

typedef struct {
    int* nums;
    int capacity;
    int count;
} RandomizedSet;

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    obj->nums = (int*)malloc(sizeof(int) * 10);  // Initial capacity
    obj->capacity = 10;
    obj->count = 0;
    return obj;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    if (obj->count == obj->capacity) {  // Resize if needed
        obj->nums = (int*)realloc(obj->nums, sizeof(int) * obj->capacity * 2);
        obj->capacity *= 2;
    }

    for (int i = 0; i < obj->count; i++) {  // Check for duplicates
        if (obj->nums[i] == val) {
            return false;
        }
    }

    obj->nums[obj->count] = val;
    obj->count++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    for (int i = 0; i < obj->count; i++) {
        if (obj->nums[i] == val) {
            obj->nums[i] = obj->nums[obj->count - 1];  // Swap with last element
            obj->count--;
            return true;
        }
    }
    return false;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int index = rand() % obj->count;  // Generate random index
    return obj->nums[index];
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj->nums);
    free(obj);
}


----------------------------------Explanation :- 
Purpose:

The code implements a data structure called RandomizedSet that efficiently stores a set of integers and supports three primary operations:
Inserting a new integer.
Removing an existing integer.
Getting a random element from the set.
Data Structure:

Structure:
nums: An integer array to store the elements of the set.
capacity: The current capacity of the nums array.
count: The actual number of elements in the set.
Key Functions:

randomizedSetCreate():
Creates and initializes a new RandomizedSet object with an initial capacity of 10.
randomizedSetInsert(obj, val):
Inserts a new integer val into the set:
Resizes the nums array if needed using realloc.
Checks for duplicates and returns false if val already exists.
Appends val to the end of the nums array and increments count.
randomizedSetRemove(obj, val):
Removes an integer val from the set:
Searches for val in the nums array.
If found, swaps it with the last element and decrements count, effectively removing it.
randomizedSetGetRandom(obj):
Returns a random element from the set:
Generates a random index within the valid range of the set using rand() % obj->count.
Returns the element at that random index.
randomizedSetFree(obj):
Frees the memory allocated for the RandomizedSet object and its nums array.
Key Points:

The nums array dynamically resizes when needed to accommodate more elements.
Element removal is efficient as it only swaps with the last element and decrements count.
The randomizedSetGetRandom() function leverages rand() to provide random element retrieval.
