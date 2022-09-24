class Solution {
public:
    int reverse(int x) {
        if(x < -2147483647 || x > 2147483646)
            return 0;
        if(x  < 0)
        {
            x = x*-1;
            string ans = to_string(x);
            cout<<ans;
            std::reverse(ans.begin() , ans.end());
            string temp = "";
            int t = 0;
            if(ans[0] == '0')
            {
                while(ans[t]!='0')
                    t++;
            }
            for(int i = t  ; i < ans.length() ; i ++)
            {
                temp += ans[i];
            }
            int num_ans  = 0 ;
            try{
             num_ans = (int)stoi(temp);
            }
            catch(...)
            {
                return 0;
            }
            num_ans*=-1;
            return num_ans;
        }
        else
        {
            string ans = to_string(x);
            cout<<ans;
            std::reverse(ans.begin() , ans.end());
            string temp = "";
            int t = 0;
            if(ans[0] == '0')
            {
                while(ans[t]!='0')
                    t++;
            }
            for(int i = t  ; i < ans.length() ; i ++)
            {
                temp += ans[i];
            }
            int num_ans = 0;
            try{
             num_ans = (int)stoi(temp);
            }
            catch(...)
            {
                return 0;
            }
            
            return num_ans;
        }
    }
};