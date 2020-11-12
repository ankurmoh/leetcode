class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        if(d*f<target)
            return 0;
         vector<vector<int>>dp(d+1, vector<int>(target+1,0));
         int i,j,k,m=1000000007;
        dp[0][0]=1;
        for(i=1;i<=d;i++)
        {
            for(j=1;j<=target;j++)
            {
                if(i*f<j)
                    break;
                for(k=1;((k<=f) && (k<=j));k++)
                    dp[i][j]=((dp[i][j]%m) + (dp[i-1][j-k]%m))%m;
            }
        }
        return dp[d][target];
//         vector<int>dp(target+1,0);
//         dp[0]=1;
//         for(i=1;i<=d;i++)
//         {
//             vector<int>dp1(target+1);
//             for(j=1;j<=target;j++)
//             {
//                 if(i*f<j)
//                     break;

//                 for(k=1;k<=min(j,f);k++)
//                     dp1[j]=(dp1[j]%m+dp[j-k]%m)%m;
//             }
//             dp = dp1;
//         }
//         return dp[target];
    }
};
