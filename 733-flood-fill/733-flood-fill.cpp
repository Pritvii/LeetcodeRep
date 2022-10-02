class Solution {
public:
    void dfs(vector<vector<int>>& image,  int color , int prev , int m , int n ,  int i , int j , vector<vector<int>>&visited)
    {
        image[i][j] = color;
        visited[i][j] = 1;
        if(i + 1 <= m && i + 1 >=0 && j <= n && j >= 0 && visited[i+1][j] == 0 && image[i+1][j] == prev)
            dfs(image , color , prev , m , n ,i + 1 , j , visited);
        
        if(i - 1 <= m && i - 1 >=0 && j <= n && j >= 0 && visited[i-1][j] == 0 && image[i-1][j] == prev)
            dfs(image , color , prev , m , n ,i - 1 , j , visited);
        
        if(i  <= m && i >=0 && j + 1 <= n && j + 1 >= 0 && visited[i][j + 1] == 0 && image[i][j + 1] == prev)
            dfs(image , color , prev , m , n , i , j + 1 , visited);
        
        if( i <= m && i  >= 0 && j - 1 <= n && j - 1 >= 0 && visited[i][j - 1 ] == 0 && image[i][j - 1] == prev)
            dfs(image , color , prev , m , n , i , j - 1 , visited);
        
        return ;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited , ans;
        int m = image.size();
        int n = image[0].size();
        for(int i =0 ; i < m ; i ++)
        {   vector<int> temp;
            for(int j = 0 ; j < n ; j ++)
            {
                temp.push_back(0);             
            }
            visited.push_back(temp);
        }
        dfs(image,color,image[sr][sc],m-1,n-1,sr,sc,visited);
        
        for(int i = 0 ; i < m   ; i ++)
        {   vector<int> temp;
            for(int j = 0 ; j < n ; j ++)
            {
                temp.push_back(image[i][j]);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};