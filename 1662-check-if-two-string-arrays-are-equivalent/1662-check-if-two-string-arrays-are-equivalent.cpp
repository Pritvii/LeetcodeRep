class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 , s2;
        for(string el : word1){
            s1 += el;
        }for(string el : word2){
            s2 += el;
        }
        return s1 == s2;
    }
};