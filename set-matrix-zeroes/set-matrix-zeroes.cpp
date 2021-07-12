class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
      /*{  bool row1,col1;
        row1=col1=false;
        int n = matrix[0].size();
        int m = matrix.size();
        //Checking for the first row and column
        for(int i=0;i<m;i++){
            for(int j=0;i<n;j++){
                if(i==0 and matrix[i][j] == 0)
                    row1=true;
                if(j==0 and matrix[i][j] == 0)
                    col1=true;
                if(matrix[i][j] == 0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
            for(int i=1;i<m;i++){
              for(int j=1;i<n;j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
         }
            if(row1){
                for(int i=0;i<n;i++){
                    matrix[0][i]=0;
                }
            }
            if(col1){
                for(int i=0;i<m;i++){
                    matrix[i][0]=0;
                }
            }
    }}*/
    // variables to check if there are any 1
    // in first row and column
    bool row_flag = false;
    bool col_flag = false;
    int C=mat[0].size();
    int R=mat.size();  
    // updating the first row and col if 1
    // is encountered
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == 0 && mat[i][j] == 0)
                row_flag = true;
 
            if (j == 0 && mat[i][j] == 0)
                col_flag = true;
 
            if (mat[i][j] == 0) {
 
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }
 
    // Modify the input matrix mat[] using the
    // first row and first column of Matrix mat
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
 
            if (mat[0][j] == 0 || mat[i][0] == 0) {
                mat[i][j] = 0;
            }
        }
    }
 
    // modify first row if there was any 1
    if (row_flag == true) {
        for (int i = 0; i < C; i++) {
            mat[0][i] = 0;
        }
    }
 
    // modify first col if there was any 1
    if (col_flag == true) {
        for (int i = 0; i < R; i++) {
            mat[i][0] = 0;
        }
    }}
};