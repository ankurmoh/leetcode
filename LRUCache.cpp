class LRUCache {
public:
    list<int>dequeue;
    unordered_map< int, list<int>::iterator >cache;
    unordered_map<int,int>mp;
    int sz;
    LRUCache(int capacity) {
   sz=capacity;
    }

    int get(int key) {
      if(mp.find(key)==mp.end())
          return -1;

            updateLRU(key);
            return mp[key];
        }

    void put(int key, int value)
    {
     if((mp.find(key)==mp.end())&&(dequeue.size()==sz))
     {
         evict();
     }
        updateLRU(key);
        mp[key]=value;
    }
    void updateLRU(int key)
    {
        if(mp.find(key)!=mp.end())
            dequeue.erase(cache[key]);
        dequeue.push_front(key);
        cache[key]=dequeue.begin();
    }
   void evict()
   {
       int val = dequeue.back();
       mp.erase(val);
       cache.erase(dequeue.back());
       dequeue.pop_back();
   }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
