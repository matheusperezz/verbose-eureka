n = 6
edges = [[0,3], [1,2], [1,5], [2,4], [3,5], [5,4], [5,0]]
graph = {}

for edge in edges:
    if edge[0] not in graph:
        graph[edge[0]] = [edge[1]]
    else:
        graph[edge[0]].append(edge[1])
        

print(graph)