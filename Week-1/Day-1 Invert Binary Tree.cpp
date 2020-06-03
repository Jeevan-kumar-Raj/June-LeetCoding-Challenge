Day-1 Invert Binary Tree.cpp

/*

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

*/

// Time:  O(n)
// Space: O(h) 
// DFS, Recursive solution.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};