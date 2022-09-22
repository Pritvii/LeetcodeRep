class Solution {
public:
    
    bool is_ok(int i , int j ,  int m , int n )
    {
        if(i>=0 && i < m && j >= 0 && j < n)
            return true;
        return false;
    }
    
    int dfs(int i , int j , vector<vector<bool>>& visited , int m , int  n ,vector<vector<int>>& grid )
    {   //cout<<i<< " "<<j<<endl;
        if(visited[i][j] == true)
            return 0;
        
        
        visited[i][j] = true;
        grid[i][j] = 0;
        
        int ans = 1 ;
        vector<pair<int , int >> neighbour;
        if(is_ok( i-1 , j , m , n) && grid[i-1][j] == 1 && visited[i-1][j] == false)
            neighbour.push_back({i-1 , j});
        if(is_ok( i , j-1 , m , n) && grid[i][j-1] == 1 && visited[i][j-1] == false)
            neighbour.push_back({i , j-1});
        if(is_ok( i+1 , j , m , n) && grid[i+1][j] == 1 && visited[i+1][j] == false)
            neighbour.push_back({i+1 , j});
        if(is_ok( i, j+1 , m , n) && grid[i][j+1] == 1 && visited[i][j+1] == false)
            neighbour.push_back({i , j + 1});
        
        for(pair<int,int> x : neighbour)
        {
            ans += dfs(x.first , x.second , visited , m , n , grid);
        }
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m  = grid.size();
        int n  = grid[0].size();
        vector<vector<bool>> visited;
        
        for(int i = 0 ; i < m ; i  ++)
        {   vector<bool> x;
            for(int j = 0 ; j < n ; j ++)
            {
                x.push_back(false);
            }
            visited.push_back(x);
        }
        
        int ans = 0;
        for(int i = 0 ; i  < m ; i ++)
        {
            for(int j = 0 ; j < n  ; j ++)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                {   //cout<<i<<" "<<j<<endl;
                    //visited[i][j] = true;
                    ans = max(ans , dfs(i , j , visited , m , n , grid));
                    cout<<ans<<endl;
                }
            }
        }
        
        return ans;
    }
};