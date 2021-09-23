class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int hi=nums.size()-2;
        int lo=0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid] == nums[mid^1]){
                lo = mid + 1;   
            }
            else{
                hi = mid - 1;
            }
        }
        return nums[lo];
    }
};