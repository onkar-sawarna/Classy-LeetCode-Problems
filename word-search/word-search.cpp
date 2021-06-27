class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool yesOrno(vector<vector<char>>& board,string word,int m,int n,int i,int j,int s,vector<vector<bool>>& visited){
        if(s == word.size())return true;
    if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || board[i][j]!=word[s])return false;
        visited[i][j]=true;
        bool res=false;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            res = res || yesOrno(board,word,m,n,x,y,s+1,visited);
            if(res)
            {visited[i][j]=false;
                return true;}
        }
        visited[i][j]=false;//backtracking
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        bool res = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = res || yesOrno(board,word,m,n,i,j,0,visited);
                if(res)
                    return true;
            }
        }
        return false;
    }
};