class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         int i=0,n=arr.size(),left=0,right=n-1;
         if(k>=n)
             return arr;
         vector<int>res;
        while(i<n)
        {
            int mid = i + (n-i)/2;
            if(arr[mid]<x)
                i=mid+1;
            else
                n=mid;
        }
        // while(left<=right)
        // {
        //     if(abs(arr[left]-x)>abs(arr[right]-x))
        //         left++;
        //     else
        //         right--;
        //     if(right-left+1 == k)
        //         break;
        // }
        // for(i=left;i<=right;i++)
        //     res.push_back(arr[i]);
        // return res;

        right=i;
        left = right-1;
        n = arr.size();
        while((left>=0) || (right<n))
        {
            if(left<0)
            {

                right++;
            }
            else if(right==n)
            {

                left--;
            }
            else if(abs(arr[left]-x)<=abs(arr[right]-x))
            {

                left--;
            }
            else
            {

                right++;
            }
            k--;
            if(k == 0)
                break;

        }
        for(i=left+1;i<right;i++)
            res.push_back(arr[i]);
        return res;
    }
};
