**Kth Smallest Element in a BST**

Problem Statement 87) Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104

-----------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int kthSmallest(struct TreeNode* root, int k) {
    int count = 0;  // Track number of nodes visited
    int result = -1;  // Store the kth smallest value

    // In-order traversal to visit nodes in ascending order
    void inorder(struct TreeNode* node) {
        if (node == NULL || result != -1) return;  // Stop if kth smallest found or tree exhausted

        inorder(node->left);

        count++;
        if (count == k) {
            result = node->val;
            return;  // Stop traversal once kth smallest is found
        }

        inorder(node->right);
    }

    inorder(root);
    return result;
}


----------------Explanation :-

This code implements a function kthSmallest that takes a binary tree root and an integer k as input and returns the kth smallest element in the tree. Here's a breakdown of how it works:

In-Order Traversal with Early Termination:

Initialization:

Initialize count to 0 to track the number of nodes visited so far.
Initialize result to -1 to indicate the kth smallest value hasn't been found yet.
Recursive In-Order Traversal:

The helper function inorder performs an in-order traversal of the tree with early termination:
Base case: If node is NULL or result has already been found (-1), stop the traversal for that branch.
Recursive call: Traverse the left subtree (inorder(node->left)) to explore smaller values first.
Increment count as we visit the current node.
Check if count is equal to k:
If yes, set result to the current node's value (node->val) as it's the kth smallest.
Return prematurely to stop further traversal since we found the target.
Recursive call: Traverse the right subtree (inorder(node->right)) to explore larger values.
Return Value:

After the in-order traversal, if result is still -1, it means the kth smallest element might not exist (if k is larger than the number of nodes). In this case, the function returns -1.
Otherwise, the function returns the stored result which is the kth smallest element found in the traversal.
Key Points:

In-order traversal guarantees visiting nodes in ascending order based on their values.
By keeping track of visited nodes (count), we can identify the kth smallest node efficiently.
Early termination stops the traversal once the kth smallest element is found, improving performance.
The time complexity is O(n) in the worst case, where n is the number of nodes, due to visiting each node once.
The space complexity is O(h) due to the recursion stack, where h is the tree's height.
