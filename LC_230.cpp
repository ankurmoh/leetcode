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
    int result=-1,count=0;
    int kthSmallest(TreeNode* root, int k) {
        traverse(root,k);
        return result;
    }
    void traverse(TreeNode* root, int k)
    {
        if(root==NULL)
            return;
        traverse(root->left,k);
        count++;
        if(k==count)
        {
            result = root->val;
            return;
        }
        traverse(root->right,k);
    }
};
/*
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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* parent=root;
        stack<TreeNode*>s;
        int count=0;
       // s.push(parent);
        while(!s.empty() || parent!=NULL)
        {
            while(parent!=NULL)
            {
                s.push(parent);
                parent=parent->left;
            }

                TreeNode* temp=s.top();
                s.pop();
                count++;
                if(count==k)
                    return temp->val;
                parent=temp->right;

        }
        return INT_MIN;
    }
};
*/
