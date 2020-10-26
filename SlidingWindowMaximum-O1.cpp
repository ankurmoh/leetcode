class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      /*  multiset<int>bag;
        int i,sz=nums.size();
        for(i=0;i<min(k,sz);i++)
            bag.insert(nums[i]);
        vector<int>res;
        res.push_back(*bag.rbegin());
        if(sz<=k)
            return res;
        for(i=k;i<sz;i++)
        {
            bag.erase(bag.find(nums[i-k]));
            bag.insert(nums[i]);
            res.push_back(*bag.rbegin());
        }
        return res;*/
        int i,j,n=nums.size(),con;
        if((n==0) || (k==0))
            return vector<int>();
        if(k==1)
            return nums;
        vector<int>left(n),right(n);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(i=1;i<n;i++)
        {
            if(i%k==0)
                left[i]=nums[i];
            else
                left[i]=max(nums[i],left[i-1]);
            j = n-1-i;
            if((j+1)%k==0)
                right[j]=nums[j];
            else
                right[j]=max(nums[j],right[j+1]);
        }
        vector<int>res;
        for(i=0;i<=n-k;i++)
        {
            res.push_back(max(right[i],left[i+k-1]));
        }
        return res;
    }
};
