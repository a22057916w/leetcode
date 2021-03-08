class MyHashMap {
private:
    vector<list<pair<int, int>>> table;
    int size, count;
public:
    /** Initialize your data structure here. */
    MyHashMap() : size(20), count(0) {
        table.resize(size);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        if(key)
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {

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
