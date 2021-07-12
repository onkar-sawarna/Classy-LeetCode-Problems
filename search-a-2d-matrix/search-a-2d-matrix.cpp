class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size(), lo, hi, mid, i, j;
        
        if(n == 0 || m==0) return false;
        
        lo = 0, hi = m*n-1;
        
        // FFFTTTT
        // p(x): x >= target
        // first T
        
        while(lo < hi) {
            mid = lo + (hi-lo)/2;
            
            i = mid/n;
            j = mid%n;
            
            if(matrix[i][j] >= target)
                hi = mid;
            else
                lo = mid+1;
  
        }
        
        // Sanity check
        i = lo/n;
        j = lo%n;
        
        if(matrix[i][j] == target)
            return true;
        
        return false;
        
    }
};