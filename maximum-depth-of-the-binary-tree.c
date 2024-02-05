**Maximum Depth of the Binary Tree**

Problem Statement 69) Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

----------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;
int h2(TreeNode* root, int len){
    if(!root){return len;}
    len++;
    int m = h2(root->left, len);
    int n = h2(root->right, len);
    return m > n ? m : n;
}
int maxDepth(TreeNode* root){
    // if(!root){return 0;}
    return h2(root, 0);
}

-----------
