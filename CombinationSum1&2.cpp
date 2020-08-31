class Solution {
public:
    void backtrack(vector<int>& candidates,int target,vector<int>& ans,vector<vector<int>>& res,int begin)
    {
      if(target<0)
      return;
        if(target==0)
        {
            res.push_back(ans);
            return;
        }
        int i,sz=candidates.size(),sum=0;
        //for(i=begin;((i<sz) && (target>=candidates[i]));i++)
        for(i=begin;i<sz;i++)
        {
            ans.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],ans,res,i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ans;
      //  sort(candidates.begin(),candidates.end());
        int i,sz=candidates.size();
        if(sz==0)
           return res;
        backtrack(candidates,target,ans,res,0);
        return res;
    }
};

class Solution {
public:
    void backtrack(vector<int>& candidates,int target,vector<int>& ans,vector<vector<int>>& res,int begin)
    {
      if(target<0)
      return;
        if(target==0)
        {
            res.push_back(ans);
            return;
        }
        int i,sz=candidates.size(),sum=0;
        //for(i=begin;((i<sz) && (target>=candidates[i]));i++)
        for(i=begin;i<sz;i++)
        {
          if((i==begin) || (candidates[i]==candidates[i-1]))
          {
            ans.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],ans,res,i+1);
            ans.pop_back();
          }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ans;
        sort(candidates.begin(),candidates.end());
        int i,sz=candidates.size();
        if(sz==0)
           return res;
        backtrack(candidates,target,ans,res,0);
        return res;
    }
};

class Solution {
public:
    void permute(vector<int>& nums,int begin,vector<int>& ans,vector<vector<int>>& res)
    {
        res.push_back(ans);
        int i,sz=nums.size();
        for(i=begin;i<sz;i++)
        {
            ans.push_back(nums[i]);
            permute(nums,i+1,ans,res);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i,sz=nums.size();
        vector<int>ans;
        vector<vector<int>>res;
        permute(nums,0,ans,res);
        return res;
    }
};

class Solution {
public:
    void permute(vector<int>& nums,int begin,vector<int>& ans,vector<vector<int>>& res)
    {
        int i,sz=nums.size();
        res.push_back(ans);
        for(i=begin;i<sz;i++)
        {
            if((i==begin) || (nums[i]!=nums[i-1]))
            {
                ans.push_back(nums[i]);
                permute(nums,i+1,ans,res);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        int i,sz=nums.size();
        vector<int>ans;
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        permute(nums,0,ans,res);
        return res;
    }
};

class Solution {
public:
    void backtrack(vector<int>& temp,vector<int>& ans,vector<vector<int>>& res,int begin,int k)
    {
        if(k==0)
        {
            res.push_back(ans);
            return;
        }
        int i,sz=temp.size();
        for(i=begin;i<sz;i++)
        {
            ans.push_back(temp[i]);
            backtrack(temp,ans,res,i+1,k-1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>>res;
        if(k==0)
            return res;
        vector<int>temp;
        for(int i=1;i<=n;i++)
            temp.push_back(i);
        vector<int>ans;
        backtrack(temp,ans,res,0,k);
        return res;
    }
};

class Solution {
public:
    void backtrack(int start,int end,int n,string temp,vector<string>& ans)
    {
        if(temp.length()==2*n)
        {
            ans.push_back(temp);
            return;
        }
        if(start<n)
            backtrack(start+1,end,n,temp+"(",ans);
        if(end<start)
            backtrack(start,end+1,n,temp+")",ans);
    }
    vector<string> generateParenthesis(int n) {
        int start=0,end=0;
        string temp="";
        vector<string>ans;
        backtrack(start,end,n,temp,ans);
        return ans;
    }
};

 class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL)
            return 0;
        return traverse(root,L,R);
    }
    int traverse(TreeNode* root,int L,int R)
    {
        if(root==NULL)
            return 0;
        if(root->val>R)
            return traverse(root->left,L,R);
        if(root->val<L)
            return traverse(root->right,L,R);
        return root->val + traverse(root->left,L,R) + traverse(root->right,L,R);
    }
};
