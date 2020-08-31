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
    void flatten(TreeNode* root) {
        if (root ==NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *left=root->left;
        TreeNode *right=root->right;
        root->left=NULL;
        root->right=left;
        TreeNode *cur=root;
        while(cur->right)
            cur=cur->right;
        cur->right=right;
    }
};

class Solution {
public:
  void flatten(TreeNode* root)
  {
    stack<TreeNode*>st;
    TreeNode* cur;
    st.push(root);
    while(!st.empty())
    {
      cur=st.top();
      st.pop();
      if(cur->right)
        st.push(cur->right);
      if(cur->left)
        st.push(cur->left);
      if(!st.empty())
        cur->right=st.top();
      cur->left=NULL;
    }
  }
};
