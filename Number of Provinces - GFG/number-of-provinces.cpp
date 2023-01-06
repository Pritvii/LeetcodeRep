//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int ans = 0 ;
    int visited[500] = {0};
    void dfs(int node , vector<vector<int>> adj , int  n){
        visited[node] = 1;
        for(int i = 0 ; i < n ; i ++){
            if(adj[node][i] == 1){
                if(visited[i] != 1){
                    dfs(i,adj , n);
                }
            }
        }
        return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int n = adj.size();
        for(int i = 0 ; i < n ; i ++){
            if(visited[i]!=1){
            dfs(i , adj , n);
            ans++;
            }
            
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends