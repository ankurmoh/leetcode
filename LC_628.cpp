class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len=nums.size(),i,max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,min1=INT_MAX,min2=INT_MAX,ans;
        for(i=0;i<len;i++)
        {
            if(nums[i]>=max1)
            {
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if((nums[i]<max1)&&(nums[i]>=max2))
            {
                max3=max2;
                max2=nums[i];
            }
            else if((nums[i]<max2)&&(nums[i]>=max3))
                max3=nums[i];
            if(nums[i]<=min1)
            {
                min2=min1;
                min1=nums[i];
            }
            else if((nums[i]<=min2) && (nums[i]>min1))
                min2=nums[i];
        }

        ans = max(max1*max2*max3,max1*min1*min2);
        return ans;
    }
};
