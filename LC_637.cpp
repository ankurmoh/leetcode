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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v;
        double sum;
        int temp,count;
        if(root==NULL)
            return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            count=q.size();
            temp=count;
            sum=0.0;
            while(temp>0)
            {
                TreeNode *x=q.front();
                q.pop();
                sum=sum+x->val;
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                temp--;
            }
            v.push_back((sum*1.0)/count);
        }
        return v;
    }
};
