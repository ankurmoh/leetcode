class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>que;
        int i,sz=nums.size(),sz1;
        if(sz==0)
            return vector<int>();
        for(i=0;i<min(k,sz);i++)
            que[nums[i]]+=1;
        vector<int>res;
        auto it = que.end();
        it--;
        res.push_back(it->first);
        if(sz<=k)
            return res;
        for(i=k;i<sz;i++)
        {
             que[nums[i-k]]-=1;
             if(que[nums[i-k]]==0)
                 que.erase(nums[i-k]);
            que[nums[i]]+=1;
            it=que.end();
            it--;
            res.push_back(it->first);
        }
        return res;
    }
};
