class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        //perform bfs on the strings that have only one change and not back on the parent
        queue<pair<pair<string,string> , pair<int, int> >> q;
        q.push({{start , start},{0,0}});
        int ans = INT_MAX;
        int visited[10] = {0};
        while(!q.empty()){
            pair<pair<string,string>,pair<int,int > > x = q.front();
            q.pop();
            
            string curr = x.first.first;
            string parent = x.first.first;
            int curr_val = x.second.first;
            int idx = x.second.second;
            
            
            cout<<curr<<"->"<<endl;
            if(curr == end)
                ans = min(ans , curr_val);
            int i= 0;
            for(string el : bank){
                if(el!=parent && el!=curr){
                    int diff = 0 ;
                    for(int i = 0 ; i < 8 ; i ++){
                        if(curr[i]!=el[i])
                            diff++;
                    }
                    if(diff == 1 && visited[i] == 0){
                        cout<<el<<endl<<endl;
                        visited[i] = 1;
                        q.push({{el,curr},{curr_val+1 , i}});
                    }
                }
                i++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};