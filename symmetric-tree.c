**Symmetric Tree**

Problem Statement 72) Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100

---------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool parallel_traverse(struct TreeNode* a, struct TreeNode* b)
{
    if (a == NULL && b == NULL)
        return true;
 
    if (a == NULL || b == NULL)
        return false;

    if (a->val != b->val)
        return false;
    
    return parallel_traverse(a->left, b->right) && parallel_traverse(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
        return true;
    return parallel_traverse(root->left, root->right);
}
-----------------------Explanation :-
This code defines two functions to check if a binary tree is symmetric:

1. parallel_traverse:

Takes two TreeNode pointers (a and b) as input.
Base Cases:
Returns true if both a and b are NULL (empty subtrees).
Returns false if one of a or b is NULL but not both (unequal structures).
Value Check: Returns false if a->val is not equal to b->val.
Recursive Check: Returns the result of calling parallel_traverse on the mirrored children:
parallel_traverse(a->left, b->right): Checks if the left subtree of a matches the right subtree of b.
parallel_traverse(a->right, b->left): Checks if the right subtree of a matches the left subtree of b.
2. isSymmetric:

Takes a TreeNode pointer (root) as input.
Base Case: Returns true if root is NULL (empty tree).
Recursive Call: Returns parallel_traverse(root->left, root->right), which checks if the entire left subtree matches the mirrored right subtree.
Key Points:

Symmetry Definition: The tree is considered symmetric if the left subtree is a mirror image of the right subtree, considering both structure and node values.
Mirrored Traversal: The parallel_traverse function checks corresponding nodes from mirrored subtrees to ensure symmetry.
Time and Space Complexity:
Time Complexity: O(n), where n is the number of nodes, as each node is visited once.
Space Complexity: O(h), where h is the height of the tree, due to the recursion stack.
