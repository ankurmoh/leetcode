class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
	{
		size_t len = nums.size();
		if(len < k) return 0;
		priority_queue<int, std::vector<int>, std::greater<int>> q;
        priority_queue<int, std::vector<int>, std::greater<int>> v1;
		for(auto &v : nums)
		{
			if(q.size() < k)
				q.push(v);
			else if (v > q.top())
			{
				q.pop();
				q.push(v);
			}
            v1=q;
            while(!v1.empty())
            {
                cout<<v1.top()<<" ";
                v1.pop();
            }
            cout<<endl;
		}
        return q.top();
    }
};
