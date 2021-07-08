class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums,int i,int& ans){
        if(i >= nums.size())
            return 0;
        if(dp[i]!=-1)return dp[i];
        int include=solve(nums,i+2,ans)+nums[i];
        int exclude=solve(nums,i+1,ans);
        ans=max(include,exclude);
        return dp[i]=ans;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        if(n==1)return nums[0];
        int ans=0;
        solve(nums,0,ans);
        return dp[0];
    }
};