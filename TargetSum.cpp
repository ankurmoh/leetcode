class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
       if(nums.size()==0)
           return true;
        int i,len=nums.size(),sum=0,j;
        for(i=0;i<len;i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        sum/=2;
    vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int curr : nums) {
            for (j = sum; j >= curr; j--) {
                dp[j] = dp[j] || dp[j - curr];
            }
        }
        return dp[sum];
     // bool dp[len+1][sum+1];
     //    for(i=0;i<=len;i++)
     //        dp[i][0]=true;
     //    for(i=1;i<=sum;i++)
     //        dp[0][i]=false;
     //    for(i=1;i<=len;i++)
     //    {
     //        for(j=1;j<=sum;j++)
     //        {
     //            dp[i][j]=dp[i-1][j];
     //            if(j>=nums[i-1])
     //                dp[i][j]=dp[i][j] || dp[i-1][j-nums[i-1]];
     //        }
     //    }
     //    return dp[len][sum];
    }
};


class Solution {
public:
    int cal=0;
    int traverse(vector<int>& nums,int S,int sum,int index,vector<vector<int>>& mp)
    {
        if(index == nums.size())
        {
            if(S==sum)
                return 1;
            return 0;
        }
        else if(mp[index][sum+1000]!=INT_MIN)
            return mp[index][sum+1000];
        int add = traverse(nums,S,sum+nums[index],index+1, mp);
        int subtract = traverse(nums,S,sum-nums[index],index+1,mp);
        mp[index][sum+1000] = add+subtract;
        return mp[index][sum+1000];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sz=nums.size();
        vector<vector<int>>mp(sz, vector<int>(2001,INT_MIN));
        return traverse(nums,S,0,0,mp);
        //return cal;
    }
};

int i,sz=nums.size(),sum=0,j;
     for(i=0;i<sz;i++)
         sum=sum+nums[i];
     if((S>sum) || (S<-sum))
         return 0;
     sum=sum+S;
     if(sum%2)
         return 0;
     sum=sum/2;
vector<int>dp(sum+1,0);
      dp[0]=1;
      for(i=1;i<=sz;i++)
      {
          for(j=sum;j>=nums[i-1];j--)
              dp[j]=dp[j]+dp[j-nums[i-1]];
      }
      return dp[sum];
