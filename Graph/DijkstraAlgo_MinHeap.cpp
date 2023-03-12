// TC = E * logV


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
private:
    int Vertex;
    int Edges;
    vector<pair<int,int>>* adj;
public:
    Graph(int Vertex,int Edges);
    void CreateList();
    void displayAdjList();
    void dijkstraAlgo();
};

Graph::Graph(int Vertex,int Edges)
{
    this->Vertex = Vertex;
    this->Edges = Edges;
    this->adj = new vector<pair<int,int>> [Vertex];
}

void Graph:: CreateList()
{
    int x,y,w;
    cout<<"Enter Edges : "<<endl;
    cout<<"From -> To -> Weights : "<<endl;
    for(int i = 0;i< Edges;i++)
    {
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
}
void Graph :: displayAdjList()
{
    for(int i = 0;i<Vertex;i++)
    {
        cout<< i <<" : ";
        for(auto it : adj[i])
        {
            cout<<"("<<it.first<<" , "<<it.second<<") ";
        }
        cout<<endl;
    }
}
void Graph :: dijkstraAlgo()
{
    priority_queue< pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int>>> pq;
    vector<int> dist(Vertex,1e9);
    int src;
    cout<<"Enter source node : ";
    cin>>src;

    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node])
        {
            int edge_wt = it.second;
            int AdjNode = it.first;
            if(d + edge_wt  < dist[AdjNode])
            {
                dist[AdjNode] = d + edge_wt;
                pq.push({dist[AdjNode],AdjNode});
            }
        }
    }
    cout<<"Shortest Distance from  : "<<src <<" to"<<endl;
    for(int i=0;i<Vertex;i++)
    {
        cout<<i<<" : "<<dist[i]<<endl;
    }
}
           
int main()
{
    int V,E,node;
    cout<<"Enter Number of Vertex : ";
    cin>>V;
    cout<<"Enter Number of Edges : ";
    cin>>E;
    Graph obj = Graph(V,E);
    obj.CreateList();
    obj.displayAdjList();
    obj.dijkstraAlgo();
}
