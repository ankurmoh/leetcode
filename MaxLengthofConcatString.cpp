class Solution {
public:
    bool isunique(string s)
    {
        vector<int>freq(26,0);
        int i,len=s.length();
        for(i=0;i<len;i++)
        {
            if(freq[s[i]-'a']>0)
                return false;
            freq[s[i]-'a']++;
        }
        return true;
    }
    void traverse(vector<string>& arr,int index,string result,int& maxres)
    {
        if(isunique(result))
        {
            if(maxres<result.length())
                maxres=result.length();
        }
        if((index == arr.size()) || (!isunique(result)))
            return;
        traverse(arr,index+1,result,maxres);
        traverse(arr,index+1,result+arr[index],maxres);
    }
    int maxLength(vector<string>& arr) {
        int res=0,sz=arr.size();
        if(sz==0)
            return res;
        if(sz==1)
            return arr[0].length();
        traverse(arr,0,"",res);
        return res;
    }
};
