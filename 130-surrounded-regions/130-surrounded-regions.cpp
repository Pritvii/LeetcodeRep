class Solution {
public:
    int visited[201][201];
    void dfs(vector<vector<char>>& board , int i , int  j , int m , int n )
    {
        visited[i][j] = 1;
        
        if(i + 1 <= m && i+1 >= 0 && j >=0 && j <= n && visited[i+1][j] == 0 && board[i+1][j] == 'O' )
            dfs(board , i+1 , j , m , n);
        
        if(i - 1 <= m && i-1 >= 0 && j >=0 && j <= n && visited[i-1][j] == 0 && board[i-1][j] == 'O' )
            dfs(board , i-1 , j , m , n);
        
        if(i  <= m && i >= 0 && j + 1 >=0 && j +1  <= n && visited[i][j+1] == 0 && board[i][j+1] == 'O' )
            dfs(board , i , j + 1 , m , n);
        
        if(i  <= m && i >= 0 && j - 1 >=0 && j - 1 <= n && visited[i][j - 1] == 0 && board[i][j -1] == 'O' )
            dfs(board , i , j -1 , m , n);
        
        return;
        
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        memset(visited , 0 , sizeof(visited));
        
        for(int i = 0 ; i < m ; i  ++)
        {
            for(int j = 0 ; j < n  ; j ++)
            {
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                    if(visited[i][j]==0 && board[i][j] == 'O')
                    {   cout<<i<<" "<<j<<endl;
                        dfs(board , i  , j  , m-1 , n-1 );
                    }
                }
            }
        }
        
        for(int i = 0  ; i < m ; i ++)
        {
            for(int  j = 0  ; j < n ; j ++)
            {
                if(visited[i][j] == 0 && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        
    }
};