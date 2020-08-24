class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0,len1=pushed.size(),len2=popped.size();
        stack<int>s;
        if(len1 != len2)
            return false;
        for(i=0;i<len1;i++)
        {
            s.push(pushed[i]);
            while((!s.empty()) && (j<len2) && (s.top() == popped[j]))
            {
                s.pop();
                j++;
            }
        }
        return s.empty();
        return (j==len2);
    }
};
