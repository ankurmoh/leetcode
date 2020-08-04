class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i,j,sz=arr.size();
        for(i=0;i<sz;)
        {
            if(arr[i]==0)
            {
                for(j=sz-2;j>=i;j--)
                    arr[j+1]=arr[j];
                i=i+2;
            }
            else
                i++;
        }
    }
};
