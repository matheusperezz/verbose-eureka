#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    public:
        int V, E;
        vector<Edge> edges;

        Graph(int v, int e){
            V = v;
            E = e;
        }

        void addEdge(int u, int v, int w){
            Edge edge = {u, v, w};
            edges.push_back(edge);
        }

        void bellmanFord(int src){
            vector<int> dist(V, INT_MAX);
            
            dist[src] = 0;

            for (int i = 1; i < V; i++){
                for(int j = 0; j < E; j++){
                    int u = edges[j].src;
                    int v = edges[j].dest;
                    int weight = edges[j].weight;

                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                        dist[v] = dist[u] + weight;
                    }
                }
            }

            for (int i = 0; i < E; i++){
                int u = edges[i].src;
                int v = edges[i].dest;
                int weight = edges[i].weight;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                    cout << "O grafo contém um ciclo negativo" << endl;
                    return;
                }
            }

            cout << "Vertice \t Distancia a partir de " << src << endl;
            for (int i = 0; i < V; i++){
                cout << i << "\t\t" << dist[i] << endl;
            }

        }
};

int main(){

    Graph graph(5, 8);
    graph.addEdge(0, 1, -1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 2);
    graph.addEdge(3, 2, 5);
    graph.addEdge(3, 1, 1);
    graph.addEdge(4, 3, -3);

    graph.bellmanFord(0);

    return 0;
}