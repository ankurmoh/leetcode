class Solution {
public:
    vector<int> sortedSquares(vector<int>& A)
    {
    int left,right,sz=A.size();
        vector<int>ans;
        for(left=0;left<sz;left++)
        {
            if(A[left]>0)
                break;
        }
        right=left;
        left=left-1;
        while((left>=0)&&(right<sz))
        {
            if(A[left]*A[left]<A[right]*A[right])
            {
                ans.push_back(A[left]*A[left]);
                left--;
            }
            else
            {
                ans.push_back(A[right]*A[right]);
                    right++;
            }
        }
        while(left>=0)
        {
            ans.push_back(A[left]*A[left]);
            left--;
        }
        while(right<sz)
        {
            ans.push_back(A[right]*A[right]);
            right++;
        }
        return ans;
    }
};
