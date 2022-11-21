class Solution {
public:
  void DFS(vector<vector<char>>& board, int i, int j)
  {
        if(i<0 or j<0 or i>=board.size() or j>=board[0] .size() or board[i][j] != 'O')
            return;
      
        board[i][j] = '1';
        DFS(board, i-1, j);
        DFS(board, i+1, j);
        DFS(board, i, j-1);
        DFS(board, i, j+1);
    }
    
    void solve(vector<vector<char>>& board) 
    {
        
        int rows = board.size(); 
        int cols = board[0].size();
        
        for(int i=0;i<cols;i++)  // check top row 
        {
            if(board[0][i]=='O')
                DFS(board,0,i);
        }
     
        for(int i=0;i<cols;i++)   // check bottom row
        {
            if(board[rows-1][i]=='O')
                DFS(board,rows-1,i);
        } 
        
        for(int i=0;i<rows;i++)   // leftmost  column
        {
            if(board[i][0]=='O')
                DFS(board,i,0);
        }
     
        for(int i=0;i<rows;i++)   // rightmost  column
        {
            if(board[i][cols-1]=='O')
                DFS(board,i,cols-1);
        }   
        
        for(int i=0; i<rows; i++)
        {
             for(int j=0; j<cols; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }    
    }
};
