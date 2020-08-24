class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<pair<int,int>>v;
    MyHashMap() {

    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int i,sz=v.size(),flag=0;
        for(i=0;i<sz;i++)
        {
            if(v[i].first==key)
            {
                flag=1;
                v[i].second=value;
            }
        }
        if(flag==0)
        {
        v.push_back(make_pair(key,value));
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int sz=v.size(),i,x1;
        for( i=0;i<sz;i++)
        {
            x1=v[i].first;
            if(x1==key)
                return v[i].second;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int i,sz=v.size();
        for(i=0;i<sz;i++)
            if(v[i].first==key)
                break;
        if(i<sz)
        {
            v.erase(v.begin()+i);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
