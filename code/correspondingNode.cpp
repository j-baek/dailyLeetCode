/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        //pre-order 
        if(original == target) return cloned;
        if(original == nullptr) return nullptr;
        
        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        TreeNode *right = getTargetCopy(original->right, cloned->right, target);
        
        if(left == nullptr) return right;
        return left;
    }
};