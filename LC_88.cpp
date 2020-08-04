class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i=0,j=0,size=m+n,con=0;
        vector<int>v(size);
        while((i<m) && (j<n))
        {
            if(nums1[i]<=nums2[j])
            {
               v[con]=nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                v[con]=nums2[j];
                j++;
            }
            con++;
        }
        while(i<m)
            v[con++]=nums1[i++];
        while(j<n)
            v[con++]=nums2[j++];
        nums1.clear();
        nums1=v;
    }
};
