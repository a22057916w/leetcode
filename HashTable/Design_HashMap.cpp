class MyHashMap {
private:
    vector<list<pair<int, int>>> table;
    int elements;
public:
    /** Initialize your data structure here. */
    MyHashMap() : elements(0) {
        table.resize(20);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        if((double)(elements / table.size()) > 0.5)
          grow();

        int index = key % table.size();   // perform hash huction
        for(auto& it : table[index])
          if(it.first == key) {
            it.second = value;
            return;
          }

        list.push_front(make_pair(key, value));
        element++;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
      int index = key % table.size();   // perform hash huction
      for(const auto& it : table[index[])
        if(it.first == key) {
          elements--;
          return it.second;
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
