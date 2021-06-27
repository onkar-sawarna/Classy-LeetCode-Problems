class Solution {
public:
    void helperSubset(vector<int>& nums,vector<int>& contri,vector<vector<int>>& a,int i)
    { int n=nums.size();
        if(i == n){
            a.push_back(contri);
            return;
        }
        helperSubset(nums,contri,a,i+1);
        contri.push_back(nums[i]);
        helperSubset(nums,contri,a,i+1);
        contri.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> contri;
        helperSubset(nums,contri,ans,0);
        return ans;
    }
};