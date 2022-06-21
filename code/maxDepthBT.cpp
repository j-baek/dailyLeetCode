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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr) return maxDepth(root->right) + 1;
        if(root->right == nullptr) return maxDepth(root->left) + 1;
        
        int lD = maxDepth(root->left) + 1;
        int rD = maxDepth(root->right) + 1;
        
        if(lD > rD) return lD;
        return rD;
    }
};
