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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *x=q.front();
            q.pop();
            TreeNode *left=x->left;
            x->left=x->right;
            x->right=left;
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
        }
        return root;
    }
};
