class Solution {
public:
    bool isPossible(int force,int diff,vector<int>& position){
        int n = position.size();
        int last = position[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(position[i] - last >= force){
                last = position[i];
                cnt++;
            }
            if(cnt == diff)return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int lo,hi,n;
        n = position.size();
        lo=1;
        hi = position[n-1] - position[0];
        while(lo<hi){
            int mid=lo + (hi-lo+1)/2;
            if(isPossible(mid,m,position)){
                lo = mid ;
            }
            else{
                hi = mid - 1;
            }
        }
        return lo;
    }
};