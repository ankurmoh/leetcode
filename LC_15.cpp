class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        int i,j,sum,low,high,sz=nums.size();
        map<vector<int>,int>mp;
        sort(nums.begin(),nums.end());
        if((sz<3) || (nums[0]>0) || (nums[sz-1]<0))
            return res;
        for(i=0;i<sz-2;i++)
        {
            low=i+1;
            high=sz-1;
            while(low<high)
            {
                sum=nums[i]+nums[low]+nums[high];
                if(sum>0)
                    high-=1;

                else if(sum<0)
                    low+=1;

                else if(sum==0)
                {
                    vector<int>v={nums[i],nums[low],nums[high]};
                    if(mp.find(v)==mp.end())
                    {
                        res.push_back(v);
                        mp[v]=true;
                    }
                    low++;
                    high--;
                }
            }
        }
        return res;
    }
};
