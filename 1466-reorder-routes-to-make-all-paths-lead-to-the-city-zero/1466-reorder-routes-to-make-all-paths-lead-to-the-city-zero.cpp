class Solution {
public:
    int ans = 0;
    int minReorder(int n, vector<vector<int>>& arr) {
        vector<int>neighbour[n],adj[n];
        for(auto it:arr){
            neighbour[it[0]].push_back(it[1]);
            neighbour[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        queue<int>q;
        vector<int>vis(n,0);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            vis[node] = 1;
            q.pop();
            for(auto it:neighbour[node]){
                if(!vis[it]){
                    bool flag = false;
                    for(auto itt:adj[it]){
                        if(itt == node){
                            flag = true;
                            q.push(it);
                            vis[it] = 1;
                            break;
                        }
                    }
                    if(!flag) {
                        ans++;
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};