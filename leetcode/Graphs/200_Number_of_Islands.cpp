class Solution {
public:
   void searchSurrounding(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j)
    {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j< 0 || grid[i][j]!='1' || vis[i][j]==1 )
        {
            return;
        }
        vis[i][j]=1;
        searchSurrounding(grid,vis,i+1,j); // down
        searchSurrounding(grid,vis,i,j+1); // right
        searchSurrounding(grid,vis,i-1,j); //  up
        searchSurrounding(grid,vis,i,j-1); // left
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int row=grid.size();
        int col = grid[0].size();
        int count=0;
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    // vis[i][j]=1;
                    searchSurrounding(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
        
    }
};


class Solution {
public:
   void searchSurrounding(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j)
    {
       
        vis[i][j]=1;
        vector<int> del_row={-1,0,1,0};
        vector<int> del_col={0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int new_row = i+del_row[k];
            int new_col = j+del_col[k];
            if(new_col >= 0 && new_row >= 0 && new_col < grid[0].size() && new_row < grid.size() && grid[new_row][new_col] == '1' && vis[new_row][new_col] ==0)
            {
                 searchSurrounding(grid,vis,new_row,new_col);
            }
                
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int row=grid.size();
        int col = grid[0].size();
        int count=0;
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    searchSurrounding(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
        
    }
};
