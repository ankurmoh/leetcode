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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>v;
        int i,mx,count;
        if(root==NULL)
            return v;
        q.push(root);
        while(!q.empty())
        {
            count=q.size();
            mx=-2147483648;
            while(count>0)
            {
                TreeNode *x=q.front();
                q.pop();
                mx=max(mx,x->val);
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                count--;
            }
            v.push_back(mx);
        }
        return v;
    }
};
