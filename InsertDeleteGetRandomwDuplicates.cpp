class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    vector<int>list;
    unordered_map<int,unordered_set<int>>index;
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        list.push_back(val);
        index[val].insert(list.size()-1);
        if(index[val].size()==1)
            return true;
        return false;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if((index.find(val) == index.end()) || (index[val].size()==0))
            return false;
        auto it = index[val].begin();
        int ind = *it;
        index[val].erase(it);
        if(index[val].size() == 0)
            index.erase(val);
        list[ind] = list[list.size()-1];
        index[list[ind]].insert(ind);
        index[list[ind]].erase(list.size()-1);
        list.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        //int x = rand()%list.size();
        return list[rand()%list.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
