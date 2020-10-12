class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i,n=nums.size(),index;
        bool foundOne = false;
        for(i=0;i<n;i++)
        {
            if(nums[i]==1)
                foundOne=true;
            if((nums[i]<=0) || (nums[i]>n))
                nums[i]=1;
        }
        if(foundOne == false)
            return 1;
        for(i=0;i<n;i++)
        {
            index = abs(nums[i])-1;
            if(nums[index]>0)
                nums[index]=-nums[index];
        }
        for(i=0;i<n;i++)
        {
            if(nums[i]>0)
                return i+1;
        }
        return n+1;
    }
};
