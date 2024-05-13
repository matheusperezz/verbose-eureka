class LRUCache:
    def __init__(self, capacity) -> None:
        self.capacity = capacity
        self.cache = {}
        self.order = []

    def get(self, key):
        if key in self.cache:
            # update order
            self.order.remove(key)
            self.order.append(key)
            return self.cache[key]
        return -1

    def put(self, key, value):
        if key in self.cache:
            # update value and order
            self.cache[key] = value
            self.order.remove(key)
            self.order.append(key)
        else:
            # add new element
            if len(self.cache) >= self.capacity:
                # remove the last recent used element
                lru_key = self.order.pop(0)
                del self.cache[lru_key]
            self.cache[key] = value
            self.order.append(key)

# Exemplo de uso:
cache = LRUCache(2)  # Capacidade máxima de 2 itens

cache.put(1, 1)
cache.put(2, 2)
print(cache.get(1))
cache.put(3, 3)
print(cache.get(2))
cache.put(4, 4)
print(cache.get(1))
print(cache.get(3))
print(cache.get(4))