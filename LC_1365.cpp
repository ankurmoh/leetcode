class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp1;
        int i,len=nums.size(),con=0;
        for(i=0;i<len;i++)
            mp[nums[i]]++;
        for(i=0;i<110;i++)
        {
           if(mp.find(i)!=mp.end())
           {
                mp1[i]=con;
                con=con+mp[i];
           }
        }
        for(i=0;i<len;i++)
            nums[i]=mp1[nums[i]];
        return nums;
    }
};
