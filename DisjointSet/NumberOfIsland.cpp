// GFG

//https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands

// User function Template for C++
class DisjointSet
{
    public : 
    vector<int> rank,size,parent;
    
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        rank.resize(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void unionRank(int u,int v)
    {
        int up = findParent(u);
        int vp = findParent(v);
        if(up==vp)
            return;
        if(rank[up] < rank[vp])
        {
            parent[up] = vp;
        }
        else if(rank[up] > rank[vp])
        {
            parent[vp]=up;
        }
        else
        {
            parent[vp] = up;
            rank[up]++;
        }
    }
    
    
    void unionSize(int u,int v)
    {
        int up = findParent(u);
        int vp = findParent(v);
        if(up==vp)
            return;
        if(size[up] < size[vp])
        {
            parent[up] = vp;
            size[vp]  += size[up];
        }
        else
        {
            parent[vp]=up;
            size[up] += vp;
        }
    }
};

class Solution {
  public:
    bool isValid(int r ,int c , int n ,int m)
    {
        return (r  >= 0  && r<n) && (c >= 0  && c<m) ;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0, sizeof(vis));
        
        int cnt = 0;
        vector<int> ans;
        
        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1) 
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            
            int delr[] = {-1,0,1,0};
            int delc[] = {0,1,0,-1};
            
            for(int i=0 ;i < 4;i++)
            {
                 int adjr = row + delr[i];
                 int adjc = col + delc[i];
                 
                 if(isValid(adjr , adjc , n , m))
                 {
                     if(vis[adjr][adjc] == 1)
                     {
                         int node = row * m +col;
                         int adjNode = adjr * m + adjc;
                         if(ds.findParent(node) != ds.findParent(adjNode))
                         {
                             cnt--;
                             ds.unionSize(node,adjNode);
                         }
                     }
                 }
            }
             ans.push_back(cnt);
        }
        
        
        
        
        
        return ans;
    }
};
