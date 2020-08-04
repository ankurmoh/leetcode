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
    int ans=INT_MAX;
    void inorder(TreeNode* root,int& prev)
    {
        if(root==NULL)
            return;
        inorder(root->left,prev);
        if(prev!=INT_MAX)
        {
            ans=min(ans,(root->val-prev));
        }
        prev=root->val;
        inorder(root->right,prev);
    }
    int minDiffInBST(TreeNode* root) {
        int prev=INT_MAX;
        if(root==NULL)
            return 0;
        inorder(root,prev);
        return ans;
    }
};
