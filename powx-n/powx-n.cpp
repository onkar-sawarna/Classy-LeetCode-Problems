class Solution {
public:
    double myPow(double x, int y) {
      double ans = 1.0;
      long long n=y;
      if(n<0) n*=-1;
      while(n>0){
          if(n&1){
              ans = ans * x;
              n--;
          }
          else{
              x = x * x;
              n/=2;
          }
      }
        if(y<0) return (1.0)/(ans);
        return ans;
    }
};