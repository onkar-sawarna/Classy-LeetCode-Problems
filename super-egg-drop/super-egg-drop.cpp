class Solution {
public:
    int eggdrop(int e, int f,vector<vector<int>>& dp) {
        if(f==0 || f==1)
            return f;
        if(e==1)
            return f;
        if(dp[e][f]!=-1)
            return dp[e][f];
        int mn=INT_MAX;
        int left,right;
        int l=1;
        int h=f;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=eggdrop(e-1,mid-1,dp);   
            int right=eggdrop(e,f-mid,dp) ;  
            int temp=1+max(left,right);           
            if(left<right){                  
                 
              l=mid+1;                      
            }
            else                             
            {    
                h=mid-1;
            }
            mn=min(mn,temp);               
        }
        return  dp[e][f]=mn;
    }
    int superEggDrop(int e, int f){
        vector<vector<int>> dp(e+1,vector<int> (f+1,-1));
        return eggdrop(e,f,dp);
    }
};