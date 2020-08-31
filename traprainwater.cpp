class Solution {
public:
    int trap(vector<int>& height) {
        int i,sz=height.size(),leftmax=0,rightmax=0,left=0,right=sz-1,ans=0;
        if(sz==0)
            return 0;
        while(left<right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>leftmax)
                    leftmax=height[left];
                else
                    ans=ans+(leftmax-height[left]);
                left++;
            }
            else
            {
                if(height[right]>rightmax)
                    rightmax=height[right];
                else
                    ans=ans+(rightmax-height[right]);
                right--;
            }
        }
        return ans;
    }
};
