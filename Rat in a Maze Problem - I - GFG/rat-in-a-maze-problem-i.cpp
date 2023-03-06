//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    vector<vector<int>> visited;
    void solve(int i  , int j , vector<vector<int>> &m  , int n , string osf){
        
        if(i == n-1 && j == n-1){
            ans.push_back(osf);
            return;
        }
        
        visited[i][j] = 1;
        
        //left
        if(j-1 >= 0 && visited[i][j-1] == 0 && m[i][j-1] == 1){
            solve(i,j-1,m,n,osf + "L");
        }
        
        //top
        if(i-1 >= 0 && visited[i-1][j] == 0 && m[i-1][j] == 1){
            solve(i-1,j,m,n,osf + "U");
        }
        
        //right
        if(j+1 < n && visited[i][j+1] == 0 && m[i][j+1] == 1){
            solve(i,j+1,m,n,osf + "R");
        }
        
        //down
        if(i+1 < n && visited[i+1][j] == 0 && m[i+1][j] == 1){
            solve(i+1,j,m,n,osf + "D");
        }
        
        
        visited[i][j] = 0;
        
        return ;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        for(int i = 0 ;i < n  ; i ++){
            vector<int> temp ;
            for(int j = 0 ; j < n ; j++){
                temp.push_back(0);
            }
            visited.push_back(temp);
        }
        if(m[0][0] == 0){
            return {};
        }
        
        solve(0 , 0 , m , n , "");
        
        sort(ans.begin() , ans.end());
        
        if(ans.size() == 0 ){
            return {};
        }
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends