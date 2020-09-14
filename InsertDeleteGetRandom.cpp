class RandomizedSet {
public:
    vector<int>vals;
    unordered_map<int,int>mp;
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = mp.find(val);
        if(it==mp.end())
        {
            vals.push_back(val);
            mp[val] = vals.size()-1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        auto it = mp.find(val);
        if(it==mp.end())
            return false;
        int index = it->second;
        vals[index]=vals[vals.size()-1];
        mp[vals[index]]=index;
        vals.pop_back();
        mp.erase(it);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int x = rand()%vals.size();
        return vals[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
