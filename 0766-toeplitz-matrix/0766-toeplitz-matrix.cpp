class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool ans = true;
        int m = matrix.size();
        int n  = matrix[0].size();
        for(int j = 0; j < n ; j ++){
            //taking col dias
            int i = 0 ;
            int col = j;
            while(col < n-1 && i < m-1){
                if(matrix[i + 1][col + 1] != matrix[i][col]){
                    ans = false;
                    break;
                }
                i++;col++;
            }
        }
        if(ans == false)
            return false;
        
        for(int i = 0 ; i < m ; i ++){
            //taking rows
            int row = i;
            int j = 0 ;
            while(row < m-1 && j < n-1){
                if(matrix[row + 1][j+1] != matrix[row][j]){
                    ans = false;
                    break;
                }
                row++;j++;
            }
        }
        if(ans ==false)
            return false;
        else
            return true;
    }
};