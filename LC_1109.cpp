class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int i,len=bookings.size(),x,y;
        vector<int>ans(n,0);
        for(i=0;i<len;i++)
        {
            x=bookings[i][0]-1;
            y=bookings[i][1]-1;
            ans[x] += bookings[i][2];
            if(y+1<n)
                ans[y+1] -= bookings[i][2];
        }
        for(i=1;i<n;i++)
            ans[i] += ans[i-1];
        return ans;
    }
};
