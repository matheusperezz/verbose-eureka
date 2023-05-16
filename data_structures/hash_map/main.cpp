#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ARR_SIZE = 10;

class HashNode {
    public:
        string key;
        int value;
        
        HashNode(string key, int value) {
            this->key = key;
            this->value = value;
        }
};

class HashMap {
    private:
        vector<HashNode*> buckets;
        int size;
    public:
        HashMap(int size){
            this->size = size;
            buckets = vector<HashNode*>(size, nullptr);
        }

        int hash(string key){
            int sum = 0;
            for (int i = 0; i < key.size(); i++){
                sum += static_cast<int>(key[i]);
            }
            return sum % ARR_SIZE;
        }

        void put(string key, int value){
            int hashValue = hash(key);
            HashNode* node = buckets[hashValue];
            while (node != nullptr && node->key != key){
            }
        }

};

int hash_function(string s){
    int sum = 0;
    for (int i = 0; i < s.size(); i++){
        sum += static_cast<int>(s[i]);
    }
    return sum % ARR_SIZE;
}

int main(){
    int hash_table[ARR_SIZE];

    cout << hash_function("matheus") << endl;
    return 0;
}