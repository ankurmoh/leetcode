class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        int i,len=nums.size(),con=0;
        for(i=0;i<len;i++)
            mp[nums[i]].push_back(i);
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            con=con + ((it->second.size()) * (it->second.size()-1)) /2;
        }
        return con;
    }
};
