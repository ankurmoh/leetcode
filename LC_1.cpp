class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>v;
        int i,len=nums.size();
        for(i=0;i<len;i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                v.push_back(mp[target-nums[i]]);
                v.push_back(i);
                return v;
            }
            mp[nums[i]]=i;
        }
        return v;
    }
};
