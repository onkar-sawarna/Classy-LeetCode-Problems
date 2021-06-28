class Solution {
public:
    int count(int n,int start,vector<int>& visited){
        int ans=0;
        if(start == n+1){
            return 1;
        }
        for(int i=1;i<=n;i++){
            if(!visited[i] and ((start)%i==0 || i%(start)==0)){
                visited[i] =true;
                ans+=count(n,start+1,visited);
                visited[i] =false;
            }
            
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<int> visited(n+1,0);
        return count(n,1,visited);
    }
};