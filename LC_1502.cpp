class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int i,d,len=arr.size();
        if(len<=2)
            return true;
        sort(arr.begin(),arr.end());
        d=arr[1]-arr[0];
        for(i=2;i<len;i++)
        {
            if(arr[i]-arr[i-1] != d)
                return false;
        }
        return true;
    }
};
