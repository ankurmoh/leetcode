class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
      int i,low,high,sz=nums.size(),sum=0,difference=INT_MAX,currentdif,ans;
        if(sz<3)
        {
            for(i=0;i<sz;i++)
                sum=sum+nums[i];
            return sum;
        }
        sort(nums.begin(),nums.end());
        for(i=0;i<sz-2;i++)
        {
            low=i+1;
            high=sz-1;
            while(low<high)
            {
                sum=nums[i]+nums[low]+nums[high];
                currentdif=abs(sum-target);
                if(currentdif<difference)
                {
                    difference=currentdif;
                    ans=sum;
                }
                if(sum==target)
                    return sum;
                else if(sum<target)
                    low++;
                else if(sum>target)
                    high--;
            }
        }
        return ans;
    }
};
