class Node:
    def __init__(self, position, parent=None) -> None:
        self.position = position
        self.parent = parent
        self.g = 0 # Cost from start to current node
        self.h = 0 # Heuristic estimate of cost to goal
        self.f = 0 # Total cost (g + h)
        
def manhattam_distance(point1, point2):
    x1, y1 = point1
    x2, y2 = point2
    return abs(x1 - x2) + abs(y1 - y2)

def a_star(maze, start, goal):
    # Possible paths
    open_list = []

    # Not to consider in shortest path
    closed_list = set()

    start_node = Node(start)
    start_node.h = manhattam_distance(start, goal)
    start_node.f = start_node.g + start_node.h
    open_list.append(start_node)

    while open_list:
        # Find the node with the lowest f score
        current_node = min(open_list, key=lambda node: node.f)
        open_list.remove(current_node)
        closed_list.add(current_node.position)

        if current_node.position == goal:
            path = []
            while current_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1] # Reverse path for start to goal order

        # Get neighbors (consider movements within the grid)
        neighbors = [
            (current_node.position[0] + 1, current_node.position[1]),
            (current_node.position[0] - 1, current_node.position[1]),
            (current_node.position[0], current_node.position[1] + 1),
            (current_node.position[0], current_node.position[1] - 1),
        ]

        for neighbor in neighbors:
            if neighbor in closed_list or neighbor[0] < 0 or neighbor[0] >= len(maze) or neighbor[1] < 0 or neighbor[1] >= len(maze[0]) or maze[neighbor[0]][neighbor[1]] == 1:
                continue
            
            # Calculate tentative g score for neighbor
            tentative_g = current_node.g + 1
            new_node = next((node for node in open_list if node.position == neighbor), None)
            if new_node is None or tentative_g < new_node.g:
                # Update neighbor information
                if new_node is None:
                    new_node = Node(neighbor, current_node)
                new_node.parent = current_node
                new_node.g = tentative_g
                new_node.h = manhattam_distance(neighbor, goal)
                new_node.f = new_node.g + new_node.g
                open_list.append(new_node)

    return None
