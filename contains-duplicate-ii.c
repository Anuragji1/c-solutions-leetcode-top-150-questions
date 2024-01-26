**Contains Duplicate II**

Problem Statement 47) Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

-----------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = #define SIZE 1000  
struct HashArray
{
    int key;
    int count;
    struct HashArray* next;
}Hash[SIZE];      
int addHash(int num,int i)   
{
    int temp=abs(num%SIZE);    
    if(Hash[temp].count==0)
    {
        Hash[temp].key=num;
        Hash[temp].count=i;
        return 0;
    }else if(Hash[temp].key==num)
    {
        int temp1=Hash[temp].count;
        Hash[temp].count=i;
        return i-temp1; 
    }else
    {
        struct HashArray *p=&Hash[temp]; 
        while(p->key!=num&&p->next!=NULL)    
        {p=p->next;}
        if(p->key==num&&p->count!=0)
        {
            int temp1=p->count;
            p->count=i;
            return i-temp1;
        }
        else
        {
            p->next=(struct HashArray*)malloc(sizeof(struct HashArray));
            p=p->next;
            p->key=num;
            p->count=i;
            p->next=NULL;
            return 0;
        }
    }   
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if(numsSize<2){return false;}
    for(int i=0;i<SIZE;i++){
        Hash[i].key=0;
        Hash[i].count=0;
        Hash[i].next=NULL;   
    }
    int temp=0;
    for(int i=0;i<numsSize;i++){
        temp=addHash(nums[i],i+1);
        if(temp!=0&&temp<=k){return true;}
    }
    return false;
}

------------------------------------------Explanation :-
Purpose:

This code determines whether an array nums contains any duplicate elements within a distance of k indices from each other.
Function Breakdown:

HashArray Structure:

Represents a node in a hash table with:
key: Stores the integer value.
count: Stores the index of its latest occurrence in nums.
next: Pointer to the next node in case of collisions.
addHash Function:

Inserts a new element (num, i) into the hash table:
Calculates the hash index using abs(num % SIZE).
If the slot is empty, directly inserts the element.
If the slot already contains the same key, updates the count and returns the distance.
If a collision occurs, handles it using chaining:
Traverses the linked list at the slot.
If the key is found, updates the count and returns the distance.
If not found, adds a new node to the end of the list.
containsNearbyDuplicate Function:

Initialization:

Handles edge cases: returns false if numsSize is less than 2.
Initializes the hash table with empty slots.
Iterating through nums:

For each element nums[i]:
Calls addHash to insert it into the hash table.
If addHash returns a non-zero distance within k, it means a duplicate is found within the specified range, so it returns true.
No Duplicates Found:

If the loop completes without finding duplicates within k, it returns false.
Key Points:

Hashing for Efficient Search: Uses hashing to quickly check for duplicates and their indices.
Chaining for Collision Handling: Employs chaining to manage collisions in the hash table.
Time Complexity: Average-case O(n), worst-case O(n^2) due to potential collisions.
Space Complexity: O(n) for the hash table, potentially O(n^2) in worst-case scenarios with many collisions.
