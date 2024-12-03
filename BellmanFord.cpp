#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

void relax(int u, int v, int w, int dis[])
{
    if (dis[v] > dis[u] + w)
    {
        dis[v] = dis[u] + w;
    }
}

void BellmanFord(vector<Edge> &G, int n)
{
    int dis[n];
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;

    // Relax all edges (n-1) times
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : G)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (dis[u] != INT_MAX && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
            
        }
        cout << "Iteration : " << i << endl;
        for (int j = 0; j < n; j++)
        {
            if (dis[j] == INT_MAX)
            {
                cout << "0 - " << j << " = INF" << endl; // For unreachable vertices
            }
            else
            {
                cout << "0 - " << j << " = " << dis[j] << endl;
            }
        }
    }

    // Check for negative weight cycle
    bool negativeCycle = false;
    for (auto edge : G)
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (dis[v] > dis[u] + w)
        {
            negativeCycle = true;
            break;
        }
    }

    // Output the result
    if (negativeCycle)
    {
        cout << "No Solution" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (dis[i] == INT_MAX)
            {
                cout << "0 - " << i << " = INF" << endl; // For unreachable vertices
            }
            else
            {
                cout << "0 - " << i << " = " << dis[i] << endl;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> G(e);

    // Read graph edges
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge ed;
        ed.u = u;
        ed.v = v;
        ed.w = w;
        G.push_back(ed); // Only add the directed edge (u -> v)
    }

    // Run Bellman-Ford
    BellmanFord(G, n);

    return 0;
}
