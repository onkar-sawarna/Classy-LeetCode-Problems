class Solution {
public:
    int getSum(int value,vector<int>& arr){
        int n= arr.size(),sum=0;
        for(int i=0;i<n;i++){
            if(arr[i] > value)
                sum+=value;
            else
                sum+=arr[i];
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();
        int lo,hi,mid,maxElt=INT_MIN;
        //Search space ranges from 0 to max(ar[i])
        for(int i=0;i<n;i++){
            maxElt=max(maxElt,arr[i]);
        }
        //TTTTTTTFFFFFFF
        //last T
        //as predicate is sum<=target
        lo=0;
        hi=maxElt;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
                if(getSum(mid,arr)<target)
                    lo=mid;
                else
                    hi=mid-1;         
        }
        int s1=getSum(lo,arr);//ye smaller dega
        int s2=getSum(lo+1,arr);//greaterthan target dega ye
        
        return (abs(s1-target)<=abs(s2-target) ? lo : lo+1);//closest stuff nikal lo
    }
};