#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<int>>& graph, int source, vector<int>& distances) {
    int n = graph.size(); // Number of vertices

    // Initialize the distances with a large value except for the source
    distances.assign(n, numeric_limits<int>::max());
    distances[source] = 0;

    // Create a priority queue to store vertices
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Add the source vertex to the priority queue
    pq.push({ 0, source });

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        int u = current.second;
        int dist = current.first;

        // Skip the vertex if we have already found a better distance
        if (dist > distances[u])
            continue;

        // Traverse the neighbors of the current vertex
        for (int v = 0; v < n; v++) {
            int weight = graph[u][v];

            // Relax the edge if a shorter path is found
            if (weight != 0 && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({ distances[v], v });
            }
        }
    }
}

// Function to find the maximum distance in the given distances vector
int findMaxDistance(const vector<int>& distances) {
    int maxDistance = 0;
    for (int distance : distances) {
        if (distance > maxDistance)
            maxDistance = distance;
    }
    return maxDistance;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int numCities = graph.size();

    int source;
    cout << "Enter the source city (0-" << numCities - 1 << "): ";
    cin >> source;

    vector<int> distances;
    dijkstra(graph, source, distances);

    cout << "Shortest time between source city and all other cities:\n";
    for (int i = 0; i < distances.size(); i++) {
        cout << "City " << source << " to City " << i << ": " << distances[i] << endl;
    }

    int maxDistance = findMaxDistance(distances);
    cout << "Maximum distance from the source city: " << maxDistance << endl;

    return 0;
}
