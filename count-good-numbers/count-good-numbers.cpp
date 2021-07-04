/*Now, we know we have 4 primes = {2, 3, 5, 7} and 5 evens = {0, 2, 4, 6, 8}

if index == 0
then there can be any of one evens at even position, so 5 ways
ans = 5

if index == 1
then there was 1 even at index = 0, and at this odd index there can be one of 4 primes
ans = 5* 4(this pos)

if index == 2
then at this even index there can be one of 5 evens
ans = (5*4) * 5(this pos)

so, continuing the pattern we can see, it's like, 5*4*5*4*5*4*5..... ans so on
here no. of 4s = no. of odd positions = n/2
no. of 5s = no. of even positions = (n-n/2)

ans = pow(4,count4) * pow(5,count5)*/
#define mod 1000000007
class Solution {
public:
    long long power(long long x,long long y){
        if(y==0)
            return 1;
        long long ans = power(x,y/2);
        ans=(ans*ans)%mod;
        if(y%2)ans=(ans*x)%mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2+n%2;
        long long ans =  ((power(5,even)%mod)*(power(4,odd)%mod))%mod;
        return ans;
    } 
};