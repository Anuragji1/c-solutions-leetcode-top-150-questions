**Validate Binary Search Tree**

Problem Statement 88) Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

-------------------------------------------------------------------------------------------------------------------
SoLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct child_res {
    int min;
    int max;
    bool valid;
} child_res;

child_res validBST(struct TreeNode *root)
{
    child_res res, res_left, res_right;

    res.min = INT_MIN;
    res.max = INT_MAX;
    res.valid = true;

    if (root) {
        res_left = validBST(root->left);
        res_right = validBST(root->right);

        if (root->left) {
            if (res_left.max >= root->val ||
                    !res_left.valid)
                res.valid = false;
            res.min = res_left.min;
        } else {
            res.min = root->val;
        }

        if (root->right) {
            if (root->val >= res_right.min ||
                    !res_right.valid)
                res.valid = false;
            res.max = res_right.max;
        } else {
            res.max = root->val;
        }
    }

    return res;
}

bool isValidBST(struct TreeNode* root)
{
    child_res res = validBST(root);
    return res.valid;
}

-----------Explanation :-
Code Structure and Functionality:

The given code implements a function isValidBST that determines whether a given binary tree root represents a valid Binary Search Tree (BST).

Breakdown of validBST function:

child_res struct: This defines a custom data structure that holds three attributes:
min: The minimum value encountered in the subtree rooted at the current node.
max: The maximum value encountered in the subtree rooted at the current node.
valid: A boolean flag indicating whether the subtree rooted at the current node is a valid BST.
Base case: If root is NULL, it's an empty subtree, considered valid with default min and max values and valid set to true.
Recursive calls:
Calls validBST on the left child (res_left), returning its child_res result.
Calls validBST on the right child (res_right), returning its child_res result.
Validation checks:
Left child:
If root->left exists and its maximum value (res_left.max) is greater than or equal to the current node's value (root->val), or if res_left.valid is false (indicating an invalid left subtree), mark the current node's subtree as invalid (res.valid = false).
Update the current node's minimum value (res.min) to the left subtree's res_left.min if root->left exists.
Right child:
Similarly, check if root->right exists and its minimum value (res_right.min) is less than or equal to the current node's value, or if res_right.valid is false.
Update the current node's maximum value (res.max) to the right subtree's res_right.max if root->right exists.
Return values: The function returns the constructed child_res structure for the current node, containing min, max, and valid information.
isValidBST function:

Calls validBST on the root node (root).
Returns the valid field from the returned child_res structure, indicating whether the entire tree is a valid BST.
Key Points:

The code recursively checks each subtree for BST properties (left child < current node < right child) while propagating minimum and maximum values for validation.
The custom child_res structure allows efficient return of multiple values from the recursive calls.
The time complexity is O(n) due to visiting each node once.
The space complexity is O(h) due to the recursion stack depth, where h is the tree's height.
