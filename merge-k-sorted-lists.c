**Merge k Sorted Lists**

Problem Statement 103) You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

-----------------------------------------------------------------------------------------------------------
SOLUTION = struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)
        return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* temp = head;
    struct ListNode* min;
    int id;    
    while(1){
        min = lists[0];
        id = 0;
        for(int i = 1; i < listsSize; i++){
            if(min == NULL && lists[i]){
                min = lists[i];
                id = i;
            }
            if(lists[i] == NULL)
                continue;
            else{
                if(lists[i]->val < min->val){
                    min = lists[i];
                    id = i;
                }
            }
        }
        if(min == NULL){
            temp->next = NULL;
            break;
        }
        temp->next = min;
        temp = temp->next;
        lists[id] = lists[id]->next;
        while(lists[id] && lists[id]->val == temp->val){
            temp->next = lists[id];
            temp = temp->next;
            lists[id] = lists[id]->next;
        }
    }
    return head->next;
}

--------------------Explanation :-
Purpose:

This code implements the mergeKLists function, which merges k sorted linked lists into a single sorted linked list.
Steps:

Handle Base Case:

If listsSize is 0 (no lists to merge), return NULL.
Create Result List:

Allocate memory for a new node head to serve as the sentinel for the result list.
Initialize a pointer temp to head for traversing the result list.
Iterate and Merge:

Use a while(1) loop to continue merging until all lists are empty:
Find the minimum node min among all non-empty lists:
Iterate through each list in lists.
Find the node with the smallest value and store it in min, along with its list index (id).
If min is NULL (all lists are empty), break the loop.
Append min to the result list:
Set temp->next to min.
Advance temp to the newly added node.
Advance the corresponding list in lists to its next node (lists[id] = lists[id]->next).
Handle duplicates:
If the next node in the list that just had its head added (lists[id]) has the same value as temp->val, add those nodes as well to maintain sorted order.
Return Result:

Return head->next to skip the sentinel node and get the actual merged list.
Key Points:

It uses a naive approach with a time complexity of O(kN), where k is the number of lists and N is the average length of the lists.
It finds the minimum node in each iteration by comparing nodes from all lists.
It creates a new list instead of modifying the existing ones.
