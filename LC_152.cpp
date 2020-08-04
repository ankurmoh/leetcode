class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int i,len=nums.size(),maxtot,max_so_far,min_so_far,prev_max_so_far,prev_min_so_far;
        if(len==1)
            return nums[0];
        max_so_far=nums[0];
        min_so_far=nums[0];
        prev_max_so_far=max_so_far;
        prev_min_so_far=min_so_far;
        maxtot=nums[0];
        for(i=1;i<len;i++)
        {
            max_so_far = max(nums[i], max(prev_max_so_far*nums[i], prev_min_so_far*nums[i]));
            min_so_far = min(nums[i], min(prev_max_so_far*nums[i], prev_min_so_far*nums[i]));
            maxtot=max(maxtot,max_so_far);
            prev_max_so_far=max_so_far;
            prev_min_so_far=min_so_far;
        }
        return maxtot;
    }
};
