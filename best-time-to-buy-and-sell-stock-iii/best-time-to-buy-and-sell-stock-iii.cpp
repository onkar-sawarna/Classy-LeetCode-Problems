class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1)return 0;
        //Pre Computation Step for one transaction
        vector<int> profit_transaction_one(n,0);
         profit_transaction_one[0]=0;
        int min_price=prices[0];
        for(int i=1;i<n;i++){
        profit_transaction_one[i]=max(profit_transaction_one[i-1],prices[i]-min_price);
            min_price=min(min_price,prices[i]);
        }
        //Main Logic for overall profit
        
        //for n-1
        int tot_profit=profit_transaction_one[n-2];//because 2nd transaction is not possible
        int answer=max(answer,tot_profit);
        int max_price=prices[n-1];
        //for n-2 to 1
        for(int i=n-2;i>=1;i--){
            tot_profit=profit_transaction_one[i-1]+max_price-prices[i];
            answer=max(answer,tot_profit);
            max_price=max(max_price,prices[i]);
        }
        //for 0
        tot_profit = max_price-prices[0];
        answer=max(answer,tot_profit);
        return answer;
    }
};