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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        preorder(root,v);
        return v;
    }
    void preorder(TreeNode* root, vector<int>& v)
    {
        if(root==NULL)
            return;
        stack<TreeNode *>s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *x=s.top();
            s.pop();
            v.push_back(x->val);
            if(x->right!=NULL)
                s.push(x->right);
            if(x->left!=NULL)
                s.push(x->left);
        }
    }
};
