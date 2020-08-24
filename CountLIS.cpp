class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int i,n=nums.size(),j,con=0,maxi=1;
        vector<int>DP(n+1,1);
        vector<int>COUNT(n+1,1);
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(DP[i]<DP[j]+1)
                    {
                        DP[i]=DP[j]+1;
                        COUNT[i]=COUNT[j];
                    }
                    else if(DP[i]==DP[j]+1)
                    {
                        COUNT[i]+=COUNT[j];
                    }
                }
            }
            maxi=max(maxi,DP[i]);
        }
        for(i=0;i<n;i++)
        {
            if(DP[i]==maxi)
                con+=COUNT[i];
        }
        return con;
    }
};
