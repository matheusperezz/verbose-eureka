class MaxHeap:
    def __init__(self):
        self.heap = []

    # Função para mover um elemento para o topo do heap e readaptar
    def heapify_up(self, index):
        while index > 0 and self.heap[index] > self.heap[(index - 1) // 2]:
            self.heap[index], self.heap[(index - 1) // 2] = self.heap[(index - 1) // 2], self.heap[index]
            index = (index - 1) // 2

    # Função para mover um elemento para o fundo do heap e readaptar
    def heapify_down(self, index):
        size = len(self.heap)
        largest = index
        left_child = 2 * index + 1
        right_child = 2 * index + 2

        if left_child < size and self.heap[left_child] > self.heap[largest]:
            largest = left_child

        if right_child < size and self.heap[right_child] > self.heap[largest]:
            largest = right_child

        if largest != index:
            self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
            self.heapify_down(largest)

    # Função para inserir um elemento no heap
    def insert(self, value):
        self.heap.append(value)
        index = len(self.heap) - 1
        self.heapify_up(index)

    # Função para remover e retornar o elemento máximo do heap
    def extract_max(self):
        if not self.heap:
            raise RuntimeError("Heap vazio")

        max_value = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self.heapify_down(0)

        return max_value

    # Função para verificar se o heap está vazio
    def is_empty(self):
        return len(self.heap) == 0

# Teste do heap máximo
max_heap = MaxHeap()
max_heap.insert(12)
max_heap.insert(8)
max_heap.insert(15)
max_heap.insert(21)

while not max_heap.is_empty():
    print(max_heap.extract_max(), end=" ")

print()
