class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i,sz=nums.size(),max1=nums[0],max2=-10;
        for(i=1;i<sz;i++)
        {
            if(nums[i]>max1)
            {
                max2=max1;
                max1=nums[i];
            }
            else if((nums[i]<=max1) && (nums[i]>max2))
            {

                max2=nums[i];
            }
        }
       cout<<max1<<" "<<max2;
        return (max1-1)*(max2-1);
    }
};
