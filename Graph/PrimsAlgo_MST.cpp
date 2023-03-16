#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
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
    void PrimsAlgo();
    void printMst();
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
void Graph :: PrimsAlgo()
{
    // visited array
    vector<int>vis (Vertex,0);

    // priority queue to get smallest weight 
    // pair<weight,node>
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

    // sum to calculate MST edge weight
    int sum = 0;


    pq.push({0,0});

    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;
        if(vis[node]==1)
        {
            continue;
        }

        vis[node] = 1;
        sum += wt;
        for(auto itr : adj[node])
        {
            int adjNode = itr.first;
            int edw = itr.second;

            if(!vis[adjNode])
            {
                pq.push({edw,adjNode});
            }
        }
    }

    cout<<"Weight of mst : " <<sum<<endl; 
}
           
void Graph  ::printMst()
{

    vector<pair<int,int>> mst;
    // visited array
    vector<int>vis (Vertex,0);

    // priority queue to get smallest weight 
    // pair<weight,node,parent>
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;

    // sum to calculate MST edge weight
    int sum = 0;


    pq.push({0,{0,-1}});

    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int node = it.second.first;
        int wt = it.first;
        int parent = it.second.second;

        if(vis[node]==1)
        {
            continue;
        }

        vis[node] = 1;
        sum += wt;
        mst.push_back({node,parent});

        for(auto itr : adj[node])
        {
            int adjNode = itr.first;
            int edw = itr.second;

            if(!vis[adjNode])
            {
                pq.push({edw,{adjNode,node}});
            }
        }
    }

    sort(mst.begin() , mst.end() , [&] (auto& a, auto& b)
    {
        return a.second < b.second;
    });

    cout<<"From -> To "<<endl;
    for(auto it : mst)
    {
        cout<<it.second<<" "<<it.first<<endl;
    }
    cout<<endl;
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
    obj.PrimsAlgo();
    obj.printMst();
}
