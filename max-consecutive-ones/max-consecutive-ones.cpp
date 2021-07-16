class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int globalMax=INT_MIN;
        int localMax=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                localMax++;
            else
                localMax=0;
            globalMax=max(globalMax,localMax);
        }
        return globalMax;
    }
};