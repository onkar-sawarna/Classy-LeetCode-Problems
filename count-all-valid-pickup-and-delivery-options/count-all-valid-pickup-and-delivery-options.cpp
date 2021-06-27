#define MOD 1000000007
typedef long long ll;
class Solution {
public:
    
    //this is a simple maths problem therefore nothing else should be thought
    int countOrders(int n) {
        ll prevCount=0,res=0;
        //k*n*(2*n-1) posssibilities where k is the number of previous arrangement
        //for every incoming nth pickiup and delivery there is (2*n-1)+2n-2+2n-3+...+1 possibilities
        //for n=1 we update the previous count and result
        prevCount=1;
        res=1;
        for(ll i=2;i<=n;i++){
            res=((prevCount%MOD)*(i%MOD)*((2*i-1)%MOD))%MOD;
            prevCount=res;
        }
        return res;
    }
};