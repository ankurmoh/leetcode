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
    vector<string>s;
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL)
            return 0;
        printpath(root,to_string(root->val));
        int res=0;

        int mod = (int)(pow(10, 9)) +7;
        for(string n: s)
        {
            long long int num = 0, ind = 0;
            for(int i= n.length()-1; i>=0; i--)
            {
                int ch = n[i] - '0';
                num += (pow(2, ind) * ch);
                ind++;
                num %= mod;
            }
            res += (int)num;
            res = res % mod;
        }
        return res;
    }
    void printpath(TreeNode* root, string val)
    {
        if((root->left==NULL) && (root->right==NULL))
        {
            s.push_back(val);
            return;
        }
        if(root->left)
            printpath(root->left,val + to_string(root->left->val));
        if(root->right)
            printpath(root->right,val + to_string(root->right->val));
        return;
    }
};
