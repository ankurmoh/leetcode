class Solution {
public:
    void backtrack(vector<vector<int>>& res,vector<int>& nums,int begin,map<vector<int>,int>& s)
    {
        if(begin==nums.size())
        {
            if(s.find(nums)==s.end())
            {
                res.push_back(nums);
                s[nums]=1;
            }
            return;
        }
        int i,sz=nums.size();
        for(i=begin;i<sz;i++)
        {
            swap(nums[begin],nums[i]);
            backtrack(res,nums,begin+1,s);
            swap(nums[begin],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map< vector<int> ,int >s;
        vector<vector<int>>res;
        if(nums.size()==0)
            return res;
        backtrack(res,nums,0,s);
        return res;
    }
};
