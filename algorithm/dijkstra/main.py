import heapq

def dijkstra(graph, start):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0

    # Inicializando a fila de prioridade com o vertice inicial
    pq = [(0, start)]
    while pq:
        # Remove o vértice com menor distância da fila de prioridade
        current_distance, current_vertex = heapq.heappop(pq)

        # Se já encontramos um caminho mais curto para esse vértice, ignoramos
        if current_distance > distances[current_vertex]:
            continue
            
        # Itera sobre o s vizinhos do vértice atual
        for neighbor, weight in graph[current_vertex].items():
            print(f'Priority queue: {pq}')
            distance = current_distance + weight
            
            # Se encontrarmos um caminho mais curto para o vizinho, atualizmaos sua distancia
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                # Adiciona o vizinho a fila de prioridade
                heapq.heappush(pq, (distance, neighbor))
        
    return distances

graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1},
    'E': {}
}

start = 'A'
distances = dijkstra(graph, start)
print(f'Distâncias mínimas a partir do vértice {start}: {distances}')