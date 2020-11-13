class Solution {
public:
    bool is_leaf(TreeNode* root)
    {
        return ((root->left == NULL) && (root->right == NULL));
    }
    void add_leaves(TreeNode* root, vector<int>& res)
    {
        if(root == NULL)
            return;
        if(is_leaf(root))
        {
            res.push_back(root->val);
            //return;
        }
        else {
        add_leaves(root->left,res);
        add_leaves(root->right,res); }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int>res;
        if(root==NULL)
            return res;
        res.push_back(root->val);
        if(is_leaf(root))
            return res;
        TreeNode* left_boundary = root->left;
        while((left_boundary!=NULL) && (!is_leaf(left_boundary)))
        {
            res.push_back(left_boundary->val);
            if(left_boundary->left!=NULL)
                left_boundary = left_boundary->left;
            else if(left_boundary->right!=NULL)
                left_boundary=left_boundary->right;
        }
        add_leaves(root,res);
        stack<int>st;
        TreeNode* right_boundary = root->right;
        while((right_boundary!=NULL)&&(!is_leaf(right_boundary)))
        {
            st.push(right_boundary->val);
            if(right_boundary->right!=NULL)
                right_boundary=right_boundary->right;
            else if(right_boundary->left!=NULL)
                right_boundary = right_boundary->left;
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
