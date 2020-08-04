class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        long long int i,len=nums.size(),flag=0,j,diff;
        vector<string>res;
        if(len==0)
            return res;
        string temp = to_string(nums[0]);
        if(len==1)
        {
            res.push_back(temp);
            return res;
        }
        for(i=0;i<len;)
        {
            flag=0;
            temp=to_string(nums[i]);
            j=i+1;
            if(j<len)
                diff=nums[j]-nums[i];
            while((j<len) && (diff==1))
            {
                flag=1;
                i=j;
                j=j+1;
                if(j==len)
                    break;
                if((nums[j]==INT_MAX) && (nums[i]<0))
                    break;
                diff=nums[j]-nums[i];
            }
            if(flag)
            {
                temp=temp+"->"+to_string(nums[i]);
                i=j;
            }
            else
                i=i+1;
            res.push_back(temp);
        }
        return res;
    }
};
