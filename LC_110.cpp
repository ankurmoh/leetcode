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
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int lh,rh;
        lh=height(root->left);
        rh=height(root->right);
        if((abs(lh-rh)<=1) && (isBalanced(root->left)) && (isBalanced(root->right)))
            return true;
        return false;
    }
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
};
