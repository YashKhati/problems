// Cycle Detection in Directed Graph

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
        bool isCycle()
        {
            int count=0;
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
                count++;
                for(auto it : adj[node])
                {
                    indegree[it]--;  
                    if(indegree[it]==0)
                    {
                        Queue.push(it);
                    }
                }
            }
            if(count==vertices)
                return false;
            else    
                return true;
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
    if(T.isCycle())
        cout<<"Cycle Present";
    else
        cout<<"Cycle Not Present";
}
