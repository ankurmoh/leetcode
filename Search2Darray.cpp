class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        int m=matrix.size(),n=matrix[0].size(),left,right,pvt,key;

        left=0;
        right=m*n-1;
        while(left<=right)
        {
            pvt=(left+right)/2;
            key=matrix[pvt/n][pvt%n];
            if(key==target)
                return true;
            else if(key>target)
                right=pvt-1;
            else
                left=pvt+1;
        }
        return false;
    }
};
