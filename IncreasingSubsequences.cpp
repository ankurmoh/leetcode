class Solution {
public:
    void backtrack(vector<int>& nums,int pos,vector<int>& res,set<vector<int>>& st)
    {
        if(res.size()>=2)
            st.insert(res);
        int i,n=nums.size();
        for(i=pos;i<n;i++)
        {
            if((res.size() == 0) || (nums[i]>=res.back()))
            {
                res.push_back(nums[i]);
                backtrack(nums,i+1,res,st);
                res.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>res;
        backtrack(nums,0,res,st);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
