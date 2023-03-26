
// Count Strongly Connected Component

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Kosaraju
{
private:
    int Vertex;
    int Edges;
    stack<int> st;
    vector<int>* adj;
public:
    Kosaraju(int Vertex,int Edges);
    void CreateList();
    void displayAdjList();
    void dfs(int node,vector<bool>& vis);
    void ApplyKosaraju(); 
    void dfs_Component(int node,vector<bool>& vis,vector<int> adj[]);
};

Kosaraju::Kosaraju(int Vertex,int Edges)
{
    this->Vertex = Vertex;
    this->Edges = Edges;
    this->adj = new vector<int> [Vertex];
}

void Kosaraju:: CreateList()
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

void Kosaraju :: displayAdjList()
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

void Kosaraju::dfs(int node,vector<bool>& vis)
{
    vis[node] = true;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis);
        }
    }
    st.push(node);
}

void Kosaraju::ApplyKosaraju()
{
    vector<bool> vis(Vertex,false);

    for(int i=0;i<Vertex;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis);
        }
    }

    vector<int> new_adj[Vertex];
    for(int i=0;i<Vertex;i++)
    {
        vis[i]=false;
        for(auto it: adj[i])
        {
            new_adj[it].push_back(i);
        }
    }
    int cnt = 0;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(!vis[node])
        {
            cnt++;
            dfs_Component(node,vis,new_adj);
        }
    }
    cout<<"Strongly Connected Component : "<<cnt<<endl;
}         

void Kosaraju::dfs_Component(int node,vector<bool>& vis,vector<int> adj[])
{
    vis[node]=true;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs_Component(it,vis,adj);
        }
    }
}
int main()
{
    int V,E,node;
    cout<<"Enter Number of Vertex : ";
    cin>>V;
    cout<<"Enter Number of Edges : ";
    cin>>E;
    Kosaraju obj = Kosaraju(V,E);
    obj.CreateList();
    obj.displayAdjList();
    obj.ApplyKosaraju();
    
}
