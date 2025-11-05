#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>
using namespace std;

const int INF = numeric_limits<int>::max();

// Dijkstra's algorithm using adjacency list and min-heap
void dijkstra(int V, vector<vector<pair<int, int>>> &adj, int source, vector<string> &locations) {
    vector<int> dist(V, INF);
    dist[source] = 0;

    // Min-heap priority queue: (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();

        if (d_u > dist[u]) continue;

        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Output shortest distances
    cout << "\n📍 Shortest distances from " << locations[source] << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To " << locations[i] << ": ";
        if (dist[i] == INF)
            cout << "Unreachable\n";
        else
            cout << dist[i] << " units\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of locations and roads: ";
    cin >> V >> E;

    vector<string> locations(V);
    cout << "Enter location names:\n";
    for (int i = 0; i < V; ++i) {
        cout << "Location " << i << ": ";
        cin >> ws;
        getline(cin, locations[i]);
    }

    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter roads (from to distance):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // Bidirectional roads
    }

    int source;
    cout << "Enter source location index: ";
    cin >> source;

    dijkstra(V, adj, source, locations);

    return 0;
}