#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define a pair for (distance, vertex)
typedef pair<int, int> pii;

void dijkstra(int start, vector<vector<pii>>& graph, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Visit all adjacent nodes
        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step
            if (currDist + weight < dist[v]) {
                dist[v] = currDist + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> graph(V);
    vector<int> dist(V, INT_MAX);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // Remove this line for directed graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    dijkstra(start, graph, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To " << i << " -> " << dist[i] << "\n";
    }

    return 0;
}
