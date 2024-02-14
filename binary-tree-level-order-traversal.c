**Binary Tree Level Order Traversal**

Problem Statement 84) Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

----------------------------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct queue {
    struct TreeNode* node;
    struct queue* next;
};

struct queue* New_Node (struct TreeNode* node) {
    struct queue* new_node = (struct queue*) malloc(sizeof(struct queue));
    new_node->next = NULL;
    new_node->node = node;
    return new_node;
}

void enqueue (struct queue** root, struct TreeNode* node) {
    
    struct queue* new_node = New_Node(node);
    if (*root == NULL) {
        *root = new_node;
        return;
    }
    struct queue* iter = *root;
    while (iter->next)
        iter = iter->next;
    iter->next = new_node;
    return;
}

struct TreeNode* dequeue (struct queue** root) {
    if (*root == NULL)
        return NULL;
    
    struct queue* temp = *root;
    *root = temp->next;
    struct TreeNode* ret = temp->node;
    free(temp);
    return ret;
}

int q_size(struct queue* root) {
    int count = 0;
    
    while (root) {
        count ++;
        root = root->next;
    }
    return count;
}

bool is_empty (struct queue* root) {
    return root == NULL ? true : false;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    
    int** a = (int**) malloc(sizeof(int*)*2000);
    *returnColumnSizes = (int*) malloc(sizeof(int)*2000);
    memset(a, 0, 2000*sizeof(int*));
    memset (*returnColumnSizes, 0, 2000*sizeof(int));
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes[0] = 0;
        return a;
    }
    int num_levels = 0;
    int len = 0;
    int max_nodes = 0;
    
    struct queue* q = NULL;
    enqueue(&q, root);
    
    while (!is_empty(q)) {
        len = q_size (q);
        a[num_levels] = (int*) malloc(sizeof(int)*len);
        for (int i = 0; i < len; i++) {
            root = dequeue (&q);
            if (root->left) {
                enqueue(&q, root->left);
            }
            if (root->right)
                enqueue(&q, root->right);
            a[num_levels][i] = root->val;   
        }
        (*returnColumnSizes)[num_levels] = len;
        num_levels++;
        
    }
    a = (int**) realloc(a, sizeof(int*)*num_levels);
    *returnColumnSizes = (int*) realloc((*returnColumnSizes), sizeof(int)*num_levels);
    *returnSize = num_levels;
    return a;
}

------------Explanation :-
1. Queue Implementation:

struct queue: Represents a node in the queue, holding a TreeNode* and a pointer to the next node.
New_Node, enqueue, dequeue, q_size, is_empty: Functions for creating, adding, removing, checking size, and checking emptiness of the queue.
2. Level-Order Traversal:

levelOrder(root, returnSize, returnColumnSizes): Performs level-order traversal and returns a 2D array of node values and an array of column sizes (number of nodes at each level).
Key Steps:

Initialization:
Allocates memory for the 2D array a and column size array *returnColumnSizes, initially assuming a maximum of 2000 levels.
Handles the empty tree case (root == NULL).
BFS Loop:
Uses a queue q to perform BFS.
Enqueues the root node.
Iterates until the queue is empty:
Gets the current level size (len).
Allocates memory for the current level's array in a.
Dequeues len nodes from the queue:
Stores the dequeued node's value in the current level's array.
Enqueues children of the dequeued node.
Stores the current level size in *returnColumnSizes.
Memory Adjustment:
Reallocates a and *returnColumnSizes to match the actual number of levels encountered.
Return Values:
Sets *returnSize to the number of levels.
Returns the 2D array a and the column size array *returnColumnSizes.
Key Points:

Employs breadth-first search (BFS) to traverse the tree level-by-level.
Uses a queue to manage node exploration.
Stores node values in a 2D array, with each sub-array representing a level.
Tracks the number of nodes at each level in a separate array.
Manages memory allocation and reallocation dynamically.
Time and Space Complexity:

Time: O(n), where n is the number of nodes (visits each node once).
Space: O(n), due to the 2D array, queue, and recursion stack in q_size.
