#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class DFS_Traversal
{
private:
    int Vertex;
    int Edges;
    vector<int>* adj;
public:
    DFS_Traversal(int Vertex,int Edges);
    void CreateList();
    void displayAdjList();
    bool isCycle();
    bool detectCycle(int node,int vis[],int pathVis[]);
};

DFS_Traversal::DFS_Traversal(int Vertex,int Edges)
{
    this->Vertex = Vertex;
    this->Edges = Edges;
    this->adj = new vector<int> [Vertex];
}

void DFS_Traversal:: CreateList()
{
    int x,y;
    cout<<"Enter Edges : "<<endl;
    cout<<"From -> To  : "<<endl;
    for(int i = 0;i< Edges;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }
}

void DFS_Traversal :: displayAdjList()
{
    for(int i = 0;i<Vertex;i++)
    {
        cout<< i <<" : ";
        cout<<"{"; 
        for(auto it : adj[i])
        {
            cout<<it<<" ";
        }
        cout<<"}";
        cout<<endl;
    }
}

bool DFS_Traversal :: isCycle()
{
    int visited[Vertex]={0};
    int pathVisited[Vertex]={0};
    for(int i =0;i<Vertex;i++)
    {
        if(!visited[i])
        {
            if(detectCycle(i,visited,pathVisited)==true)
                return true;
        }
    }
    return false;
}

bool DFS_Traversal ::detectCycle(int node,int vis[],int pathVis[])
{
    vis[node]=1;
    pathVis[node]=1;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            if(detectCycle(it,vis,pathVis)==true)
                return true;
        }
        else if(pathVis[it])
        {
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}
int main()
{
    int V,E,node;
    cout<<"Enter Number of Vertex : ";
    cin>>V;
    cout<<"Enter Number of Edges : ";
    cin>>E;
    DFS_Traversal obj = DFS_Traversal(V,E);
    obj.CreateList();
    obj.displayAdjList();
    if(obj.isCycle())
    {
        cout<<"Cycle Present";
    }
    else
    {
        cout<<"Cycle Not present";
    }
}
