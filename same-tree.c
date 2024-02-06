**Same Tree**

Problem Statement 70) Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104

------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;  // Both trees are empty, so they are the same
    } else if (p == NULL || q == NULL) {
        return false;  // One tree is empty, the other is not, so they are different
    } else if (p->val != q->val) {
        return false;  // Node values don't match, so the trees are different
    } else {
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}

----------------Explanation:-
Here's a breakdown of the C code for the isSameTree function:

Purpose:

Determines whether two given binary trees have the same structure and node values.
Function Breakdown:

Base Cases:

Both Empty: If both p and q are NULL, it means both trees are empty and thus are considered the same. Return true.
One Empty: If either p or q is NULL but not both, it means one tree is empty while the other isn't, so they are different. Return false.
Different Values: If both p and q are not NULL but have different val fields, it means the trees differ at the current nodes. Return false.
Recursive Check:

If none of the base cases apply, it means the current nodes have the same value. Recursively check if their left and right subtrees are also the same:
Call isSameTree(p->left, q->left) to compare the left subtrees.
Call isSameTree(p->right, q->right) to compare the right subtrees.
Return true only if both recursive calls return true, indicating that both subtrees are also the same.
Key Points:

Recursive Approach: The function employs recursion to traverse and compare the trees simultaneously.
Structure and Values: It checks both the structure (node arrangement) and values to ensure complete similarity.

Time and Space Complexity:

Time Complexity: O(n), where n is the number of nodes in the trees, as it visits each node at most once.
Space Complexity: O(h), where h is the height of the trees, due to the recursion stack's depth.
