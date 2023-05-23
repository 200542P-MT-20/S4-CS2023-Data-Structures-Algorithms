#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

// Function to find the MST using Prim's algorithm
void primMST(vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();

    vector<bool> visited(numNodes, false);
    vector<int> parent(numNodes, -1);
    vector<int> key(numNodes, INT_MAX);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Start with the given startNode
    pq.push(make_pair(0, startNode));
    key[startNode] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (int v = 0; v < numNodes; ++v) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree: ";
    for (int i = 0; i < numNodes; ++i) {
        if (i != startNode) {
            cout << "(" << parent[i] << "-" << i << ") ";
        }
    }
    cout << endl;
}

int main() {
    // Sample graph representation (adjacency matrix)
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int startNode = 0;

    // Find MST using Prim's algorithm
    primMST(graph, startNode);

    return 0;
}
