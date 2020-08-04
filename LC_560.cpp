class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i,len=nums.size(),cur=0,con=0;
        if(len==0)
            return 0;
        mp[0]++;
        for(i=0;i<len;i++)
        {
            cur+=nums[i];
            if(mp.count(cur-k))
                con+=mp[cur-k];
            mp[cur]++;
        }
        return con;
    }
};
