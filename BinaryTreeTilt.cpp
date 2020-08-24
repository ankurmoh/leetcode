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
    int sumSubTree(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        return root->val + sumSubTree(root->left) + sumSubTree(root->right);
    }
    int findTilt(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int curVal = 0;
        curVal = abs(sumSubTree(root->left) - sumSubTree(root->right));
        return curVal + findTilt(root->left) + findTilt(root->right);
    }
};
