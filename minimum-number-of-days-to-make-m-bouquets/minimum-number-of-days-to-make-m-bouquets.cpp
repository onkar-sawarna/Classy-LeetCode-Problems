class Solution {
public:
    bool isPossible(int mid,vector<int>& bloomDay, int m, int k){
        int n = bloomDay.size();
        int cnt=0,res=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt == k){
                res++;
                cnt=0;
            }
        }
        if(res>=m)return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo=1,hi=1e9;
        int mid=0;
        while(lo < hi){
             mid = (lo + (hi-lo)/2);
            if(isPossible(mid,bloomDay,m,k))
                hi=mid;
            else
                lo = mid+1;
        }
        if(isPossible(lo,bloomDay,m,k))
            return lo;
        else
            return -1;
    }
};