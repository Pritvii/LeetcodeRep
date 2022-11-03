class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        //return 0;
        int ans_f = 0 ;
        unordered_map<string , int> m;
        for(string el : words)
            m[el]++;
        int max_odd = 0 ;
        string max_o;
        for(auto el : m){
            string s = el.first;
            int num = el.second;
            if(s[0] == s[1]){
                if(num%2 == 1){
                    if(max_odd < num){
                        max_odd = num;
                        max_o = s;
                }                    
            }
        }
    }
        string ans;
        for(int i = 0 ; i < max_odd ; i ++){
            m[max_o]--;
            ans_f+=2;
        }
        for(string el : words){
            if(el[0] == el[1]){
            if(m[el]%2 == 0){
                int num = m[el];
                for(int i = 0;  i< num/2 ; i ++){
                    m[el]-=2;
                    ans_f+=4;
                }
            }else{
                int num  = m[el];
                if(num > 2){
                    for(int i = 0; i < (num-1)/2 ; i++){
                        m[el]-=2;
                         ans_f+=4;
                    }
                }
            }
            }
        }
        for(string el : words){
            if(el[0]!=el[1]){
                string op = el;
                reverse(op.begin(),op.end());
                int num1 = m[el];
                int num2 = m[op];
                int minn = min(num1 , num2);
                if(minn > 0){
                    for(int i = 0 ; i < minn ; i ++){
                        m[el]--;
                        m[op]--;
                         ans_f+=4;
                    }
                }
            }
        }
        cout<<ans<<endl;
        return ans_f;
}
};