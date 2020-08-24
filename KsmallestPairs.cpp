class Solution {
public:
    struct numCompare
    {
        bool operator() (const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y)
        {
          return ((x.second.first + x.second.second) > (y.second.first + y.second.second));
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare> minHeap;
        int i,j,len1=nums1.size(),len2=nums2.size();
        vector<vector<int>>res;
        if((len1==0)||(len2==0)||(k<=0))
            return res;
        for(i=0;i<min(len1,k);i++)
            minHeap.push(make_pair(0,make_pair(nums1[i],nums2[0])));
        int sz = min(k,len1*len2);
        while(sz>0)
        {
            auto fron = minHeap.top();
            minHeap.pop();
            res.push_back({fron.second.first,fron.second.second});
            fron.first=fron.first+1;
            if(fron.first<len2)
                minHeap.push(make_pair(fron.first,make_pair(fron.second.first,nums2[fron.first])));
            sz--;
        }
        return res;

    }
};
