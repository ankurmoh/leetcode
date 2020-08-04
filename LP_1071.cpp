class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string prefix="",validprefix="";
        int i,j,len1=str1.length(),len2=str2.length(),len_pref;
        for(i=0;i< min(len1,len2); i++)
        {
            if(str1[i]==str2[i])
            {
                prefix=prefix+str1[i];
                len_pref = prefix.length();
                if((len1%len_pref!=0) || (len2%len_pref!=0))
                    continue;
                string temp1 = "";
                string temp2 = "";
                for(j=0;j<len1/len_pref;j++)
                    temp1=temp1+prefix;
                for(j=0;j<len2/len_pref;j++)
                    temp2=temp2+prefix;
                if ((temp1 == str1) && (temp2 == str2))
                    validprefix = prefix;
            }
            else
                break;
        }
        return validprefix;
    }
};
