class Solution {
public:
    bool canPartition(vector<int>& nums) {
       if(nums.size()==0)
           return true;
        int i,len=nums.size(),sum=0,j;
        for(i=0;i<len;i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        sum/=2;
     bool dp[len+1][sum+1];
     dp[0][0]=true;
        for(i=1;i<=len;i++)
            dp[i][0]=true;
        for(i=1;i<=sum;i++)
            dp[0][i]=false;
        for(i=1;i<=len;i++)
        {
            for(j=1;j<=sum;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1])
                    dp[i][j]=dp[i][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[len][sum];
    }
};
