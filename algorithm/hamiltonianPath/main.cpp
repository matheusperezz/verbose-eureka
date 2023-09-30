#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // infinite

int n; // number of vertices
vector<vector<int>> graph;
vector<bool> visited;
vector<int> path;
int cost;

void findHamiltonianPath(int start)
{
    visited.assign(n, false); // init the visited vectors
    path.clear();             // clear the hamiltonian path
    cost = 0;                 // total cost

    path.push_back(start); // add the first vertice in path
    visited[start] = true; // mark the first vertice as visited

    for (int i = 0; i < n - 1; i++)
    {
        int last = path.back();
        int next = -1;
        int dist = INF;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && graph[last][j] < dist)
            {
                next = j;
                dist = graph[last][j];
            }
        }

        if (next == -1)
        {
            return;
        }

        path.push_back(next);
        visited[next] = true;
        cost += dist;
    }
}

int main()
{

    n = 5;
    graph.assign(n, vector<int>(n, INF));

    graph[0][1] = 2;
    graph[0][2] = 1;
    graph[0][3] = 3;
    graph[0][4] = 4;
    graph[1][2] = 4;
    graph[1][3] = 2;
    graph[1][4] = 3;
    graph[2][3] = 5;
    graph[2][4] = 2;
    graph[3][4] = 3;

    // find the hamiltonian path from vertice 0
    findHamiltonianPath(4);

    cout << "Hamiltonian Path: ";
    for (int i : path)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}