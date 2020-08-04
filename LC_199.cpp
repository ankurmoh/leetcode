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
    vector<int> rightSideView(TreeNode* root) {
       queue<TreeNode*>q;
        vector<int>res;
        if(root==NULL)
            return res;
        q.push(root);
        int i,count,value;
        while(!q.empty())
        {
            count=q.size();
            for(i=0;i<count;i++)
            {
                TreeNode *x=q.front();
                value=x->val;
                q.pop();
                if(i==count-1)
                    res.push_back(value);
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
        }
        return res;
    }
};
