class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int , int >  , int > > qu;
        vector<vector<int>> visited;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i =0 ; i < m ; i ++)
        {   vector<int> temp;
            for(int j =0 ; j  < n ; j ++)
            {
                temp.push_back(0);
            }
         visited.push_back(temp);
        }
        
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j  < n ; j ++)
            {
                if(grid[i][j] == 2)
                {
                    qu.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        
        int ans = 0 ;
        
        while(!qu.empty())
        {
            pair<pair<int  , int > , int > x;
            x = qu.front();
            qu.pop();
            int curr = x.second;
            ans = max(ans , x.second);
            
            int i = x.first.first;
            int j = x.first.second;
            
            if(i + 1 >= 0 && i + 1 < m && j >= 0 && j < n && visited[i+1][j] == 0 && grid[i+1][j] == 1)
            {
                visited[i+1][j] = 1;
                grid[i+1][j] = 2;
                qu.push({{i+1 , j},curr + 1});
            }
            if(i - 1 >= 0 && i - 1 < m && j >= 0 && j < n && visited[i-1][j] == 0 && grid[i-1][j] == 1)
            {
                visited[i-1][j] = 1;
                grid[i-1][j] = 2;
                qu.push({{i-1 , j},curr + 1});
            }
            if(i  >= 0 && i  < m && j + 1>= 0 && j + 1 < n && visited[i][j+1] == 0 && grid[i][j+1] == 1)
            {
                visited[i][j+1] = 1;
                grid[i][j + 1] = 2;
                qu.push({{i , j + 1},curr + 1});
            }
            if(i  >= 0 && i  < m && j - 1 >= 0 && j - 1 < n && visited[i][j - 1] == 0 && grid[i][j - 1] == 1)
            {
                visited[i][j - 1] = 1;
                grid[i][j-1] = 2;
                qu.push({{i , j - 1},curr + 1});
            }
            
        }
        
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return ans;
        
    }
};