class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
       unordered_map<int,vector<int>>freq;
        int i,len=nums.size(),shortest,sz,mx=-10;
        for(i=0;i<len;i++)
        {
            freq[nums[i]].push_back(i);
        }
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            vector<int>temp=it->second;
            sz=temp.size();
            if(mx<sz)
            {
                mx=sz;
            }
        }
        shortest=len;
         for(auto it=freq.begin();it!=freq.end();it++)
        {
             vector<int>temp1=it->second;
             if(temp1.size()==mx)
             {
                 shortest=min(shortest,temp1[temp1.size()-1]-temp1[0]+1);
             }
        }
        return shortest;

    }
};
