class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int i,j=arr.size()/20,sum=0,n=arr.size();
        for(i=j;i<=n-1-j;i++)
            sum=sum+arr[i];
        double res = (1.0*sum)/(0.9*n);
        return res;
    }
};
