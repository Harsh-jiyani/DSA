#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> lruList; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // Key not found
        }

        // Move the accessed pair to front (most recently used)
        auto it = cacheMap[key];
        int val = it->second;
        lruList.erase(it);
        lruList.push_front({key, val});
        cacheMap[key] = lruList.begin();

        return val;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Remove the old entry
            lruList.erase(cacheMap[key]);
        } else if (lruList.size() == capacity) {
            // Remove LRU from the list and map
            int lruKey = lruList.back().first;
            lruList.pop_back();
            cacheMap.erase(lruKey);
        }

        // Insert the new key-value pair at front
        lruList.push_front({key, value});
        cacheMap[key] = lruList.begin();
    }

    void display() {
        cout << "Cache content (Most -> Least Recently Used): ";
        for (auto& p : lruList) {
            cout << "[" << p.first << ":" << p.second << "] ";
        }
        cout << endl;
    }
};

int main() {
    LRUCache cache(3); // Capacity = 3

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);
    cache.display();

    cout << "Access key 2: " << cache.get(2) << endl;
    cache.display();

    cache.put(4, 400); // This will evict key 1
    cache.display();

    cout << "Access key 1: " << cache.get(1) << endl; // Should return -1 (evicted)
    cache.display();

    return 0;
}
