class Solution {
public:
    void helper(vector<vector<string>>& res,vector<string>& contri,vector<bool>& rowv,vector<bool>& colv,vector<bool>& pdv,vector<bool>& sdv,int n,int rownum){
        //base case
        if(rownum == n){
            res.push_back(contri);
            return;
        }
        //gpoing through each column
        for(int col=0;col<n;col++){
            if(rowv[rownum] || colv[col] || pdv[rownum-col+n-1] || sdv[rownum+col])
                continue;
            //mark the non-visited stuffs
        
            rowv[rownum]=true;
            colv[col]=true;
            pdv[rownum-col+n-1]=true;
            sdv[rownum+col]=true;
            //recursive call
            contri[rownum][col]='Q';//contribution
            helper(res,contri,rowv,colv,pdv,sdv,n,rownum+1);
            contri[rownum][col]='.';//removing contribution
            //unmarking for the nex recursive call
            sdv[rownum+col]=false;
            pdv[rownum-col+n-1]=false;
            colv[col]=false;
            rowv[rownum]=false;
            
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> contri(n,string(n,'.'));
        vector<bool> rowv(n,false);
        vector<bool> colv(n,false);
        vector<bool> pdv(2*n-1,false);
        vector<bool> sdv(2*n-1,false);
        helper(res,contri,rowv,colv,pdv,sdv,n,0);
        return res.size();
    }
};