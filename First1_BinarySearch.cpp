// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       int start=1,end=n,mid;
        while(start<end)
        {
            mid = start + (end-start)/2;
            if(isBadVersion(mid)==false)
                start=mid+1;
            else
                end=mid;
        }
        return start;
    }
};

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start=1,end=n,mid;
        while(start<end)
        {
            mid=start + (end-start)/2;
            if((guess(mid)==1))
            {
                start=mid+1;
            }
            else
                end=mid;
        }
        return start;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int left=0,right=nums.size(),mid;
        vector<int>v;
        int start=findfirst(nums,target);
        if((start==right) || (nums[start]!=target))
        {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        else
            v.push_back(start);
        int end=findfirst(nums,target+1)-1;
        v.push_back(end);
        return v;
    }
    int findfirst(vector<int>& nums, int target)
    {
        int low=0,high=nums.size(),mid;
        while(low<high)
        {
            mid=low + (high-low)/2;
            if(nums[mid]<target)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
