class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> nge(n);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() and stk.top()<=nums2[i])
                stk.pop();
            if(!stk.empty())
                nge[i]=stk.top();
            else
                nge[i]=-1;
            stk.push(nums2[i]);
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            int index=find(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            ans[i]=nge[index];
        }
        return ans;
    }
};