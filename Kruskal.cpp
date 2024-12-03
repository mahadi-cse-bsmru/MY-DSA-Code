#include<bits/stdc++.h>
using namespace std;
struct Edge{

int u,v,weight;

bool operator<(const Edge& e) const {
        return weight < e.weight;
    }
};
void makeset(vector<Edge> & edges,int parent[],int rank[],int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;

    }
}
int find(int parent[],int x)
{
    if(parent[x]!=x)
    {
        parent[x] = find(parent, parent[x]); 
    }
    return parent[x];
}
void unionSet(int parent[] ,int rank[], int u,int v)
{
    int parU = find(parent,u);
    int parV = find(parent,v);
    if(parU!=parV)
    {
        if(rank[u]>rank[v])
        {
            parent[parV]=parU;
        }
        else if(rank[u]<rank[v])
        {
            parent[parU]=parV;
        }
        else 
        {
            parent[parV]=parU;
            rank[parU]++;
        }
    }
}
void kruskal(vector<Edge> &edges,int n)
{
    sort(edges.begin(),edges.end());
    int parent[n];
    int rank[n];

    makeset(edges,parent,rank,n);
    vector<Edge>mst;
    int minST=0;
    for(auto edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        if(find(parent,u)!=find(parent,v))
        {
            unionSet(parent,rank,u,v);
            mst.push_back(edge);
            minST+=edge.weight;
        }
    }
    for(auto edge:mst)
    {
        cout<<edge.u<<" - "<<edge.v<<" = "<<edge.weight<<endl;
    }
    cout<<"Total cost: "<<minST;


}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge>edges(e);
    for(int i=0; i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges[i].u=u;
        edges[i].v=v;
        edges[i].weight=w;

    }
    kruskal(edges,n);
    return 0;
}