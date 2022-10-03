class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n , 0);
        for(auto el  : pre)
        {
            indegree[el[1]]++;
        }
        
        queue<int> q;
        for(int i  =0 ; i< n ; i ++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        int cnt =0 ; 
        
        vector<vector<int>> adj;
        for(int i = 0  ; i < n ; i ++)
        {
            adj.push_back({});
        }
        
        for(auto el : pre)
        {
            adj[el[0]].push_back(el[1]);
        }
        
        
        while(!q.empty())
        {
            int fr = q.front();
            cnt++;
            q.pop();
            
            for(int el : adj[fr])
            {
                indegree[el]--;
                if(indegree[el] == 0)
                    q.push(el);
                
            }
        }
        
        if(cnt == n)
            return true;
        else
            return false;
        
        
    }
};