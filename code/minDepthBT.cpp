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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int leftNode = minDepth(root->left) + 1;
        int rightNode = minDepth(root->right) + 1;
        
        if(root->left == nullptr) return rightNode;
        if(root->right == nullptr) return leftNode;
        return min({leftNode,rightNode});
    }
};