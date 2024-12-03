#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w;

    bool operator<(const edge& e) const {
        return w < e.w;
    }
};

void Prims(vector<edge> &graph,int vertices)
{
    int dis[vertices+1];
    int visited[vertices+1];
    for(int i=1; i<= vertices; i++)
    {
        dis[i]=INT_MAX;
        visited[i]=0;

    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    dis[1]=0;
    visited[1]=1;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(auto edges: graph)
        {
            int uV = edges.u;
            int v = edges.v;
            int w = edges.w;
            if(uV==u && dis[v]> w&& !visited[v])
            {
                dis[v]=w;
                pq.push({w,v});
            }
        }
        visited[u]=1;
    }
    int sum =0; 
      for(int i=1; i<=vertices; i++)
    {
        cout<<dis[i]<<" ";
        sum=sum+dis[i];
    }
    cout<<"Minimum MST is : "<<sum<<endl;
    
}

int main()
{
    int vertices, edges;
    cin>>vertices>>edges;
    vector<edge> graph(vertices+1);
    for(int i=1; i<=edges; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[i].u = u;
        graph[i].v = v;
        graph[i].w = w;
    }

    Prims(graph,vertices);
  
    return 0;
}