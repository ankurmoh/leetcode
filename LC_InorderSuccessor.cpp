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
    TreeNode* minvalue(TreeNode* r)
    {
        while(r->left!=NULL)
            r=r->left;
        return r;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
       if(root==NULL)
           return NULL;
        if(p->right)
            return minvalue(p->right);
        TreeNode* succ=NULL;
        while(root!=NULL)
        {
            if(root->val>p->val)
            {
                succ=root;
                root=root->left;
            }
            else if(root->val<p->val)
                root=root->right;
            else
                break;
        }
        return succ;
    }
};
