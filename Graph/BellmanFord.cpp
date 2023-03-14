// TC = V*E

#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Graph
{
private:
    int Vertex;
    int Edges;
    vector<vector<int>>* adj;
public:
    Graph(int Vertex,int Edges);
    void CreateList();
    void displayAdjList();
    void bellmanFord();
};

Graph::Graph(int Vertex,int Edges)
{
    this->Vertex = Vertex;
    this->Edges = Edges;
    this->adj = new vector<vector<int>>();
}

void Graph:: CreateList()
{
    int x,y,w;
    cout<<"Enter Edges : "<<endl;
    cout<<"From -> To -> Weights : "<<endl;
    for(int i = 0;i< Edges;i++)
    {
        cin>>x>>y>>w;
        adj->push_back({x,y,w});
    }
}
void Graph :: displayAdjList()
{
    for(auto row : *adj )
    {
        cout<<"("<<row[0]<<" , "<<row[1]<<" , "<<row[2]<<" ) "<<endl;
    }
}
void Graph :: bellmanFord()
{
    // Enter Source Node To Start
    int S;
    cout<<"Enter Source node : ";
    cin>>S;

    vector<int> dist(Vertex,1e8);
    dist[S]=0;
    // run updation loop for V-1 times
    for(int i=0;i<Vertex-1;i++)
    {
        for(auto it : *adj)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]+wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            } 
        }
    }

    // Nth relaxation to check -ve cycle in graph
     for(auto it : *adj)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u]+wt < dist[v])
            {
                cout<<"-ve cycle present "<<endl;
                return ;
            } 
        }

    for(int i=0;i<dist.size();i++)
    {
        cout<<"distance of "<<i<<" from "<<S<<" : "<<dist[i]<<endl;
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
    obj.bellmanFord();
}
