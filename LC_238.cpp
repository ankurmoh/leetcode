class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i,len=nums.size(),res;
        if(len==0)
            return nums;
        vector<int>begin,end;

        res=1;
        for(i=0;i<len;i++)
        {
            res=res*nums[i];
            begin.push_back(res);
        }
        res=1;
        for(i=len-1;i>=0;i--)
        {
            res=res*nums[i];
            end.push_back(res);
        }
        reverse(end.begin(),end.end());
        for(i=0;i<len;i++)
            cout<<begin[i]<<" ";
        cout<<endl;
        for(i=0;i<len;i++)
            cout<<end[i]<<" ";
        for(i=0;i<len;i++)
            nums[i]=-1;
        nums[0]=end[1];
        nums[len-1]=begin[len-2];
        for(i=1;i<len-1;i++)
            nums[i]=begin[i-1]*end[i+1];
        return nums;
    }
};
