class DisjointSet
{
    vector<int> parent,minWt;
    public : 
        DisjointSet(int n)
        {
            parent.resize(n+1);
            minWt.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
                minWt[i] = INT_MAX;
            }
        }

        int findUparent(int node)
        {
            return (parent[node] == node) ? node : (parent[node] = findUparent(parent[node]));
        }

        bool find(int u ,int v)
        {
            return findUparent(u) == findUparent(v);
        }

        void UnionNode(int u,int v,int w)
        {
            int up = findUparent(u);
            int vp = findUparent(v);
            parent[vp] = up;
            minWt[up] = min({minWt[up] , minWt[vp] , w});
        }
        int minDist(int u,int v)
        {
            return min(minWt[findUparent(u)], minWt[findUparent(v)]);
        }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);      
        for(auto it : roads)
        {
            ds.UnionNode(it[0],it[1],it[2]);
        }
        return ds.minDist(1,n);
    }
};
