class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int pointer1=1,pointer2=1;
        int n = a.size();
        if(n==0)return 0;
        for(int i=1;i<n;i++){
            if(a[i-1] == a[i])
                pointer2++;
            else{
                a[pointer1]=a[pointer2];
                pointer1++;
                pointer2++;
            }
                
        }
        return pointer1;
    }
};