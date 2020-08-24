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

    void in(TreeNode* root, vector<int>& v)
    {
        if(root==NULL)
            return;
        in(root->left,v);
        v.push_back(root->val);
        in(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
    vector<int>a;
        vector<int>res;
        vector<int>b;
        in(root1,a);
        in(root2,b);
        int len1=a.size(),len2=b.size(),i=0,j=0;
        if(len1==0)
            return b;
        if(len2==0)
            return a;
        while((i<len1) && (j<len2))
        {
           if(a[i]<=b[j])
               res.push_back(a[i++]);
          else
                res.push_back(b[j++]);
        }
        while(i<len1)
            res.push_back(a[i++]);
        while(j<len2)
            res.push_back(b[j++]);
        return res;
    }
};
