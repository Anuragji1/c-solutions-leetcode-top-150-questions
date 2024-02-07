**Invert Binary Tree**

Problem Statement 71) Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

---------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;  // Base case: empty tree
    }

    // Recursively invert left and right subtrees
    struct TreeNode* temp = root->left;  // Temporary variable for swapping
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;  // Return the inverted tree
}

----------------Explanation :-
Purpose:

This function takes the root node of a binary tree as input and inverts the tree in-place. In other words, it swaps the left and right children of each node in the tree, effectively mirroring the tree structure.
Breakdown:

Base Case:

If the root is NULL, it means the tree is empty. In this case, there's nothing to invert, so the function simply returns NULL.
Recursive Inversion:

A temporary variable temp is used to store the root's left child.
The function recursively calls itself on root->right to invert the right subtree and assigns the returned inverted right subtree to root->left.
It then recursively calls itself on temp (which initially holds the left child) to invert the left subtree and assigns the returned inverted left subtree to root->right.
Essentially, the left and right subtrees are swapped at the current node, and the inversion continues recursively down the tree.
Return Inverted Tree:

After inverting both subtrees and swapping them, the function returns the modified root node, which now represents the inverted tree.
Key Points:

In-Place Modification: The function modifies the original tree in-place without creating a new tree.
Recursive Approach: The inversion is achieved by recursively traversing the tree and swapping children at each node.
Time and Space Complexity: The time complexity is O(n), where n is the number of nodes in the tree, as each node is visited and processed once. The space complexity is O(h), where h is the height of the tree, due to the recursion stack.
