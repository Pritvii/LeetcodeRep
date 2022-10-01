class Solution {
public:
    
    
    bool isBipartite_help(vector<vector<int>>& graph , int i , vector<int>& color_visit) {
        queue<int >  que;
        que.push(i);
        color_visit[i] = 0;
        while(!que.empty())
        {
            int top = que.front();
            que.pop();
            int color_top = color_visit[top];
            
            for(int el : graph[top])
            {
                if(color_visit[el]==-1 )
                {   
                    if(color_visit[top] == 1)
                    color_visit[el] = 0;
                    else
                    color_visit[el] = 1;
                    
                    que.push(el);
                }
                else
                {
                    if(color_top == color_visit[el])
                        return false;
                }
            }
        }
            
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph)
    {   bool ans = true;
        vector<int> color_visit(graph.size() , -1);
        for(int i=0 ; i < graph.size() ; i ++)
        {   if(color_visit[i] == -1)
            ans &= isBipartite_help(graph , i , color_visit);
        }
     return ans;
    }
};