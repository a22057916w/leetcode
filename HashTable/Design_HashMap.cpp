class MyHashMap {
private:
    vector<list<pair<int, int>>> table;
    int elements;
public:
    /** Initialize your data structure here. */
    MyHashMap() : elements(0) {
        table.resize(3000);     // m = 1000, load factor = 10000/3000 = 0.33333
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % table.size();   // perform hash huction
        for(auto& it : table[index])
          if(it.first == key) {
            it.second = value;
            return;
          }

        table[index].push_front(make_pair(key, value));
        elements++;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
      int index = key % table.size();   // perform hash huction
      for(const auto& it : table[index])
        if(it.first == key) {
          elements--;
          return it.second;
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
      int index = key % table.size();   // perform hash huction
      for(auto it = table[index].begin(); it != table[index].end(); it++)
        if(it->first == key) {
          elements--;
          it = table[index].erase(it);
          return;
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
