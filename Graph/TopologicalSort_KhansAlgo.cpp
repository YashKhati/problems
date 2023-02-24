#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Topo_Sort
{
    private :
        int edges;
        int vertices;
        vector<int>* adj;

    public:
        Topo_Sort(int e,int v)
        {
            this->edges = e;
            this->vertices = v;
            adj = new vector<int>[v];
        }
        void CreateList()
        {
            int x,y;
            cout<<"Enter Edges  :"<<endl;
            for(int i = 0;i<edges ;i++)
            {
                cin>>x>>y;
                adj[x].push_back(y);
            }
        }
        void displayAdjList()
        {
            cout<<"Adjacency List : "<<endl;
            for(int i=0;i<vertices;i++)
            {
                cout<<i << " : ";
                for(auto it : adj[i])
                {
                    cout<<it<<" ";
                }
                cout<<endl;
            }
        }
        void toposort()
        {
            int indegree[vertices]={0};
            for(int i =0; i <vertices;i++)
            {
                for(auto it : adj[i])
                {
                    indegree[it]++;
                }
            }
            queue<int> Queue;
            for(int i=0;i<vertices;i++)
            {
                if(indegree[i]==0)
                {
                    Queue.push(i);
                }
            }
            while(!Queue.empty())
            {
                int node  = Queue.front();
                Queue.pop();
                cout<<node<<" ";
                for(auto it : adj[node])
                {
                    indegree[it]--;  
                    if(indegree[it]==0)
                    {
                        Queue.push(it);
                    }
                }
            }
        }

};
int main()
{
    int E,V;
    cout<<"Enter number of Edges : ";
    cin>>E;
    cout<<"Enter number of Vertices : ";
    cin>>V;

    Topo_Sort T =  Topo_Sort(E,V);
    T.CreateList();
    T.displayAdjList();
    T.toposort();
}
