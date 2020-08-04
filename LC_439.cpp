class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
      stack<int>s;
        int i,n=T.size();
        if(n==0)
            return vector<int>();

        vector<int>arr(n,0);
      for(i=0;i<n;i++)
      {
          while((!s.empty()) && (T[i]>T[s.top()]))
          {
              arr[s.top()]=i-s.top();
              s.pop();
          }
          s.push(i);
      }
      return arr;
    }
};
