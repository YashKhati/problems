#include <bits/stdc++.h> 
bool BipartiteMatch(vector<vector<int>> &mat,int u,vector<bool> &vis,vector<int> &job)
{
    for(int v=0;v<mat[0].size();v++)
    {
        if(mat[u][v]==0 || vis[v])
        {
            continue;
        }
        vis[v]=true;
        if(job[v] < 0 || BipartiteMatch(mat,job[v],vis,job))
        {
            job[v]=u;
            return true;
        }
    }
    return false;
}
int maxMatch(vector<vector<int> > &mat) 
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> job(n,-1);
    int match = 0;
    for(int u=0;u<m;u++)
    {   
        vector<bool> visited(n,false);
        if(BipartiteMatch(mat,u,visited,job))
        {
            match++;
        }
    }    
    return match;
}
