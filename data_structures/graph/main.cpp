#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <climits>

using namespace std;

/*
    
    ::::: PROPERTIES OF GRAPHS :::::

    What is a graph? -> a graph G is an ordered pair of a set V of vertices and a set of
    E of edges === G = (V, E)

    Directed graph || DiGraph, the vertices have a direction: A --> B

    Undirected graph, all the edges are bidirecional: A -- B

    Weighted Graph, the edges have Weight/Cost: A -- 200 -- B -- 150 -- C

    Self-loop: node linked with yourself (not usual utilities)

    Multi or parallel edge: an node with two edges that go to the same node

    Number of edges: Minimum: 0, 
    Maximum if directed, 0 <= |E| <= n (n-1) E = edges, n = nodes.
    Maximum if undirected, 0 <= |E| <= (n(n-1))/2

    Dense -> too many edges (close to square of nodes)
    Sparse -> too few edges (lesser than square of nodes)

    Path -> a sequence of vertices where each adjacent pair is connected by an edge.
    < A, B, F, H >

    Simples path -> no verticies (and thus no edges) are repeated.

    Strongly connected graphs -> if there is a path from any vertex to any ohter vertex

    Simples cycle -> no repetition other than start and end

    acyclic graph -> a graph with no cycle


    ::::: Adjacency Matrix :::::

    Search for more information, but is a way to represent graphs with matrices.

    ::::: Adjacency List :::::

    Search for more information, but is way to represent graphs with linked lists.


*/

struct Node {
    string value;
    vector<class Edge*> incomingEdges;
    vector<class Edge*> outgoingEdges;
};

struct Edge {
    class Node* startNode;
    class Node* endNode;
    int weight;
};

// direteced graph with weights
class Graph {
    public:
        void insertNode(string val){
            Node* newNode = new Node;
            newNode->value = val;
            nodes.push_back(newNode);
        }

        void insertEdge(Node* startNode, Node* endNode, int weight){
            Edge* newEdge = new Edge;
            newEdge->startNode = startNode;
            newEdge->endNode = endNode;
            newEdge->weight = weight;
            edges.push_back(newEdge);

            // Update the properties of incomingEdges and outgoingEdges
            startNode->outgoingEdges.push_back(newEdge);
            endNode->incomingEdges.push_back(newEdge);
        }

        Node* getNode(string value){
            for (Node* node : nodes){
                if (node->value == value){
                    return node;
                }
            }
            return nullptr;
        }

        // Depth first search
        void DFS(Node* node, unordered_set<Node*>& visited){
            visited.insert(node);
            cout << node->value << " ";

            for (Edge* edge : node->outgoingEdges) {
                if (visited.find(edge->endNode) == visited.end()){
                    DFS(edge->endNode, visited);
                }
            }
        }

        // Implements the dijkstra
        pair<vector<Node*>, int> dijkstra(Node* startNode, Node* endNode){
            // Initialize the distance and previous node maps
            map<Node*, int> distance;
            map<Node*, Node*> previous;
            for (Node* node : nodes){
                distance[node] = INT_MAX;
                previous[node] = nullptr;
            }

            // Set the distance of the start node to 0
            distance[startNode] = 0;

            // Initialize the priority queue with the start node and its distance
            priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
            pq.push(make_pair(0, startNode));

            // Loop until the priority queue is empty or the end node is reached
            while (!pq.empty()){
                // Get the node with the smallest distance from the start node
                Node* currentNode = pq.top().second;
                pq.pop();

                // Stop if the end node is reached
                if (currentNode == endNode){
                    break;
                }

                // Loop through the outgoing edges of the current node
                for (Edge* edge : currentNode->outgoingEdges){
                    // Calculate the distance from the start node to the end node of the edge
                    int newDistance = distance[currentNode] + edge->weight;

                    // If the new distance is smaller than the current distance, update the distance and previous node
                    if (newDistance < distance[edge->endNode]){
                        distance[edge->endNode] = newDistance;
                        previous[edge->endNode] = currentNode;

                        // Push the updated distance and node into the priority queue 
                        pq.push(make_pair(newDistance, edge->endNode));
                    }
                }
            }

            // Reconstruct the shortest path from the previous node table
            vector<Node*> path;
            Node* currentNode = endNode;
            while (currentNode != nullptr){
                path.insert(path.begin(), currentNode);
                currentNode = previous[currentNode];
            }

            // Return the shortes path and its length
            return make_pair(path, distance[endNode]);
        }

    private:
        vector<Node*> nodes;
        vector<Edge*> edges;
    
};

int main(){
    
    Graph g;

    // Insert the nodes
    g.insertNode("A");
    g.insertNode("B");
    g.insertNode("C");
    g.insertNode("D");
    g.insertNode("E");
    g.insertNode("F");
    g.insertNode("G");
    g.insertNode("H");

    // Some references from this nodes
    Node* nodeA = g.getNode("A");
    Node* nodeB = g.getNode("B");
    Node* nodeC = g.getNode("C");
    Node* nodeD = g.getNode("D");
    Node* nodeE = g.getNode("E");
    Node* nodeF = g.getNode("F");
    Node* nodeG = g.getNode("G");
    Node* nodeH = g.getNode("H");


    // Insert some edges
    g.insertEdge(nodeA, nodeB, 47);
    g.insertEdge(nodeA, nodeC, 50);
    g.insertEdge(nodeA, nodeD, 12);
    g.insertEdge(nodeA, nodeF, 35);

    g.insertEdge(nodeB, nodeD, 78);
    g.insertEdge(nodeB, nodeE, 7);
    g.insertEdge(nodeB, nodeG, 22);

    g.insertEdge(nodeC, nodeF, 2);
    g.insertEdge(nodeC, nodeG, 91);

    g.insertEdge(nodeE, nodeF, 14);

    g.insertEdge(nodeF, nodeG, 15);
    g.insertEdge(nodeF, nodeH, 31);

    unordered_set<Node*> visited;

    // visit all nodes that can be acess from this nodeA
    g.DFS(nodeE, visited);

    cout << endl;

    // Shortest path
    pair<vector<Node*>, int> shortestPath_A_TO_F = g.dijkstra(nodeA, nodeF);
    for (Node* node : shortestPath_A_TO_F.first){
        cout << node->value << " ";
    }
    cout << endl;
    cout << "The range is: " << shortestPath_A_TO_F.second << endl;

    return 0;
}