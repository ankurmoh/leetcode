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
    //double res = 0.0;
    vector<double> postorder(TreeNode* root)
    {
        vector<double>v(3);
        int i;
        double avg,nodes,sum;
        if(root==NULL)
        {
            for(i=0;i<3;i++)
                v[i]=0.0;
            return v;
        }
        if((root->left == NULL) && (root->right == NULL))
        {
            v[0] = 1.0 * root->val;
            v[1] = 1.0;
            v[2] = v[0]/v[1];
            return v;
        }

        vector<double>left = postorder(root->left);
        vector<double>right = postorder(root->right);

        nodes = 1.0 + left[1] + right[1];
        sum = (1.0*root->val) + left[0] + right[0];
        avg = sum/nodes;

        v[0] = sum;
        v[1] = nodes;
        v[2] = max(avg,max(left[2],right[2]));
        return v;
    }
    double maximumAverageSubtree(TreeNode* root) {
        if(root == NULL)
            return 0.0;
        if((root->left == NULL) && (root->right == NULL))
            return 1.0*root->val;
        return postorder(root)[2];
    }
};
