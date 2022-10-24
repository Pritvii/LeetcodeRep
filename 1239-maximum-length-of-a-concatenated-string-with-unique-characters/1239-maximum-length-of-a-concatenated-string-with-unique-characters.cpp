class Solution {
public:
    int ans = INT_MIN;
    set<char> s;
    void solve(vector<string>& arr,int curr){
        if(curr == arr.size()){
            //base case
            ans = max(ans ,  (int)s.size() ) ;
            return ;
        }
        //try to include
        bool can_take = true;
        for(char el : arr[curr]){
            if(s.find(el)!=s.end()){
                can_take = false;
            }
        }
        if(can_take == true){
            for(char el : arr[curr]){
                s.insert(el);
            }
            solve(arr , curr + 1);
            for(char el : arr[curr]){
                s.erase(s.find(el));
            }
        }
        //do not include
        solve(arr , curr + 1);
        
    }
    int maxLength(vector<string>& arr) {
        vector<string> temp;
        
        for(int i = 0 ; i < arr.size() ; i ++){
            int flag = 0 ;
            map<char , int> x;
            for(char el : arr[i]){
                ++x[el];
                if(x[el] > 1){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                continue;
            }
            else{
                temp.push_back(arr[i]);
            }
            
        }
        solve(temp , 0);
        return ans;
    }
};