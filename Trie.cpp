struct TrieNode
{
    bool isKey;
    TrieNode* next[26];
    TrieNode()
    {
        isKey = false;
        memset(next, NULL, sizeof(next));
    }
};

class WordDictionary
{
public:
    WordDictionary() {
       root = new TrieNode();
    }
    void addWord(string word)
    {
        TrieNode* node = root;
        for(auto c: word)
        {
            if(node->next[c - 'a'] == NULL)
                node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isKey = true;
    }
    bool search(string word) {
        return helper(word, root);
    }
private:
    TrieNode* root;
    bool helper(string word, TrieNode* node)
    {
        int i,sz = word.length(),j;
        for(i = 0; i<sz; i++)
        {
            char c = word[i];
            if(c != '.')
            {
                if(node->next[c - 'a'] == NULL)
                    return false;
                node = node->next[c - 'a'];
            }
            else
            {
                bool found = false;
                for(j=0; j<26; j++)
                {
                    if(node->next[j])
                        found = found | helper(word.substr(i + 1), node->next[j]);
                    if(found)
                        return true;
                }
                if(j == 26)
                    return false;
            }
        }
        return node->isKey;
    }
};

class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    TrieNode()
    {
        memset(next, 0, sizeof(next));
        is_word = false;
    }
};
class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string s)
    {
        TrieNode *p = root;
        int i,len=s.length();
        for(i=0;i<len;i++)
        {
            if(p->next[s[i] - 'a']==NULL)
                p->next[s[i] - 'a']=new TrieNode();
            p=p->next[s[i] - 'a'];
        }
        p->is_word = true;
    }
    bool search(string key)
    {
        TrieNode *p = find(key);
        return ((p!=NULL) && (p->is_word==true));
    }
    bool startsWith(string prefix)
    {
        TrieNode *p = find(prefix);
        return p!=NULL;
    }

private:
    TrieNode* find(string key)
    {
        TrieNode *p = root;
        int i,len=key.length();
        for(i=0;i<len;i++)
        {
            p=p->next[key[i] - 'a'];
            if(p==NULL)
                break;
        }
        return p;
    }
};

class TrieNode
{
public:
    TrieNode *children[26];
    bool is_word;
    TrieNode()
    {
        memset(children, NULL, sizeof(children));
        is_word = false;
    }
};
class Trie
{
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }
    void add(string word)
    {
        TrieNode* t = root;
        for (auto ch: word)
        {
            if(t->children[ch-'a']==NULL)
                t->children[ch-'a'] = new TrieNode();
            t = t->children[ch-'a'];
        }
        t->is_word = true;
    }
    string findPrefix(string word)
    {
        string res = "", curr="";
        TrieNode* t = root;
        for(auto ch: word)
        {
            if(t->children[ch-'a']==NULL || t->is_word)
            {
                if(t->is_word)
                    res = curr;
                return (res=="") ? word : res;
            }
            t = t->children[ch-'a'];
            curr += ch;
        }
        return (res=="") ? word : res;
    }
};
class Solution {
public:
    vector<string> split(string s)
    {
        vector<string> words;
        string tmp = "";
        for(auto ch: s)
        {
            if(ch==' ')
            {
                words.push_back(tmp);
                tmp = "";
            }
            else
                tmp += ch;
        }
        if(tmp!="")
            words.push_back(tmp);
        return words;
    }
    string replaceWords(vector<string>& dict, string sentence)
    {
        Trie* trie = new Trie();
        for(auto word: dict)
            trie->add(word);
        string res = "";
        vector<string>words = split(sentence);
        for(auto word: words)
        {
            if(res=="")
                res = trie->findPrefix(word);
            else
                res = res + " " + trie->findPrefix(word);
        }
        return res;
    }
};

class Node
{
public:
    vector<Node*>next;
    bool isWord;
    Node()
    {
        isWord = false;
        next = vector<Node*>(26, NULL);
    }
};
class Trie
{
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(string s)
    {
        Node* cur = root;
        for(char c: s)
        {
            if(cur->next[c - 'a'] == NULL)
                cur->next[c - 'a'] = new Node();
            cur = cur->next[c - 'a'];
        }
        cur->isWord = true;
    }
    bool find(string s)
    {
        Node* cur = root;
        for(char c: s)
        {
            if(cur->next[c - 'a'] == NULL)
                return false;
            cur = cur->next[c - 'a'];
        }
        return cur->isWord;
    }
};
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        trie = new Trie();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict)
    {
        for(string s: dict)
            trie->insert(s);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word)
    {
        for(int i = 0; i < word.size(); i++)
        {
            for(int j = 0; j < 26; j++)
            {
                char c = j + 'a';
                if(c == word[i])
                    continue;
                char oriChar = word[i];
                word[i] = c;
                if(trie->find(word))
                    return true;
                word[i] = oriChar;
            }
        }
        return false;
    }
private:
    Trie* trie;
};
