class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        //FFFFFFFTTTTT
        //First T
        while(lo<hi){
            int mid = lo + (hi - lo)/2;
            if((mid%2==0 and nums[mid]==nums[mid+1]) || (mid%2==1 and nums[mid]==nums[mid-1]))
                lo = mid+1;
            else
                hi = mid;    
        }
        return nums[lo];
    }
};