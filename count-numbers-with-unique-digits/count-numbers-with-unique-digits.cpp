class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int running_product=9;
        int nextDigit=9;
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=ans+running_product;
            running_product*=nextDigit;
            nextDigit--;
        }
        return ans;
    }
};