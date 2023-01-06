//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int visited[100][100];
    void dfs(int sr , int sc , vector<vector<int>>& image ,int newcolor,int n , int m,int ini){
        visited[sr][sc] = 1;
        image[sr][sc] = newcolor;
       // cout<<sr<<" "<<sc<<endl;
        if(sr + 1 < n && visited[sr+1][sc] == 0 && image[sr+1][sc] == ini){
            dfs(sr+1,sc,image,newcolor,n,m,ini);
        }
        if(sr - 1 >= 0 && visited[sr-1][sc] == 0 && image[sr-1][sc] == ini){
            dfs(sr-1,sc,image,newcolor,n,m,ini);
        }
        if(sc + 1 < m && visited[sr][sc+1] == 0 && image[sr][sc+1] == ini){
            dfs(sr,sc+1,image,newcolor,n,m,ini);
        }
        if(sc-1 >= 0 && visited[sr][sc-1] == 0 && image[sr][sc-1] == ini){
            dfs(sr,sc-1,image,newcolor,n,m,ini);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        for(int i = 0 ; i < 100 ; i++){
            for(int j = 0 ; j < 100 ; j ++){
                visited[i][j] = 0 ;
            }
        }
        int initial_color = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        dfs(sr,sc,image,newColor,n,m,initial_color);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends