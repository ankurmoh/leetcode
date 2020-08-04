class Solution {
public:
    int rob(vector<int>& nums) {
        int sz=nums.size(),i,val1=INT_MIN;
        if(sz==0)
            return 0;
        if(sz==1)
            return nums[0];
       vector<int>dp(sz+1,0);
       dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(i=2;i<sz-1;i++)
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        val1=dp[sz-2];
        dp.clear();
        dp[0]=0;
        dp[1]=nums[1];
        if(sz>=3)
            dp[2]=max(nums[1],nums[2]);
        for(i=3;i<sz;i++)
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        return max(dp[sz-1],val1);
    }
};
