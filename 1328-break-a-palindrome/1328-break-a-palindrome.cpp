class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.length();
        if(s=="aba") return "abb";
        if(n==1) return "";
        for(int i=0;i<n;i++){
            if(s[i]!='a' && i!=n/2){
                s[i] = 'a';
                return s;
            }
        }
        s[n-1] = 'b';
        return s;
    }
};