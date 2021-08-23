class Solution {
public:
    //Here in this question we can take two dp arrays and initialise them to 0
    //one of the array represents max profit I can make assuming i had bought the previous 
    //second array represents max profit I can make assuming i had sold the previous time
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1)return 0;
        int dp1[n];
        int dp2[n];
        dp1[0]=-prices[0];
        dp2[0]=0;
        for(int i=1;i<n;i++){
            dp1[i]=max(dp1[i-1],dp2[i-1]-prices[i]);
            dp2[i]=max(dp2[i-1],dp1[i-1]+prices[i]);
        }
        return dp2[n-1];
    }
};