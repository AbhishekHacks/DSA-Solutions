/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 */

//Time Complexity -- O(logn)

class LRUCache {
public:
    map<int,int>time_key;
    unordered_map<int,int>key_time;
    unordered_map<int,int>key_value;
    int capacity;
    int time=0;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(key_value.count(key)){
            int t = key_time[key];
            time_key.erase(t);
            time_key[time]=key;
            key_time[key]=time;
            time++;
            return key_value[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(key_value.count(key)){
            int t = key_time[key];
            time_key.erase(t);
            time_key[time]=key;
            key_time[key]=time;
            time++;
            key_value[key]=value;
        }
        else{
            if(key_value.size()==capacity){
                auto it = time_key.begin();
                int t = it->first;
                int k = it->second;
                time_key.erase(t);
                key_time.erase(k);
                key_value.erase(k);
            }
            time_key[time]=key;
            key_time[key]=time;
            key_value[key]=value;
            time++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
