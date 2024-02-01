**Copy List with Random Pointer**

Problem Statement 61) A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.

------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> old_to_new;
        
        Node* curr = head;
        while (curr) {
            old_to_new[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            old_to_new[curr]->next = old_to_new[curr->next];
            old_to_new[curr]->random = old_to_new[curr->random];
            curr = curr->next;
        }
        
        return old_to_new[head];
    }
};

-------------------------Explanation :-
Purpose:

This code creates a deep copy of a linked list with a random pointer, where each node has a value, a next pointer, and a random pointer that can point to any node in the list (or nullptr).
Function Breakdown:

Handles Empty List:

Returns nullptr if the input list is empty.
Creates Node Map:

Initializes an unordered_map called old_to_new to store mappings between original nodes and their corresponding copied nodes.
Creates New Nodes:

Iterates through the original list:
For each node, creates a new node with the same value and stores the mapping in old_to_new.
Links New Nodes:

Iterates through the original list again:
Sets the next and random pointers of each copied node using the mappings in old_to_new, effectively recreating the structure of the list with new nodes.
Returns Copied List Head:

Returns the head of the copied list, retrieved from old_to_new.
Key Points:

Deep Copy: Creates a completely independent copy of the list, not just shallow references.
Handling random Pointers: Successfully replicates the random pointers in the copied list.
Hash Map for Mapping: Uses a hash map to efficiently store and retrieve node mappings during the copying process.
Time and Space Complexity: O(n) time complexity, where n is the number of nodes, due to linear traversal. O(n) space complexity for the hash map.
