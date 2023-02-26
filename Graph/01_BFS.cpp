#include<iostream>
#include<vector>
#include<deque>
#include<limits.h>
using namespace std;
class BFS_ZeroOne
{
    private :
        int edges;
        int vertices;
        vector<pair<int,int>>* adj;

    public:
        BFS_ZeroOne(int e,int v)
        {
            this->edges = e;
            this->vertices = v;
            adj = new vector<pair<int,int>>[v];
        }
        void CreateList()
        {
            int x,y,w;
            cout<<"Enter Edges :"<<endl;
            cout<<"From -> To  -> Weight"<<endl;
            for(int i = 0;i< edges;i++)
            {
                cin>>x>>y>>w;
                adj[x].push_back({y,w});
                adj[y].push_back({x,w});
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
                    cout<<"("<<it.first<<" , "<<it.second<<")"<<"  ;  "; 
                }
                cout<<endl;
            }
        }
        
        void search(int start)
        {
            deque<int> dq;
            vector<int> distance(vertices,INT_MAX);
            dq.push_back(start);
            distance[start] = 0;
            while(!dq.empty())
            {
                int v = dq.front();
                dq.pop_front();
                for(auto it : adj[v])
                {   
                    if(distance[it.first] > distance[v]+it.second)
                    {
                        distance[it.first] = distance[v]+ it.second;
                      
                        if(it.second == 0)
                        {
                            dq.push_front(it.first);
                        }
                        else
                        {
                            dq.push_back(it.first);
                        }
                    }
                }
            }
            for(int i=0;i<vertices ;i++)
            {
                cout<<"Distance from "<<start<<" to "<<i<<": "<<distance[i]<<endl;
            }
        }

        void BFS()
        {
            int start;
            cout<<"Enter starting node of BFS search : ";
            cin>>start;
            search(start);
           
        }
        

};
int main()
{
    int E,V;
    cout<<"Enter number of Edges : ";
    cin>>E;
    cout<<"Enter number of Vertices : ";
    cin>>V;

    BFS_ZeroOne obj =  BFS_ZeroOne(E,V);
    obj.CreateList();
    obj.displayAdjList();
    obj.BFS();
}
