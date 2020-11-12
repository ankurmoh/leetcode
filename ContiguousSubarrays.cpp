class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      /*  int i,j,sz=nums.size();
        vector<int>sum(sz,0);
        sum[0]=nums[0];
        for(i=1;i<sz;i++)
            sum[i]=sum[i-1]+nums[i];
        for(i=0;i<sz-1;i++)
        {
            for(j=i+1;j<sz;j++)
            {
                if((sum[j]-sum[i]+nums[i]==k) || ((k!=0)&&((sum[j]-sum[i]+nums[i])%k==0)))
                    return true;
            }
        }
        return false;*/

        unordered_map<int,int>mp;
        int i,sum=0,n=nums.size();
        if(k==0)
        {
            for(i=0;i<n-1;i++)
            {
                if((nums[i]==0)&&(nums[i+1]==0))
                    return true;
            }
            return false;
        }
        for(i=0;i<n;i++)
        {
            sum=sum+nums[i];
            sum=sum%k;
            if((sum == 0) && (i>0))
                return true;
            if(mp.find(sum)!=mp.end())
            {
                if(i-mp[sum]>1)
                    return true;
            }
            else
            {
                mp[sum]=i;
            }
        }
        return false;
    }
};
