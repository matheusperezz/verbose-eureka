#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    public:
        LRUCache(int capacity){
            _capacity = capacity;
        }

        int get(int key){
            auto it = _cacheMap.find(key);
            if (it == _cacheMap.end()){
                return -1;
            }
            _cacheList.splice(_cacheList.begin(), _cacheList, it->second);
            return it->second->second;
        }

        void put(int key, int value){
            auto it = _cacheMap.find(key);
            if (it != _cacheMap.end()){
                _cacheList.erase(it->second);
                _cacheMap.erase(it);
            }
            _cacheList.push_front(make_pair(key, value));
            _cacheMap[key] = _cacheList.begin();
            if (_cacheMap.size() > _capacity){
                int k = _cacheList.back().first;
                _cacheList.pop_back();
                _cacheMap.erase(k);
            }
        }

    private:
        int _capacity;
        // List <first: int, second: int> cacheList
        list<pair<int,int>> _cacheList;
        // HashMap <int <List <first: int, second: int>>> cacheMap
        unordered_map<int, list<pair<int, int>>::iterator> _cacheMap;
};


int main(){

    LRUCache cache(2);

    cache.put(1, 2); // key 1, value 2
    cache.put(2, 2); // key 2, value 2
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cache.put(4, 4);
    cout << cache.get(3) << endl;

    return 0;
}
