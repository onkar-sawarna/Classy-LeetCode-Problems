class Solution {
public:
    bool isPossible(double speed,double hour,vector<int>& dist){
        double ans = 0.0;
        int n = dist.size();
        for(int i=0;i<n;i++){
            ans += ceil(dist[i]/speed);
        }
        //ans += (double)dist.back()/speed;
        if(ans <= hour)
            return true;
        return false;
    }
        int minEatingSpeed(vector<int>& dist, double hour) {
        int lo,hi,n=dist.size();
        lo = 1;
        hi = 1e9;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(isPossible(mid,hour,dist)){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        if(isPossible(lo,hour,dist))
            return lo;
        else
            return -1;
    }
};