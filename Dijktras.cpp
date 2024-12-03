#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &e) const {
        return w < e.w;  // To help with sorting in case you need sorting, but not strictly required in Dijkstra.
    }
};

void Dijkstra(vector<Edge> edges, int n) {
    vector<int> dis(n, INT_MAX);  // Distance array
    vector<int> visited(n, 0);    // Visited array
    dis[0] = 0;                   // Starting point

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});  // Starting from node 0 with distance 0

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();  // Pop the top element

        if (visited[u]) continue;  // If already visited, skip

        visited[u] = 1;  // Mark node as visited after popping

        // Process all edges from the node u
        for (auto edge : edges) {
            if (edge.u == u) {
                int v = edge.v;
                // Relaxation step
                if (dis[v] > dis[u] + edge.w && !visited[v]) {
                    dis[v] = dis[u] + edge.w;
                    pq.push({dis[v], v});  // Push the new distance to the priority queue
                }
            }
        }
    }

    // Output the shortest distance for each node
    for (int i = 0; i < n; i++) {
        cout <<"0"<<" -> "<< i << " = " << dis[i] << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;  // Number of nodes (n) and number of edges (e)
    vector<Edge> edges(e);  // Correct initialization of the edge list

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;  
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }

    Dijkstra(edges, n);  

    return 0;
}
