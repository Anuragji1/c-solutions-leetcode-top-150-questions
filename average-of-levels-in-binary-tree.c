**Average of Levels in Binary Tree**

Probelm Statement 83) Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
Example 2:


Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

--------------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int depth(struct TreeNode* root );

void BFS(struct TreeNode* root, int depth, long long** table){
    table[depth][0] += 1;
    table[depth][1] +=  root->val;
    
    if(root->left){
        BFS(root->left, depth + 1, table);
    }
    
    if(root->right){
        BFS(root->right, depth + 1, table);
    }
}

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    int i;    
    int dep = depth(root);

    //table[i][0] -->count, table[i][1] -->sum
    long long** table = (long long**)malloc(dep * sizeof(long long*));
    for(i = 0; i < dep; i++){
        table[i] = calloc( 2 , sizeof(long long));
    }
    BFS(root, 0 , table);
    
    double* ans = (double*)malloc(dep * sizeof(double));
    for(i = 0; i < dep; i++){
        if(table[i][0] == 0)
            ans[i] = 0;
        else
            ans[i] = (double)table[i][1] / table[i][0];
    }
    
    * returnSize = dep;
    
    //freee memory
    for(i = 0; i < dep; i++){
        free(table[i]);
    }
    free(table);
    
    return ans;
}

int depth(struct TreeNode* root ){
    if(root == NULL)
        return 0;
    else 
        return 1 + fmax(depth(root->left), depth(root->right));
}

------------Explanation :-
Functionality:

This code calculates the average value of nodes at each level in a binary tree. It achieves this by performing a breadth-first search (BFS) and maintaining a cumulative sum and count of nodes at each level.

Step-by-Step Breakdown:

depth function:

Takes a TreeNode pointer as input.
Base case: If root is NULL, returns 0 (empty tree).
Recursive case: Returns 1 + the maximum depth of the left and right subtrees, calculated recursively.
BFS function:

Takes a TreeNode pointer, a depth int, and a 2D long long array table as input.
Increments table[depth][0] (count of nodes at this depth).
Adds the current node's value to table[depth][1].
Recursively calls itself on the left child (if present) with depth + 1.
Recursively calls itself on the right child (if present) with depth + 1.
averageOfLevels function:

Takes a TreeNode pointer and an int pointer to store the return size.
Calls the depth function to determine the maximum depth of the tree.
Allocates a 2D long long array table of size dep * 2 to store counts and sums for each depth.
Initializes each element of table to 0.
Calls the BFS function with root, 0 (initial depth), and table.
Allocates a double array ans of size dep.
Iterates through each depth i:
If table[i][0] (count) is 0, sets ans[i] to 0 (no nodes at this depth).
Otherwise, calculates the average ans[i] by dividing table[i][1] (sum) by table[i][0] (count).
Sets *returnSize to the calculated depth.
Frees the allocated memory for table.
Returns the ans array containing the average values at each level.
Key Points:

The code employs BFS to efficiently explore the tree level-by-level.
The 2D table array accumulates counts and sums of nodes at each depth.
The averageOfLevels function iterates through the table to calculate and store the average values in the ans array.
Memory management is crucial, and the code ensures proper deallocation of the table array.
