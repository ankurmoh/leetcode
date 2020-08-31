class Solution {
public:
    int func(int x,int a,int b,int c)
    {
        return (a*x*x + b*x + c);
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
     int i,sz=nums.size(),left=0,right=sz-1,k;
        for(i=0;i<sz;i++)
            nums[i]=func(nums[i],a,b,c);
        vector<int>res(sz);
        if(a>=0)
        {
            k=sz-1;
            while(k>=0)
            {
                if(nums[left]>=nums[right])
                {
                    res[k]=nums[left];
                    left++;
                }
                else
                {
                    res[k]=nums[right];
                    right--;
                }
                k--;
            }
        }
        else
        {
            k=0;
            while(k<sz)
            {
                if(nums[left]<=nums[right])
                {
                    res[k]=nums[left];
                    left++;
                }
                else
                {
                    res[k]=nums[right];
                    right--;
                }
                k++;
            }
        }
        return res;
    }
};
