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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int>ans;
        lonely(root, false, ans);
        return ans;
    }
    void lonely(TreeNode* root,bool isLonely,vector<int>& ans) {
        if( root == NULL)
            return;
        if( isLonely )
            ans.push_back(root->val);
        lonely(root->left, (root->right == NULL), ans);
        lonely(root->right, (root->left == NULL), ans);
    }
};
