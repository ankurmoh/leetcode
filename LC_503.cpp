class Solution {
public:
   /* vector<int> nextGreaterElements(vector<int>& nums)
    {
        stack<int>s;
        int i,len=nums.size();
        vector<int>ans(len,-1);
        for(i=0;i<len*2;i++)
        {
            int x=nums[i%len];
            while((x>nums[s.top()]) && (!s.empty()))
            {
                ans[s.top()]=x;
                s.pop();
            }
            s.push(i%len);
        }
        return ans;
    }*/
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, -1);
        stack<int> s;
        for (int i = 0; i < n * 2; i++) {
            int num = nums[i % n];
            while (!s.empty() && nums[s.top()] < num) {
                next[s.top()] = num;
                s.pop();
            }
            s.push(i%n);
        }
        return next;
    }
};
