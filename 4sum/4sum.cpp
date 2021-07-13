class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int left=j+1;
                int right=n-1;
                while(left<right){
                int rem_sum = target-(nums[i]+nums[j]);
                if(nums[left]+nums[right] < rem_sum)
                    left++;
                else if(nums[left]+nums[right] > rem_sum)
                    right--;
                else{
                    vector<int> quad;
                    quad.push_back(nums[i]);
                    quad.push_back(nums[j]);
                    quad.push_back(nums[left]);
                    quad.push_back(nums[right]);
                    ans.insert(quad);
                    left++;
                    right--;
                }
              }
            }
        }
        vector<vector<int>> res;
        for(auto quadruplets : ans){
            res.push_back(quadruplets);
        }
        return res;
    }
};