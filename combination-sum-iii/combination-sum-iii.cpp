class Solution {
public:
    void helper(vector<vector<int>>& res,vector<int>& contri,int k,int n,int i){
        //positive base case
        if(k == 0 and n==0){
            res.push_back(contri);
            return;
        }
        //negative base case
        if(i == 10 || n<0)
            return;
        //recursive case
        //include
        contri.push_back(i);
        helper(res,contri,k-1,n-i,i+1);
        contri.pop_back();
        //exclude
        helper(res,contri,k,n,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> contri;
        helper(res,contri,k,n,1);
        return res;
    }
};