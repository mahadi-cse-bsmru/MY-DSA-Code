#include <bits/stdc++.h>
using namespace std;

void prim(vector<vector<pair<int, int>>> &graph, vector<int> &key, vector<int> &par, vector<int> &visited, int start)
{
    // Initialize key values and set all nodes as not visited

    for (int i = 1; i <= graph.size(); i++)
    {
        key[i] = INT_MAX;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    key[start] = 0;  // Starting from vertex 1
    par[start] = -1; // No parent for the first node

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // Traverse neighbors of node u
        for (auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v] && weight < key[v])
            {
                key[v] = weight;
                par[v] = u;
                pq.push({key[v], v});
            }
        }
        visited[u] = 1;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    // Create an adjacency list to represent the graph
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX); // To store minimum weight of the edges
    vector<int> par(n + 1, -1);      // To store parent of each vertex
    vector<int> visited(n + 1, 0);   // To track visited vertices

    int start;
    cin >> start;
    prim(graph, key, par, visited, start);

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + key[i];
    }

    cout << sum << endl;

    return 0;
}
