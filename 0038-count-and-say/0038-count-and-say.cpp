class Solution {
public:

string say(string str){
  int cnt=1;
    string res="";
    for(int i=1;i<str.length();i++){
        if(str[i]==str[i-1]) cnt++;
        else{
            res+=cnt+'0';
            res+=str[i-1];
            cnt=1;
        }
    }
     res+=cnt+'0';
     res+=str[str.length()-1];
     cnt=1;
    return res;
}

string countAndSay(int n) {
    if(n==1) return "1";
   return say(countAndSay(n-1));
}

};