/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void validateBST(TreeNode* root,int& res,int& mini,int& maxi)
    {
        if(root==NULL)
            return;
        int l_count=0,r_count=0,l_min=INT_MIN,l_max=INT_MAX,r_min=INT_MIN,r_max=INT_MAX;
        validateBST(root->left,l_count,l_min,l_max);
        validateBST(root->right,r_count,r_min,r_max);
        if(((root->left == NULL) || (root->val>l_max)) && ((root->right == NULL) || (root->val<r_min)))
        {
            res = 1 + l_count+r_count;
            mini = (root->left)? l_min:root->val;
            maxi = (root->right)? r_max:root->val;
        }
        else
            res = max(l_count,r_count);
    }
    int largestBSTSubtree(TreeNode* root) {
        if(root==NULL)
            return 0;
        if((root->left == NULL) && (root->right == NULL))
            return 1;
        int res=0,mini = INT_MIN, maxi = INT_MAX;
        validateBST(root,res,mini,maxi);
        return res;
    }
};

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
     int largestBSTSubtree(TreeNode* root)
     {
         if(root==NULL)
             return 0;
         if(validate(root,NULL,NULL))
             return countnodes(root);
         return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
     }
     bool validate(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
     {
         if(root==NULL)
             return true;
         if((minNode && minNode->val>=root->val) || (maxNode && maxNode->val<=root->val))
             return false;
         return (validate(root->left,minNode,root) && validate(root->right,root,maxNode));
     }
     int countnodes(TreeNode* root)
     {
         if(root==NULL)
             return 0;
         return 1 + countnodes(root->left) + countnodes(root->right);
     }
 };
