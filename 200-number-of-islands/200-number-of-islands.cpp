class Solution {
public:
    int visited_arr[301][301];
    void dfs(vector<vector<char>>& matrix , int i , int j , int m , int n )
    {   
        visited_arr[i][j] = 1;
        
        if(i + 1 <= m && i + 1>= 0 && j <= n && j >= 0 && visited_arr[i+1][j]!=1 && matrix[i+1][j] == '1')
        {
            dfs(matrix , i+1 , j , m  , n);
        }
        if(i - 1 <= m && i - 1 >= 0 && j <= n && j >= 0 && visited_arr[i-1][j]!=1 && matrix[i-1][j] == '1')
        {
            dfs(matrix , i-1 , j , m  , n);
        }
        if(i  <= m && i >= 0 && j + 1 <= n && j + 1 >= 0 && visited_arr[i][j+1]!=1 && matrix[i][j+1]=='1')
        {
            dfs(matrix , i , j + 1 , m  , n );
        }
        if(i  <= m && i >= 0 && j - 1 <= n && j - 1 >= 0 && visited_arr[i][j-1]!=1 && matrix[i][j-1]=='1')
        {
            dfs(matrix , i, j-1 , m  , n );
        }
        
        return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        memset(visited_arr,0,sizeof(visited_arr));
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        //cout<<m<<" "<<n<<endl;
        for(int i = 0 ; i < m  ; i++)
        {
            for(int j = 0 ; j < n ; j ++)
            {   
                if(visited_arr[i][j] == 1 || grid[i][j] == '0')
                {
                    continue;
                }
                
                dfs(grid  , i , j , m - 1 , n - 1);
                ans++;   
               
    
               
            }
        }
        return ans;
    }
};