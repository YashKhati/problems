class Solution {
public:
   
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size(); 
        vector<int> isVisited(n,0);
        int count = 0;
      
        for(int i=0; i<n; i++)
        {
            if(!isVisited[i])
            {
                count ++;
                queue<int> que;
                que.push(i);
                isVisited[i] = 1;
                
                while(!que.empty())
                {
                    int top = que.front();
                    que.pop();
                    
                    for(int j=0; j<n; j++){
                        if(isConnected[top][j] && isVisited[j] == 0){
                            que.push(j);
                            isVisited[j] = 1;
                        }
                    }
                }
            }
        }
        return count;
    }
};



//----------------------------------------------------------------------------------------------------


class Solution {
public:
    void dfs(vector<vector<int>> isConnected,vector<int> &vis,int curr)
    {
        vis[curr]=1;
        for(int i=0;i<isConnected.size();i++)
        {
            if(isConnected[curr][i]==1 && vis[i]==0)
            {
                dfs(isConnected,vis,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]== 0 )
            {
                count++;
                dfs(isConnected,vis,i);
            }
        }
        return count;
    }
};

// ---------------------------------------------------------------------------
// Using Disjoint set


class Solution {
public:
    vector<int> parent;
        int findUParent(int node)
        {
            if(parent[node] == node)
                return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionOfAccounts(int u, int v)
        {
            u = findUParent(u);
            v = findUParent(v);
            if(u != v)
                parent[v] = u;

        }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j])
                {
                    unionOfAccounts(i,j);
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                count++;
        }
        return count;
    }
};
