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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if((p==NULL) && (q==NULL))
           return true;
        else if((p==NULL) || (q==NULL))
            return false;
        return ((p->val == q->val) && (isSameTree(p->left,q->left)) && (isSameTree(p->right,q->right)));
        /*queue<TreeNode*>q1,q2;
        q1.push(p);
        q2.push(q);
        while((!q1.empty()) && (!q2.empty()))
        {
            TreeNode *x=q1.front();
            TreeNode *y=q2.front();
            q1.pop();
            q2.pop();
            if((x->val)!=(y->val))
                return false;
             if((x->left!=NULL) && (y->left!=NULL))
            {
                q1.push(x->left);
                q2.push(y->left);
            }
            else if((x->left) || (y->left))
                return false;
            if((x->right!=NULL) && (y->right!=NULL))
            {
                q1.push(x->right);
                q2.push(y->right);
            }
            else if((x->right) || (y->right))
                return false;

        }
        return true; */
    }
};
