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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if((t1==NULL) && (t2==NULL))
            return NULL;
        if((t1)&&(!t2))
            return t1;
        if((!t1) && (t2))
            return t2;
        queue<TreeNode*>q1,q2;
        q1.push(t1);
        q2.push(t2);
        while((!q1.empty()) && (!q2.empty()))
        {
            TreeNode *x=q1.front();
            q1.pop();
            TreeNode *y=q2.front();
            q2.pop();
            if((x) && (y))
            {
                x->val=x->val+y->val;
            if((x->left==NULL) && (y->left!=NULL))
                x->left=new TreeNode(0);
            if((x->right==NULL) && (y->right!=NULL))
                x->right=new TreeNode(0);
            q1.push(x->left);
            q1.push(x->right);
            q2.push(y->left);
            q2.push(y->right);
            }

        }
        return t1;
    }
};
