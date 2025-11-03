#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

struct Edge {
    int u, v, cost;
};

bool compare(Edge a, Edge b) {
    return a.cost < b.cost;
}

class DSU {
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int kruskalMST(int buildings, vector<Edge>& connections) {
    sort(connections.begin(), connections.end(), compare);
    DSU dsu(buildings);
    int totalCost = 0;

    cout << "\n🔗 Selected Connections:\n";
    for (auto& edge : connections) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            totalCost += edge.cost;
            cout << "Building " << edge.u << " ↔ Building " << edge.v << " → Cost: " << edge.cost << endl;
        }
    }

    return totalCost;
}

int main() {
    int buildings, edges;
    cout << "Enter number of buildings: ";
    cin >> buildings;

    cout << "Enter number of possible connections: ";
    cin >> edges;

    vector<Edge> connections;
    cout << "Enter each connection as: Building1 Building2 Cost\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, cost;
        cout << "Connection " << i + 1 << ": ";
        cin >> u >> v >> cost;
        connections.push_back({u, v, cost});
    }

    auto start = high_resolution_clock::now();
    int cost = kruskalMST(buildings, connections);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "\n📊 Total Cost to Connect Campus = " << cost << endl;
    cout << "⏱️ Execution Time: " << duration.count() << " microseconds" << endl;
    cout << "💾 Estimated Memory Used: " << buildings * sizeof(int) << " bytes" << endl;

    return 0;
}