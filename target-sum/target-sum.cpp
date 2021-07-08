class Solution {
public:
    //This will be analogous to counting the number of subset with a given differnce
    int dp[21][2001];
    int solve(vector<int>& nums, int target){
        int sum=0;
        int cnt=0;
        int n=nums.size();
        //Calculating the sum of the array
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]==0)
                cnt = cnt+1;
        }
        //Subset sum
        if(target > sum)
            return 0;
        if((target+sum)%2!=0)
            return 0;
        int S=(target+sum)/2;
        //Initialization
        for(int i=0;i<=n;i++){
            for(int j=0;j<=S;j++){
                if(i==0)
                    dp[i][j]=0;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=S;j++){
                if(j==0)
                    dp[i][j]=1;
            }
        }
        //Main Step
        for(int i=1;i<=n;i++){
            for(int j=1;j<=S;j++){
                if(nums[i-1]==0)
                    dp[i][j] = dp[i-1][j];
                else if(j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return pow(2,cnt)*dp[n][S];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,target);
    }
};