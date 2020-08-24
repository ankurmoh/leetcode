/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
    queue<NestedInteger>q;
        int i,sz = nestedList.size(),sum=0,level=1,j,maxlev=1;
        NestedInteger fron;
        unordered_map<int,int>mp;
        for(i=0;i<sz;i++)
            q.push(nestedList[i]);
        while(!q.empty())
        {
            sz = q.size();
            sum = 0;
            for(i=0;i<sz;i++)
            {
                fron = q.front();
                q.pop();
                if(fron.isInteger())
                    sum = sum + fron.getInteger();
                else
                {
                    vector<NestedInteger>temp = fron.getList();
                    for(j=0;j<temp.size();j++)
                        q.push(temp[j]);
                }
            }
            mp[level] = sum;
            maxlev= max(maxlev,level);
            level++;
        }
        sum = 0;
        j=1;
        for(i=maxlev;i>=1;i--)
        {
                sum = sum + (mp[i]*j);
            j++;
        }
        return sum;
    }
};
