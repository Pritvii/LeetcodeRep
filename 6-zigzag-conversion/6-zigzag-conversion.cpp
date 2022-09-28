class Solution {
public:
    string convert(string s, int numRows) {
        map<int , string> x;
        if(numRows == 1)
            return s;
        
        char arr[numRows][1001];
        memset(arr , ' ' , sizeof(arr));
        int used = 0;
        int last_col = 0;
        int plus = numRows - 1;
        for(int i  = 0  ; i < 1000  ; i++)
        {   
            
            if(used == s.length()){last_col = i ;
                break;
            }
            last_col = i ;
            cout<<i<<endl;
            int flag = 0;
            for(int  j = 0 ; j < numRows ; j ++)
            {
                arr[j][i] = s[used];
                x[j] += s[used];
                used++;
                if(used == s.length()){
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 1){last_col = i ;
                break;
            }
            i++;
            flag = 0;
            for(int j = numRows - 2 ; j >= 1 ; j --)
            {   
                if(used == s.length()){
                flag  = 1;
                    break;
            }
                arr[j][i] = s[used];
                x[j]+=s[used];
                used++;
                i++;
                
            }
            if(flag == 1){last_col  = i;
                break;
            }
            i--;
            
            last_col = i;
        }
        
        string ans = "";
        cout<<x.size()<<endl;
        vector<pair<int , string >  > ansv;
        for(auto el : x)
        {   ans+=el.second;
            ansv.push_back({el.first , el.second});
        }
        
        return ans;
    }
};