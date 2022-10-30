// class Solution {
// public:
//     int shortestPath(vector<vector<int>>& grid, int k) {
        
//         //can be done using bfs 
//         //important thing to learn from this is how to handle the visited array in bfs
//         //visited array in this case can be implemented in this using a 3-D array of
//         //[i = row][j = col][k = no of obstacle we can remove from here]
//         //Solution goes here ;}
        
//         int m,n;
//         m = grid.size();
//         n = grid[0].size();
        
//         int visited[41][41][1601];
//         memset(visited , 0 , sizeof(visited));
        
//         //making queue for bfs
//         queue<pair<pair<int,int> , pair<int,int>>> q;
//         q.push({{0,0},{k,0}});
        
//         int ans = INT_MAX;
        
//         //preforming bfs
//         while(!q.empty()){
            
//             pair<pair<int , int > , pair<int,int>> x = q.front();
//             q.pop();
//             //visiting neighbours
//             int i , j , kt ,t_ans;
//             i = x.first.first;
//             j = x.first.second;
//             kt = x.second.first;
//             t_ans = x.second.second;
            
//             cout<<i<<" "<<j<<" "<<kt<<" "<<t_ans<<" "<<endl;
            
//             if(i == m-1 && j == n-1 ){
//                 visited[i][j][kt] = 1;
//                 ans = min(ans , t_ans);
//                 continue;
//             }
            
//             visited[i][j][kt] = 1;
//             if(i + 1 < m && visited[i+1][j][kt] == 0){
//                 if(grid[i+1][j] == 1 ){
//                     if(kt-1 >= 0){
//                     q.push({{i+1,j},{kt-1,t_ans+1}});
//                         visited[i+1][j][kt-1] = 1;
//                     }
//                 }else{
//                     q.push({{i+1,j},{kt,t_ans+1}});
//                      visited[i+1][j][kt] = 1;
//                 }
//             }
//             if(j + 1 < n && visited[i][j+1][kt] == 0){
//                 if(grid[i][j+1] == 1){
//                     if(kt-1 >= 0){
//                     q.push({{i,j+1},{kt-1,t_ans+1}});
//                          visited[i][j+1][kt-1] = 1;
//                     }
//                 }else{
//                     q.push({{i,j+1},{kt,t_ans+1}});
//                      visited[i][j+1][kt] = 1;
//                 }
//             }
//             if(i - 1 >= 0 && visited[i-1][j][kt] == 0){
//                 if(grid[i-1][j] == 1){
//                     if(kt-1 >= 0){
//                     q.push({{i-1,j},{kt-1,t_ans+1}});
//                          visited[i-1][j][kt-1] = 1;
//                     }
//                 }else{
//                     q.push({{i-1,j},{kt,t_ans+1}});
//                      visited[i-1][j][kt] = 1;
//                 }
//             }
//             if(j - 1 >= 0 && visited[i][j-1][kt] == 0){
//                 if(grid[i][j-1] == 1){
//                     if(kt-1 >= 0){
//                     q.push({{i,j-1},{kt-1,t_ans+1}});
//                          visited[i][j-1][kt-1] = 1;
//                     }
//                 }else{
//                     q.push({{i,j-1},{kt,t_ans+1}});
//                      visited[i][j-1][kt] = 1;
//                 }
//             }
//         }
//         return ans == INT_MAX ? -1 : ans;
//     }
// };
class Solution {
public:
    int solve(vector<vector<int>>& grid,int k){
		// At a particular cell we will store the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;
		
		// queue stores (x,y,current path length,number of obstacles we can still remove)
        q.push({0,0,0,k});
        while(!q.empty()){
            auto t=q.front();
            int x=t[0],y=t[1];
            q.pop();
			
			// Exit if current position is outside of the grid
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
                continue;
            }
			
			// Destination found
            if(x==grid.size()-1 && y==grid[0].size()-1)
                return t[2];

            if(grid[x][y]==1){
                if(t[3]>0) // If we encounter an obstacle and we can remove it
                    t[3]--;
                else
                    continue;
            }
			
			// The cell was previously visited by some path and we were able to remove more obstacles from the previous path.
			// Then we don't need to continue on our current path
            if(vis[x][y]!=-1 && vis[x][y]>=t[3])
                continue;
            vis[x][y]=t[3];
            
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});
            
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return solve(grid,k);
    }
};