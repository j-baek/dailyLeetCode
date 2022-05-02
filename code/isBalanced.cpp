/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int treeHeight(TreeNode *node) {
        if(node == nullptr) return 0;
        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        // balanced tree has height diff no more than 1. 
        if(abs(treeHeight(root->left) - treeHeight(root->right)) <= 1)
            // recursive call to check if they are actually balanced
            return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }
    
};