/*inspite of making visited as bool array and marking true and false at required positions
we take visited as integer array and increase/decrease the value at indices
this ensures that while marking a index available(restoring) for a particular queen we dont unmark for any previous queen*/  

/*we get multiple possible solutions , because when for loop runs in queenHelper function for col=0 we fix position for first queen at col=0 and try finding positions for (n-1) queens recursively.
Similarly for col=1 we fix first queen at col =1 and find positions for remaining (n-1) queens.
 So for only those possibilities of first queen where we are successively able to reach rowNum till last row we push them in result 
and possibilities where rowNum does not reach till end we dont push in res because it runs till last line of queenHelper func without incrementing value for rowNum and return control to caller func*/

/* when col=0 we find if there is a possible solution if we fix 1st queen at col=0, in the process we keep on marking the cells recursively , after the recursive function unfolds it is necessary that we switch visited array back to its previous state(all cells as ‘.’ because it will again start finding a solution by fixing 1st queen at col=1*/

class Solution {
public:
    void mark(vector<vector<int>> &visited,int n,int row,int col, int offset)
    {
        
        int i,j;
        //marking column
        for( i=0;i<n;i++)
            visited[i][col]+=offset;
        //marking row
        for(i=0;i<n;i++)
            visited[row][i] +=offset;
        
        //principal diagonal check
        //go down
        i=row,j=col;
        while(i<n && j<n)
            visited[i++][j++] +=offset;
        //secondary diagonal check.
        //go down
        i=row,j=col;
        while(i<n && j>=0)
            visited[i++][j--] +=offset;
        
    }
    
    void queenHelper(vector<vector<int>> &visited, int n, int rowNum, vector<string> currBoard, vector<vector<string>> &res)
    {
        //base case
        //positive base case
        if(rowNum==n)
        {
            res.push_back(currBoard);
            return;
        }
        
        //recursive case
        //checking for all possibility of column for rowNum
        int col;
        for(col=0;col<n;col++)
        {
            //if already visited(i.e not available) we skip this col 
            if(visited[rowNum][col])
                continue;
            
            //marking the corresponding row,col and diagonals
            mark(visited,n,rowNum,col,1);
            //pushing current contribution
            currBoard[rowNum][col]='Q';
            //calling recursively
            queenHelper(visited,n,rowNum+1,currBoard, res);
            //pop current contribution
            currBoard[rowNum][col]='.';
            //unmark the corresponding row,col and diagonals
            mark(visited,n,rowNum,col,-1);
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> currBoard(n,string(n,'.'));
        vector<vector<string>> res;
        vector<vector<int>> visited(n,vector<int>(n,0)); 
        queenHelper(visited,n,0,currBoard,res);
        return res;
    }
};
