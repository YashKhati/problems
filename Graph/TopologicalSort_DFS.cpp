//Code Studio
#include<unordered_map>
#include<stack>
#include<list>
void toposort(int i,vector<bool>& visited,stack<int>& st, unordered_map<int,list<int>>& adj)
{
    visited[i]=true;
    for(auto it : adj[i])
    {
        if(!visited[it])
        {
            toposort(it,visited,st,adj);
        }
    }
    st.push(i);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   
   unordered_map<int,list<int>> adj;
   for(int i=0;i<edges.size();i++)
   {
       int u = edges[i][0];
       int v = edges[i][1];
       adj[u].push_back(v);
   }

    vector<bool> visited(v,false);
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            toposort(i,visited,st,adj);
        }
    }

   vector<int> ans;
   while(!st.empty())
   {
       ans.push_back(st.top());
       st.pop();
   }
    return ans;

}
