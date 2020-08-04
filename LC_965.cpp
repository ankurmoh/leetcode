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
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
            return true;
        queue<TreeNode*>q;
        int val=root->val;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *x=q.front();
            q.pop();
            if(x->val!=val)
                return false;
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
        }
        return true;
    }
};
