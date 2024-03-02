**Convert Sorted Array to Binary Search Tree**

Problem Statement 101) Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

-------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
struct TreeNode* new_node;
if (numsSize==0) return NULL;
new_node = malloc(sizeof(struct TreeNode));
if (numsSize==1) {
    new_node->val = nums[0];
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}
new_node->left = sortedArrayToBST(nums,numsSize/2);
new_node->val = nums[numsSize/2];
new_node->right = sortedArrayToBST(nums+(numsSize/2)+1,numsSize-(1+(numsSize/2)));
return new_node;
}

----------Explanation :-
Purpose:

This code implements the sortedArrayToBST function, designed to construct a balanced binary search tree (BST) from a given sorted array of integers.
Key Steps:

Handle Base Cases:

If numsSize is 0 (empty array), return NULL as there's no BST to create.
If numsSize is 1 (single element), create a BST with just that element as the root and return it.
Create Root Node:

Allocate memory for a new TreeNode to represent the root of the BST.
Construct Left Subtree:

Recursively call sortedArrayToBST with the first half of the nums array (nums to numsSize/2) to create the left subtree.
Assign the resulting subtree as the left child of the root node.
Set Root Node's Value:

Set the val field of the root node to the middle element of the original array (nums[numsSize/2]).
Construct Right Subtree:

Recursively call sortedArrayToBST with the second half of the nums array (nums[numsSize/2]+1 to numsSize-1) to create the right subtree.
Assign the resulting subtree as the right child of the root node.
Return Root Node:

Return the created root node, representing the fully constructed balanced BST.
Key Points:

The recursion ensures a balanced BST since each subarray is divided into halves for subtree construction.
The middle element of each subarray becomes the root of its corresponding subtree, maintaining BST properties.
The base cases handle the simplest scenarios for termination of recursion.
