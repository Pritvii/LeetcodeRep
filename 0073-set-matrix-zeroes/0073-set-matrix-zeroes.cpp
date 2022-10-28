class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<pair<int , int >  , int > x;
        for(int i = 0 ; i  < matrix.size() ; i ++){
            for(int j = 0  ;j < matrix[0].size() ;  j++){
                if(matrix[i][j] == 0){
                    for(int k = 0 ; k < matrix[0].size() ; k++){
                        x[{i,k}]=1;
                    }
                    for(int k = 0 ; k  < matrix.size() ;k  ++){
                       x[{k,j}]=1;
                    }
                }
            }
        }
        for(auto el : x){
            matrix[el.first.first][el.first.second] = 0 ;
        }
        
    }
};