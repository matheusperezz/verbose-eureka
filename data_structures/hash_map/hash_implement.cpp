#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Entry
{
    string key;
    int value;
    Entry *next;

    Entry(const string &k, int v) : key(k), value(v), next(nullptr) {}
};

class HashMap
{
private:
    vector<Entry *> table;
    int capacity;

    // Função has que pode ser mais complexa
    int hash(string key)
    {
        int hashValue = 0;
        for (char c : key)
        {
            hashValue = (hashValue * 31 + c) % capacity;
        }
        return hashValue;
    }

public:
    HashMap(int size) : capacity(size)
    {
        table.resize(capacity, nullptr);
    }

    // Função para inserir uma chave e um valor no HashMap
    void put(const string key, int value)
    {
        int index = hash(key);
        Entry *newEntry = new Entry(key, value);

        if (!table[index])
        {
            table[index] = newEntry;
        }
        else
        {
            Entry *current = table[index];
            while (current->next)
            {
                current = current->next;
            }
            current->next = newEntry;
        }
    }

    int get(const string key)
    {
        int index = hash(key);
        Entry *current = table[index];

        while (current)
        {
            if (current->key == key)
            {
                return current->value;
            }
        }

        // Chave não encontrada
        return -1;
    }

    void remove(const string key)
    {
        int index = hash(key);
        Entry *current = table[index];
        Entry *prev = nullptr;

        while (current)
        {
            if (current->key == key)
            {
                if (prev)
                {
                    prev->next = current->next;
                }
                else
                {
                    table[index] = current->next;
                }

                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    //  Destrutor para liberar memória
    ~HashMap()
    {
        for (int i = 0; i < capacity; i++)
        {
            Entry *current = table[i];
            while (current)
            {
                Entry *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main()
{
    HashMap hashMap(10);

    hashMap.put("dez", 10);
    hashMap.put("vinte", 20);
    hashMap.put("trinta", 30);

    cout << "Valor chave 'vinte': " << hashMap.get("vinte") << endl;

    hashMap.remove("vinte");

    return 0;
}