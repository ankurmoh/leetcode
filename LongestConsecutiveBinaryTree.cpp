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
    int res = 0;
    void helper(TreeNode* root,int cur,int val)
    {
        if(root==NULL)
            return;
        if(root->val == val)
            cur++;
        else
            cur=1;
        res=max(res,cur);
        helper(root->left,cur,root->val+1);
        helper(root->right,cur,root->val+1);
    }
    int longestConsecutive(TreeNode* root) {
        if(root==NULL)
            return 0;
        helper(root,0,root->val);
        return res;
    }
};
