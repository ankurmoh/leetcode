class Solution {
public:
    int maximumSum(vector<int>& arr) {
     int i,n=arr.size(),max_so_far,overall_max;
     if(n==0)
         return 0;
        max_so_far = arr[0];
        overall_max = arr[0];
        vector<int>forward(n),backward(n);
        forward[0]=arr[0];
        for(i=1;i<n;i++)
        {
            max_so_far = max(arr[i],max_so_far+arr[i]);
            overall_max = max(overall_max, max_so_far);
            forward[i] = max_so_far;
        }
        max_so_far = arr[n-1];
        overall_max = arr[n-1];
        backward[n-1] = arr[n-1];
        for(i=n-2;i>=0;i--)
        {
            max_so_far = max(arr[i],max_so_far+arr[i]);
            overall_max = max(overall_max, max_so_far);
            backward[i] = max_so_far;
        }
        for(i=1;i<=n-2;i++)
        {
            if(overall_max < forward[i-1] + backward[i+1])
                overall_max = forward[i-1] + backward[i+1];
        }
        return overall_max;
    }
};
