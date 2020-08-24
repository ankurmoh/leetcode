class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int i,len=nums.size(),firstmax,secondmax,thirdmax,ans,flag=0;
        firstmax=INT_MIN;
        secondmax=INT_MIN;
        thirdmax=INT_MIN;
        for(i=0;i<len;i++)
        {
            if(nums[i]>firstmax)
            {
                thirdmax=secondmax;
                secondmax=firstmax;
                firstmax=nums[i];
            }
            else if((nums[i]>secondmax) && (nums[i]<firstmax))
            {
                thirdmax=secondmax;
                secondmax=nums[i];
            }
            else if((nums[i]>thirdmax) && (nums[i]<secondmax))
                thirdmax=nums[i];
            if(nums[i]==INT_MIN)
                flag=1;
        }
        if (len<=2)
            return firstmax;
        if((thirdmax == INT_MIN) && (flag==0))
            return firstmax;
        if(secondmax == INT_MIN)
            return firstmax;
        return thirdmax;
    }
};
