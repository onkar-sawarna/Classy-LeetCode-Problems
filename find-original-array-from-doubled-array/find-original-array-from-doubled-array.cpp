class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n&1)return {};
        sort(changed.begin(),changed.end());
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
            mpp[changed[i]]++;
        for(int i=0;i<n;i++){
       if(changed[i]!=0 and mpp.find(changed[i]*2)!=mpp.end() and mpp[changed[i]*2]>0 and mpp[changed[i]]>0){
                mpp[changed[i]]--;
                mpp[changed[i]*2]--;
                ans.push_back(changed[i]);
            }
        }int c = mpp[0];
        if(c&1)return {};
        else
        {  c= c/2;
            while(c--)
                ans.push_back(0);
        }
        if(ans.size() == n/2)return ans;
        else return {};      
    }
};