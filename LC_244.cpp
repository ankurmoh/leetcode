class WordDistance {
public:
    unordered_map<string , vector<int> > word;
    WordDistance(vector<string>& words) {
        int i,sz=words.size();
        for(i=0;i<sz;i++)
            word[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        int i,j,sz,mindiff=INT_MAX;

        i=0;
        j=0;
        sz=word[word1].size();
        int sz1=word[word2].size();
        while(i<sz && j<sz1)
        {
            mindiff=min(mindiff,abs(word[word1][i]-word[word2][j]));
            if(word[word1][i]<word[word2][j])
                i++;
            else
                j++;
        }
        return mindiff;
    }
};
