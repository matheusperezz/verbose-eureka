class HashMap:
    def __init__(self, size) -> None:
        self.size = size
        self.table = [None] * size
    
    def _hash(self, key) -> int:
        return hash(key) % self.size
    
    def put(self, key, value):
        index = self._hash(key)
        if self.table[index] is None:
            self.table[index] = []
        self.table[index].append((key, value))
    
    def get(self, key):
        index = self._hash(key)
        if self.table[index] is not None:
            for k, v in self.table[index]:
                if k == key:
                    return v
        return None

    def __str__(self) -> str:
        elements = []
        for item in self.table:
            if item is not None:
                elements.extend(item)
        return '{' + ', '.join([f'{k}: {v}' for k, v in elements]) + '}'

"""
HashMaps in python will automatically allocate a new position in array when
you make more puts than the size
"""

hash_map = HashMap(10)
hash_map.put('a', 124)
hash_map.put('b', 2903)
hash_map.put('c', 9999)
hash_map.put('d', 8946)
hash_map.put('e', 1)
hash_map.put('f', 2)
hash_map.put('g', 3)
hash_map.put('h', 4)
hash_map.put('i', 5)
hash_map.put('j', 6)
hash_map.put('k', 7)
hash_map.put('l', 8)
hash_map.put('m', 9)
hash_map.put('n', 10)

print(hash_map.get('a'))
print(hash_map.get('b'))
print(hash_map.get('c'))
print(hash_map.get('d'))
print(hash_map.get('e'))
print(hash_map.get('f'))
print(hash_map.get('g'))
print(hash_map.get('h'))
print(hash_map.get('i'))
print(hash_map.get('j'))
print(hash_map.get('k'))
print(hash_map.get('l'))
print(hash_map.get('m'))
print(hash_map.get('n'))