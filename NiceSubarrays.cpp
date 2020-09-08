class Solution {
public:
    int atmost(vector<int>& nums,int k)
    {
        int left=0,right,sz=nums.size(),con=0,s=0;
        for(right=0;right<sz;right++)
        {
            if(nums[right]%2)
                con++;
            while((con>k) && (left<=right))
            {
                if(nums[left]%2)
                    con--;
                left++;
            }
            s =s + (right-left+1);
        }
        return s;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};
