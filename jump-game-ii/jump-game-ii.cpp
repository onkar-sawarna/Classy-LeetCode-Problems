class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int current_farthest=0;
        int curr_end=0;
        int jumps=0;
        //last element is not required 
        for(int i=0;i<n-1;i++){
            current_farthest = max(current_farthest,nums[i]+i);
            if(i == curr_end){
                jumps++;
                curr_end=current_farthest;
            }
        }
        return jumps;
    }
};