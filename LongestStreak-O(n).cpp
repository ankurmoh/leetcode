class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i,sz=nums.size(),streak=0,maxstreak=1,first;
        if(sz==0)
            return 0;
        unordered_map<int,int>mp;
        for(i=0;i<sz;i++)
            mp[nums[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            first=it->first;
            if(mp.find(first-1)==mp.end())
            {
                streak=1;
                first++;
                while(mp.find(first)!=mp.end())
                {
                    streak++;
                    first++;
                }
                maxstreak=max(maxstreak,streak);
            }
        }
        return maxstreak;
    }
};
