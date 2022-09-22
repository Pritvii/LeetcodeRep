class Solution {
public:
    string longestPalindrome(string s) {
        int n  = s.length();
        int odd_ans = 0;
        string anss_odd , anss_ev;
        for(int i = 0 ; i < n ; i ++)
        {
            //considering i as centre
            int left = i-1;
            int right  = i +1;
            int temp = 1;
            //cout<<left<<" "<<right<<endl;
            string tempo ;
            tempo += s[i];
            
            while(left >= 0 && right <= n-1 && s[left] == s[right])
            {   tempo  = s[left] + tempo + s[right];
                temp+=2;
                left--;
                right++;
            }
            //cout<<tempo<<endl;
            if(odd_ans < temp)
                anss_odd = tempo;
            odd_ans = max(temp , odd_ans);
        }
        int ev_ans = 0;
        for(int i = 0 ; i < n - 1 ; i ++)
        {   int temp = 0;
            int left  = i;
            int right = i +1;
            string tempo;
            if(s[left] == s[right]){
                tempo += s[left];
                tempo += s[right];
                temp+=2;
            }
            else
            {
                continue;
            }
            left--;
            right++;
            //cout<<left<<right<<endl;
            while(left >= 0 && right <= n-1 && s[left] == s[right])
            {   tempo   = s[left] + tempo + s[right];
                temp+=2;
                left--;
                right++;
            }
            //cout<<tempo<<endl;
            if(ev_ans < temp)
                anss_ev = tempo;
            ev_ans = max(ev_ans , temp);
        }
        //cout<<anss_odd<<" "<<anss_ev;
        cout<<s.length();
        if(anss_ev.length() > anss_odd.length())
        {
            return anss_ev;
        }
        else
        {
            return anss_odd;
        }
        
    }
};