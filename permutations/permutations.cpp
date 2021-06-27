class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans,int start){
        int n=nums.size();
        if(start == n){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<n;i++){
            swap(nums[i],nums[start]);
            helper(nums,ans,start+1);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,ans,0);
        return ans;
    }
};