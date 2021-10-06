class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            dp[i] = cost[i]+dp[i+1];
            if(i+2<=n){
                dp[i] = min(dp[i],cost[i]+dp[i+2]);
            }
        }
        return min(dp[0],dp[1]);
    }
};