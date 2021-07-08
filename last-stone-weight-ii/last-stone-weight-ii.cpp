class Solution {
public:
    //Minimum Subset Sum Difference
    int lastStoneWeightII(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        bool dp[n+1][sum+1];
        memset(dp,false,sizeof(dp));
         //Initialization
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)
                    dp[i][j]=false;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0)
                    dp[i][j]=true;
            }
        }
        //subset sum Code
        //Main Logic
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int diff=0;
        for(int i=sum/2;i>=0;i--){
            if(dp[n][i] == true){
                diff = sum - 2*i;
                break;
            }
        }
        return diff;
    }
};