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
    bool isCompleteTree(TreeNode* root)
    {
     if(root==NULL)
         return true;
     queue<TreeNode*>q;
        q.push(root);
        TreeNode *x;
        while(true)
        {
            x=q.front();
            q.pop();
            if(x->left==NULL)
            {
                if(x->right!=NULL)
                    return false;
            }
            else
                q.push(x->left);
            if(x->right==NULL)
                break;
            else
               q.push(x->right);
        }
        while(!q.empty())
        {
            x=q.front();
            q.pop();
            if((x->left!=NULL) || (x->right!=NULL))
                return false;
        }
        return true;
    }
};
