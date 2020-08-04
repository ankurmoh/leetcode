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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode *>q;
        q.push(root);
        int depth=1;
        while(!q.empty())
        {
            int con = q.size();
            for(int i=0;i<con;i++)
            {
            TreeNode *x=q.front();
            q.pop();
            if((x->right==NULL) && (x->left==NULL))
                return depth;
            if(x->left!=NULL)
                q.push(x->left);
            if(x->right!=NULL)
                q.push(x->right);
            }
            depth++;
        }
        return 0;
    }
};
