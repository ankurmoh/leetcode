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
    int robUtil(TreeNode* root,unordered_map<TreeNode*,int>& dp)
    {
        if(root==NULL)
            return 0;
        if(dp.find(root)!=dp.end())
            return dp[root];
        int res = 0;
        if(root->left)
            res = res + robUtil(root->left->left,dp) + robUtil(root->left->right,dp);
        if(root->right)
            res = res + robUtil(root->right->left,dp) + robUtil(root->right->right,dp);
        res = res + root->val;
        dp[root] = max(res, robUtil(root->left,dp) + robUtil(root->right,dp));
        res = dp[root];
        return res;
    }
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        if((!root->left) && (!root->right))
            return root->val;
        unordered_map<TreeNode*,int>dp;
        return robUtil(root,dp);
    }
};
