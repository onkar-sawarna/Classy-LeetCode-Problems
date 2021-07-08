class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        int S=sum/2;
        bool dp[n+1][sum+1];
        memset(dp,false,sizeof(dp));
         //Initialization
        for(int i=0;i<=n;i++){
            for(int j=0;j<=S;j++){
                if(i==0)
                    dp[i][j]=false;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=S;j++){
                if(j==0)
                    dp[i][j]=true;
            }
        }
        //Main Logic
        for(int i=1;i<=n;i++){
            for(int j=1;j<=S;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][S];  
    }
};