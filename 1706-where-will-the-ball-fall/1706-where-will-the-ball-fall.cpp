class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int >>& grid  , int i ,  int j , int m , int n){
        //cout<<i<<" "<<j<<endl;

        if(i == m){
            return j;
        }
        
        if(grid[i][j] == 1){
            //move to right
            //have to check that if i can move to the right or i am blocked
            
            // case - 1 (\/)
            if(j < n-1){
                if(grid[i][j+1] == -1){
                    // I am stuck cant move
                    return -2;
                }
            }
            //case - 2 (\|)
            if(j == n-1){
                return -2;
            }
            if(dp[i][j]!=-1)
                return dp[i][j];
            return dp[i][j] = solve(grid,i+1,j+1,m,n);
        }else{
            //move to left
            if(j>0){
                if(grid[i][j-1] == 1){
                    return -2;
                }
            }
            if(j == 0){
                return -2;
            }
            if(dp[i][j]!=-1)
                return dp[i][j];
            return dp[i][j] = solve(grid,i+1,j-1,m,n);
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m,n ;
        m = grid.size();
        n  = grid[0].size();
        memset(dp , -1 , sizeof(dp));
        vector<int> ans;
        for(int i = 0 ; i < n ; i ++){
            if(solve(grid,0,i,m,n) == -2)
            ans.push_back(-1);
            else
            ans.push_back(solve(grid,0,i,m,n));
            
            cout<<endl<<endl<<endl;
        }
        
        return ans;
    }
};