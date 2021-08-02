class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nextGreater(n,-1);
        stack<int> stk;
        for(int  i=2*n-1;i>=0;i--){
            while(stk.empty()==false and stk.top()<=nums[i%n])
                stk.pop();
            if(i<n and stk.empty()==false){
                nextGreater[i]=stk.top();
            }
            stk.push(nums[i%n]);
        }
        return nextGreater;
    }
};

