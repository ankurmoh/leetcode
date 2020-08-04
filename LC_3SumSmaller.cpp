class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int i,low,high,sz=nums.size(),con=0;
        if(sz==0)
            return 0;
        sort(nums.begin(),nums.end());
        for(i=0;i<sz-2;i++)
        {
            low=i+1;
            high=sz-1;
            while(low<high)
            {
                if(nums[i]+nums[low]+nums[high]>=target)
                    high--;
                else if(nums[i]+nums[low]+nums[high]<target)
                {
                    con=con+high-low;
                    low++;
                }
            }
        }
        return con;
    }
};
