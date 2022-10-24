class Solution {
public:
    string getSmallestString(int n, int k) {
        // if curr - 26 >= left
        //take 26 
        //if curr - 26 < left
        //come from start and place a till u can and then place diff on last
        string ans = "";
        int temp = n ;
        while(k - 26 >= temp){
            ans += "z";
            temp--;
            k-=26;
        }
        string tempok = "";
        for(int i = 0 ; i < temp - 1 ; i ++){
            tempok+="a";
            k--;
        }
        char x = 97 + k - 1;
        tempok += x;
        ans  = tempok + ans;
        return ans;
    }
};